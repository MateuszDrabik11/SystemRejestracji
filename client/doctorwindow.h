#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "../lib/com.pb.h"
#include "client.h"
#include "../lib/schedule.h"
#include "qshortcut.h"

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
class DoctorWindow;
}

class DoctorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorWindow(QWidget *parent = nullptr);
    ~DoctorWindow();
    void get_account(const account_message& a) {logged_account = a;};
    void get_client(const std::shared_ptr<client>& c) { client_ = c;};
    bool init();
public slots:
    void show_prescribtion();
    void get_next_patient();
    void new_referal();
    void new_prescribtion();
    void show_history();
    void refresh();
    void add_results();
private:
    std::weak_ptr<client> client_;
    account_message logged_account;
    Ui::DoctorWindow *ui;
    std::unique_ptr<schedule> Schedule;
    void SetPatientData(const patient_message& p);
    void SetPatientHistory();
    std::string get_dialog_message(std::shared_ptr<med_event> &event) const;
    std::vector<prescribtion> prescribtions;
    std::string room;
    std::unique_ptr<QShortcut> refresh_sc;
    std::string type;
};

#endif // DOCTORWINDOW_H
