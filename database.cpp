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
    // db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(password);

    // Check connexion
    if(!db.open())
    {
        qDebug() << db.lastError().text();
        qDebug() <<"DataBase::connect : Can't connect to database";
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

   if(this->connect("localhost","HgPOS",db_username,db_password) == 0)
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
    QSqlDatabase db(QSqlDatabase::database());

    QList<Produit> *listProduits = new QList<Produit>();

    if(!db.open())
    {
        qDebug()<<"DataBase::loadProduits : Can't open database";
        return listProduits;
    }

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

QList<int>* DataBase::loadStock()
{
    QSqlDatabase db(QSqlDatabase::database());

    QList<int> *stock = new QList<int>();

    if(!db.open())
    {
        qDebug()<<"DataBase::loadStock : Can't open database";
        return stock;
    }

    int x;
    QString q = "SELECT * FROM stock";
    QSqlQuery query(q);

    while(query.next())
    {
        x = query.value(1).toInt();

        stock->append(x);
    }

    return stock;
}

QList<Ventes>* DataBase::loadVente()
{

    QSqlDatabase db(QSqlDatabase::database());

    QList<Ventes> *ventes = new QList<Ventes>();

    if(!db.open())
    {
        qDebug()<<"DataBase::loadVente : Can't open database";
        return ventes;
    }

    Ventes v;
    QString q = "SELECT idProduit, unite FROM vente WHERE  date >= (SELECT date FROM caisse ORDER BY idCaisse DESC LIMIT 1)";
    QSqlQuery query(q);

    while(query.next())
    {
        v.idProduit = query.value(0).toInt();
        v.unite = query.value(1).toInt();

        ventes->append(v);
    }

    return ventes;
}

void DataBase::setStock(int id, int q)
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::setStock : Can't open database";
        return;
    }

    QString qs;

    qs = "UPDATE `stock` SET `quantite` = '" +  QString::number(q) + "' WHERE `stock`.`idProduit` = " + QString::number(id) + ";";
    QSqlQuery query(qs);

}

void DataBase::setCaisse(float theorie, float reel)
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::setCaisse : Can't open database";
        return;
    }

    QString q;
    q = "INSERT INTO `caisse` (`idCaisse`, `date`, `totalTheorie`, `totalReel`) VALUES (NULL, CURRENT_TIMESTAMP, '" + QString::number(theorie) + "', '" + QString::number(reel) + "');";
    QSqlQuery query(q);
}

void DataBase::setCaisse(float theorie, float reel, float stock, float caisse)
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::setCaisse : Can't open database";
        return;
    }

    QString q;
    q = "INSERT INTO `caisse` (`idCaisse`, `date`, `totalTheorie`, `totalReel`, `erreurStock`, `erreurCaisse`) VALUES (NULL, CURRENT_TIMESTAMP, '" + QString::number(theorie) + "', '" + QString::number(reel) + "', '" + QString::number(stock) + "', '" + QString::number(caisse) + "');";
    qDebug() << q;
    QSqlQuery query(q);
}

int DataBase::getLastVenteId()
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::getLastVenteId : Can't open database";
        return -1;
    }

    QString q;
    q = "SELECT idVente FROM vente ORDER BY idVente DESC LIMIT 1;";
    QSqlQuery query(q);
    query.next();
    return query.value(0).toInt();
}

int DataBase::getDroitAcces()
{
    bool validReturn;
    QString login = QInputDialog::getText(0, QObject::tr("Login"),
                                             QObject::tr("Login :"), QLineEdit::Normal,
                                             "", &validReturn);
    if (!validReturn || login.isEmpty())
    {
        qDebug() << "DataBase::getDroitAcces : Error with login";
        return false;
    }

    QString password = QInputDialog::getText(0, QObject::tr("Password"),
                                             QObject::tr("Password :"), QLineEdit::Normal,
                                             "", &validReturn);
    if (!validReturn || password.isEmpty())
    {
        qDebug() << "DataBase::getDroitAcces : Error with tresorier";
        return false;
    }


    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::getLastVenteId : Can't open database";
        return -1;
    }

    QString q;
    q = "SELECT droitAcces FROM utilisateurs WHERE login = '" + login + "' AND password = '" + password + "';";
    QSqlQuery query(q);
    query.next();
    return query.value(0).toInt();
}

void DataBase::addMembre(QString nom, QString prenom, QString email, int annee)
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::addMembre : Can't open database";
        return;
    }

    QString q;
    q = "INSERT INTO `membres` (`idMembre`, `nom`, `prenom`, `email`, `annee`) VALUES (NULL, '" + nom + "', '" + prenom + "', '" + email + "', '" + QString::number(annee) + "');";
    QSqlQuery query(q);
}

QString DataBase::searchMembre(QString nom, QString prenom)
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::searchMembre : Can't open database";
        return "Can't open database";
    }

    QString r = "";
    QString q;
    q = "SELECT * FROM membres WHERE nom = '" + nom + "' OR prenom = '" + prenom + "';";
    QSqlQuery query(q);

    while(query.next())
        {
            r += query.value(1).toString();
            r += " ";
            r += query.value(2).toString();
            r += " ";
            r += "ID : ";
            r += query.value(0).toString();
            r += " - ";
            r += "Email : ";
            r += query.value(3).toString();
            r += " - ";
            r += "Annee : ";
            r += query.value(4).toString();
            r += "\n";
        }
    if (r == "")
            r = "Membre introuvable";
    return r;
}

QDate DataBase::getLastCaisseDate()
{
    QSqlDatabase db(QSqlDatabase::database());
    if(!db.open())
    {
        qDebug()<<"DataBase::getLastCaisseDate : Can't open database";
        return QDate::currentDate();
    }

    QString q;
    q = "SELECT date FROM caisse ORDER BY idCaisse DESC LIMIT 1;";
    QSqlQuery query(q);
    query.next();
    return query.value(0).toDate();

}
