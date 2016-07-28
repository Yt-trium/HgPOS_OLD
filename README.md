# HgPOS
Hg Mercure POS

## Project
Hg POS est un logiciel de gestion d'un point de vente associatif.
Hg POS permet de gérer la vente, les stocks, les inscriptions...

###  TODO
- Amélioration BDD
- Client : Ajout Colonne boutton en fonction du type.
- Supprimer les incohérence de langage dans le source (Anglais/Français, il faut choisir ...)

### DONE
- Création du README
- Création de la BDD de gestion de vente.
- Création du logiciel Client basique pour la vente.





## VERSION AND REVISION
### VERSION ACTUEL : ALPHA 1





## Dev Section

## Database

### Database Rules
- nom de base de donnée "HgPOS"
- nom de table et colonne en CamelCase
- date = timestamp

### Database Structure
- "produits" : la liste des articles en vente (idProduit, nom, type, prix, img(link))
types : (snacks = 1, boissons = 2, sandwichs = 100, inscriptions = 200, remise = 250, hide = 254, default = 255)

> Une formule, c'est < snack + boisson + sandwichs + remise >.

- "vente" : la liste des articles vendus pendant l'exercice annuel. (idVente, idProduit, date)

Calcul de la recette total :
SELECT SUM(prix) FROM produits INNER JOIN vente ON vente.idProduit = produits.idProduit;

Liste des nom de produits vendus sur une durée :
SELECT nom FROM produits INNER JOIN vente ON vente.idProduit = produits.idProduit
WHERE 	date >= '2016-07-22 01:24:28'
AND 	date <= '2016-07-22 01:24:30';

- "stock" : la liste des stocks theorique (idProduit, quantite).
> TODO TRIGGER AVEC VENTE
On calcul la différence de stock lorsque l'ont fait la caisse afin de donner la différence pour le total théorique, ce qui met a jours la table.

- "caisse" : la liste des caisses faites par le trésorier. (idCaisse, date, totalTheorie, totalReel)

totalTheorie = total vente + total erreur stock.

SELECT SUM(prix * unite) FROM produits INNER JOIN vente ON vente.idProduit = produits.idProduit
WHERE  date >= (SELECT date FROM caisse ORDER BY idCaisse DESC LIMIT 1)

INSERT INTO `caisse` (`idCaisse`, `date`, `totalTheorie`, `totalReel`) VALUES (NULL, CURRENT_TIMESTAMP, '4.5', '5');
