#ifndef DIALOGINSCRIPTION_H
#define DIALOGINSCRIPTION_H

#include <QDialog>

#include "database.h"

namespace Ui {
class DialogInscription;
}

class DialogInscription : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInscription(QWidget *parent = 0);
    void setDataBase(DataBase *d);
    ~DialogInscription();

private:
    Ui::DialogInscription *ui;
    DataBase *db;

private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOGINSCRIPTION_H
