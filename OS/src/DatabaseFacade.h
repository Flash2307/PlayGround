#ifndef DATABASEFACADE_H
#define DATABASEFACADE_H

#include <vector>

#include <QString>
#include <QtSql/QSqlDatabase>

#include "Score.h"

class QSqlDatabase;
class Profile;

class DatabaseFacade
{
public:
    DatabaseFacade();
    ~DatabaseFacade();

    std::vector< Profile > getUsers();
    void addUserStat( int userId, const QString& gameName_, int score_ );
    std::vector< Score > getHightScores( const QString& gameName_, int limit_ );
private:
    void openConnexion();
    void closeConnection();

    bool connected;
    QSqlDatabase db;
};

#endif // DATABASEFACADE_H
