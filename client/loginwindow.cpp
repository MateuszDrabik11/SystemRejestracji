#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    qDebug() <<"LoginWindow created";
}
const bool LoginWindow::isValidPassword()
{
    return std::regex_match(ui->lineEdit_Login_password->text().toStdString(),valid_password);
}
void LoginWindow::get_client(const std::shared_ptr<client>& c)
{
    client_ = c;
}
void LoginWindow::SendLogin()
{
    //todo send request to server
    if(isValidPassword())
    {
        password = ui->lineEdit_Login_password->text().toStdString();
        username = ui->lineEdit_Login_user->text().toStdString();
        ui->lineEdit_Login_user->clear();
        ui->lineEdit_Login_password->clear();
        account_request ar;
        ar.set_password(password);
        ar.set_username(username);
        Status s;
        logged_account = client_.lock()->SearchForAccount(ar,s);
        if(s.ok())
        {
            emit closed();
        }
        else
        {
            ui->lineEdit_Login_password->setStyleSheet("border: 1px solid red");
            ui->lineEdit_Login_user->setStyleSheet("border: 1px solid red");
        }
    }
}
LoginWindow::~LoginWindow()
{
    qDebug() <<"LoginWindow destroyed";
    delete ui;
}
void LoginWindow::closeEvent(QCloseEvent * ev)
{
    emit closed();
    ev->accept();
}
const account_message LoginWindow::get_account()
{
    return logged_account;
}
