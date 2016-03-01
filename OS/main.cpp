#include <QApplication>

#include "HomeWindow.h"

#include "tests/GamepadMsgServerTest.h"

QString readFiles( const QStringList& files )
{
    QString result;

    foreach (QString file, files)
    {
        QFile f(file);
        if (!f.open(QFile::ReadOnly | QFile::Text)) break;
        QTextStream in(&f);
        result.append( in.readAll() );
    }
qDebug() << result << '\n';
    return result;
}


inline int runApp( int argc, char *argv[] )
{
    QApplication app(argc, argv);
    app.setStyleSheet( readFiles( QStringList() << "css/GameProfil.css" ) );

    HomeWindow w;
    w.showMaximized();

    return app.exec();
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
