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
    void venteBtn_clicked(int idProduit);

private:
    Ui::MainWindow *ui;
    DataBase *db;
    QList<Produit> *listProduits;
    QList<QPushButton*> *listBtn;
    QSignalMapper mapper;
};

#endif // MAINWINDOW_H
