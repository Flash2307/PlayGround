#include "GamePadCom.h"

GamePadCom::GamePadCom()
{
    QObject::connect( &server, SIGNAL( newConnection() ), this, SLOT( newConnection()) );

    if( !server.listen( QHostAddress::Any, Port ) )
    {
        qDebug() << "Fail to init server on port " << Port << '\n';
    }
}

void GamePadCom::stop()
{
    this->server.close();
}

void GamePadCom::newConnection()
{
    this->mbedBrige = this->server.nextPendingConnection();

    if( this->mbedBrige != nullptr )
    {
        QObject::connect( this->mbedBrige, SIGNAL( readyRead() ), this, SLOT( dataArrive() ) );
    }
}

void GamePadCom::dataArrive()
{
    if( this->mbedBrige != nullptr && this->mbedBrige->bytesAvailable() >= (qint64)sizeof( GamePadMsgType ) )
    {
        static_assert( sizeof( GamePadMsgType ) == 2, "Size mismatch." );

        QByteArray gamepadMsg = this->mbedBrige->read( sizeof( GamePadMsgType ) );
        GamePadMsgType msg = ( ( (GamePadMsgType)gamepadMsg[ 1 ] << 8 ) | gamepadMsg[ 0 ] );

        emit newMessageArrive( msg );
    }
}
