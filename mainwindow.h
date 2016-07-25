#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>

#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setDataBase(DataBase *d);

public slots:
    void on_btn_vente_clicked(QString idProduit);

private:
    Ui::MainWindow *ui;
    DataBase *db;
    QList<Produit> *listProduits;
    QList<QPushButton*> *listBtn;
};

#endif // MAINWINDOW_H
