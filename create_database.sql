-- MySQL dump 10.13  Distrib 8.0.29, for Linux (x86_64)
--
-- Host: 127.0.0.1    Database: celebrite
-- ------------------------------------------------------
-- Server version	8.0.29-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `celeb_images`
--

DROP TABLE IF EXISTS `celeb_images`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `celeb_images` (
  `image` varchar(50) NOT NULL,
  `celeb_id` int NOT NULL,
  PRIMARY KEY (`image`),
  KEY `celeb_id` (`celeb_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `celeb_images`
--

LOCK TABLES `celeb_images` WRITE;
/*!40000 ALTER TABLE `celeb_images` DISABLE KEYS */;
/*!40000 ALTER TABLE `celeb_images` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `celeb_metiers`
--

DROP TABLE IF EXISTS `celeb_metiers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `celeb_metiers` (
  `celeb_id` int NOT NULL,
  `metier_id` int NOT NULL,
  PRIMARY KEY (`celeb_id`,`metier_id`),
  KEY `fk_metier_iid` (`metier_id`),
  CONSTRAINT `fk_celeb_id` FOREIGN KEY (`celeb_id`) REFERENCES `celebrites` (`celeb_id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `fk_metier_iid` FOREIGN KEY (`metier_id`) REFERENCES `metiers` (`metier_id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `celeb_metiers`
--

LOCK TABLES `celeb_metiers` WRITE;
/*!40000 ALTER TABLE `celeb_metiers` DISABLE KEYS */;
INSERT INTO `celeb_metiers` VALUES (1,1),(2,2),(3,3),(4,4),(5,6),(6,6),(7,7),(8,8),(9,9),(4,16),(5,17),(5,18);
/*!40000 ALTER TABLE `celeb_metiers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `celeb_pays`
--

DROP TABLE IF EXISTS `celeb_pays`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `celeb_pays` (
  `celeb_id` int NOT NULL,
  `pays_id` int NOT NULL,
  PRIMARY KEY (`celeb_id`,`pays_id`),
  KEY `fk_pays_id` (`pays_id`),
  CONSTRAINT `fk_celeb_id2` FOREIGN KEY (`celeb_id`) REFERENCES `celebrites` (`celeb_id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `fk_pays_id` FOREIGN KEY (`pays_id`) REFERENCES `pays` (`pays_id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `celeb_pays`
--

LOCK TABLES `celeb_pays` WRITE;
/*!40000 ALTER TABLE `celeb_pays` DISABLE KEYS */;
INSERT INTO `celeb_pays` VALUES (1,1),(2,1),(3,2),(4,2),(5,3),(6,4),(7,5),(8,6),(8,7),(9,7);
/*!40000 ALTER TABLE `celeb_pays` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `celebrites`
--

DROP TABLE IF EXISTS `celebrites`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `celebrites` (
  `celeb_id` int NOT NULL AUTO_INCREMENT,
  `nom` varchar(50) DEFAULT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `genre` enum('masculin','feminin','autre','') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`celeb_id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `celebrites`
--

LOCK TABLES `celebrites` WRITE;
/*!40000 ALTER TABLE `celebrites` DISABLE KEYS */;
INSERT INTO `celebrites` VALUES (1,'Thompson','Ken','masculin'),(2,'Jobs','Steve','masculin'),(3,'Lovelace','Ada','feminin'),(4,'Turing','Alan','masculin'),(5,'de Vinci','Léonard','masculin'),(6,'Picasso','Pablo','masculin'),(7,'Gagarine','Youri','masculin'),(8,'Curie','Marie','feminin'),(9,'D\'arc','Jeanne','feminin');
/*!40000 ALTER TABLE `celebrites` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `metiers`
--

DROP TABLE IF EXISTS `metiers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `metiers` (
  `metier_id` int NOT NULL AUTO_INCREMENT,
  `metier` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`metier_id`),
  UNIQUE KEY `metier` (`metier`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `metiers`
--

LOCK TABLES `metiers` WRITE;
/*!40000 ALTER TABLE `metiers` DISABLE KEYS */;
INSERT INTO `metiers` VALUES (9,' Bergère'),(2,' CEO'),(7,' Cosmonaute'),(3,' Développeur'),(1,' informaticien'),(4,' Mathématicien '),(6,' peintre'),(8,' Physicienne'),(18,'architecte'),(16,'Cryptologue'),(17,'sculpteur');
/*!40000 ALTER TABLE `metiers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pays`
--

DROP TABLE IF EXISTS `pays`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pays` (
  `pays_id` int NOT NULL AUTO_INCREMENT,
  `pays` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`pays_id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pays`
--

LOCK TABLES `pays` WRITE;
/*!40000 ALTER TABLE `pays` DISABLE KEYS */;
INSERT INTO `pays` VALUES (1,' USA'),(2,' Angleterre'),(3,' Italie'),(4,' Espagne'),(5,' URSS'),(6,' Pologne'),(7,' France');
/*!40000 ALTER TABLE `pays` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-30  7:09:49
