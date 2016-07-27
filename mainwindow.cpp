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

        connect(tmpBtn, SIGNAL(clicked()), &mapper, SLOT(map()));
        mapper.setMapping(tmpBtn, listProduits->at(i).idProduit);

        ui->gridBtnVente->addWidget(tmpBtn,i/4,i%4);
    }
    connect(&mapper, SIGNAL(mapped(int)), this, SLOT(venteBtn_clicked(int)));

    panier = new QList<Produit>;
    panierUnite = new QList<int>;
}

MainWindow::~MainWindow()
{
    delete ui;

    delete listBtn;
    delete panier;
    delete panierUnite;
}


void MainWindow::setDataBase(DataBase *d)
{
    db = d;
}

void MainWindow::venteBtn_clicked(int idProduit)
{
    if(listProduits->at(idProduit-1).idProduit == idProduit)
    {
        panier->append(listProduits->at(idProduit-1));
        panierUnite->append(1);
    }
    else
        return;
    // TODO : Ajout Propre
    update_tableWidgetVente();
}

void MainWindow::update_tableWidgetVente()
{
    ui->tableWidgetVente->clearContents();
    ui->tableWidgetVente->setRowCount(0);

    int i = 0;
    QTableWidgetItem *tmpItm;
    for(i=0;i<panier->size();i++)
    {
        ui->tableWidgetVente->insertRow(0);
        tmpItm = new QTableWidgetItem(panier->at(i).nom);
        ui->tableWidgetVente->setItem(0,0,tmpItm);
        tmpItm = new QTableWidgetItem(QString::number(panier->at(i).prix));
        ui->tableWidgetVente->setItem(0,1,tmpItm);
        tmpItm = new QTableWidgetItem(QString::number(panierUnite->at(i)));
        ui->tableWidgetVente->setItem(0,2,tmpItm);
        // TODO : Fuite mémoire ?
    }
}

void MainWindow::on_pushButtonValider_clicked()
{
    // Total et Monnaie.

    int i = 0;

    for(i=0;i<panier->size();i++)
    {
        db->sellProduit(panier->at(i).idProduit,panierUnite->at(i));
    }

    panier->clear();
    panierUnite->clear();
    ui->tableWidgetVente->clearContents();
    ui->tableWidgetVente->setRowCount(0);
}
