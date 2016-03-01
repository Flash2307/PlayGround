#include "UserProfilPageTest.h"

#include <QTest>

#include "HomeWindow.h"

UserProfilPageTest::UserProfilPageTest()
{
}

void UserProfilPageTest::testConnexion()
{
    HomeWindow window;
    window.show();

    QVERIFY( window.isOnProfilPage() );

    window.newMessageArrive( makeMessage( 1 ) );
    window.newMessageArrive( makeMessage( 2 ) );
    window.newMessageArrive( makeMessage( 1, false, false, false, false, true ) );
    window.newMessageArrive( makeMessage( 2, false, false, false, false, true ) );

    QTimer::singleShot( 1000, qApp, SLOT( quit() ) );
    qApp->exec();

    QVERIFY( window.isOnGameSelectionPage() );
}
