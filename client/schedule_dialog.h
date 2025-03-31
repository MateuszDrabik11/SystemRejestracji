#ifndef SCHEDULE_DIALOG_H
#define SCHEDULE_DIALOG_H

#include <QDialog>
#include "../lib/com.pb.h"

namespace Ui {
class schedule_dialog;
}

class schedule_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit schedule_dialog(QWidget *parent = nullptr);
    ~schedule_dialog();
    void SetSchedules(const std::vector<schedule_message>& schedules);
    size_t GetChoosenId();
    std::string GetRoom();
    std::string GetType();
public slots:
    void choose();
private:
    Ui::schedule_dialog *ui;
    size_t id;
    std::vector<schedule_message> schedules;
    std::string room, type;
};

#endif // SCHEDULE_DIALOG_H
