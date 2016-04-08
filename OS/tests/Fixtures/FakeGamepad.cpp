#include "FakeGamepad.h"

#include <QSerialPortInfo>

#include "GamePadCom.h"

FakeGamepad::FakeGamepad( const QString& serialPortName_, QObject *parent ) :
    QObject(parent),
    pClient( NULL ),
    mbedSerialBridge( NULL ),
    loopbackMsg(),
    serialPortName( serialPortName_ )
{
}

void FakeGamepad::connect()
{
    if( serialPortName.isEmpty() )
    {
        pClient = new QTcpSocket( this );
        pClient->connectToHost( QString( "127.0.0.1" ), GamePadCom::Port );
    }
    else
    {
        QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

        foreach( QSerialPortInfo port, ports )
        {
            qDebug() << "description:" << port.description();
            qDebug() << "portName:" << port.portName();
        }

        mbedSerialBridge = new QSerialPort( this );
        mbedSerialBridge->setPortName( serialPortName );

        if( !mbedSerialBridge->open( QIODevice::ReadWrite ) )
        {
            qDebug() << "Fail to init serial port.";
        }
        else
        {
            mbedSerialBridge->setBaudRate( QSerialPort::Baud9600 );
            mbedSerialBridge->setDataBits( QSerialPort::Data8 );
            mbedSerialBridge->setParity( QSerialPort::NoParity );
            mbedSerialBridge->setStopBits( QSerialPort::OneStop );
        }
    }
}

void FakeGamepad::send( GamePadMsgType message_ )
{
    if( serialPortName.isEmpty() )
    {
        pClient->write( (char*)&message_, sizeof( message_ ) );
    }
    else
    {
        mbedSerialBridge->write( (char*)&message_, sizeof( message_ ) );
    }
}

GamePadMsgType FakeGamepad::getLoopbackMsg() const
{
    return this->loopbackMsg;
}

void FakeGamepad::sendedMessageLoopback( GamePadMsgType message_ )
{
    this->loopbackMsg = message_;
}
