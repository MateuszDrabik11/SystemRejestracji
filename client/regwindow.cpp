#include "regwindow.h"
#include "ui_regwindow.h"
RegWindow::RegWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegWindow)
{
    qDebug() <<"RegWindow created";
    ui->setupUi(this);
    selected_patient_index = 0;
    refresh_sc = std::make_unique<QShortcut>(QKeySequence("F5"),this,SLOT(refresh()));
    ui->add_account_pesel->setStyleSheet("border: 1px solid lightgrey;");
    ui->add_account_pesel->setDisabled(true);
    ready_schedule = false;
}
void RegWindow::set_title()
{
    std::string text = logged_account.username() + " - " +
                       logged_account.name() + " " +
                       logged_account.familyname();
    ui->menuBar->addMenu(QString::fromStdString(text));
}
void RegWindow::get_client(const std::shared_ptr<client>& c)
{
    client_ = c;
}
void RegWindow::SetSearchedpatient_messages(const size_t& i)
{

    ui->tableWidget_search_patient->setItem(i,0,new QTableWidgetItem(QString::fromStdString(patients[i].username().name()),1));
    ui->tableWidget_search_patient->setItem(i,1,new QTableWidgetItem(QString::fromStdString(patients[i].username().familyname()),1));
    ui->tableWidget_search_patient->setItem(i,2,new QTableWidgetItem(QString::fromStdString(patients[i].pesel()),1));
    ui->tableWidget_search_patient->setItem(i,3,new QTableWidgetItem(QString::fromStdString(patients[i].city()),1));
    ui->tableWidget_search_patient->setItem(i,4,new QTableWidgetItem(QString::fromStdString(patients[i].postcode()),1));
    ui->tableWidget_search_patient->setItem(i,5,new QTableWidgetItem(QString::fromStdString(patients[i].street()),1));
    ui->tableWidget_search_patient->setItem(i,6,new QTableWidgetItem(QString::fromStdString(patients[i].birthdate()),1));
}
RegWindow::~RegWindow()
{
    qDebug() <<"RegWindow destroyed";
    delete ui;
}
bool RegWindow::check(const QString& object, const std::regex& reg)
{
    return std::regex_match(object.toStdString(),reg);
}
void RegWindow::name_change()
{
    if(check(ui->name_input->text(),std::regex("[a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+")))
    {
        patients[selected_patient_index].mutable_username()->set_name(ui->name_input->text().toStdString());
        ui->name_input->setStyleSheet("border: 1px solid #0dff00");
    }
    else
    {
        ui->name_input->setStyleSheet("border: 1px solid red");
    }
}
void RegWindow::familyname_change()
{
    if(check(ui->familyname_input->text(),std::regex("[a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+")))
    {
        patients[selected_patient_index].mutable_username()->set_familyname( ui->familyname_input->text().toStdString());
        ui->familyname_input->setStyleSheet("border: 1px solid #0dff00");
    }
    else
    {
        ui->familyname_input->setStyleSheet("border: 1px solid red");
    }
}
void RegWindow::city_change()
{
    if(check(ui->city_input->text(),std::regex("[a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ\\s]+")))
    {
        patients[selected_patient_index].set_city(ui->city_input->text().toStdString());
        ui->city_input->setStyleSheet("border: 1px solid #0dff00");
    }
    else
    {
        ui->city_input->setStyleSheet("border: 1px solid red");
    }
}
void RegWindow::street_change()
{
    if(check(ui->street_input->text(),std::regex("[a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+\\s[0-9]+")))
    {
        patients[selected_patient_index].set_street( ui->street_input->text().toStdString());
        ui->street_input->setStyleSheet("border: 1px solid #0dff00");
    }
    else
    {
        ui->street_input->setStyleSheet("border: 1px solid red");
    }
}
void RegWindow::postcode_change()
{
    if(check(ui->postcode_input->text(),std::regex("[0-9]{2}-[0-9]{3}")))
    {
        patients[selected_patient_index].set_postcode(ui->postcode_input->text().toStdString());
        ui->postcode_input->setStyleSheet("border: 1px solid #0dff00");
    }
    else
    {
        ui->postcode_input->setStyleSheet("border: 1px solid red");
    }
}
void RegWindow::birthdate_change()
{
    patients[selected_patient_index].set_birthdate(ui->birthdate_input->date().toString("yyyy-MM-dd").toUtf8().toStdString());
}

void RegWindow::search_patients()
{
    patient_message temp;
    std::string text = ui->lineEdit_search_patient->text().toUtf8().toStdString();
    std::regex reg ("(([a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+){1}(\\s)?([a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+)?)|([0-9]{11})");
    std::smatch match;
    std::regex_search(text,match,reg);
    temp.set_pesel(match.str(5));
    temp.mutable_username()->set_name(match.str(2));
    temp.mutable_username()->set_familyname(match.str(4));
    client_.lock()->SearchForPatients(temp,patients);
    ui->tableWidget_search_patient->setRowCount(patients.size());
    for(size_t i = 0;i<patients.size();++i)
    {
        SetSearchedpatient_messages(i);
    }
}
void RegWindow::set_current_patient()
{
    ui->tableWidget_search_patient->blockSignals(true);
    if(patients.size()>0 && selected_patient_index < patients.size())
    {
        client_.lock()->UpdatePatientData(patients[selected_patient_index]);
        search_patients();
    }
    ui->tableWidget_search_patient->resizeColumnsToContents();
    selected_patient_index = ui->tableWidget_search_patient->currentRow();
    clear_patient_tablewidget();
    ui->name_input->setPlaceholderText(QString::fromStdString(patients[selected_patient_index].username().name()));
    ui->familyname_input->setPlaceholderText(QString::fromStdString(patients[selected_patient_index].username().familyname()));
    ui->city_input->setPlaceholderText(QString::fromStdString(patients[selected_patient_index].city()));
    ui->postcode_input->setPlaceholderText(QString::fromStdString(patients[selected_patient_index].postcode()));
    ui->street_input->setPlaceholderText(QString::fromStdString(patients[selected_patient_index].street()));
    ui->birthdate_input->setDate(QDate::fromString(QString::fromStdString(patients[selected_patient_index].birthdate()),"yyyy-MM-dd"));
    ui->tableWidget_search_patient->blockSignals(false);
    refresh();
}
void RegWindow::clear_patient_tablewidget()
{
    ui->birthdate_input->clear();
    ui->birthdate_input->setStyleSheet("");
    ui->city_input->clear();
    ui->city_input->setStyleSheet("");
    ui->familyname_input->clear();
    ui->familyname_input->setStyleSheet("");
    ui->postcode_input->clear();
    ui->postcode_input->setStyleSheet("");
    ui->name_input->clear();
    ui->name_input->setStyleSheet("");
    ui->street_input->clear();
    ui->street_input->setStyleSheet("");
}
void RegWindow::tab_changed(int i)
{
    qDebug()<<"tab:"<<i;
    enum tab
    {
        Select_Edit_patient_message = 0,
        Show_next_visits = 1,
        Show_prescribtions = 2,
        Schedule_new_visit = 3,
        Manage_schedules = 4,
        Manage_account_messages = 5
    };
    switch(i)
    {
        case Select_Edit_patient_message:
            {
                qDebug()<<"Select_Edit_patient_message refresh";
                if(patients.size()>0 && selected_patient_index < patients.size())
                {
                    client_.lock()->UpdatePatientData(patients[selected_patient_index]);
                }
                search_patients();
            }
            break;
        case Show_next_visits:
            {
                if(patients.size()>0 && selected_patient_index < patients.size())
                {
                    client_.lock()->GetNextVisits(patients[selected_patient_index],me);
                    set_next_visits();
                }
                qDebug()<<"Show_next_visits refresh";
            }
            break;
        case Show_prescribtions:
            {
                if(patients.size()>0 && selected_patient_index < patients.size())
                {
                    me.clear();
                    client_.lock()->GetPres(patients[selected_patient_index],me);
                    client_.lock()->GetProc(patients[selected_patient_index],me);
                    client_.lock()->GetExam(patients[selected_patient_index],me);
                    client_.lock()->GetReferals(patients[selected_patient_index],referals);
                    SetPres();
                }
                qDebug()<<"Show_prescribtions refresh";
            }
            break;
        case Schedule_new_visit:
            {
                tab_changed(Show_prescribtions);
                schedules.clear();
                ui->available_dates->clear();
                SetRefferals();
                if(patients.size()>0 && selected_patient_index < patients.size())
                {
                    std::string type = ui->visit_type->currentText().toStdString();
                    std::ranges::transform(type,type.begin(),[](auto i){return std::tolower(i);});
                    client_.lock()->GetAvailableVisits(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString(),type,schedules);
                    client_.lock()->GetAvailableExams(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString(),type,schedules);
                    client_.lock()->GetAvailableProcs(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString(),type,schedules);
                    std::ranges::for_each(schedules, [this](const auto& i){this->ui->available_dates->addItem(new QListWidgetItem(QString::fromStdString(i.who().name()+" "+i.who().familyname()),0));});
                }
                qDebug()<<"Schedule_new_visit refresh";
            }
            break;
        case Manage_schedules:
            {
                ready_schedule = false;
                client_.lock()->GetDoctors(doctors);
                ui->schedule_doctors->clear();
                ui->schedules_table->clearContents();
                std::ranges::for_each(doctors,[this](const auto& i){set_doctor(i);});
                qDebug()<<"Manage_schedule refresh";
                ready_schedule = true;
                set_schedules();
            }
            break;
        case Manage_account_messages:
            {
                clear_acc();
                qDebug()<<"Manage_account_messages refresh";
            }
            break;
    }
}
void RegWindow::refresh()
{
    tab_changed(ui->tabWidget->currentIndex());
}
void RegWindow::set_next_visits()
{
    ui->tableWidget_visits->setRowCount(me.size());
    for(size_t i = 0;i<me.size();++i)
    {
        SetVisitsRow(i);
    }
    ui->tableWidget_visits->resizeColumnsToContents();
}
void RegWindow::SetVisitsRow(const size_t& i)
{
    ui->tableWidget_visits->setItem(i,0,new QTableWidgetItem(QString::fromStdString(me[i]->GetDescribtion()),1));
    ui->tableWidget_visits->setItem(i,1,new QTableWidgetItem(QString::fromStdString(me[i]->who_prescribed.name()+" "+me[i]->who_prescribed.familyname()),1));
    ui->tableWidget_visits->setItem(i,2,new QTableWidgetItem(QString::fromStdString(me[i]->GetWhenPrescribed()),1));
    ui->tableWidget_visits->setItem(i,3,new QTableWidgetItem(QString::fromStdString(me[i]->GetWherePrescribed()),1));
    qDebug()<<"item set";
}
void RegWindow::SetRefferals()
{
    enum visit_type
    {
        Visit = 0,Proc = 1,Rtg = 2,Mri = 3,Ekg = 4,Usg = 5 ,Morf = 6
    };
    ui->select_referral->clear();
    std::string text = ui->visit_type->currentText().toLower().toStdString();
    for(auto& i : referals)
    {
        qDebug() <<"me";
        if(i.GetDescribtion() == text && i.who_prescribed.username() != "prywatnie" )
        {
            ui->select_referral->addItem(QString::fromStdString(i.who_prescribed.name() + " " + i.who_prescribed.familyname()
                                                                + "/" + i.GetWhenPrescribed()));
        }
    }
    ui->select_referral->addItem("prywatnie");
}
void RegWindow::SetPres()
{
    ui->tableWidget_prescribtions->clearContents();
    ui->tableWidget_prescribtions->setRowCount(me.size());
    size_t count = 0;
    for(auto& i : me)
    {
        if(i->GetDescribtion() == "mri" || i->GetDescribtion() == "rtg" || i->GetDescribtion() == "morfologia" || i->GetDescribtion() == "usg" || i->GetDescribtion() == "ekg")
        {
            qDebug()<<"exam";
            ui->tableWidget_prescribtions->setItem(count,0, new QTableWidgetItem(QString::fromStdString(i->GetDescribtion()),1));
            ui->tableWidget_prescribtions->setItem(count,1, new QTableWidgetItem(QString::fromStdString(i->who_prescribed.name() +" "+ i->who_prescribed.familyname()),1));
            ui->tableWidget_prescribtions->setItem(count,2, new QTableWidgetItem(QString::fromStdString(((examination*)i.get())->who_performs.name() +" "+ ((examination*)i.get())->who_performs.familyname()),1));
            ui->tableWidget_prescribtions->setItem(count,3, new QTableWidgetItem(QString::fromStdString(((examination*)i.get())->GetWhenPerformed()),1));
            ui->tableWidget_prescribtions->setItem(count,4, new QTableWidgetItem(QString::fromStdString(((examination*)i.get())->GetWherePerformed()),1));
            ++count;
        }
        if(i->GetDescribtion() == "zabieg")
        {
            ui->tableWidget_prescribtions->setItem(count,0, new QTableWidgetItem(QString::fromStdString(i->GetDescribtion()),1));
            ui->tableWidget_prescribtions->setItem(count,1, new QTableWidgetItem(QString::fromStdString(i->who_prescribed.name() +" "+ i->who_prescribed.familyname()),1));
            ui->tableWidget_prescribtions->setItem(count,2, new QTableWidgetItem(QString::fromStdString(((procedure*)i.get())->who_performs.name() +" "+ ((procedure*)i.get())->who_performs.familyname()),1));
            ui->tableWidget_prescribtions->setItem(count,3, new QTableWidgetItem(QString::fromStdString(((procedure*)i.get())->GetWhenPerformed()),1));
            ui->tableWidget_prescribtions->setItem(count,4, new QTableWidgetItem(QString::fromStdString(((procedure*)i.get())->GetWherePerformed()),1));
            ++count;
        }
        if(i->GetDescribtion() == "recepta")
        {
            ui->tableWidget_prescribtions->setItem(count,0, new QTableWidgetItem(QString::fromStdString(i->GetDescribtion()),1));
            ui->tableWidget_prescribtions->setItem(count,1, new QTableWidgetItem(QString::fromStdString(i->who_prescribed.name() +" "+ i->who_prescribed.familyname()),1));
            ui->tableWidget_prescribtions->setItem(count,2, new QTableWidgetItem(QString::fromStdString(""),1));
            ui->tableWidget_prescribtions->setItem(count,3, new QTableWidgetItem(QString::fromStdString(i->GetWhenPrescribed()),1));
            ui->tableWidget_prescribtions->setItem(count,4, new QTableWidgetItem(QString::fromStdString(i->GetWherePrescribed()),1));
            ++count;
        }
    }
    ui->tableWidget_prescribtions->resizeColumnsToContents();
}
void RegWindow::schedule_new_event()
{
    enum visit_type
    {
        Visit = 0,Proc = 1,Rtg = 2,Mri = 3,Ekg = 4,Usg = 5 ,Morf = 6
    };

    if(patients.size()>0 && selected_patient_index < patients.size())
    {
        schedule_request sr;
        std::string who_pres = ui->select_referral->currentText().toStdString();
        switch(ui->visit_type->currentIndex())
        {
            case Visit:
            {
                sr.mutable_visit()->set_room(ui->room_input->text().toStdString());
                sr.mutable_visit()->set_describtion("wizyta");
                sr.mutable_visit()->set_time(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
                sr.mutable_patient()->mutable_username()->set_username(patients[selected_patient_index].username().username());
                sr.mutable_schedule()->set_id(schedules[ui->available_dates->currentRow()].id());
                sr.mutable_schedule()->mutable_who()->set_username(schedules[ui->available_dates->currentRow()].who().username());
            }
            break;
            case Proc:
            {
                if(who_pres != "prywatnie")
                {
                    if(selected_refferal)
                    {
                        sr.mutable_patient()->mutable_username()->set_username(patients[selected_patient_index].username().username());
                        sr.mutable_schedule()->set_id(schedules[ui->available_dates->currentRow()].id());
                        sr.mutable_schedule()->mutable_who()->set_username(schedules[ui->available_dates->currentRow()].who().username());
                        sr.mutable_proc()->mutable_who_performs()->set_username(schedules[ui->available_dates->currentRow()].who().username());
                        sr.mutable_proc()->mutable_event()->mutable_who_prescribed()->set_username(selected_refferal->who_prescribed.username());
                        sr.mutable_proc()->mutable_event()->set_room(selected_refferal->GetWherePrescribed());
                        sr.mutable_proc()->mutable_event()->set_id(selected_refferal->GetId());
                        sr.mutable_proc()->mutable_event()->set_describtion(ui->visit_type->currentText().toLower().toStdString());
                        sr.mutable_proc()->set_when(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
                        sr.mutable_proc()->set_room(ui->room_input->text().toStdString());
                    }
                }
                else
                {
                    qDebug()<<"Zabieg prywatne";
                    sr.mutable_proc()->mutable_event()->set_time(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
                    sr.mutable_patient()->mutable_username()->set_username(patients[selected_patient_index].username().username());
                    sr.mutable_schedule()->set_id(schedules[ui->available_dates->currentRow()].id());
                    sr.mutable_schedule()->mutable_who()->set_username(schedules[ui->available_dates->currentRow()].who().username());
                    sr.mutable_proc()->mutable_who_performs()->set_username(schedules[ui->available_dates->currentRow()].who().username());
                    sr.mutable_proc()->mutable_event()->mutable_who_prescribed()->set_username("prywatnie");
                    sr.mutable_proc()->set_when(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
                    sr.mutable_proc()->set_room(ui->room_input->text().toStdString());
                    sr.mutable_proc()->mutable_event()->set_describtion(ui->visit_type->currentText().toLower().toStdString());
                }
            }
            break;
            case Rtg:
            case Mri:
            case Ekg:
            case Usg:
            case Morf:
            {
                if(who_pres != "prywatnie")
                {
                    if(selected_refferal)
                    {
                        sr.mutable_patient()->mutable_username()->set_username(patients[selected_patient_index].username().username());
                        sr.mutable_schedule()->set_id(schedules[ui->available_dates->currentRow()].id());
                        sr.mutable_schedule()->mutable_who()->set_username(schedules[ui->available_dates->currentRow()].who().username());
                        sr.mutable_exam()->mutable_who_performs()->set_username(schedules[ui->available_dates->currentRow()].who().username());
                        sr.mutable_exam()->mutable_event()->mutable_who_prescribed()->set_username(selected_refferal->who_prescribed.username());
                        sr.mutable_exam()->mutable_event()->set_room(selected_refferal->GetWherePrescribed());
                        sr.mutable_exam()->mutable_event()->set_id(selected_refferal->GetId());
                        sr.mutable_exam()->mutable_event()->set_describtion(ui->visit_type->currentText().toLower().toStdString());
                        sr.mutable_exam()->set_when(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
                        sr.mutable_exam()->set_room(ui->room_input->text().toStdString());
                    }
                }
                else
                {
                    qDebug()<<"Badanie prywatne";
                    sr.mutable_patient()->mutable_username()->set_username(patients[selected_patient_index].username().username());
                    sr.mutable_schedule()->set_id(schedules[ui->available_dates->currentRow()].id());
                    sr.mutable_schedule()->mutable_who()->set_username(schedules[ui->available_dates->currentRow()].who().username());
                    sr.mutable_exam()->mutable_who_performs()->set_username(sr.schedule().who().username());
                    sr.mutable_exam()->mutable_event()->mutable_who_prescribed()->set_username("prywatnie");
                    sr.mutable_exam()->mutable_event()->set_describtion(ui->visit_type->currentText().toLower().toStdString());
                    sr.mutable_exam()->set_when(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
                    sr.mutable_exam()->set_room(ui->room_input->text().toStdString());
                    sr.mutable_exam()->mutable_event()->set_time(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());

                }
            }
            break;
        }
        client_.lock()->ScheduleEvent(sr);
    }
}
void RegWindow::choose_reff()
{
    std::string who_pres = ui->select_referral->currentText().toStdString();
    std::regex reg("([a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+)\\s([a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+)/(([0-9]{4}-[0-9]{2}-[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9]{2}))?");
    std::smatch match;
    std::regex_search(who_pres,match,reg);
    auto events = std::ranges::find_if(referals,[&match](med_event& i)
                                      {return i.who_prescribed.name() == match[1] && i.who_prescribed.familyname() == match[2] && i.GetWhenPrescribed() == match[3];
                                      });
    if(events != referals.end())
    {
        selected_refferal = &(*events);
    }
}
void RegWindow::new_sch_visit()
{
    ui->select_referral->clear();
    ui->room_input->clear();
    refresh();
}
void RegWindow::add_account_type_selected(int i)
{
    if(i == 2)
    {
        ui->add_account_pesel->setEnabled(true);
        ui->add_account_pesel->setStyleSheet("border: 1px solid black;");
    }
    else
    {
        ui->add_account_pesel->clear();
        ui->add_account_pesel->setStyleSheet("border: 1px solid lightgrey;");
        ui->add_account_pesel->setDisabled(true);
    }
}
void RegWindow::set_doctor(const account_message& d)
{
    QString text =QString::fromStdString(d.name() + " " + d.familyname() + " - " + d.username());
    ui->schedule_doctors->addItem(text);
}
void RegWindow::set_schedule(const schedule_message& s, size_t i)
{
    ui->schedules_table->setItem(i,0,new QTableWidgetItem(QString::number(s.id())));
    ui->schedules_table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(s.start())));
    ui->schedules_table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(s.end())));
    ui->schedules_table->setItem(i,3,new QTableWidgetItem(QString::fromStdString(s.type())));
}
void RegWindow::set_schedules()
{
    if(doctors.size() && ready_schedule)
    {
        std::vector<schedule_message> schedules;
        client_.lock()->GetSchedules(doctors[ui->schedule_doctors->currentIndex()],schedules);
        ui->schedules_table->setRowCount(schedules.size());
        size_t index = 0;
        std::ranges::for_each(schedules,[&index,this](const auto& i){set_schedule(i,index++);});
    }
}
void RegWindow::add_schedule()
{
    const std::vector<std::string> types {"wizyta","zabieg","rtg","mri","usg","ekg","morfologia"};
    schedule_message s;
    std::string start,end,doc;
    doc = ui->schedule_doctors->currentText().toStdString();
    start = ui->dateEdit->date().toString("yyyy-MM-dd ").toStdString();
    start += ui->timeEdit->time().toString("hh:mm:ss").toStdString();
    end = ui->dateEdit->date().toString("yyyy-MM-dd ").toStdString();
    end += ui->timeEdit_2->time().toString("hh:mm:ss").toStdString();
    qDebug()<<start.c_str();
    s.set_start(start);
    s.set_end(end);
    s.set_type(types[ui->comboBox_3->currentIndex()]);
    s.set_room(ui->schedule_room->text().toStdString());
    std::regex r("([a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+)\\s([a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ]+)\\s-\\s([a-zA-ZąĄćĆęĘłŁńŃóÓśŚźŹżŻ.0-9]+)");
    std::smatch match;
    std::regex_search(doc,match,r);
    s.mutable_who()->set_username(match[3]);
    if(client_.lock()->AddSchedule(s))
    {
        refresh();
    }
    else
    {
        QErrorMessage msg(this);
        msg.showMessage("Nie można dodać harmonogramu");
        msg.setModal(true);
        msg.exec();
    }
}
void RegWindow::delete_schedule()
{
    schedule_message toDelete;
    auto rows = ui->schedules_table->selectionModel()->selectedRows(0);
    for(const auto& i: rows)
    {
        toDelete.set_id(i.data().toLongLong());
        client_.lock()->DeleteSchedule(toDelete);
    }
    refresh();
}
void RegWindow::export_prescribtion()
{

}
void RegWindow::clear_acc()
{
    ui->add_account_password->clear();
    ui->add_account_pesel->clear();
    ui->add_account_user->clear();
    ui->add_account_type->setCurrentIndex(0);
    ui->lineEdit_reset_password->clear();
    set_acc();
}
void RegWindow::set_acc()
{
    ui->comboBox_delete->clear();
    ui->comboBox_reset->clear();
    std::vector<account_message> accounts;
    client_.lock()->GetAccounts(accounts);
    for(const auto& i : accounts)
    {
        ui->comboBox_reset->addItem(QString::fromStdString(i.username()));
        ui->comboBox_delete->addItem(QString::fromStdString(i.username()));
    }
    qDebug()<<accounts.size();
}
void RegWindow::add_account()
{
    const std::vector<std::string> types {"doctor","registration","patient"};
    add_account_msg a;
    if(check(ui->add_account_password->text(),std::regex("[a-zA-Z0-9]{5,20}")))
    {
        a.mutable_account()->set_username(ui->add_account_user->text().toStdString());
        a.mutable_account()->set_password(ui->add_account_password->text().toStdString());
        a.mutable_account()->set_type(types[ui->add_account_type->currentIndex()]);
        if(check(ui->add_account_pesel->text(),std::regex("[0-9]{11}")))
        {
            a.set_pesel(ui->add_account_pesel->text().toStdString());
        }
        if(client_.lock()->AddAccount(a))
        {
            clear_acc();
        }
        else
        {
            QErrorMessage msg(this);
            msg.showMessage("Nie można dodać konta");
            msg.setModal(true);
            msg.exec();
        }
    }
}
void RegWindow::reset_pass()
{
    if(check(ui->lineEdit_reset_password->text(),std::regex("[a-zA-Z0-9]{5,20}")))
    {
        account_message a;
        a.set_username(ui->comboBox_reset->currentText().toStdString());
        a.set_password(ui->lineEdit_reset_password->text().toStdString());
        if(client_.lock()->ResetPassword(a))
        {
            clear_acc();
        }
        else
        {
            QErrorMessage msg(this);
            msg.showMessage("Nie można zresetować hasła");
            msg.setModal(true);
            msg.exec();
        }
    }
}
void RegWindow::delete_acc()
{
    QMessageBox msgBox;
    msgBox.setText("Usuwanie konta");
    msgBox.setInformativeText("Czy na pewno chcesz usunąć to konto?");
    msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    account_message a;
    a.set_username(ui->comboBox_delete->currentText().toStdString());
    int ret = msgBox.exec();
    switch(ret)
    {
        case QMessageBox::Yes:
        {
            client_.lock()->DeleteAccount(a);
        }
        break;
        case QMessageBox::Cancel:
        {
            break;
        }
        break;
    }
    clear_acc();
}
