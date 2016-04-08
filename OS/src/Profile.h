#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QPixmap>

class Profile
{
public:
    Profile(int id, QString name, QPixmap picture)
        :id(id), name(name), picture(picture){}

    inline int getId() const {return id;}
    inline QString getName() const {return name;}
    inline QPixmap getPicture() const {return picture;}

private:
    int id;
    QString name;
    QPixmap picture;
};

#endif // PROFILE_H
