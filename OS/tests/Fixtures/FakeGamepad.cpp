#include "FakeGamepad.h"

#include "GamePadCom.h"

FakeGamepad::FakeGamepad(QObject *parent) :
    QObject(parent),
    loopbackMsg( 0 )
{
}

void FakeGamepad::connect()
{
    client.connectToHost( QString( "127.0.0.1" ), GamePadCom::Port );
}

void FakeGamepad::send( GamePadMsgType message_ )
{
    client.write( (char*)&message_, sizeof( message_ ) );
}

GamePadMsgType FakeGamepad::getLoopbackMsg() const
{
    return this->loopbackMsg;
}

void FakeGamepad::sendedMessageLoopback( GamePadMsgType message_ )
{
    this->loopbackMsg = message_;
}
