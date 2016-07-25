#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetVente->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    listProduits = db->loadProduits();
    listBtn = new QList<QPushButton*>;

    int i;
    for(i=0;i<listProduits->size();i++)
    {
        QPushButton *tmpBtn = new QPushButton(this);
        tmpBtn->setText(listProduits->at(i).nom);
        listBtn->append(tmpBtn);
        connect(tmpBtn, SIGNAL(clicked()), this, SLOT(on_btn_vente_clicked(listBtn->at(i)->text());));
        ui->gridBtnVente->addWidget(tmpBtn,i/4,i%4);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setDataBase(DataBase *d)
{
    db = d;
}

void MainWindow::on_btn_vente_clicked(QString idProduit)
{
    qDebug() << idProduit;
}
