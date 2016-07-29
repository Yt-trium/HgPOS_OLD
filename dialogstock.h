#ifndef DIALOGSTOCK_H
#define DIALOGSTOCK_H

#include <QDialog>

#include "database.h"

namespace Ui {
class DialogStock;
}

class DialogStock : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStock(QWidget *parent = 0);
    void setDataBase(DataBase *d);
    ~DialogStock();

private:
    Ui::DialogStock *ui;
    DataBase *db;
};

#endif // DIALOGSTOCK_H
