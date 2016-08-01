#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listProduits = db->loadProduits();
    listBtn = new QList<QPushButton*>;

    int i;
    for(i=0;i<listProduits->size();i++)
    {
        QPushButton *tmpBtn = new QPushButton(this);
        tmpBtn->setText(listProduits->at(i).nom);

        if(listProduits->at(i).img != "")
        {
            tmpBtn->setIcon(QIcon("./logoProduits/" + listProduits->at(i).img));
            tmpBtn->setIconSize(QSize(50,50));
        }

        listBtn->append(tmpBtn);

        connect(tmpBtn, SIGNAL(clicked()), &mapper, SLOT(map()));
        mapper.setMapping(tmpBtn, listProduits->at(i).idProduit);

        // RIRI
        switch(listProduits->at(i).type)
        {
            case 1:     // SNACK
            ui->verticalLayoutVente_1->addWidget(tmpBtn);
            break;
            case 2:     // BOISSON
            ui->verticalLayoutVente_2->addWidget(tmpBtn);
            break;
            case 254:   // HIDE
            // NOTHING
            break;
            default:
            ui->verticalLayoutVente_3->addWidget(tmpBtn);
            break;
        }

        // ui->gridBtnVente->addWidget(tmpBtn,i/4,i%4);
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
    update_listWidgetVente();
}

void MainWindow::update_listWidgetVente()
{
    ui->listWidgetVente->clear();

    int i = 0;
    for(i=0;i<panier->size();i++)
    {
        QListWidgetItem* itm = new QListWidgetItem(panier->at(i).nom + "\t - \t" + QString::number(panier->at(i).prix) + "€\t - \t"  + QString::number(panierUnite->at(i)) + "µ");
        itm->setTextAlignment(Qt::AlignRight);
        ui->listWidgetVente->addItem(itm);
        // ui->listWidgetVente->addItem(panier->at(i).nom + "\t - \t" + QString::number(panier->at(i).prix) + "€\t - \t"  + QString::number(panierUnite->at(i)) + "µ");
    }
}

void MainWindow::on_pushButtonValider_clicked()
{
    // Total et Monnaie.
    /*
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Test", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
      } else {
        qDebug() << "Yes was *not* clicked";
      }*/
    int i = 0;
    float total = 0;
    for(i=0;i<panier->size();i++)
        total+=panier->at(i).prix*panierUnite->at(i);

    // TODO CHECK RETURN
    bool validReturn;
    float esp;

    if(QMessageBox::question(this,"Total",QString("Total : " + QString::number(total) + "€\nValider ?"),QMessageBox::Yes|QMessageBox::No)  == QMessageBox::Yes)
    {
        for(i=0;i<panier->size();i++)
        {
            db->sellProduit(panier->at(i).idProduit,panierUnite->at(i));
        }
        esp = QInputDialog::getDouble(this,"Espèces","Espèces :",total,0,5000,2,&validReturn);
        QMessageBox::information(this,"Rendu",QString("Rendu : " + QString::number(esp - total)));
    }

    panier->clear();
    panierUnite->clear();
    ui->listWidgetVente->clear();
}

void MainWindow::on_pushButtonQuantite_clicked()
{
    bool validReturn;
    int u = QInputDialog::getInt(this,"Unite","Unite :",1,0,1000,1,&validReturn);
    panierUnite->replace(ui->listWidgetVente->currentRow(),u);
    /*
    Produit tmp = panier->at(ui->listWidgetVente->currentRow());

    panier->removeAt(ui->listWidgetVente->currentRow());
    panierUnite->removeAt(ui->listWidgetVente->currentRow());

    panier->append(tmp);
    panierUnite->append(u);
    */
    update_listWidgetVente();
}

void MainWindow::on_pushButtonAnnuler_clicked()
{
    panier->clear();
    panierUnite->clear();
    ui->listWidgetVente->clear();
}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    panier->removeAt(ui->listWidgetVente->currentRow());
    panierUnite->removeAt(ui->listWidgetVente->currentRow());
    update_listWidgetVente();
}

void MainWindow::on_listWidgetVente_itemDoubleClicked()
{
    // TODO CLEAN
    bool validReturn;
    int u = QInputDialog::getInt(this,"Unite","Unite :",1,0,1000,1,&validReturn);
    panierUnite->replace(ui->listWidgetVente->currentRow(),u);
    update_listWidgetVente();
}

// TODO : VERIFICATION DECOMPTE POUR ACCES RESTREINT

void MainWindow::on_actionAccesCaisse_triggered()
{
    qDebug() << "on_actionAccesCaisse_triggered";
    DialogCaisse d;
    d.setDataBase(db);
    d.exec();
}

void MainWindow::on_actionAccesStock_triggered()
{
    qDebug() << "on_actionAccesStock_triggered";
    DialogStock d;
    d.setDataBase(db);
    d.exec();
}

void MainWindow::on_actionA_propos_triggered()
{
    qDebug() << "on_actionA_propos_triggered";
    QMessageBox::about(this,"HgPOS","HgPOS\nMeyer Cyril\ncyril@adem.u-strasbg.fr");
}

void MainWindow::on_actionAnnulation_triggered()
{
    // Demande d'annulation pour la dernière vente.
    // db->getLastVenteId()
}
