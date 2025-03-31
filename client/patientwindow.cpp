#include "patientwindow.h"
#include "qmessagebox.h"
#include "ui_patientwindow.h"

PatientWindow::PatientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
}

PatientWindow::~PatientWindow()
{
    delete ui;
}

void PatientWindow::show_history()
{
    size_t id = ui->historyTree->currentItem()->text(1).toInt();
    auto item = std::ranges::find_if(history,[id](auto i){return i.GetId() == id;});
    if(item != history.end())
    {
        std::shared_ptr<med_event> event = client_.lock()->GetPatientEvent(*item);
        std::string message = get_dialog_message(event);
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText(message.c_str());
        msgBox.setWindowTitle("Historia pacjenta");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}
void PatientWindow::show_prescribtion()
{
    size_t i = ui->PrescribtionList->currentIndex().row();
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
void PatientWindow::init()
{
    std::string text = logged_account.username() + " - " +
                       logged_account.name() + " " +
                       logged_account.familyname();
    ui->menubar->addMenu((QString::fromStdString(text)));
    client_.lock()->GetPatientEvents(logged_account,events);
    client_.lock()->GetPatientsHistory(logged_account,history);
    client_.lock()->GetPatientPrescribtion(logged_account,prescribtions);
    qDebug()<<prescribtions.size();
    qDebug()<<events.size();
    qDebug()<<history.size();
    set_history();
    set_events();
    set_prescribtions();
}
void PatientWindow::set_history()
{
    std::map<int,std::vector<med_event>> history_grouped_by_year;
    std::ranges::for_each(history,[&history_grouped_by_year](auto& i)
    {
        history_grouped_by_year[std::stoi(i.GetWhenPrescribed().substr(0,4))].push_back(i);
    });

    std::ranges::for_each(history_grouped_by_year,[this](auto& i)
    {
        QTreeWidgetItem *temp = new QTreeWidgetItem(ui->historyTree);
        temp->setText(0,QString::number(i.first));
        std::ranges::for_each(i.second,[&temp](auto& j)
        {
            QTreeWidgetItem *child = new QTreeWidgetItem();
            child->setText(1, QString::number(j.GetId()));
            child->setText(2, j.GetDescribtion().c_str());
            child->setText(3, j.GetWhenPrescribed().c_str());
            temp->addChild(child);
        });
    });
}
void PatientWindow::set_event(const med_event& me, size_t i)
{
    ui->nextVisitsTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(me.GetDescribtion())));
    ui->nextVisitsTable->setItem(i,1,new QTableWidgetItem(QString::fromStdString(me.who_prescribed.name() + " " + me.who_prescribed.familyname())));
    ui->nextVisitsTable->setItem(i,2,new QTableWidgetItem(QString::fromStdString(me.GetWhenPrescribed())));
    ui->nextVisitsTable->setItem(i,3,new QTableWidgetItem(QString::fromStdString(me.GetWherePrescribed())));
}
void PatientWindow::set_events()
{
    size_t index = 0;
    ui->nextVisitsTable->setRowCount(events.size());
    std::ranges::for_each(events,[this, &index](const auto& i){ set_event(i,index++);});
}
void PatientWindow::set_prescribtions()
{
    std::ranges::for_each(prescribtions,[this](auto& i)
    {
        ui->PrescribtionList->addItem(i.GetMedicine().c_str());
    });
}
std::string PatientWindow::get_dialog_message(std::shared_ptr<med_event>& event) const
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
