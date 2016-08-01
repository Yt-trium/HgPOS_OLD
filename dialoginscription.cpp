#include "dialoginscription.h"
#include "ui_dialoginscription.h"

DialogInscription::DialogInscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInscription)
{
    ui->setupUi(this);
}

DialogInscription::~DialogInscription()
{
    delete ui;
}

void DialogInscription::setDataBase(DataBase *d)
{
    db = d;
}

void DialogInscription::on_buttonBox_accepted()
{
    int annee = 0;
    switch(ui->comboBox_annee->currentIndex())
    {
        case 0:
            annee = 1;
        break;
        case 1:
            annee = 20;
        break;
        case 2:
            annee = 30;
        break;
        case 3:
            annee = 40;
        break;
        case 4:
            annee = 50;
        break;
        case 5:
            annee = 21;
        break;
        case 6:
            annee = 31;
        break;
        case 7:
            annee = 41;
        break;
        case 8:
            annee = 51;
        break;
        case 9:
            annee = 100;
        break;

    }

    db->addMembre(ui->lineEdit_nom->text(),ui->lineEdit_prenom->text(),ui->lineEdit_email->text(),annee);
}
