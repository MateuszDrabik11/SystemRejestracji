#include "app_control.h"

void app_control::raport_handler() {
    raport_users_handler();
    raport_med_event_handler();
}

void app_control::raport_users_handler() {
    std::string sql = "select type, count(*) from account group by type having type not in ('null','prywatnie');";
    int rc;
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    std::cout<<"konta w systemie"<<std::endl;
    std::cout<<std::left<<std::setw(40)<<"rodzaj"<<std::setw(40)<<"ilość"<<std::endl;
    std::cout<<"==================================="<<std::endl;
    while(rc == SQLITE_ROW) {
        std::cout<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    std::cout<<std::endl;
    std::cout<<"gdzie mieszkają pacjencji"<<std::endl;
    std::cout<<std::left<<std::setw(40)<<"miasto"<<std::setw(40)<<"ilość"<<std::endl;
    std::cout<<"==================================="<<std::endl;
    sql = "select city, count(*) from patient group by city;";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    while(rc == SQLITE_ROW) {
        std::cout<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<sqlite3_column_int(stmt, 1)<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    std::cout<<std::endl;
}

void app_control::raport_med_event_handler() {
    std::string sql = "select describtion, count(*) from med_event group by describtion;";
    int rc;
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    std::cout<<"wykonywane czynności w przychodni"<<std::endl;
    std::cout<<std::left<<std::setw(40)<<"rodzaj"<<std::setw(40)<<"ilość"<<std::endl;
    std::cout<<"==================================="<<std::endl;
    while(rc == SQLITE_ROW) {
        std::cout<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<sqlite3_column_int(stmt, 1)<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    std::cout<<std::endl;
    std::cout<<"czym zajmują się lekarze"<<std::endl;
    std::cout<<std::left<<std::setw(40)<<"lekarz"<<std::setw(40)<<"czynność"<<std::setw(40)<<"ilość"<<std::endl;
    std::cout<<"==================================="<<std::endl;
    sql = "select who_prescribed, describtion, count(*) from med_event group by who_prescribed, describtion order by who_prescribed;";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    while(rc == SQLITE_ROW) {
        std::cout<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))
                <<std::setw(40)<<sqlite3_column_int(stmt, 2)<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    std::cout<<std::endl;
}

void app_control::raport_handler(std::ofstream &writer) {
    raport_users_handler(writer);
    raport_med_event_handler(writer);
}

void app_control::raport_users_handler(std::ofstream &writer) {
    std::string sql = "select type, count(*) from account group by type having type not in ('null','prywatnie');";
    int rc;
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    writer<<"konta w systemie"<<std::endl;
    writer<<std::left<<std::setw(40)<<"rodzaj"<<std::setw(40)<<"ilość"<<std::endl;
    writer<<"==================================="<<std::endl;
    while(rc == SQLITE_ROW) {
        writer<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    writer<<std::endl;
    writer<<"gdzie mieszkają pacjencji"<<std::endl;
    writer<<std::left<<std::setw(40)<<"miasto"<<std::setw(40)<<"ilość"<<std::endl;
    writer<<"==================================="<<std::endl;
    sql = "select city, count(*) from patient group by city;";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    while(rc == SQLITE_ROW) {
        writer<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<sqlite3_column_int(stmt, 1)<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    writer<<std::endl;
}

void app_control::raport_med_event_handler(std::ofstream &writer) {
    std::string sql = "select describtion, count(*) from med_event group by describtion;";
    int rc;
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    writer<<"wykonywane czynności w przychodni"<<std::endl;
    writer<<std::left<<std::setw(40)<<"rodzaj"<<std::setw(40)<<"ilość"<<std::endl;
    writer<<"==================================="<<std::endl;
    while(rc == SQLITE_ROW) {
        writer<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<sqlite3_column_int(stmt, 1)<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    writer<<std::endl;
    writer<<"czym zajmują się lekarze"<<std::endl;
    writer<<std::left<<std::setw(40)<<"lekarz"<<std::setw(40)<<"czynność"<<std::setw(40)<<"ilość"<<std::endl;
    writer<<"==================================="<<std::endl;
    sql = "select who_prescribed, describtion, count(*) from med_event group by who_prescribed, describtion order by who_prescribed;";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    while(rc == SQLITE_ROW) {
        writer<<std::left<<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))
                <<std::setw(40)<<reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))
                <<std::setw(40)<<sqlite3_column_int(stmt, 2)<<std::endl;
        rc = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    writer<<std::endl;
}

void app_control::handler(events e) {
    switch (e) {
        case exit: {
            work = false;
            std::exit(0);
        }
        break;
        case raport: {
            raport_handler();
        }
        break;
        case raport_users: {
            raport_users_handler();
        }
        break;
        case raport_med_events: {
            raport_med_event_handler();
        }
        break;
    }
}

void app_control::handler(events e, std::ofstream &writer) {
    switch (e) {
        case exit: {
            work = false;
            std::exit(0);
        }
        break;
        case raport: {
            raport_handler(writer);
        }
        break;
        case raport_users: {
            raport_users_handler(writer);
        }
        break;
        case raport_med_events: {
            raport_med_event_handler(writer);
        }
        break;
    }
}

app_control::app_control() {
    sqlite3_open("../projekt.db", &db);
    work = true;
}

void app_control::loop() {
    while(work) {
        std::string temp;
        std::getline(std::cin,temp);
        std::regex reg("(exit)|(raport)|(user\\s raport)|(event\\s raport)|(save\\sraport\\s([a-zA-Z0-9\\/\\.\\-\\_]+))");
        std::smatch match;
        std::ofstream writer;
        writer.close();
        std::regex_search(temp,match,reg);
        events event = none;
        if(match[1].matched) {
            event = exit;
        }
        else if(match[2].matched) {
            event = raport;
        }
        else if(match[3].matched) {
            event = raport_users;
        }
        else if(match[4].matched) {
            event = raport_med_events;
        }
        if(match[5].matched) {
            writer.open(std::filesystem::path{match[6]});
            handler(raport,writer);
        }
        else {
            handler(event);
        }
    }
}
