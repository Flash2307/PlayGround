#include "DatabaseFacade.h"

#include <QDebug>

#include "Profile.h"
#include <QSqlQuery>
#include <QSqlError>

#define DATABASE_IP "192.168.0.101"
#define DATABASE_NAME "Playground"
#define DATABASE_USER "playground2"
#define DATABASE_PASS "playground"

DatabaseFacade::DatabaseFacade() :
    connected(false),
    db(QSqlDatabase::addDatabase( "QMYSQL" ))
{
    qDebug() << "DATABASE CTR" ;
    openConnexion();
}

DatabaseFacade::~DatabaseFacade()
{
    closeConnection();
}

void DatabaseFacade::openConnexion()
{
    db.setHostName( DATABASE_IP );
    db.setDatabaseName( DATABASE_NAME );
    db.setUserName( DATABASE_USER );
    db.setPassword( DATABASE_PASS );

    connected = db.open();

    if(!connected)
    {
        qDebug() << "Connexion to database failed";
        QSqlError err = db.lastError();
        qDebug() << err.databaseText() << "\n" << err.driverText() << "\n" << err.nativeErrorCode();
    }

}

void DatabaseFacade::closeConnection()
{
    db.close();
    connected = db.isOpen();

    if(connected)
        qDebug() << "Database close failed";
}

std::vector< Profile > DatabaseFacade::getUsers()
{
    std::vector<Profile> profiles;

    if(!connected)
    {
        qDebug() << "Not connected to database";
        return profiles;
    }

    QSqlQuery query;
    query.exec("SELECT * FROM Gamers");

    QSqlError err = query.lastError();
    qDebug() << err.databaseText() << "\n" << err.driverText() << "\n" << err.nativeErrorCode();
    
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();

        QPixmap picture;
        picture.loadFromData(query.value(2).toByteArray());

        profiles.emplace_back(id, name, picture);
    }

    query.clear();

    return profiles;
}

void DatabaseFacade::addUserStat( int userId, const QString& gameName_, int score_ )
{
    if(!connected)
    {
        qDebug() << "Not connected to database";
        return;
    }

    QSqlQuery query;
    QSqlQuery query2;
    query.exec("SELECT Games.id "
               "FROM HighScores "
               "INNER JOIN Games ON Games.id = HighScores.game_id "
               "WHERE Games.name = " + gameName_ + " AND HighScores.gamer_id = " + userId + ";");

    QSqlError err = query.lastError();
    qDebug() << err.databaseText() << "\n" << err.driverText() << "\n" << err.nativeErrorCode();

    if(query.next())
    {
        query2.exec(QString("UPDATE HighScores SET HighScores.score = %1 "
                            "WHERE HighScores.game_id = %2 AND HighScores.gamer_id = %3;").arg(score_).arg(query.value(0).toString()).arg(userId));
    }
    else
    {
        query2.exec(QString("INSERT INTO HighScores VALUES(%1, (SELECT Games.id FROM Games WHERE Games.name = %2), %3)").arg(userId).arg(gameName_).arg(score_));
    }
}

std::vector< Score > DatabaseFacade::getHightScores( const QString& gameName_ )
{
    std::vector< Score > scores;

    if(!connected)
    {
        qDebug() << "Not connected to database";
        return scores;
    }

    QSqlQuery query;
    query.exec("SELECT Gamers.name, HighScores.score FROM HighScores INNER JOIN Games on Games.id = HighScores.game_id WHERE Games.name = " + gameName_ + ";");

    QSqlError err = query.lastError();
    qDebug() << err.databaseText() << "\n" << err.driverText() << "\n" << err.nativeErrorCode();

    while (query.next())
    {
        QString name = query.value(0).toString();
        int score = query.value(1).toInt();

        scores.emplace_back(name, score);
    }

    query.clear();

    return scores;
}


