# HgPOS
Hg Mercure POS

## Project
Hg POS est un logiciel de gestion d'un point de vente associatif.
Hg POS permet de gérer la vente, les stocks, les inscriptions...

###  TODO
- Exportation des caisse et stock (En cours).
- Amélioration BDD
- Supprimer les incohérence de langage dans le source (Anglais/Français, il faut choisir ...)
- Class mieux organisé (QDialog et héritage...)
- ReRédaction du README
- Création d'une DOC
- Réagement du code (nettoyage)

### IDEA
- Recherche membre avec lecteur code bar
- Solde de compte pour les membres
- compte administration ajout produits

### DONE
- Création du README
- Création de la BDD de gestion de vente.
- Création du logiciel Client basique pour la vente.
- Client : Ajout Colonne boutton en fonction du type.
- Accès Stock / Caisse
- Debug Caisse et Stock
- Inscription / Recherche membre
- Réservations
- Sécurité Accès restreint



## VERSION AND REVISION
### VERSION ACTUEL : ALPHA 2



## Dev Section

## Reservation
Les reservations sont stockés dans un fichier nommé reservation.ini.
Format :

[default]
list=
[date]
list=

Exemple :

[default]
emmental_1=
emmental_2=
poulet%20curry_1=
poulet%20curry_2=
poulet%20curry_3=
saumon%20frommage%20frais_1=

[03-08-2016]
emmental_1=
emmental_2=Cyril
poulet%20curry_1=VENDU
poulet%20curry_2=Jimmy
poulet%20curry_3=
saumon%20frommage%20frais_1=Julien

[04-08-2016]
emmental_1=
emmental_2=
poulet%20curry_1=Bastien
poulet%20curry_2=Mathilde
poulet%20curry_3=
saumon%20frommage%20frais_1=


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
On calcul la différence de stock lorsque l'ont fait la caisse afin de donner la différence pour le total théorique, ce qui met a jours la table.

- "caisse" : la liste des caisses faites par le trésorier. (idCaisse, date, totalTheorie, totalReel, erreurStock, erreurCaisse)

totalTheorie = total vente + total erreur stock.

SELECT SUM(prix * unite) FROM produits INNER JOIN vente ON vente.idProduit = produits.idProduit
WHERE  date >= (SELECT date FROM caisse ORDER BY idCaisse DESC LIMIT 1)

INSERT INTO `caisse` (`idCaisse`, `date`, `totalTheorie`, `totalReel`) VALUES (NULL, CURRENT_TIMESTAMP, '4.5', '5');

- "membres" : la liste des membres (idMembre, nom, prenom, email, annee) (inconnu = 0, L1 = 1, L2MATH = 20, L2INFO = 21, L3MATH = 30, L3INFO = 31, ... M2INFO = 51, Autre = 100)

- "utilisateurs" : la liste des utilisateurs (idUtilisateurs, login, password, droitAcces) (droit acces : stock = 5, tresorier = 10, president = 20, root = 42)
