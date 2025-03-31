#include "doctorwindow.h"
#include "dialog_prescribtion.h"
#include "qdatetime.h"
#include "qmessagebox.h"
#include "qshortcut.h"
#include "schedule_dialog.h"
#include "ui_doctorwindow.h"
#include <ranges>
#include <QInputDialog>

DoctorWindow::DoctorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);
    qDebug()<<"DoctorWindow created";
    refresh_sc = std::make_unique<QShortcut>(QKeySequence("F5"),this,SLOT(refresh()));
}

DoctorWindow::~DoctorWindow()
{
    qDebug()<<"DoctorWindow destroyed";
    delete ui;
}

bool DoctorWindow::init()
{
    std::string text = logged_account.username() + " - " +
                       logged_account.name() + " " +
                       logged_account.familyname();
    ui->menuBar->addMenu((QString::fromStdString(text)));
    std::vector<schedule_message> schedules = client_.lock()->GetDoctorSchedules(logged_account);
    schedule_dialog dialog;
    dialog.SetSchedules(schedules);
    int a = dialog.exec();
    if(a == QDialog::Rejected)
    {
        this->close();
        return false;
    }
    size_t index = dialog.GetChoosenId();
    room = dialog.GetRoom();
    type = dialog.GetType();
    qDebug()<<room.c_str();
    Schedule = std::make_unique<schedule>(client_.lock(),index);
    if(!Schedule->GetPatients().empty())
    {
        std::ranges::for_each(Schedule->GetPatients(),[this](auto& i)
        {
            QString temp = QString(i.username().name().c_str()) + " " + QString(i.username().familyname().c_str());
            ui->PatientsList->addItem(temp);
        });
        ui->PatientsList->setCurrentRow(0);
        ui->CurrentPatientName->setText(ui->PatientsList->currentItem()->text());
        SetPatientData(Schedule->GetCurrentPatient());
        SetPatientHistory();
        client_.lock()->GetPatientPrescribtion(Schedule->GetCurrentPatient().username(),prescribtions);
        std::ranges::for_each(prescribtions,[this](auto& i)
                              {
                                  ui->PatientMeds->addItem(i.GetMedicine().c_str());
                              });
    }
    return true;
}
void DoctorWindow::show_prescribtion()
{
    size_t i = ui->PatientMeds->currentIndex().row();
    std::string message = prescribtions[i].GetMedicine() + "\n" +
                          prescribtions[i].GetDose() + "\n" +
                          "koniec ważności recepty: " + prescribtions[i].GetExpDate() + "\n"+
                          "przepisał: " + prescribtions[i].who_prescribed.name() + " " + prescribtions[i].who_prescribed.familyname();
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(message.c_str());
    msgBox.setWindowTitle("Recepta");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
void DoctorWindow::get_next_patient()
{
    client_.lock()->EventDone(*Schedule->GetCurrentEvent());
    Schedule->Next();
    ui->PatientMeds->clear();
    std::string text = Schedule->GetCurrentPatient().username().name() + " " +Schedule->GetCurrentPatient().username().familyname();
    ui->CurrentPatientName->setText(QString::fromStdString(text));
    SetPatientData(Schedule->GetCurrentPatient());
    SetPatientHistory();
    client_.lock()->GetPatientPrescribtion(Schedule->GetCurrentPatient().username(),prescribtions);
    std::ranges::for_each(prescribtions,[this](auto& i)
                          {
                              ui->PatientMeds->addItem(i.GetMedicine().c_str());
                          });
}
void DoctorWindow::new_referal()
{
    QInputDialog dialog;
    med_event m;
    m.SetDescribtion(dialog.getItem(this,"Nowe skierowanie","Rodzaj skierowania",QStringList{"rtg","mri","usg","ekg","morfologia","zabieg"}).toStdString());
    m.SetWherePrescribed(room);
    m.patient = Schedule->GetCurrentPatient();
    m.who_prescribed = logged_account;
    m.SetWhenPrescribed(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
    client_.lock()->NewReferal(m);
    refresh();
}
void DoctorWindow::new_prescribtion()
{
    dialog_prescribtion dialog(this);
    dialog.exec();
    if(dialog.Accepted)
    {
        prescribtion p = dialog.GetPrescribtion();
        p.SetWherePrescribed(room);
        p.patient = Schedule->GetCurrentPatient();
        p.who_prescribed = logged_account;
        client_.lock()->NewPrescribtion(p);
        refresh();
    }
}
void DoctorWindow::SetPatientData(const patient_message& p)
{
    ui->PatientName->setText(QString(p.username().name().c_str())+" "+QString(p.username().familyname().c_str()));
    ui->PatientAddress->setText(QString(p.street().c_str()) + " " + QString(p.city().c_str()) + " " + QString(p.postcode().c_str()));
    ui->PatientPesel->setText(QString(p.pesel().c_str()));
}
void DoctorWindow::SetPatientHistory()
{
    ui->treeWidget->clear();
    auto history = Schedule->GetCurrentPatientHistory();
    std::map<std::string,std::vector<std::shared_ptr<med_event>>> history_grouped;
    if(!history.empty())
    {
        std::ranges::for_each(history,[&history_grouped](auto i)
                              {
                                  std::string year = i->GetWhenPrescribed().substr(0,4);
                                  history_grouped[year].push_back(i);
                              });
        std::ranges::for_each(history_grouped,[this](auto& i)
                              {
                                  QTreeWidgetItem* temp = new QTreeWidgetItem(ui->treeWidget);
                                  temp->setText(0,QString::fromStdString(i.first));
                                  std::ranges::for_each(i.second,[&temp](auto& j)
                                                        {
                                                            QTreeWidgetItem *child = new QTreeWidgetItem();
                                                            child->setText(1, QString::number(j->GetId()));
                                                            child->setText(2, j->GetDescribtion().c_str());
                                                            child->setText(3, j->GetWhenPrescribed().c_str());
                                                            temp->addChild(child);
                                                        });
                              });
    }
}
void DoctorWindow::show_history()
{
    size_t id = ui->treeWidget->currentItem()->text(1).toInt();
    auto history = Schedule->GetCurrentPatientHistory();
    auto item = history | std::ranges::views::filter([id](auto i){ return i->GetId() == id;});
    if(item)
    {
        std::shared_ptr<med_event> event = client_.lock()->GetPatientEvent(*item.begin()->get());
        std::string message = get_dialog_message(event);
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText(message.c_str());
        msgBox.setWindowTitle("Historia pacjenta");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}
std::string DoctorWindow::get_dialog_message(std::shared_ptr<med_event>& event) const
{
    std::string ret;
    if(dynamic_cast<examination*>(event.get()))
    {
        examination* ex = (examination*)event.get();
        std::shared_ptr<exam_results> ex_res = client_.lock()->GetExamResults(*ex);
        ret = std::to_string(ex->GetId()) + "\n" +
              ex->GetDescribtion() + "\n" +
              "przepisał: " +ex->who_prescribed.name() + " " + ex->who_prescribed.familyname() + "\n" +
              "data: " + ex->GetWhenPrescribed() + "\n" +
              "przeprowadził: " +ex->who_performs.name() + " " + ex->who_performs.familyname() + "\n" +
              "data: " + ex->GetWhenPerformed() + "\n" +
              "wyniki: " + ex_res->get_str();

    }
    else if(dynamic_cast<prescribtion*>(event.get()))
    {
        prescribtion* pres = dynamic_cast<prescribtion*>(event.get());
        ret = std::to_string(pres->GetId()) + "\n" +
              pres->GetDescribtion() + "\n" +
              pres->GetMedicine() + "\n" +
              pres->GetDose() + "\n" +
              pres->GetExpDate() + "\n" +
              "przepisał: " + pres->who_prescribed.name() + " " + pres->who_prescribed.familyname() + "\n" +
              "data: " + pres->GetWhenPrescribed();

    }
    else if(dynamic_cast<procedure*>(event.get()))
    {
        procedure* proc = dynamic_cast<procedure*>(event.get());
        ret = std::to_string(proc->GetId()) + "\n" +
              proc->GetDescribtion() + "\n" +
              "przepisał: " + proc->who_prescribed.name() + " " + proc->who_prescribed.familyname() + "\n" +
              "data: " + proc->GetWhenPrescribed() + "\n" +
              "przeprowadził: " + proc->who_performs.name() + " " + proc->who_performs.familyname() + "\n" +
              "data: " + proc->GetWhenPerformed();
    }
    else
    {
        ret = std::to_string(event->GetId()) + "\n" +
              event->GetDescribtion() + "\n" +
              "lekarz: " + event->who_prescribed.name() + " " + event->who_prescribed.familyname() + "\n" +
              "data: " + event->GetWhenPrescribed();
    }
    return ret;
}
void DoctorWindow::refresh()
{
    ui->PatientMeds->clear();
    std::string text = Schedule->GetCurrentPatient().username().name() + " " +Schedule->GetCurrentPatient().username().familyname();
    ui->CurrentPatientName->setText(QString::fromStdString(text));
    SetPatientData(Schedule->GetCurrentPatient());
    SetPatientHistory();
    client_.lock()->GetPatientPrescribtion(Schedule->GetCurrentPatient().username(),prescribtions);
    std::ranges::for_each(prescribtions,[this](auto& i)
                          {
                              ui->PatientMeds->addItem(i.GetMedicine().c_str());
                          });
}
void DoctorWindow::add_results()
{
    if(type == "rtg" ||type == "usg" ||type == "mri")
    {
        QInputDialog dialog;
        rtg_res_message res;
        res.set_result(dialog.getText(this,"Wyniki badania","Wpisz wyniki").toStdString());
        res.mutable_result_id()->mutable_event()->set_id(Schedule->GetCurrentEvent()->GetId());
        res.mutable_result_id()->mutable_event()->set_describtion(type);
        client_.lock()->AddResult(res);
    }
    else if(type == "morfologia")
    {
        mor_res_message res;
        QInputDialog dialog;
        res.set_hb(dialog.getInt(this,"Wyniki badania","Podaj HB"));
        res.set_rbc(dialog.getInt(this,"Wyniki badania","Podaj RBC"));
        res.set_wbc(dialog.getInt(this,"Wyniki badania","Podaj WBC"));
        res.set_plt(dialog.getInt(this,"Wyniki badania","Podaj PLT"));
        res.mutable_result_id()->mutable_event()->set_id(Schedule->GetCurrentEvent()->GetId());
        qDebug()<<res.result_id().event().id();
        client_.lock()->AddResult(res);
    }
    else if (type == "ekg")
    {
        ekg_res_message res;
        QInputDialog dialog;
        res.set_rhytm(dialog.getInt(this,"Wyniki badania","Podaj rytm"));
        res.set_pr_delay(dialog.getInt(this,"Wyniki badania","Podaj PR"));
        res.set_qrs(dialog.getInt(this,"Wyniki badania","Podaj QRS"));
        res.mutable_result_id()->mutable_event()->set_id(Schedule->GetCurrentEvent()->GetId());
        client_.lock()->AddResult(res);
    }
    else
    {
        return;
    }
}
