#include "DatabaseFacade.h"

#include <QDebug>

#include <QtSql/QSqlDatabase>

DatabaseFacade::DatabaseFacade()
{
    openConnexion();
}

void DatabaseFacade::openConnexion()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL" );
    db.setHostName( "localhost" );
    db.setDatabaseName( "playground" );
    db.setUserName( "playground_user" );
    db.setPassword( "cNfYes5ptjLHcXAV" );
    bool ok = db.open();

    if( !ok )
    {
        qDebug() << "Connexio to database fail...";
    }
}

void DatabaseFacade::connectUser( const QString& username_ )
{

}

void DatabaseFacade::addUserStat( int userId, const QString& gameName_, int score_ )
{

}

std::vector< Score > DatabaseFacade::getHightScores( const QString& gameName_ )
{
    std::vector< Score > scores;

    return scores;
}


