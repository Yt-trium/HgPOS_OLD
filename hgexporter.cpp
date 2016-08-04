#include "hgexporter.h"

HgExporter::HgExporter()
{

}

int HgExporter::pdfCaisse()
{
    QPdfWriter writer("caisse-" + QDate::currentDate().toString("dd-MM-yyyy") + ".pdf");
    writer->setPageSize(QPagedPaintDevice::A4);

    QPainter painter(&writer);
    painter.setPen(Qt::red);
    painter.drawText(0,0,"THIS IS MY RED PDF TEXT..");

    painter.setPen(Qt::green);
    painter.drawText(0,500,"THIS IS MY GREEN PDF TEXT..");

    painter.setPen(Qt::blue);
    painter.drawText(0,1000,"THIS IS MY BLUE PDF TEXT..");

    painter.end();
    QMessageBox::information(NULL,"Hi!","Text has been written to the pdf file!");
}
