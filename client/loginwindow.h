#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <regex>
#include <QDebug>
#include <QCloseEvent>
#include <memory>
#include "../lib/com.pb.h"
#include "../lib/com.grpc.pb.h"
#include "client.h"

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
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    const bool isValidPassword();
    const account_message get_account();
    void get_client(const std::shared_ptr<client>& c);
public slots:
    void SendLogin();
signals:
    void closed();
private:
    account_message logged_account;
    std::string password,username;
    Ui::LoginWindow *ui;
    std::weak_ptr<client> client_;
    const std::regex valid_password {"[a-zA-Z0-9]{5,20}"};
    void closeEvent(QCloseEvent *ev);
};

#endif // LOGINWINDOW_H
