#include "dialog_prescribtion.h"
#include "qdatetime.h"
#include "ui_dialog_prescribtion.h"

dialog_prescribtion::dialog_prescribtion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog_prescribtion)
{
    ui->setupUi(this);
}

dialog_prescribtion::~dialog_prescribtion()
{
    delete ui;
}

prescribtion dialog_prescribtion::GetPrescribtion()
{
    std::map<std::string,int> date {{"tydzień",7},{"dwa tygodnie", 14},{"miesiąc",31},{"pół roku",180},{"rok",365}};
    prescribtion ret;
    ret.SetMedicine(ui->medicine->text().toStdString());
    ret.SetDose(ui->dose->text().toStdString());
    ret.SetExpDate(QDateTime::currentDateTime().addDays(date[ui->expdate->currentText().toStdString()]).toString("yyyy-MM-dd hh:mm:ss").toStdString());
    ret.SetDescribtion("recepta");
    ret.SetWhenPrescribed(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString());
    return ret;
}
