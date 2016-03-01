#ifndef FAKEGAMEPAD_H
#define FAKEGAMEPAD_H

#include <QObject>
#include <QTcpSocket>

#include "GamepadMsg.h"

class FakeGamepad : public QObject
{
    Q_OBJECT
public:
    explicit FakeGamepad(QObject *parent = 0);
    void connect();
    void send( GamePadMsgType message_ );
    GamePadMsgType getLoopbackMsg() const;
signals:

public slots:
    void sendedMessageLoopback( GamePadMsgType );
private:
    QTcpSocket client;
    GamePadMsgType loopbackMsg;
};

#endif // FAKEGAMEPAD_H
