#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QMainWindow>
#include "client.h"
#include <regex>
#include <vector>
#include <QWidget>
#include <memory>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QErrorMessage>
#include <iterator>
#include <string>
#include <algorithm>
#include <ranges>
#include <cctype>
#include <QShortcut>
#include "../lib/com.pb.h"
#include "../lib/com.grpc.pb.h"
#include "../lib/med_event.h"
#include "../lib/exam_results.h"

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

QT_BEGIN_NAMESPACE
namespace Ui {
class RegWindow;
}
QT_END_NAMESPACE

class RegWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegWindow(QWidget *parent = nullptr);
    ~RegWindow();
    bool check(const QString& object, const std::regex& reg);
    void get_client(const std::shared_ptr<client>& c);
    void get_account(const account_message& a) { logged_account = a; set_title();}
public slots:
    void name_change();
    void familyname_change();
    void birthdate_change();
    void city_change();
    void postcode_change();
    void street_change();
    void search_patients();
    void set_current_patient();
    void tab_changed(int i);
    void refresh();
    void set_next_visits();
    void schedule_new_event();
    void choose_reff();
    void new_sch_visit();
    void add_account_type_selected(int i);
    void set_schedules();
    void add_schedule();
    void delete_schedule();
    void export_prescribtion();
    void add_account();
    void reset_pass();
    void delete_acc();
private:
    void clear_acc();
    void set_acc();
    void SetSearchedpatient_messages(const size_t& i);
    void set_title();
    void SetVisitsRow(const size_t& i);
    void SetPres();
    void SetRefferals();
    void set_doctor(const account_message& d);
    void set_schedule(const schedule_message& s, size_t i);
    Ui::RegWindow *ui;
    std::weak_ptr<client> client_;
    size_t selected_patient_index;
    med_event *selected_refferal;
    std::vector<patient_message> patients;
    std::vector<std::unique_ptr<med_event>> me;
    std::vector<med_event> referals;
    void clear_patient_tablewidget();
    std::vector<schedule_message> schedules;
    std::vector<account_message> doctors;
    std::unique_ptr<QShortcut> refresh_sc;
    account_message logged_account;
    bool ready_schedule;
};
#endif // REGWINDOW_H
