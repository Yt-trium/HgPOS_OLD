#ifndef DIALOGCAISSE_H
#define DIALOGCAISSE_H

#include <QDialog>
#include <QtWidgets>
#include <QtGui>
#include <QInputDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui {
class DialogCaisse;
}

class DialogCaisse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCaisse(QWidget *parent = 0);
    void setDataBase(DataBase *d);
    ~DialogCaisse();

private:
    Ui::DialogCaisse *ui;
    DataBase *db;
    float fdc;
    float totalVentes;
    float theorique;
    QList<Produit> *listProduits;
    QList<Ventes> *ventes;
    float getTotalReel();

private slots:
    void updateTotalReel();
    void on_buttonBox_accepted();
    void on_pushButtonValiderCaisse_clicked();
};

#endif // DIALOGCAISSE_H
