#ifndef DIALOG_PRESCRIBTION_H
#define DIALOG_PRESCRIBTION_H

#include <QDialog>
#include "../lib/med_event.h"

namespace Ui {
class dialog_prescribtion;
}

class dialog_prescribtion : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_prescribtion(QWidget *parent = nullptr);
    ~dialog_prescribtion();
    prescribtion GetPrescribtion();
private:
    Ui::dialog_prescribtion *ui;
};

#endif // DIALOG_PRESCRIBTION_H
