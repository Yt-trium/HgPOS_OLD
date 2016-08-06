#ifndef HGEXPORTER_H
#define HGEXPORTER_H

#include <QtWidgets>
#include <QtGui>
#include <QPrinter>

class HgExporter
{
public:
    HgExporter();
    static int pdfCaisse(float theorie, float reel, float stock, float caisse);
};

#endif // HGEXPORTER_H
