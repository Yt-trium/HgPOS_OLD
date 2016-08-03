#ifndef DIALOGRESERVATION_H
#define DIALOGRESERVATION_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class DialogReservation;
}

class DialogReservation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogReservation(QWidget *parent = 0);
    ~DialogReservation();

private:
    Ui::DialogReservation *ui;
    QString date;
    QSettings *iniFile;

private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOGRESERVATION_H
