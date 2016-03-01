#ifndef USERPROFILPAGETEST_H
#define USERPROFILPAGETEST_H

#include <QObject>

class UserProfilPageTest : public QObject
{
    Q_OBJECT
public:
    UserProfilPageTest();
private slots:
    void testConnexion();
};

#endif // USERPROFILPAGETEST_H
