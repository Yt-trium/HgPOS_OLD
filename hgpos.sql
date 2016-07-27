-- phpMyAdmin SQL Dump
-- version 4.5.5.1
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mer 27 Juillet 2016 à 21:00
-- Version du serveur :  5.7.11
-- Version de PHP :  5.6.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `hgpos`
--

-- --------------------------------------------------------

--
-- Structure de la table `caisse`
--

CREATE TABLE `caisse` (
  `idCaisse` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `totalTheorie` float NOT NULL,
  `totalReel` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `caisse`
--

INSERT INTO `caisse` (`idCaisse`, `date`, `totalTheorie`, `totalReel`) VALUES
(1, '2016-07-21 23:39:01', 4.5, 5);

-- --------------------------------------------------------

--
-- Structure de la table `produits`
--

CREATE TABLE `produits` (
  `idProduit` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `type` tinyint(4) UNSIGNED DEFAULT '255',
  `prix` float NOT NULL,
  `img` varchar(255) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `produits`
--

INSERT INTO `produits` (`idProduit`, `nom`, `type`, `prix`, `img`) VALUES
(1, 'Ice Tea', 2, 0.5, ''),
(2, 'M&M\'s', 1, 0.5, ''),
(3, 'Poulet Curie', 100, 2.5, ''),
(4, 'Membre d\'honneur', 200, 0, ''),
(5, 'Membre', 200, 4, ''),
(6, 'Remise formule 0.50', 250, -0.5, '');

-- --------------------------------------------------------

--
-- Structure de la table `stock`
--

CREATE TABLE `stock` (
  `idProduit` int(11) NOT NULL,
  `quantite` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `stock`
--

INSERT INTO `stock` (`idProduit`, `quantite`) VALUES
(1, 50),
(2, 50);

-- --------------------------------------------------------

--
-- Structure de la table `vente`
--

CREATE TABLE `vente` (
  `idVente` int(11) NOT NULL,
  `idProduit` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `unite` int(11) NOT NULL DEFAULT '1'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `vente`
--

INSERT INTO `vente` (`idVente`, `idProduit`, `date`, `unite`) VALUES
(1, 1, '2016-07-21 23:24:28', 1),
(2, 1, '2016-07-21 23:24:28', 1),
(3, 3, '2016-07-21 23:24:28', 1),
(4, 4, '2016-07-21 23:24:49', 1),
(5, 2, '2016-07-21 23:34:25', 1),
(6, 1, '2016-07-21 23:34:25', 1),
(7, 1, '2016-07-21 23:39:41', 1),
(8, 3, '2016-07-27 20:32:28', 1),
(9, 1, '2016-07-27 20:52:43', 1),
(10, 1, '2016-07-27 20:52:43', 1),
(11, 1, '2016-07-27 20:58:33', 1),
(12, 1, '2016-07-27 20:58:33', 1),
(13, 2, '2016-07-27 20:58:33', 1),
(14, 2, '2016-07-27 20:58:33', 1),
(15, 6, '2016-07-27 20:59:50', 1),
(16, 3, '2016-07-27 20:59:50', 1),
(17, 2, '2016-07-27 20:59:50', 1),
(18, 1, '2016-07-27 20:59:50', 1),
(19, 5, '2016-07-27 20:59:54', 1);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `caisse`
--
ALTER TABLE `caisse`
  ADD PRIMARY KEY (`idCaisse`);

--
-- Index pour la table `produits`
--
ALTER TABLE `produits`
  ADD PRIMARY KEY (`idProduit`);

--
-- Index pour la table `stock`
--
ALTER TABLE `stock`
  ADD PRIMARY KEY (`idProduit`);

--
-- Index pour la table `vente`
--
ALTER TABLE `vente`
  ADD PRIMARY KEY (`idVente`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `caisse`
--
ALTER TABLE `caisse`
  MODIFY `idCaisse` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT pour la table `produits`
--
ALTER TABLE `produits`
  MODIFY `idProduit` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT pour la table `vente`
--
ALTER TABLE `vente`
  MODIFY `idVente` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
