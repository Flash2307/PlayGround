#include "TCPServerCom.h"

#include "mbed.h"
#include "Config.h"

extern Serial terminal;

#define SERVER_PORT 5000

// Créé une connexion web socket et une connection ethernet.
TCPServerCom::TCPServerCom( const std::string& url_ )
{
    const char* serverAdress = url_.c_str();
    
    //eth.init(); //Use DHCP
    eth.init( "172.16.209.129", "255.255.255.0", "172.16.209.128" );
    eth.connect();
    DEBUG_DISPLAY( terminal.printf("IP Address is %s\n\r", eth.getIPAddress()); )
    /*
    while( socket.connect( serverAdress, SERVER_PORT ) < 0 ) 
    {
        DEBUG_DISPLAY(  terminal.printf("Unable to connect to (%s) on port (%d)\n\r", serverAdress, SERVER_PORT) );
        wait(1);
    }*/
    
    DEBUG_DISPLAY( terminal.printf( "Connected to Server at %s\n\r", serverAdress ) );
}

// Boucle de réception des données de la connexion websocket.
void TCPServerCom::echoData( const void* pData_ )
{
    enum { BUFFER_SIZE = 200 };
    
    TCPServerCom* webSockCom = (TCPServerCom*)pData_;
    char buffer[ BUFFER_SIZE ];
    
    while(1)
    {
        memset( buffer, 0, BUFFER_SIZE );

        if( size_t n = webSockCom->socket.receive( buffer, BUFFER_SIZE ) )
        {
            terminal.printf( "Websocket data received: %s\r\n", buffer );
        }      
        
        wait_ms( 10 );
    }
}

void TCPServerCom::send( CommandType val_ )
{
    socket.send_all( (char*)&val_, sizeof( CommandType ) );
}

// Envoi une chaine de caractère texte par la connection websocket.
void TCPServerCom::send( const std::string& str_ )
{
    socket.send_all( (char*)str_.c_str(), str_.size() );
}
