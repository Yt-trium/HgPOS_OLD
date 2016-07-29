#include "dialogstock.h"
#include "ui_dialogstock.h"

DialogStock::DialogStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStock)
{
    ui->setupUi(this);



}

DialogStock::~DialogStock()
{
    delete ui;
}

void DialogStock::setDataBase(DataBase *d)
{
    db = d;
}
