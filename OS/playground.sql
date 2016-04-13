CREATE DATABASE `Playground` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `Playground`;

CREATE TABLE `Gamers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tag` varchar(45) NOT NULL,
  `picture` longblob NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;


CREATE TABLE `Games` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;


CREATE TABLE `HighScores` (
  `gamer_id` int(11) NOT NULL,
  `game_id` varchar(45) NOT NULL,
  `score` varchar(45) NOT NULL,
  PRIMARY KEY (`gamer_id`,`game_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
