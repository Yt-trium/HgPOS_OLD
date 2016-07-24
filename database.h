#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QObject>

#include <QInputDialog>

#include <QDebug>

class DataBase
{
public:
    DataBase();
    int connect(QString hostName, QString dbName, QString userName, QString password);
    void close();
    bool connect_dialog();
    bool checkTableProduitsNotEmpty();

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
