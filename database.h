#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QObject>

#include <QInputDialog>

#include <QDebug>

#include "produit.h"
#include "struct.h"

class DataBase
{
public:
    DataBase();

    int connect(QString hostName, QString dbName, QString userName, QString password);
    bool connect_dialog();
    void close();

    bool checkTableProduitsNotEmpty();
    QList<Produit>* loadProduits();
    bool sellProduit(int id, int unit);
    QList<int>* loadStock();
    QList<Ventes>* loadVente();

    void setStock(int id, int q);

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
