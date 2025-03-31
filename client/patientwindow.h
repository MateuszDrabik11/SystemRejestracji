#ifndef PATIENTWINDOW_H
#define PATIENTWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "../lib/com.pb.h"
#include "../lib/com.grpc.pb.h"
#include "client.h"

#include <algorithm>
#include <ranges>
#include <QDateTime>

#include <grpcpp/alarm.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

namespace Ui {
class PatientWindow;
}

class PatientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PatientWindow(QWidget *parent = nullptr);
    void get_account(const account_message& a) {logged_account = a;};
    void get_client(const std::shared_ptr<client>& c) { client_ = c;};
    void init();
    ~PatientWindow();
public slots:
    void show_history();
    void show_prescribtion();

private:
    void set_history();
    void set_event(const med_event& me, size_t i);
    void set_events();
    void set_prescribtions();
    std::string get_dialog_message(std::shared_ptr<med_event> &event) const;
    Ui::PatientWindow *ui;
    std::weak_ptr<client> client_;
    account_message logged_account;
    std::vector<med_event> history, events;
    std::vector<prescribtion> prescribtions;
};

#endif
