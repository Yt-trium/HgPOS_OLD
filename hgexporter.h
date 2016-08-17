#ifndef HGEXPORTER_H
#define HGEXPORTER_H

#include <QtWidgets>
#include <QtGui>
#include <QPrinter>

class HgExporter
{
public:
    HgExporter();
    static int pdfCaisse(QDate datedebut, QDate datefin);
};

#endif // HGEXPORTER_H
