#include <QApplication>

#include "HomeWindow.h"

#include "tests/GamepadMsgServerTest.h"

inline int runApp( int argc, char *argv[] )
{
    QApplication a(argc, argv);
    HomeWindow w;
    w.showMaximized();

    return a.exec();
}

int runTests(int argc, char *argv[])
{
    QApplication app( argc, argv ); app;

    GamepadMsgServerTest tc;
    QTest::qExec(&tc, argc, argv);

    return 0;
}

int main(int argc, char *argv[])
{
    // return runTests( argc, argv );
    return runApp( argc, argv );
}
