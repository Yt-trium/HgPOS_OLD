# HgPOS
Hg Mercure POS

## Project
Hg POS est un logiciel de gestion d'un point de vente associatif.
Hg POS permet de gérer la vente, les stocks, les inscriptions...

###  TODO
- Création de la BDD de gestion de vente.
- Création du logiciel Client basique pour la vente.

### DONE
- Création du README





## VERSION AND REVISION
### VERSION ACTUEL : ALPHA 0





## Dev Section

## Database

### Database Rules
- nom de base de donnée "HgPOS"
- nom de table et colonne en CamelCase

### Database Structure
- "produits" : la liste des articles en vente (idProduit, nom, type, prix, img(link))
types : (snacks = 1, boissons = 2, sandwichs = 100, inscriptions = 200, remise = 250, default = 255)

> Une formule, c'est < snack + boisson + sandwichs + remise >.

- "vente" : la liste des articles vendus pendant l'exercice annuel. (idVente, idProduit)