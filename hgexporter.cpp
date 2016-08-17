#include "hgexporter.h"

HgExporter::HgExporter()
{

}

int HgExporter::pdfCaisse(float theorie, float reel, float stock, float caisse)
{

    QFile model("model_tex/caisse.tex");
    QString filename = "caisse-" + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + ".tex";
    model.copy(filename);
    QFile file(filename);

    QProcess process;
    process.setNativeArguments(filename);
    process.start("pdflatex");
    process.waitForFinished(10000);


    /*
     * OLD VERSION USING QPdfWriter / Maybe usefull later if the second version isn't perfect.
     *
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
    */

    // QTextDocumentWriter ?
    // QTextDocumentWriter test;
    /*
    QString html =
    "<div align=right>"
       "ADEM<br>"
       "Strasbourg"
    "</div>"
    "<div align=left>"
       "Caisse<br>"
    + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") +
    "</div>"
    "<h1 align=center>Caisse du "
    + QDate::currentDate().toString("dd/MM/yyyy") +
    "</h1>"
    "<h3 align=center>HgPOS - cyril@adem.u-strasbg.fr</h3>"
        "<style>"
            "table, tr, th, td {"
            "border: 5px;"
            "padding: 15px;"
            "}"
        "</style>"
    "<div align=center>"
       "<table style=\"width:100%\">"
       "     <tr>"
       "       <th>Type Produits</th>"
       "       <th>Recette</th>"
       "       <th>Age</th>"
       "     </tr>"
       "     <tr>"
       "       <td>Jill</td>"
       "       <td>Smith</td>"
       "       <td>50</td>"
       "     </tr>"
       "     <tr>"
       "       <td>Eve</td>"
       "       <td>Jackson</td>"
       "       <td>94</td>"
       "     </tr>"
       "   </table>"
    "</div>"
    "<div align=right>Signature et Schtampfel</div>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    printer.setOutputFileName("caisse-" + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + ".pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);
    */

    return 0;
}
