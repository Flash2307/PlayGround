#ifndef GAMEPADMSGSERIALTEST_H
#define GAMEPADMSGSERIALTEST_H

#include <QtTest/QtTest>

class GamepadMsgSerialTest : public QObject
{
    Q_OBJECT
private slots:
    void testSendMessage();
};

#endif // GAMEPADMSGSERIALTEST_H
