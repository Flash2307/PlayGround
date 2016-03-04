#include <QApplication>

#include "HomeWindow.h"

#include "tests/GamepadMsgServerTest.h"
#include "tests/UserProfilPageTest.h"

//#define TEST_BUILD

inline int runApp( int argc, char *argv[] )
{
    QApplication app(argc, argv);

    HomeWindow w;
    w.showMaximized();

    return app.exec();
}

int runTests(int argc, char *argv[])
{
    QApplication app( argc, argv ); app;

    GamepadMsgServerTest tc;
    QTest::qExec(&tc, argc, argv);

    UserProfilPageTest userProfilPageTest;
    QTest::qExec(&userProfilPageTest, argc, argv);

    return 0;
}

int main(int argc, char *argv[])
{
#ifdef TEST_BUILD
    return runTests( argc, argv );
#else
    return runApp( argc, argv );
#endif
}
