#include "dialogreservation.h"
#include "ui_dialogreservation.h"

DialogReservation::DialogReservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogReservation)
{
    bool ok;
    QStringList items;
    items << QDate::currentDate().toString("dd-MM-yyyy") << QDate::currentDate().addDays(1).toString("dd-MM-yyyy");
    date = QInputDialog::getItem(this, "Date réservation","Date réservation", items, 0, false, &ok);

    if(!ok)
        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);

    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // LOAD AND SAVE INSIDE INI FILE
    iniFile = new QSettings("reservation.ini",QSettings::IniFormat);
    QStringList stream;
    int i;

    if(!iniFile->contains(date+"/"+"emmental_1"))   // TODO : CHANGER emmental_1 par quelque chose de certain.
    {
        qDebug() << "QSetting create";
        iniFile->beginGroup("default");
        stream = iniFile->allKeys();
        iniFile->endGroup();
        for(i=0;i<stream.size();++i)
            iniFile->setValue(date+"/"+stream.at(i),"");
    }

    iniFile->beginGroup(date);
    stream = iniFile->allKeys();
    QString streamChop;
    for(i=stream.size()-1;i>=0;--i)
    {
        streamChop = stream.at(i);
        streamChop.chop(2);
        QTableWidgetItem *itm = new QTableWidgetItem(streamChop);
        itm->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,itm);
        itm = new QTableWidgetItem(iniFile->value(stream.at(i)).toString());
        ui->tableWidget->setItem(0,1,itm);
    }

    iniFile->sync();


}

DialogReservation::~DialogReservation()
{
    delete ui;
}

void DialogReservation::on_buttonBox_accepted()
{
    qDebug() << "on_buttonBox_accepted";
    iniFile = new QSettings("reservation.ini",QSettings::IniFormat);
    iniFile->beginGroup(date);
    QStringList stream = iniFile->allKeys();
    int i = 0;

    qDebug() << stream;

    for(i=stream.size()-1;i>=0;--i)
    {
        qDebug() << stream.at(i) << " " << ui->tableWidget->item(i,1)->text();
        iniFile->setValue(stream.at(i),ui->tableWidget->item(i,1)->text());
    }

    iniFile->sync();
}
