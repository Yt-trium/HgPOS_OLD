#include "hgexporter.h"

HgExporter::HgExporter()
{

}

int HgExporter::pdfCaisse(QDate datedebut, QDate datefin,
                          unsigned int _500e, float total_500e,
                          unsigned int _200e, float total_200e,
                          unsigned int _100e, float total_100e,
                          unsigned int _50e, float total_50e,
                          unsigned int _20e, float total_20e,
                          unsigned int _10e, float total_10e,
                          unsigned int _5e, float total_5e,
                          unsigned int _2e, float total_2e,
                          unsigned int _1e, float total_1e,
                          unsigned int _050e, float total_050e,
                          unsigned int _020e, float total_020e,
                          unsigned int _010e, float total_010e,
                          unsigned int _005e, float total_005e,
                          unsigned int _002e, float total_002e,
                          unsigned int _001e, float total_001e,
                          float fondcaisse, float totalesp,
                          float totalthq, float totalrec,
                          float totalerrstock, float totalerr,
                          float DET_1, float DET_2,
                          float DET_5, float DET_6,
                          float DET_7, float DET_100,
                          float DET_200, float DET_250,
                          float DET_X
                          )
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

    data.replace("*500e*",QString::number(_500e));
    data.replace("*TOTAL-500e*",QString::number(total_500e));
    data.replace("*200e*",QString::number(_200e));
    data.replace("*TOTAL-200e*",QString::number(total_200e));
    data.replace("*100e*",QString::number(_100e));
    data.replace("*TOTAL-100e*",QString::number(total_100e));
    data.replace("*50e*",QString::number(_50e));
    data.replace("*TOTAL-50e*",QString::number(total_50e));
    data.replace("*20e*",QString::number(_20e));
    data.replace("*TOTAL-20e*",QString::number(total_20e));
    data.replace("*10e*",QString::number(_10e));
    data.replace("*TOTAL-10e*",QString::number(total_10e));
    data.replace("*5e*",QString::number(_5e));
    data.replace("*TOTAL-5e*",QString::number(total_5e));

    data.replace("*2e*",QString::number(_2e));
    data.replace("*TOTAL-2e*",QString::number(total_2e));
    data.replace("*1e*",QString::number(_1e));
    data.replace("*TOTAL-1e*",QString::number(total_1e));
    data.replace("*05e*",QString::number(_050e));
    data.replace("*TOTAL-05e*",QString::number(total_050e));
    data.replace("*02e*",QString::number(_020e));
    data.replace("*TOTAL-02e*",QString::number(total_020e));
    data.replace("*01e*",QString::number(_010e));
    data.replace("*TOTAL-01e*",QString::number(total_010e));
    data.replace("*005e*",QString::number(_005e));
    data.replace("*TOTAL-005e*",QString::number(total_005e));
    data.replace("*002e*",QString::number(_002e));
    data.replace("*TOTAL-002e*",QString::number(total_002e));
    data.replace("*001e*",QString::number(_001e));
    data.replace("*TOTAL-001e*",QString::number(total_001e));

    data.replace("*FOND-CAISSE*",QString::number(fondcaisse));
    data.replace("*TOTAL-ESP*",QString::number(totalesp));
    data.replace("*TOTAL-THQ*",QString::number(totalthq));
    data.replace("*TOTAL-REC*",QString::number(totalrec));
    data.replace("*TOTAL-ERR-STOCK*",QString::number(totalerrstock));
    data.replace("*TOTAL-ERR*",QString::number(totalerr));

    data.replace("*DET-1*",QString::number(DET_1));
    data.replace("*DET-2*",QString::number(DET_2));
    data.replace("*DET-5*",QString::number(DET_5));
    data.replace("*DET-6*",QString::number(DET_6));
    data.replace("*DET-7*",QString::number(DET_7));
    data.replace("*DET-100*",QString::number(DET_100));
    data.replace("*DET-200*",QString::number(DET_200));
    data.replace("*DET-250*",QString::number(DET_250));
    data.replace("*DET-X*",QString::number(DET_X));

    file.seek(0);
    QTextStream out(&file);
    out << data; //writing to the same file
    file.close();

    QProcess process;
    // process.setNativeArguments(filename);
    QStringList x;
    x.append(filename);

    qDebug() << x;

    // process.setArguments(x);
    process.start("pdflatex", QStringList() << filename);

    if(process.waitForFinished(5000))
    {
            QFile::remove(filename);
            QFile::remove(filename.replace(".tex",".log"));
            QFile::remove(filename.replace(".log",".aux"));
    }


    return 0;
}
