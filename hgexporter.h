#ifndef HGEXPORTER_H
#define HGEXPORTER_H

#include <QtWidgets>
#include <QtGui>
#include <QPrinter>

class HgExporter
{
public:
    HgExporter();
    static int pdfCaisse(QDate datedebut, QDate datefin,
                         unsigned int _500e=0, float total_500e=0,
                         unsigned int _200=0, float total_200e=0,
                         unsigned int _100e=0, float total_100e=0,
                         unsigned int _50e=0, float total_50e=0,
                         unsigned int _20e=0, float total_20e=0,
                         unsigned int _10e=0, float total_10e=0,
                         unsigned int _5e=0, float total_5e=0,
                         unsigned int _2e=0, float total_2e=0,
                         unsigned int _1e=0, float total_1e=0,
                         unsigned int _050e=0, float total_050e=0,
                         unsigned int _020e=0, float total_020e=0,
                         unsigned int _010e=0, float total_010e=0,
                         unsigned int _005e=0, float total_005e=0,
                         unsigned int _002e=0, float total_002e=0,
                         unsigned int _001e=0, float total_001e=0,
                         float fondcaisse=0, float totalesp=0,
                         float totalthq=0, float totalrec=0,
                         float totalerrstock=0, float totalerr=0,
                         float DET_1=0, float DET_2=0,
                         float DET_5=0, float DET_6=0,
                         float DET_7=0, float DET_100=0,
                         float DET_200=0, float DET_250=0,
                         float DET_X=0);
};

#endif // HGEXPORTER_H
