#include "patientwindow.h"
#include "regwindow.h"
#include "loginwindow.h"
#include "doctorwindow.h"
#include "patientwindow.h"
#include <QApplication>
#include <QEventLoop>

#include "../lib/com.pb.h"
#include "../lib/com.grpc.pb.h"

#include <grpcpp/alarm.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include <fstream>
#include <filesystem>

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    std::ifstream config(std::filesystem::path{"./config"});
    std::string port;
    if(config)
    {
        config>>port;
    }
    else
    {
        port.clear();
    }
    if(port.empty())
    {
        port = "localhost:50051";
    }
    LoginWindow login;
    std::shared_ptr<client> com_handler (new client((grpc::CreateChannel(port, grpc::InsecureChannelCredentials()))));
    std::unique_ptr<QMainWindow> w;
    login.get_client(com_handler);
    login.show();
    QEventLoop loop;
    login.connect(&login,SIGNAL(closed()),&loop,SLOT(quit()));
    loop.exec();
    login.close();
    account_message acc = login.get_account();
    if(acc.type() == "registration")
    {
        w = std::make_unique<RegWindow>();
        RegWindow* m = &dynamic_cast<RegWindow&>(*w);
        m->get_client(com_handler);
        m->get_account(acc);
        w->show();
    }
    else if(acc.type() == "doctor")
    {
        w = std::make_unique<DoctorWindow>();
        DoctorWindow* m = &dynamic_cast<DoctorWindow&>(*w);
        m->get_account(acc);
        m->get_client(com_handler);
        if(m->init())
        {
            w->show();
        }
    }
    else if(acc.type() == "patient")
    {
        w = std::make_unique<PatientWindow>();
        PatientWindow* m = &dynamic_cast<PatientWindow&>(*w);
        m->get_account(acc);
        m->get_client(com_handler);
        m->init();
        w->show();
    }
    return a.exec();
}
