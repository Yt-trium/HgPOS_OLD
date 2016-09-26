-- phpMyAdmin SQL Dump
-- version 4.6.4
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Sep 26, 2016 at 11:29 AM
-- Server version: 10.1.17-MariaDB
-- PHP Version: 7.0.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `HgPOS`
--

-- --------------------------------------------------------

--
-- Table structure for table `caisse`
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
-- Dumping data for table `caisse`
--

INSERT INTO `caisse` (`idCaisse`, `date`, `totalTheorie`, `totalReel`, `erreurStock`, `erreurCaisse`) VALUES
(1, '2016-09-26 11:24:58', 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `membres`
--

CREATE TABLE `membres` (
  `idMembre` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `annee` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `membres`
--

INSERT INTO `membres` (`idMembre`, `nom`, `prenom`, `email`, `annee`) VALUES
(1, 'Administrateur', 'Système', 'cyril@adem.u-strasbg.fr', 100);

-- --------------------------------------------------------

--
-- Table structure for table `produits`
--

CREATE TABLE `produits` (
  `idProduit` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `type` tinyint(4) UNSIGNED DEFAULT '255',
  `prix` float NOT NULL,
  `img` varchar(255) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `produits`
--

INSERT INTO `produits` (`idProduit`, `nom`, `type`, `prix`, `img`) VALUES
(1, 'Chips', 1, 0.3, 'chips.png'),
(2, 'Prince', 1, 0.3, 'prince.png'),
(3, 'Kinder Maxi', 1, 0.3, 'kinder_maxi.png'),
(4, 'Kinder Country', 1, 0.3, 'kinder_country.png'),
(5, 'Lion', 1, 0.5, 'lion.png'),
(6, 'Snickers', 1, 0.5, 'snickers.png'),
(7, 'Oréo', 1, 0.5, 'oreo.png'),
(8, 'Kit-Kat', 1, 0.5, 'kit_kat.png'),
(9, 'Kit-Kat Ball', 1, 0.5, 'kit_kat_ball.png'),
(10, 'M&M\'s', 1, 0.5, 'm_m_s.png'),
(11, 'Twix', 1, 0.5, 'twix.png'),
(12, 'Kinder Délice', 1, 0.5, 'kinder_delice.png'),
(13, 'Mars', 1, 0.5, 'mars.png'),
(14, 'Kinder Bueno', 1, 0.6, 'kinder_bueno.png'),
(15, 'Coca Cola', 2, 0.5, 'coca_cola.png'),
(16, 'Coca Cola Zéro', 2, 0.5, 'coca_cola_zero.png'),
(17, 'Coca Cola Cherry', 2, 0.5, 'coca_cola_cherry.png'),
(18, 'Schweppes', 2, 0.5, 'schweppes.png'),
(19, 'Oasis', 2, 0.5, 'oasis.png'),
(20, 'Ice Tea', 2, 0.5, 'ice_tea.png'),
(21, 'Orangina', 2, 0.5, 'orangina.png'),
(22, 'Sprite', 2, 0.5, 'sprite.png'),
(23, 'Fanta', 2, 0.5, 'fanta.png'),
(24, 'Eau', 2, 0.3, 'eau.png'),
(25, 'Capri-Sun', 2, 0.3, 'capri_sun.png'),
(26, 'Impression Amicaliste', 5, 0.03, 'impression_amicaliste.png'),
(27, 'Impression Non-Amicaliste', 5, 0.05, 'impression_non_amicaliste.png'),
(28, 'Pin\'s', 6, 2, 'pins.png'),
(29, 'Tasse', 6, 7, 'tasse.png'),
(30, 'Eco-Cup', 6, 1, 'eco_cup.png'),
(31, 'Polo', 6, 10, 'polo.png'),
(32, 'Pi-Shirt', 7, 3.14, 'pi_shirt.png'),
(33, 'Badge Pi', 7, 0.78, 'badge_pi.png'),
(34, 'Sandwich', 100, 2.5, 'sandwich.png'),
(35, 'Inscription', 200, 4, 'inscription.png'),
(36, 'Inscription Membre d\'Honneur', 200, 0, 'inscription.png'),
(37, 'Remise 0.10', 250, -0.1, 'remise.png'),
(38, 'Remise 0.30', 250, -0.3, 'remise.png'),
(39, 'Remise 0.50', 250, -0.5, 'remise.png');

-- --------------------------------------------------------

--
-- Table structure for table `stock`
--

CREATE TABLE `stock` (
  `idProduit` int(11) NOT NULL,
  `quantite` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `stock`
--

INSERT INTO `stock` (`idProduit`, `quantite`) VALUES
(1, 100),
(2, 100),
(3, 100),
(4, 100),
(5, 100),
(6, 100),
(7, 100),
(8, 100),
(9, 100),
(10, 100),
(11, 100),
(12, 100),
(13, 100),
(14, 100),
(15, 100),
(16, 100),
(17, 100),
(18, 100),
(19, 100),
(20, 100),
(21, 100),
(22, 100),
(23, 100),
(24, 100),
(25, 100),
(26, 100),
(27, 100),
(28, 100),
(29, 100),
(30, 100),
(31, 100),
(32, 100),
(33, 100),
(34, 100),
(35, 100),
(36, 100),
(37, 100),
(38, 100),
(39, 100),
(40, 100);

-- --------------------------------------------------------

--
-- Table structure for table `utilisateurs`
--

CREATE TABLE `utilisateurs` (
  `idUtilisateur` int(11) NOT NULL,
  `login` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `droitAcces` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `utilisateurs`
--

INSERT INTO `utilisateurs` (`idUtilisateur`, `login`, `password`, `droitAcces`) VALUES
(1, 'root', 'root', 42);

-- --------------------------------------------------------

--
-- Table structure for table `vente`
--

CREATE TABLE `vente` (
  `idVente` int(11) NOT NULL,
  `idProduit` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `unite` int(11) NOT NULL DEFAULT '1'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `caisse`
--
ALTER TABLE `caisse`
  ADD PRIMARY KEY (`idCaisse`);

--
-- Indexes for table `membres`
--
ALTER TABLE `membres`
  ADD PRIMARY KEY (`idMembre`);

--
-- Indexes for table `produits`
--
ALTER TABLE `produits`
  ADD PRIMARY KEY (`idProduit`);

--
-- Indexes for table `stock`
--
ALTER TABLE `stock`
  ADD PRIMARY KEY (`idProduit`);

--
-- Indexes for table `utilisateurs`
--
ALTER TABLE `utilisateurs`
  ADD PRIMARY KEY (`idUtilisateur`),
  ADD UNIQUE KEY `login` (`login`);

--
-- Indexes for table `vente`
--
ALTER TABLE `vente`
  ADD PRIMARY KEY (`idVente`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `caisse`
--
ALTER TABLE `caisse`
  MODIFY `idCaisse` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `membres`
--
ALTER TABLE `membres`
  MODIFY `idMembre` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `produits`
--
ALTER TABLE `produits`
  MODIFY `idProduit` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=40;
--
-- AUTO_INCREMENT for table `utilisateurs`
--
ALTER TABLE `utilisateurs`
  MODIFY `idUtilisateur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `vente`
--
ALTER TABLE `vente`
  MODIFY `idVente` int(11) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
