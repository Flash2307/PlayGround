#ifndef GAMEPADCOM_H
#define GAMEPADCOM_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "GamepadMsg.h"

class GamePadCom : public QObject
{
    Q_OBJECT
public:
    enum { Port = 5000 };

    GamePadCom();
    void stop();
public slots:
    void newConnection();
    void dataArrive();
signals:
    void newMessageArrive( GamePadMsgType );
private:
    QTcpServer server;
    QTcpSocket* mbedBrige;
};

#endif // GAMEPADCOM_H
