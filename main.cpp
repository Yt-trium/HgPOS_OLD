#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Creation de la class d'accès à la db.
    DataBase *db = new DataBase();
    db->connect_dialog();

    // Check la db
    if(!db->checkTableProduitsNotEmpty())
    {
        QMessageBox(QMessageBox::Critical,
                    "Error",
                    "Can't connect to database",
                    QMessageBox::Ok,
                    0).exec();
        return 1;
    }

    // Lance la fenètre et lui donne un accès à la db.
    MainWindow w;
    w.setDataBase(db);
    w.show();


    // Fermeture et suppression de la class d'accès à la db.
    db->close();
    delete db;

    // Fin
    return a.exec();
}
