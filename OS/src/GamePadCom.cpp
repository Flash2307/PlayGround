#include "GamePadCom.h"

#include <QtEndian>

#include <cassert>

static void printBytes( const QByteArray& bytes_ )
{
    for( int index = 0; index < bytes_.size(); ++index )
    {
        char c = bytes_[ index ];
        unsigned char uc = c;
        unsigned int i = uc;

        qDebug() << "byte: " << QString("%1").arg(i , 0, 16);
    }
}

GamePadCom::GamePadCom( const QString& serialPortName_ ) :
    server( NULL ),
    mbedBrige( NULL ),
    mbedSerialBridge( NULL )
{
    if( serialPortName_.isEmpty() )
    {
        server = new QTcpServer( this );
        QObject::connect( server, SIGNAL( newConnection() ), this, SLOT( newConnection()) );

        if( !server->listen( QHostAddress::Any, Port ) )
        {
            qDebug() << "Fail to init server on port " << Port << '\n';
        }
    }
    else
    {
        mbedSerialBridge = new QSerialPort( this );
        mbedSerialBridge->setPortName( serialPortName_ );

        if( !mbedSerialBridge->open( QIODevice::ReadWrite ) )
        {
            qDebug() << "Fail to init serial port.";
        }
        else
        {
            mbedSerialBridge->setBaudRate( SERIAL_BAUD_RATE );
            mbedSerialBridge->setDataBits( QSerialPort::Data8 );
            mbedSerialBridge->setParity( QSerialPort::NoParity );
            mbedSerialBridge->setStopBits( QSerialPort::OneStop );
            mbedSerialBridge->setFlowControl( QSerialPort::NoFlowControl );
        }

        connect( this->mbedSerialBridge, &QSerialPort::readyRead, this, &GamePadCom::dataArrive );
    }
}

void GamePadCom::stop()
{
    if( this->server != NULL ) this->server->close();
    if( this->mbedSerialBridge != NULL ) this->mbedSerialBridge->close();
}

void GamePadCom::newConnection()
{
    this->mbedBrige = this->server->nextPendingConnection();

    if( this->mbedBrige != nullptr )
    {
        QObject::connect( this->mbedBrige, SIGNAL( readyRead() ), this, SLOT( dataArrive() ) );
    }
}

void GamePadCom::dataArrive()
{
    constexpr static int HeaderChar = '~';

    QIODevice* pDevice = NULL;

    if( mbedSerialBridge == NULL )
    {
        pDevice = mbedBrige;
    }
    else
    {
        pDevice = mbedSerialBridge;
    }

    if( pDevice != nullptr )
    {
        char skip = '\0';

        while( ( pDevice->peek( &skip, 1 ), skip ) != HeaderChar && pDevice->bytesAvailable() > 0 )
        {
            pDevice->getChar( &skip );
        }

        if( ( pDevice->peek( &skip, 1 ), skip ) == HeaderChar &&
            pDevice->bytesAvailable() >= (qint64)( sizeof( GamePadMsgType ) + 1 ) )
        {
            pDevice->getChar( &skip );

            QByteArray gamepadMsg = pDevice->read( sizeof( GamePadMsgType ) );
            GamePadMsgType msg;

            assert( (char)gamepadMsg[ 0 ] != HeaderChar );
            memcpy( &msg, gamepadMsg.data(), sizeof( msg ) );

            emit newMessageArrive( msg );
        }
    }




}
