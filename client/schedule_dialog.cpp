#include "schedule_dialog.h"
#include "ui_schedule_dialog.h"
#include <regex>

schedule_dialog::schedule_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::schedule_dialog)
{
    ui->setupUi(this);
    id = 0;
}

schedule_dialog::~schedule_dialog()
{
    delete ui;
}

void schedule_dialog::SetSchedules(const std::vector<schedule_message>& s)
{
    schedules = s;
    std::ranges::for_each(schedules,[this](auto i)
    {
        QString text = std::to_string(i.id()).c_str();
        text += QString(" - ");
        text += QString(i.type().c_str());
        text += QString(", ");
        text += QString(i.start().c_str());
        ui->listWidget->addItem(text);
    });
}
void schedule_dialog::choose()
{
    id = schedules[ui->listWidget->currentRow()].id();
    room = schedules[ui->listWidget->currentRow()].room();
    type = schedules[ui->listWidget->currentRow()].type();
}
size_t schedule_dialog::GetChoosenId()
{
    return id;
}
std::string schedule_dialog::GetRoom()
{
    return room;
}

std::string schedule_dialog::GetType()
{
    return type;
}
