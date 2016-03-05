#include "CoordinatorXbee.h"

#include "EthernetInterface.h"

#include "Config.h"
#include "Configuration.h"
#include "Util.h"

extern Serial terminal;

// Initialisation du coordinateur du xbee.
CoordinatorXbee::CoordinatorXbee() :
    xbee( p13, p14, p12 )
{
    
}

// Exécution du coodinateur, il ne fait que  reçevoir les données du xbee.
void CoordinatorXbee::exec( const Configuration& config_ )
{        
    EthernetInterface eth;
    eth.init(); //Use DHCP
    eth.connect();
    printf("IP Address is %s\n", eth.getIPAddress());
    
    TCPSocketConnection sock;
    sock.connect( "mbed.org", 5000 );
    
    XBeeTrame xbeeTrame;
    
    this->xbee.reset();
    DEBUG_DISPLAY( config_.display( terminal ); )
    CALL_XCTU_LOOP( XBee::xctuLink( this->xbee, terminal ); )
    
    this->xbee.init( config_ );
    
    while(1) 
    {
        if( xbee.receive( xbeeTrame ) )
        {
            DEBUG_DISPLAY( terminal.printf( "Received: %i\r\n", *(uint16_t*)xbeeTrame.trame.data ); )
            sock.send( (char*)xbeeTrame.trame.data, sizeof( uint16_t ) );
        }
    }
}

    