#include "dialogreservation.h"
#include "ui_dialogreservation.h"

DialogReservation::DialogReservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogReservation)
{
    bool ok;
    QStringList items;
    items << QDate::currentDate().toString("dd/MM/yyyy") << QDate::currentDate().addDays(1).toString("dd/MM/yyyy");
    QString date = QInputDialog::getItem(this, "Date réservation","Date réservation", items, 0, false, &ok);

    if(!ok)
        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);

    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // LOAD AND SAVE INSIDE INI FILE

}

DialogReservation::~DialogReservation()
{
    delete ui;
}
