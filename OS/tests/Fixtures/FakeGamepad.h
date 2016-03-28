#ifndef FAKEGAMEPAD_H
#define FAKEGAMEPAD_H

#include <QObject>
#include <QTcpSocket>
#include <QtSerialPort/QSerialPort>

#include "GamepadMsg.h"

class FakeGamepad : public QObject
{
    Q_OBJECT
public:
    FakeGamepad( const QString& serialPortName_ = QString(), QObject *parent = 0);
    void connect();
    void send( GamePadMsgType message_ );
    GamePadMsgType getLoopbackMsg() const;
signals:

public slots:
    void sendedMessageLoopback( GamePadMsgType );
private:
    QTcpSocket* pClient;
    QSerialPort* mbedSerialBridge;
    GamePadMsgType loopbackMsg;
    QString serialPortName;
};

#endif // FAKEGAMEPAD_H
