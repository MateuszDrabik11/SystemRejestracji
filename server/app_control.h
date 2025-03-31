#ifndef APP_CONTROL_H
#define APP_CONTROL_H
#include <fstream>
#include "../lib/sqlite3.h"
#include <regex>
#include <filesystem>
#include <iostream>
#include <iomanip>


class app_control {
    bool work;
    sqlite3 *db;
    //exit - obvious, raport - raport całościowy, raport_users - jacy są użytkownicy, ile ich jest itp.
    enum events {exit,raport, raport_users, raport_med_events, none};
    void raport_handler();

    void raport_users_handler();

    void raport_med_event_handler();

    void raport_handler(std::ofstream& writer);

    void raport_users_handler(std::ofstream& writer);

    void raport_med_event_handler(std::ofstream& writer);

    void handler(events e);

    void handler(events e,std::ofstream& writer);

public:
    app_control();

    void loop();
};




#endif //APP_CONTROL_H
