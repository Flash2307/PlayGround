#ifndef GAMEPADCOM_H
#define GAMEPADCOM_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtSerialPort/QSerialPort>

#include "GamepadMsg.h"

class GamePadCom : public QObject
{
    Q_OBJECT
public:
    enum { Port = 5000 };

    GamePadCom( const QString& serialPortName_ = QString() );
    void stop();
public slots:
    void newConnection();
    void dataArrive();
signals:
    void newMessageArrive( GamePadMsgType );
private:
    QTcpServer* server;
    QTcpSocket* mbedBrige;
    QSerialPort* mbedSerialBridge;
};

#endif // GAMEPADCOM_H
