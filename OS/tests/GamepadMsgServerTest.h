#ifndef GAMEPADMSGSERVERTEST_H
#define GAMEPADMSGSERVERTEST_H

#include <QtTest/QtTest>

class GamepadMsgServerTest : public QObject
{
    Q_OBJECT
private slots:
    void testSendMessage();
};

#endif // GAMEPADMSGSERVERTEST_H
