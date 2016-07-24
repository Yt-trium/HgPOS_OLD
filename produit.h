#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>

class Produit
{
public:
    Produit(){}
    int idProduit;
    QString nom;
    unsigned char type;
    float prix;
    QString img;
};

#endif // PRODUIT_H

