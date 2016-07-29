#ifndef DIALOGCAISSE_H
#define DIALOGCAISSE_H

#include <QDialog>

namespace Ui {
class DialogCaisse;
}

class DialogCaisse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCaisse(QWidget *parent = 0);
    ~DialogCaisse();

private:
    Ui::DialogCaisse *ui;
};

#endif // DIALOGCAISSE_H
