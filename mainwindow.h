#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>

#include "dialogstock.h"
#include "dialogcaisse.h"
#include "dialoginscription.h"

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

public slots:

private slots:
    void venteBtn_clicked(int idProduit);

    void on_pushButtonValider_clicked();
    void on_pushButtonQuantite_clicked();
    void on_pushButtonAnnuler_clicked();
    void on_pushButtonSupprimer_clicked();

    void on_listWidgetVente_itemDoubleClicked();

    void on_actionAccesCaisse_triggered();
    void on_actionAccesStock_triggered();
    void on_actionA_propos_triggered();
    void on_actionAnnulation_triggered();
    void on_actionAjouterMembre_triggered();

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
