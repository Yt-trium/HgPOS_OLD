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
    void update_listWidgetVente();

private slots:
    void venteBtn_clicked(int idProduit);
    void on_pushButtonValider_clicked();

private:
    Ui::MainWindow *ui;
    DataBase *db;
    QList<Produit> *listProduits;
    QList<QPushButton*> *listBtn;
    QSignalMapper mapper;
    QList<Produit> *panier;
    QList<int> *panierUnite;
};

#endif // MAINWINDOW_H
