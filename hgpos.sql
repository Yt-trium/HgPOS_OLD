-- phpMyAdmin SQL Dump
-- version 4.5.5.1
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Jeu 04 Août 2016 à 22:59
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
  `totalReel` float NOT NULL,
  `erreurStock` float NOT NULL DEFAULT '0',
  `erreurCaisse` float NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `caisse`
--

INSERT INTO `caisse` (`idCaisse`, `date`, `totalTheorie`, `totalReel`, `erreurStock`, `erreurCaisse`) VALUES
(1, '2016-07-21 23:39:01', 4.5, 5, 0, 0),
(3, '2016-07-28 02:07:17', 14.5, 14.5, 0, 0),
(4, '2016-07-29 23:39:57', 10.8, 10.8, 0, 0),
(5, '2016-07-29 23:57:09', 0, 0, 0, 0),
(6, '2016-07-30 00:01:34', 1.7, 1.7, 0, 0),
(7, '2016-07-31 00:58:57', 10.5, 10.6, 0, 0),
(8, '2016-07-31 01:02:04', 0, 0, 0, 0),
(9, '2016-07-31 01:09:56', 10, 15, 4, 1),
(10, '2016-08-01 19:41:58', 11.5, 13, 1.2, 0.3),
(11, '2016-08-03 18:07:01', 20, 20.5, 0.5, 0);

-- --------------------------------------------------------

--
-- Structure de la table `membres`
--

CREATE TABLE `membres` (
  `idMembre` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `annee` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `membres`
--

INSERT INTO `membres` (`idMembre`, `nom`, `prenom`, `email`, `annee`) VALUES
(3, 'M', 'Cyril', 'cyril@m.m', 31),
(4, 'ab', 'bc', 'de', 100),
(5, 'ab', 'bc', 'azrazijroaizjr', 1),
(6, 'Meyer', 'Bernard', 'meyer.bernard@toto.fr', 100);

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
(6, 'Remise formule 0.50', 250, -0.5, ''),
(7, 'Kinder Bueno', 1, 0.6, 'bueno.png'),
(8, 'Kinder Maxi', 1, 0.3, ''),
(9, 'Coca Cola Zero', 2, 0.5, 'coca_zero.png'),
(10, 'Coca Cola', 2, 0.5, 'coca.png');

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
(1, 27),
(2, 30),
(3, 42),
(4, 44),
(5, 44),
(6, 45),
(7, 40),
(8, 48),
(9, 44),
(10, 47);

-- --------------------------------------------------------

--
-- Structure de la table `utilisateurs`
--

CREATE TABLE `utilisateurs` (
  `idUtilisateur` int(11) NOT NULL,
  `login` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `droitAcces` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `utilisateurs`
--

INSERT INTO `utilisateurs` (`idUtilisateur`, `login`, `password`, `droitAcces`) VALUES
(1, 'tresorier', 'tresorier', 10),
(2, 'stock', 'stock', 5),
(3, 'president', 'president', 20),
(4, 'root', 'root', 42);

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
(19, 5, '2016-07-27 20:59:54', 1),
(20, 2, '2016-07-28 01:40:49', 1),
(21, 1, '2016-07-28 02:02:25', 2),
(22, 2, '2016-07-28 02:07:35', 1),
(23, 2, '2016-07-28 13:38:10', 1),
(24, 1, '2016-07-28 13:38:19', 1),
(25, 2, '2016-07-28 13:56:04', 1),
(26, 1, '2016-07-28 13:56:19', 3),
(27, 1, '2016-07-28 13:56:37', 1),
(28, 1, '2016-07-28 13:56:44', 1),
(29, 1, '2016-07-28 13:57:01', 4),
(30, 2, '2016-07-28 13:57:23', 2),
(31, 1, '2016-07-28 13:57:23', 1),
(32, 2, '2016-07-28 14:01:20', 1),
(33, 7, '2016-07-28 14:47:38', 2),
(34, 10, '2016-07-28 14:52:38', 1),
(35, 7, '2016-07-28 14:53:18', 1),
(36, 2, '2016-07-29 23:59:22', 1),
(37, 7, '2016-07-29 23:59:22', 2),
(38, 2, '2016-07-31 00:58:06', 1),
(39, 9, '2016-08-01 19:35:36', 2),
(40, 2, '2016-08-01 19:35:36', 1),
(41, 3, '2016-08-01 19:44:51', 1),
(42, 1, '2016-08-01 19:44:51', 1),
(43, 9, '2016-08-01 19:44:51', 1),
(44, 6, '2016-08-01 19:44:51', 1),
(45, 10, '2016-08-01 22:54:20', 1),
(46, 10, '2016-08-02 00:16:41', 1),
(47, 9, '2016-08-03 18:04:03', 2);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `caisse`
--
ALTER TABLE `caisse`
  ADD PRIMARY KEY (`idCaisse`);

--
-- Index pour la table `membres`
--
ALTER TABLE `membres`
  ADD PRIMARY KEY (`idMembre`);

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
-- Index pour la table `utilisateurs`
--
ALTER TABLE `utilisateurs`
  ADD PRIMARY KEY (`idUtilisateur`),
  ADD UNIQUE KEY `login` (`login`);

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
  MODIFY `idCaisse` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT pour la table `membres`
--
ALTER TABLE `membres`
  MODIFY `idMembre` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT pour la table `produits`
--
ALTER TABLE `produits`
  MODIFY `idProduit` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT pour la table `utilisateurs`
--
ALTER TABLE `utilisateurs`
  MODIFY `idUtilisateur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `vente`
--
ALTER TABLE `vente`
  MODIFY `idVente` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=48;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
