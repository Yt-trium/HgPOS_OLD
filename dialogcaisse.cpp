#include "dialogcaisse.h"
#include "ui_dialogcaisse.h"

DialogCaisse::DialogCaisse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCaisse)
{
    // TODO : FOND DE CAISSE > Fichier .ini

    fdc = QInputDialog::getDouble(this,"Fond de Caisse","Fond de Caisse :",85,0,5000,2);

    // Total theorique = total ventes + fond de caisse

    listProduits = db->loadProduits();
    ventes = db->loadVente();
    totalVentes = 0;
    int i;

    for(i=0;i<ventes->size();i++)
    {
        totalVentes += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
    }

    theorique = totalVentes + fdc;

    ui->setupUi(this);

    ui->label_totalTheo->setText(QString::number(theorique) + "€");
    updateTotalReel();

    connect(ui->spinBox_500, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_200, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_100, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_50,  SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_20,  SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_10,  SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_5,   SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_2,   SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_1,   SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_050, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_020, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_010, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_005, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_002, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->spinBox_001, SIGNAL(valueChanged(int)), this, SLOT(updateTotalReel()));
    connect(ui->doubleSpinBox_stock, SIGNAL(valueChanged(double)), this, SLOT(updateTotalReel()));
}

DialogCaisse::~DialogCaisse()
{
    delete ui;
}

void DialogCaisse::setDataBase(DataBase *d)
{
    db = d;
}

float DialogCaisse::getTotalReel()
{
    float total;
    total = ui->spinBox_500->value() * 500
          + ui->spinBox_200->value() * 200
          + ui->spinBox_100->value() * 100
          + ui->spinBox_50->value() * 50
          + ui->spinBox_20->value() * 20
          + ui->spinBox_10->value() * 10
          + ui->spinBox_5->value() * 5
          + ui->spinBox_2->value() * 2
          + ui->spinBox_1->value() * 1
          + ui->spinBox_050->value() * 0.50
          + ui->spinBox_020->value() * 0.20
          + ui->spinBox_010->value() * 0.10
          + ui->spinBox_005->value() * 0.05
          + ui->spinBox_002->value() * 0.02
          + ui->spinBox_001->value() * 0.01
            ;
    return total;
}

void DialogCaisse::updateTotalReel()
{
    float total = getTotalReel();
    ui->label_totalTheo->setText(QString::number(theorique + ui->doubleSpinBox_stock->value()));
    ui->label_totalReel->setText(QString::number(total) + "€");
    ui->label_erreur->setText(QString::number(total - (theorique + ui->doubleSpinBox_stock->value()) ) + "€");
}

void DialogCaisse::on_pushButtonValiderCaisse_clicked()
{



    if(QMessageBox::question(this,"Valider ?","Valider ?",QMessageBox::Yes|QMessageBox::No)  == QMessageBox::Yes)
    {
        // HgExporter::pdfCaisse(QDate::currentDate(),QDate::currentDate(),1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45);

        /*
        HgExporter::pdfCaisse(db->getLastCaisseDate(),QDate::currentDate()
                              ,ui->spinBox_500->value(),ui->spinBox_500->value()*500);
        */

        float DET_1 = 0;
        float DET_2 = 0;
        float DET_5 = 0;
        float DET_6 = 0;
        float DET_7 = 0;
        float DET_100 = 0;
        float DET_200 = 0;
        float DET_250 = 0;
        float DET_X = 0;
        int i;

        for(i=0;i<ventes->size();i++)
        {
            switch(listProduits->at(ventes->at(i).idProduit-1).type)
            {
            case 1:
            DET_1 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            case 2:
            DET_2 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            case 5:
            DET_5 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            case 6:
            DET_6 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            case 7:
            DET_7 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            case 100:
            DET_100 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            case 200:
            DET_200 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            case 250:
            DET_250 += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            default:
            DET_X += listProduits->at(ventes->at(i).idProduit-1).prix * ventes->at(i).unite;
            break;
            }
        }

        HgExporter::pdfCaisse(db->getLastCaisseDate(),QDate::currentDate()
                              ,ui->spinBox_500->value(),ui->spinBox_500->value()*500
                              ,ui->spinBox_200->value(),ui->spinBox_200->value()*200
                              ,ui->spinBox_100->value(),ui->spinBox_100->value()*100
                              ,ui->spinBox_50->value(),ui->spinBox_50->value()*50
                              ,ui->spinBox_20->value(),ui->spinBox_20->value()*20
                              ,ui->spinBox_10->value(),ui->spinBox_10->value()*10
                              ,ui->spinBox_5->value(),ui->spinBox_5->value()*5
                              ,ui->spinBox_2->value(),ui->spinBox_2->value()*2
                              ,ui->spinBox_1->value(),ui->spinBox_1->value()*1
                              ,ui->spinBox_050->value(),ui->spinBox_050->value()*0.5
                              ,ui->spinBox_020->value(),ui->spinBox_020->value()*0.2
                              ,ui->spinBox_010->value(),ui->spinBox_010->value()*0.1
                              ,ui->spinBox_005->value(),ui->spinBox_005->value()*0.05
                              ,ui->spinBox_002->value(),ui->spinBox_002->value()*0.02
                              ,ui->spinBox_001->value(),ui->spinBox_001->value()*0.01
                              ,fdc,getTotalReel()
                              ,theorique,getTotalReel()-fdc
                              ,ui->doubleSpinBox_stock->value()
                              ,(getTotalReel() - (theorique + ui->doubleSpinBox_stock->value()))
                              ,DET_1, DET_2, DET_5, DET_6
                              ,DET_7,DET_100,DET_200,DET_250
                              ,DET_X);

        db->setCaisse(theorique,getTotalReel(),ui->doubleSpinBox_stock->value(),(getTotalReel() - (theorique + ui->doubleSpinBox_stock->value())));
    }
}

void DialogCaisse::on_buttonBox_accepted()
{
    if(QMessageBox::question(this,"Quitter ?","Êtes vous sur de vouloir quitter sans sauvegarder ?",QMessageBox::Yes|QMessageBox::No)  == QMessageBox::Yes)
    {
        this->accept();
    }
}
