#include "database.h"

DataBase::DataBase()
{

}

int DataBase::connect(QString hostName, QString dbName, QString userName, QString password)
{
    qDebug() << "DataBase::connect";

    // Check database open
    if(db.isOpen())
    {
        qDebug()<<"DataBase::connect : Database already open";
        return 1;
    }

    // Connect to database
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(password);

    // Check connexion
    if(!db.open())
    {
        qDebug()<<"DataBase::connect : Can't connect to database";
        return 2;
    }

    return 0;
}

void DataBase::close()
{
    db.close();
}

bool DataBase::connect_dialog()
{
    // Get username & password
    bool validReturn;

    QString db_username = QInputDialog::getText(0, QObject::tr("Username"),
                                             QObject::tr("Username:"), QLineEdit::Normal,
                                             "root", &validReturn);
    if (!validReturn || db_username.isEmpty())
    {
        qDebug() << "DataBase::connect_dialog : Error with db_username";
        return false;
    }

    QString db_password = QInputDialog::getText(0, QObject::tr("Password"),
                                             QObject::tr("Password:"), QLineEdit::Normal,
                                             "", &validReturn);
    if (!validReturn || db_username.isEmpty())
    {
        qDebug() << "DataBase::connect_dialog : Error with db_password";
        return false;
    }

   if(this->connect("localhost","hgpos",db_username,db_password) == 0)
       return true;
   else
       return false;
}

bool DataBase::checkTableProduitsNotEmpty()
{
    QString q = "SELECT * FROM produits";
    QSqlQuery query(q);

    return query.isActive();
}

QList<Produit>* DataBase::loadProduits()
{
    QList<Produit> *listProduits = new QList<Produit>();

    Produit p;
    QString q = "SELECT * FROM produits";
    QSqlQuery query(q);

    while(query.next())
    {
        p.idProduit = query.value(0).toInt();
        p.nom       = query.value(1).toString();
        p.type      = query.value(2).toInt();
        p.prix      = query.value(3).toFloat();
        p.img       = query.value(4).toString();

        listProduits->append(p);
    }


    return listProduits;
}

bool DataBase::sellProduit(int id, int unit)
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::sellProduit : Can't open database";
        return false;
    }

    QString q = "INSERT INTO `vente` (`idVente`, `idProduit`, `date`, `unite`) VALUES (NULL, '" + QString::number(id) + "', CURRENT_TIMESTAMP, '" + QString::number(unit) + "');";
    QSqlQuery query(q);
    return true;
}
