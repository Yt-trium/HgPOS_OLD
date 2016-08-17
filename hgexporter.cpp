#include "hgexporter.h"

HgExporter::HgExporter()
{

}

int HgExporter::pdfCaisse(QDate datedebut, QDate datefin)
{

    QFile model("model_tex/caisse.tex");
    QString filename = "caisse-" + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + ".tex";
    model.copy(filename);
    QFile file(filename);

    file.open(QFile::ReadWrite);

    QString data = QString(file.readAll());

    data.replace("*DATE-DEBUT*",
                 datedebut.toString("dd/MM/yyyy"));
    data.replace("*DATE-FIN*",
                 datefin.toString("dd/MM/yyyy"));
    data.replace("*DATE-HEURE*",
                 QString(QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss")));


    file.seek(0);
    QTextStream out(&file);
    out << data; //writing to the same file
    file.close();

    QProcess process;
    process.setNativeArguments(filename);
    process.start("pdflatex");
    if(process.waitForFinished(5000))
    {
            QFile::remove(filename);
            QFile::remove(filename.replace(".tex",".log"));
            QFile::remove(filename.replace(".log",".aux"));
    }


    return 0;
}
