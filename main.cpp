#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase *db = new DataBase();

    db->connect_dialog();
    // CHECK CONNECTION TODO

    MainWindow w;
    w.setDataBase(db);
    w.show();

    db->close();
    delete db;
    return a.exec();
}
