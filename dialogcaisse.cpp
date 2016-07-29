#include "dialogcaisse.h"
#include "ui_dialogcaisse.h"

DialogCaisse::DialogCaisse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCaisse)
{
    // TODO : PENSER AU FOND DE CAISSE
    ui->setupUi(this);
}

DialogCaisse::~DialogCaisse()
{
    delete ui;
}
