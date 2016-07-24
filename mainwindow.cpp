#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listProduits = db->loadProduits();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setDataBase(DataBase *d)
{
    db = d;
}
