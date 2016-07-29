#ifndef DIALOGSTOCK_H
#define DIALOGSTOCK_H

#include <QDialog>
#include <QtWidgets>

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
    QList<Produit> *listProduits;
    QList<int> *stock;
    QList<Ventes> *ventes;

public slots:
    void on_buttonBox_accepted();


};

#endif // DIALOGSTOCK_H
