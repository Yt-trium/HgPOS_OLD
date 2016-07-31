#include "dialogstock.h"
#include "ui_dialogstock.h"

DialogStock::DialogStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStock)
{
    ui->setupUi(this);

    /*
     * Lister les produits
     * Recuperer les stocks
     * Calculer le theorique
     *
     */

    listProduits = db->loadProduits();
    // TODO : Changer la structure de donné pour stock.
    stock = db->loadStock();
    ventes = db->loadVente();
    diff = new QList<int>();
    int i;

    for(i=0;i<listProduits->size();i++)
        diff->append(0);

    for(i=0;i<ventes->size();i++)
    {
        diff->replace(ventes->at(i).idProduit-1,
        diff->at(ventes->at(i).idProduit-1) - ventes->at(i).unite);
    }

    // GUI
    listSpin = new QList<QSpinBox*>;

    for(i=0;i<listProduits->size();i++)
    {
        QLabel *tmpLbl1 = new QLabel(listProduits->at(i).nom);
        QLabel *tmpLbl2 = new QLabel(QString::number(stock->at(i)));
        QLabel *tmpLbl3 = new QLabel(QString::number(diff->at(i)));
        QLabel *tmpLbl4 = new QLabel(QString::number(stock->at(i) + diff->at(i)));

        QSpinBox *tmpSpin = new QSpinBox(this);
        tmpSpin->setValue(stock->at(i) + diff->at(i));

        ui->gridLayoutStock->addWidget(tmpLbl1,i+1,0);
        ui->gridLayoutStock->addWidget(tmpLbl2,i+1,1);
        ui->gridLayoutStock->addWidget(tmpLbl3,i+1,2);
        ui->gridLayoutStock->addWidget(tmpLbl4,i+1,3);
        ui->gridLayoutStock->addWidget(tmpSpin,i+1,4);
        listSpin->append(tmpSpin);
    }
}

DialogStock::~DialogStock()
{
    delete ui;
}

void DialogStock::setDataBase(DataBase *d)
{
    db = d;
}

void DialogStock::on_buttonBox_accepted()
{
    int i;
    float diffPrix = 0;

    for(i=0;i<listProduits->size();i++)
    {
        // Différence = Somme ( ( Realité - Théorique ) * Prix )
        diffPrix += (listSpin->at(i)->value() - (stock->at(i) + diff->at(i))) * listProduits->at(i).prix;
    }

    QMessageBox::information(this,"Diff","Différence : " + QString::number(-diffPrix) + "€");

    for(i=0;i<listSpin->size();i++)
        db->setStock(listProduits->at(i).idProduit,listSpin->at(i)->value());

    QMessageBox::information(this,"Information","! DATABASE UPDATE !");
}
