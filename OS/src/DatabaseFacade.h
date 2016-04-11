#ifndef DATABASEFACADE_H
#define DATABASEFACADE_H

#include <vector>

#include <QString>
#include <QtSql/QSqlDatabase>

class QSqlDatabase;
class Profile;

struct Score
{
    QString userName;
    int score;
};

class DatabaseFacade
{
public:
    DatabaseFacade();
    ~DatabaseFacade();

    std::vector< Profile > getUsers();
    void addUserStat( int userId, const QString& gameName_, int score_ );
    std::vector< Score > getHightScores( const QString& gameName_ );
private:
    void openConnexion();
    void closeConnection();

    bool connected;
    QSqlDatabase db;
};

#endif // DATABASEFACADE_H
