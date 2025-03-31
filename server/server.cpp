#include "server.h"
Status server::SearchForAccount(ServerContext *context, const account_request *ar, account_message *ac)
{
    if (!db_closed)
    {
        std::string temp = "SELECT * FROM account WHERE password = '" + ar->password() + "' and username = '" + ar->username() + "';";
        const char *sql = temp.c_str();
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_DONE)
        {
            ac->Clear();
        }
        std::string username, password, name, familyname, type;
        username = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        password = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
        {
            name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        }
        if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
        {
            familyname = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
        }
        if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
        {
            type = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
        }
        ac->set_name(name);
        ac->set_familyname(familyname);
        ac->set_password(password);
        ac->set_username(username);
        ac->set_type(type);
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":user sent" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::SearchForPatients(ServerContext *context, const patient_message *request,
                                 ServerWriter<patient_message> *writer)
{
    if (!db_closed)
    {
        std::string sql;
        if (!request->pesel().empty())
        {
            sql = "SELECT * FROM patients WHERE pesel = '" + request->pesel() + "';";
        }
        else if (!request->username().familyname().empty())
        {
            sql = "SELECT * FROM patients WHERE name = '" + request->username().name() + "' AND familyname = '" + request->username().familyname() + "';";
        }
        else
        {
            sql = "SELECT * FROM patients WHERE name = '" + request->username().name() + "';";
        }
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            patient_message temp;
            std::string pesel, name, familyname, city, street, postcode, birthdate, username;
            pesel = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
            {
                name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            }
            if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
            {
                familyname = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            }
            if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
            {
                city = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            }
            if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
            {
                street = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
            }
            if (sqlite3_column_type(stmt, 5) != SQLITE_NULL)
            {
                postcode = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));
            }
            if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
            {
                birthdate = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6));
            }
            if (sqlite3_column_type(stmt, 7) != SQLITE_NULL)
            {
                username = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7));
            }
            temp.set_pesel(pesel);
            temp.set_birthdate(birthdate);
            temp.set_city(city);
            temp.set_postcode(postcode);
            temp.set_street(street);
            temp.mutable_username()->set_name(name);
            temp.mutable_username()->set_familyname(familyname);
            temp.mutable_username()->set_username(username);
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":patients request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::UpdatePatientData(ServerContext *context, const patient_message *update, Empty *skip)
{
    if (!db_closed)
    {
        std::stringstream sqlStream;
        sqlStream << "BEGIN TRANSACTION; "
                  << "UPDATE patient SET name = '" << update->username().name() << "', "
                  << "familyname = '" << update->username().familyname() << "', "
                  << "city = '" << update->city() << "', "
                  << "street = '" << update->street() << "', "
                  << "postcode = '" << update->postcode() << "', "
                  << "birthdate = '" << update->birthdate() << "' "
                  << "WHERE username = '" << update->username().username() << "'; "
                  << "UPDATE account SET name = '" << update->username().name() << "', "
                  << "familyname = '" << update->username().familyname() << "' "
                  << "WHERE username = '" << update->username().username() << "'; "
                  << "COMMIT TRANSACTION;";
        int rc = sqlite3_exec(db, sqlStream.str().c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":updated patient data" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetNextVisits(ServerContext *context, const patient_message *selected,
                             ServerWriter<med_event_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "SELECT * FROM visits WHERE visits.done = 0 AND visits.patient_name = '" + selected->username().username() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            med_event_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))));
            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            temp.set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":visits request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetExam(ServerContext *context, const patient_message *selected,
                       ServerWriter<exam_message> *exam_writer)
{
    if (!db_closed)
    {
        std::string sql = "SELECT * FROM exams WHERE done = 0 AND patient_name = '" + selected->username().username() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            exam_message temp;
            temp.mutable_event()->set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_event()->mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_event()->set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_event()->mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_event()->mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.mutable_event()->mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))));
            temp.mutable_who_performs()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            temp.mutable_who_performs()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.mutable_who_performs()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));
            temp.set_when(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9))));
            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10))));
            temp.mutable_event()->set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 12))));
            exam_writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":exams request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetProcedure(ServerContext *context, const patient_message *selected,
                            ServerWriter<procedure_message> *proc_writer)
{
    if (!db_closed)
    {
        std::string sql = "SELECT * FROM procedures WHERE done = 0 AND patient_name = '" + selected->username().username() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            procedure_message temp;
            temp.mutable_event()->set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_event()->mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_event()->set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_event()->mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_event()->mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.mutable_event()->mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))));
            temp.mutable_who_performs()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            temp.mutable_who_performs()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.mutable_who_performs()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));
            temp.set_when(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9))));
            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10))));
            temp.mutable_event()->set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 12))));
            proc_writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":procs request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetPrescribtions(ServerContext *context, const patient_message *selected,
                                ServerWriter<prescribtion_message> *pres_writer)
{
    if (!db_closed)
    {
        std::string sql = "SELECT prescribtions.med_event_id, prescribtions.name,prescribtions.describtion, prescribtions.who_prescribed,account.name,account.familyname,medicine, dose, exp_date,time  FROM prescribtions JOIN account on who_prescribed = account.username WHERE prescribtions.name = '" + selected->username().username() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            prescribtion_message temp;
            temp.mutable_event()->set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_event()->mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_event()->set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_event()->mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.mutable_event()->mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))));
            temp.mutable_event()->mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_event()->set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9))));
            temp.set_medicine(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            temp.set_dose(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.set_exp_date(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));
            pres_writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":pres request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetAvailableVisits(ServerContext *context, const med_event_message *me,
                                  ServerWriter<schedule_message> *writer)
{
    if (!db_closed)
    {
        std::string sql;
        sql = "SELECT DISTINCT schedule.sched_id ,schedule.who, acc.name, acc.familyname FROM schedule JOIN account AS acc ON schedule.who = acc.username WHERE '" +
              me->time() + std::string("' BETWEEN schedule.start AND schedule.end AND schedule.type = '" + me->describtion() + "' AND schedule.active = 1 EXCEPT ") +
              std::string("SELECT DISTINCT schedule.sched_id,schedule.who , acc.name, acc.familyname FROM schedule JOIN sched_ev ON schedule.sched_id = sched_ev.sched_id ") +
              "JOIN med_event ON med_event.med_event_id = sched_ev.med_ev_id JOIN account AS acc ON schedule.who = acc.username " +
              "WHERE time BETWEEN datetime('" + me->time() + "','-20 minutes') AND datetime('" + me->time() + "','+20 minutes') AND schedule.type = '" + me->describtion() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            schedule_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_who()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_who()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_who()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":available visits request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetAvailableExams(ServerContext *context, const exam_message *me,
                                 ServerWriter<schedule_message> *writer)
{
    if (!db_closed)
    {
        std::string sql;
        sql =
            "SELECT DISTINCT schedule.sched_id ,schedule.who, acc.name, acc.familyname FROM schedule JOIN account AS acc ON schedule.who = acc.username WHERE '" +
            me->when() + std::string("' BETWEEN schedule.start AND schedule.end AND schedule.type = '" + me->event().describtion() + "'EXCEPT ") +
            std::string("SELECT DISTINCT schedule.sched_id,schedule.who , acc.name, acc.familyname FROM schedule JOIN sched_ev ON schedule.sched_id = sched_ev.sched_id ") +
            "JOIN exam ON exam.exam_id = sched_ev.med_ev_id JOIN account AS acc ON schedule.who = acc.username " +
            "WHERE exam.\"when\" BETWEEN datetime('" + me->when() + "','-20 minutes') AND datetime('" + me->when() + "','+20 minutes') AND schedule.type = '" + me->event().describtion() + "';";

        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            schedule_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_who()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_who()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_who()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":available exams request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetAvailableProcs(ServerContext *context, const procedure_message *me,
                                 ServerWriter<schedule_message> *writer)
{
    if (!db_closed)
    {
        std::string sql;
        sql =
            "SELECT DISTINCT schedule.sched_id ,schedule.who, acc.name, acc.familyname FROM schedule JOIN account AS acc ON schedule.who = acc.username WHERE '" +
            me->when() + std::string("' BETWEEN schedule.start AND schedule.end AND schedule.type = '" + me->event().describtion() + "'EXCEPT ") +
            std::string("SELECT DISTINCT schedule.sched_id,schedule.who , acc.name, acc.familyname FROM schedule JOIN sched_ev ON schedule.sched_id = sched_ev.sched_id ") +
            "JOIN procedure ON procedure.procedure_id = sched_ev.med_ev_id JOIN account AS acc ON schedule.who = acc.username " +
            "WHERE procedure.\"when\" BETWEEN datetime('" + me->when() + "','-20 minutes') AND datetime('" + me->when() + "','+20 minutes') AND schedule.type = '" + me->event().describtion() + "';";

        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            schedule_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_who()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_who()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_who()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":available procs request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::ScheduleEvent(ServerContext *context, const schedule_request *sr, Empty *e)
{
    if (!db_closed)
    {
        std::string sql = "BEGIN TRANSACTION; \n";
        switch (sr->event_case())
        {
        case schedule_request::EventCase::kExam:
        {
            std::string t1, t2;
            t1 = std::to_string(sr->exam().event().id());
            t2 = t1;
            if (sr->exam().event().who_prescribed().username() == "prywatnie")
            {
                sql += "INSERT INTO med_event(name,describtion,who_prescribed,room,done,time) VALUES('" +
                       sr->patient().username().username() + "','" + sr->exam().event().describtion() + "','" + "prywatnie" + "','" + sr->exam().event().room() + "',0,'" + sr->exam().event().time() + "');\n ";
                t1 = "last_insert_rowid()";
                t2 = "(select max(ROWID) from med_event)";
            }
            sql += "INSERT INTO sched_ev VALUES(" + std::to_string(sr->schedule().id()) + "," + t1 + "); ";
            sql += " INSERT INTO exam(exam_id,who_performs,\"when\",room) VALUES(" + t2 + ",'" + sr->schedule().who().username() +
                   "','" + sr->exam().when() + "','" + sr->exam().room() + "');\n ";
        }
        break;
        case schedule_request::EventCase::kProc:
        {
            std::string t1, t2;
            t1 = std::to_string(sr->proc().event().id());
            t2 = t1;
            if (sr->proc().event().who_prescribed().username() == "prywatnie")
            {
                sql += "INSERT INTO med_event(name,describtion,who_prescribed,room,done,time) VALUES('" +
                       sr->patient().username().username() + "','" + sr->proc().event().describtion() + "','" + "prywatnie" + "','" + sr->proc().event().room() + "',0,'" + sr->proc().event().time() + "');\n ";
                t1 = "last_insert_rowid()";
                t2 = "(select max(ROWID) from med_event)";
            }
            sql += "INSERT INTO sched_ev VALUES(" + std::to_string(sr->schedule().id()) + "," + t1 + "); \n";
            sql += " INSERT INTO procedure(procedure_id,who_performs,\"when\",room) VALUES(" + t2 + ",'" + sr->proc().who_performs().username() +
                   "','" + sr->proc().when() + "','" + sr->proc().room() + "');\n ";
        }
        break;
        case schedule_request::EventCase::kVisit:
        {
            sql += "INSERT INTO med_event(name,describtion,who_prescribed,room,done,time) VALUES('" +
                   sr->patient().username().username() + "','wizyta','" + sr->schedule().who().username() + "','" + sr->visit().room() + "',0,'" + sr->visit().time() + "'); \n";
            sql += "INSERT INTO sched_ev VALUES(" + std::to_string(sr->schedule().id()) + std::string(",last_insert_rowid()); \n");
        }
        break;
        default:
        {
            return Status::CANCELLED;
        }
        break;
        }
        sql += "COMMIT TRANSACTION;";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            sql = "ROLLBACK;";
            int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":scheduled event" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetReferals(ServerContext *context, const patient_message *selected,
                           ServerWriter<med_event_message> *writer)
{
    std::string sql_exam = "select med_event.*, doc.name, doc.familyname, pat.name, pat.familyname from med_event join account as doc on doc.username = med_event.who_prescribed join account as pat on pat.username = med_event.name " +
                           std::string("where med_event.med_event_id ") +
                           " in (select * from referal_exam) AND med_event.name = '" + selected->username().username() + "' and done = 0;";
    std::string sql_proc = "select med_event.*, doc.name, doc.familyname, pat.name, pat.familyname from med_event join account as doc on doc.username = med_event.who_prescribed join account as pat on pat.username = med_event.name " +
                           std::string("where med_event.med_event_id") +
                           " in (select * from referal_proc) AND med_event.name = '" + selected->username().username() + "' and done = 0;";
    if (!db_closed)
    {
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql_exam.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            med_event_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_name()->mutable_username()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9))));
            temp.mutable_name()->mutable_username()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10))));

            temp.mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));

            temp.set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));

            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));

            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":exam referals" << std::endl;
        sqlite3_stmt *stmt1;
        rc = sqlite3_prepare_v2(db, sql_proc.c_str(), -1, &stmt1, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt1);
        while (rc == SQLITE_ROW)
        {
            med_event_message temp;
            temp.set_id(sqlite3_column_int64(stmt1, 0));
            temp.mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 1))));
            temp.mutable_name()->mutable_username()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 9))));
            temp.mutable_name()->mutable_username()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 10))));

            temp.mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 3))));
            temp.mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 7))));
            temp.mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 8))));

            temp.set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 2))));

            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 4))));
            temp.set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt1, 6))));
            writer->Write(temp);
            rc = sqlite3_step(stmt1);
        }
        sqlite3_finalize(stmt1);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":procs referals" << std::endl;
        log.close();
        return Status::OK;
    }
    return Status::CANCELLED;
}

Status server::GetDoctors(ServerContext *context, const Empty *e, ServerWriter<account_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "SELECT * FROM doctors";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            account_message temp;
            temp.set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
            temp.set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.set_type("doctor");
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":doctors request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetSchedules(ServerContext *context, const account_message *acc,
                            ServerWriter<schedule_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "SELECT * FROM schedule WHERE who = '" + acc->username() + "' AND active = 1;";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            schedule_message temp;
            temp.mutable_who()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
            temp.set_id(sqlite3_column_int64(stmt, 1));
            temp.set_start(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.set_end(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.set_type(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":schedules request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::AddAccount(ServerContext *context, const add_account_msg *acc, Empty *e)
{
    if (!db_closed)
    {
        std::string sql;
        if (acc->pesel().empty())
        {
            sql = "INSERT INTO account(username, password, type) VALUES('" + acc->account().username() + "','" + acc->account().password() + "','" + acc->account().type() + "');";
        }
        else
        {
            sql = "BEGIN TRANSACTION; \n";
            sql += "INSERT INTO account(username, password, type) VALUES('" + acc->account().username() + "','" + acc->account().password() + "','" + acc->account().type() + "'); \n";
            sql += "INSERT INTO patient(pesel, username) VALUES('" + acc->pesel() + "','" + acc->account().username() + "'); \n";
            sql += "COMMIT TRANSACTION;";
        }
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":add account" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::ResetPassword(ServerContext *context, const account_message *acc, Empty *e)
{
    if (!db_closed)
    {
        std::string sql = "UPDATE account SET password = '" + acc->password() + "' WHERE username = '" + acc->username() + "';";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":password reset" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::DeleteAccount(ServerContext *context, const account_message *acc, Empty *e)
{
    if (!db_closed)
    {
        std::string sql = "DELETE FROM account WHERE username = '" + acc->username() + "';";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":deleted account" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::AddSchedule(ServerContext *context, const schedule_message *s, Empty *e)
{
    if (!db_closed)
    {
        std::string sql = "INSERT INTO schedule(who,start,end,type,active,room) VALUES('" + s->who().username() + "','" + s->start() + "','" + s->end() + "'";
        sql += ",'" + s->type() + "', 1, '" + s->room() + "');";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":schedule added" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::DeleteSchedule(ServerContext *context, const schedule_message *s, Empty *e)
{
    if (!db_closed)
    {
        std::string sql = "DELETE FROM schedule WHERE sched_id = " + std::to_string(s->id()) + ";";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":schedule deleted" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetAccounts(ServerContext *context, const Empty *e, ServerWriter<account_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "SELECT username FROM account where type not in ('prywatnie','null');";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            account_message temp;
            temp.set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":accounts request send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetPatientsHistory(ServerContext *context, const account_message *acc,
                                  ServerWriter<med_event_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "select med_event_id, med_event.name, describtion, who_prescribed, room, done, time, doc.name , doc.familyname from med_event join account as doc on who_prescribed = doc.username where done = 1 and med_event.name = '" + acc->username() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            med_event_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));
            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":patient history send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetPatientsEvent(ServerContext *context, const med_event_message *me, event_response *r)
{
    if (!db_closed)
    {
        int rc;
        sqlite3_stmt *stmt;
        if (me->describtion() == "ekg" || me->describtion() == "rtg" || me->describtion() == "usg" || me->describtion() == "mri" || me->describtion() == "morfologia")
        {
            std::string sql_exam = std::string("select who_performs, \"when\", results, exam.room, account.name, account.familyname from med_event join exam on med_event_id = exam_id join account on exam.who_performs = account.username where exam_id = ") + std::to_string(me->id()) + std::string(";");
            rc = sqlite3_prepare_v2(db, sql_exam.c_str(), -1, &stmt, nullptr);
            if (rc != SQLITE_OK)
            {
                return Status::CANCELLED;
            }
            rc = sqlite3_step(stmt);
            if (rc == SQLITE_ROW)
            {
                exam_message *temp = new exam_message();
                temp->mutable_event()->CopyFrom(*me);
                temp->set_result_id(sqlite3_column_int64(stmt, 2));
                temp->set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
                temp->set_when(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                temp->mutable_who_performs()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
                temp->mutable_who_performs()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
                temp->mutable_who_performs()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))));
                r->set_allocated_exam(temp);
                sqlite3_finalize(stmt);
            }
        }
        else if (me->describtion() == "zabieg")
        {
            std::string sql_proc = std::string("select who_performs, \"when\", procedure.room, account.name, account.familyname from med_event join procedure on med_event_id = procedure_id join account on procedure.who_performs = account.username where procedure_id = ") + std::to_string(me->id()) + std::string(";");
            rc = sqlite3_prepare_v2(db, sql_proc.c_str(), -1, &stmt, nullptr);
            if (rc != SQLITE_OK)
            {
                return Status::CANCELLED;
            }
            rc = sqlite3_step(stmt);
            if (rc == SQLITE_ROW)
            {
                procedure_message *temp = new procedure_message();
                temp->mutable_event()->CopyFrom(*me);
                temp->set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
                temp->set_when(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                temp->mutable_who_performs()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
                temp->mutable_who_performs()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
                temp->mutable_who_performs()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
                r->set_allocated_proc(temp);
                sqlite3_finalize(stmt);
            }
        }
        else if (me->describtion() == "recepta")
        {
            std::string sql_pres = "select medicine, dose, exp_date from prescribtions where done = 1 and med_event_id = " + std::to_string(me->id()) + ";";
            rc = sqlite3_prepare_v2(db, sql_pres.c_str(), -1, &stmt, nullptr);
            if (rc != SQLITE_OK)
            {
                return Status::CANCELLED;
            }
            rc = sqlite3_step(stmt);
            if (rc == SQLITE_ROW)
            {
                prescribtion_message *temp = new prescribtion_message();
                temp->mutable_event()->CopyFrom(*me);
                temp->set_medicine(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
                temp->set_dose(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                temp->set_exp_date(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
                r->set_allocated_pres(temp);
                sqlite3_finalize(stmt);
            }
        }
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":patient event send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetPatientsEvents(ServerContext *context, const account_message *acc,
                                 ServerWriter<med_event_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "select med_event_id, med_event.name, describtion, who_prescribed, room, done, time, doc.name , doc.familyname from med_event join account as doc on who_prescribed = doc.username where done = 0 and describtion <> 'recepta' and med_event.name = '" + acc->username() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            med_event_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));
            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":patient events send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetPatientPrescribtion(ServerContext *context, const account_message *acc,
                                      ServerWriter<prescribtion_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "select prescribtions.*, account.name, account.familyname from prescribtions join account on prescribtions.who_prescribed = account.username where prescribtions.name = '" + acc->username() + "';";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            prescribtion_message temp;
            temp.set_medicine(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.set_dose(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));
            temp.set_exp_date(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9))));
            temp.mutable_event()->set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_event()->mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_event()->set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.mutable_event()->mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_event()->mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10))));
            temp.mutable_event()->mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 11))));
            temp.mutable_event()->set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.mutable_event()->set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":patient prescribtions send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetExamResults(ServerContext *context, const exam_message *e, result *res)
{
    if (!db_closed)
    {
        std::string type;
        if (e->event().describtion() == "morfologia")
        {
            type = "mor";
        }
        else
        {
            type = e->event().describtion();
        }
        std::string sql = "select * from " + type + "_res where res_id = (select results from exam where exam_id = " + std::to_string(e->event().id()) + ");";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        if (e->event().describtion() == "morfologia")
        {
            mor_res_message* m = new mor_res_message;
            m->set_hb(sqlite3_column_int(stmt, 2));
            m->set_plt(sqlite3_column_int(stmt, 4));
            m->set_rbc(sqlite3_column_int(stmt, 1));
            m->set_wbc(sqlite3_column_int(stmt, 3));
            res->set_allocated_mor(m);
        }
        else if (e->event().describtion() == "ekg")
        {
            ekg_res_message* m = new ekg_res_message;
            m->set_rhytm(sqlite3_column_int(stmt, 1));
            m->set_pr_delay(sqlite3_column_int(stmt, 2));
            m->set_qrs(sqlite3_column_int(stmt, 3));
            res->set_allocated_ekg(m);
        }
        else
        {
            rtg_res_message* mes = new rtg_res_message;
            std::string tem = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            mes->set_result(tem);
            res->set_allocated_rest(mes);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":exam result send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetDoctorSchedules(grpc::ServerContext *context, const account_message *request,
                                  grpc::ServerWriter<schedule_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "select who, sched_id, start, end, type, room from schedule where who = '" + request->username() + "' and active = 1;";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW && rc != SQLITE_DONE)
        {
            schedule_message temp;
            temp.mutable_who()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
            temp.set_id(sqlite3_column_int64(stmt, 1));
            temp.set_start(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.set_end(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.set_type(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":doctor schedules send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetScheduledPatients(grpc::ServerContext *context, const schedule_message *request,
                                    grpc::ServerWriter<patient_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "select patient.* from sched_ev " +
                          std::string("join med_event on sched_ev.med_ev_id = med_event.med_event_id ") +
                          "join patient on med_event.name = patient.username " +
                          "where med_event.done = 0 and sched_ev.sched_id = " + std::to_string(request->id()) + ";";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW && rc != SQLITE_DONE)
        {
            patient_message temp;
            temp.set_pesel(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))));
            temp.mutable_username()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_username()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            temp.set_city(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.set_street(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            temp.set_postcode(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5))));
            temp.set_birthdate(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            temp.mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":schedule patients send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::GetScheduledEvents(grpc::ServerContext *context, const schedule_message *request,
                                  grpc::ServerWriter<med_event_message> *writer)
{
    if (!db_closed)
    {
        std::string sql = "select med_event.*, a.name, a.familyname, b.name, b.familyname " +
                          std::string("from sched_ev join med_event on sched_ev.med_ev_id = med_event.med_event_id ") +
                          "join account a on med_event.who_prescribed = a.username " +
                          "join account b on med_event.name = b.username " +
                          "where done = 0 and sched_ev.sched_id = " + std::to_string(request->id()) + ";";
        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        rc = sqlite3_step(stmt);
        while (rc == SQLITE_ROW)
        {
            med_event_message temp;
            temp.set_id(sqlite3_column_int64(stmt, 0));
            temp.mutable_name()->mutable_username()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
            temp.mutable_name()->mutable_username()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9))));
            temp.mutable_name()->mutable_username()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10))));
            temp.mutable_who_prescribed()->set_username(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3))));
            temp.mutable_who_prescribed()->set_name(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7))));
            temp.mutable_who_prescribed()->set_familyname(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8))));
            temp.set_describtion(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))));
            if(sqlite3_column_type(stmt, 4)!= SQLITE_NULL)
            {
                temp.set_room(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))));
            }
            else
            {
                temp.set_room(std::string(""));
            }
            temp.set_time(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6))));
            writer->Write(temp);
            rc = sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
        log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
        log << current_datetime() << ":schedule events send" << std::endl;
        log.close();
        return Status::OK;
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::NewReferal(grpc::ServerContext *context, const med_event_message *request, Empty *response)
{
    if (!db_closed)
    {

        std::string sql = "insert into med_event(name,describtion, who_prescribed,room,done, time) values(" +
                          std::string("'") + request->name().username().username() + "','" + request->describtion() + "','" +
                          request->who_prescribed().username() + "','" + request->room() + "',0,'" + request->time() + "');";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":new referal" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::EventDone(grpc::ServerContext *context, const med_event_message *request, Empty *response)
{
    if (!db_closed)
    {
        std::string sql = "update med_event set done = 1 where med_event_id = " + std::to_string(request->id()) + ";";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":event done" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::NewPrescribtion(grpc::ServerContext *context, const prescribtion_message *request, Empty *response)
{
    if (!db_closed)
    {
        std::string sql = "begin transaction; ";
        sql += "insert into med_event(name,describtion, who_prescribed,room,done, time) values(" +
               std::string("'") + request->event().name().username().username() + "','" + request->event().describtion() + "','" +
               request->event().who_prescribed().username() + "','" + request->event().room() + "',0,'" + request->event().time() + "'); ";
        sql += "insert into prescribtion values(last_insert_rowid(),'" + request->medicine() + "','" + request->dose() + "','" + request->exp_date() + "'); ";
        sql += "commit transaction;";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            sql = "rollback;";
            sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":new prescribtion" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

Status server::ScheduleDone(grpc::ServerContext *context, const schedule_message *request, Empty *response)
{
    if (!db_closed)
    {
        std::string sql = "update schedule set active = 0 where sched_id = " + std::to_string(request->id()) + ";";
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":schedule done" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}
Status server::AddResult(grpc::ServerContext *context, const result *res, Empty *e)
{

    std::string sql;
    if(res->has_ekg())
    {
        sql = "insert into ekg_res values((select results from exam where exam_id = " + std::to_string(res->ekg().result_id().event().id()) + ")," +
        std::to_string(res->ekg().rhytm()) + "," + std::to_string(res->ekg().pr_delay()) +", " + std::to_string(res->ekg().qrs()) + ");";
    }
    else if(res->has_mor())
    {
        sql = "insert into mor_res values((select results from exam where exam_id = " + std::to_string(res->mor().result_id().event().id()) + " )," +
        std::to_string(res->mor().rbc()) + "," + std::to_string(res->mor().hb()) +", " + std::to_string(res->mor().wbc()) + "," +
        std::to_string(res->mor().plt())+ ");";

    }
    else if(res->has_rest())
    {
        sql = "insert into " + res->rest().result_id().event().describtion() +"_res values((select results from exam where exam_id = " +
        std::to_string(res->rest().result_id().event().id()) +"), '"+
        res->rest().result()+"');";
    }
    if (!db_closed)
    {
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, 0);
        if (rc != SQLITE_OK)
        {
            return Status::CANCELLED;
        }
        else
        {
            log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
            log << current_datetime() << ":exam result" << std::endl;
            log.close();
            return Status::OK;
        }
    }
    else
    {
        return Status::CANCELLED;
    }
}

server::server()
{
    db_closed = sqlite3_open("../projekt.db", &db);
}
void server::RunServer()
{
    std::ifstream config(std::filesystem::path{"./config"});
    std::string port;
    std::string config_log;
    if (config.is_open())
    {
        config >> port;
        config >> config_log;
    }
    std::string server_adress;
    if (!port.empty())
    {
        server_adress = "0.0.0.0:" + port;
    }
    else
    {
        server_adress = "0.0.0.0:50051";
    }
    if (!config_log.empty())
    {
        global::path_to_log = config_log + "/log";
    }
    else
    {
        global::path_to_log = "./log";
    }
    log.open(std::filesystem::path{global::path_to_log}, std::ios::app);
    log << "server works on port: " << port << std::endl
        << "start: " << current_datetime() << std::endl;
        log.close();
    server service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_adress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    server->Wait();
}

server::~server()
{
    log << "end: " << current_datetime() << std::endl;
    sqlite3_close(db);
    db_closed = true;
    log.close();
}
