#include "DatabaseFacade.h"

#include <QDebug>

#include "Profile.h"
#include <QSqlQuery>
#include <QSqlError>

#define DATABASE_IP "192.168.1.103"
#define DATABASE_NAME "Playground"
#define DATABASE_USER "playground2"
#define DATABASE_PASS "playground"

DatabaseFacade::DatabaseFacade() :
    connected(false),
    db(QSqlDatabase::addDatabase( "QMYSQL" ))
{
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
}

std::vector< Score > DatabaseFacade::getHightScores( const QString& gameName_ )
{
    std::vector< Score > scores;

    if(!connected)
    {
        qDebug() << "Not connected to database";
        return scores;
    }



    return scores;
}


