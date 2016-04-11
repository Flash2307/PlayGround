#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QPixmap>

class Game
{
public:
    Game(int id, QString name, QString path, QString description, QPixmap picture)
        :id(id), name(name), path(path), description(description), picture(picture){}

    inline int getId() const {return id;}
    inline QString getPath() const {return path;}
    inline QString getName() const {return name;}
    inline QString getDescription() const {return description;}
    inline QPixmap getPicture() const {return picture;}

private:
    int id;
    QString name;
    QString path;
    QString description;
    QPixmap picture;
};

#endif // GAME_H
