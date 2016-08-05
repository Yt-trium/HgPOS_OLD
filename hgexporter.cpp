#include "hgexporter.h"

HgExporter::HgExporter()
{

}

int HgExporter::pdfCaisse(float theorie, float reel, float stock, float caisse)
{
    QPdfWriter writer("caisse-" + QDate::currentDate().toString("dd-MM-yyyy") + ".pdf");
    writer.setTitle("Caisse du " + QDate::currentDate().toString("dd-MM-yyyy"));
    writer.setPageSize(QPagedPaintDevice::A4);

    QPainter painter(&writer);
    painter.setPen(Qt::red);
    painter.drawText(0,0,"PDF GENERER LE : ");
    painter.drawText(0,250,QDateTime::currentDateTime().toString("hh:mm:ss dd-MM-yyyy"));

    painter.setPen(Qt::black);
    painter.drawText(0,500,"Total Theorique (total des ventes) :");
    painter.drawText(0,750,QString::number(theorie));
    painter.drawText(0,1000,"Total Reel (total dans la caisse) :");
    painter.drawText(0,750,QString::number(reel));
    painter.drawText(0,1500,"Total stock (erreur comptage stock) :");
    painter.drawText(0,1750,QString::number(stock));
    painter.drawText(0,2000,"Total FIN (reel - (theorique + stock)) :");
    painter.drawText(0,1250,QString::number(caisse));
    painter.end();

    return 0;
}
