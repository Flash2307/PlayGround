#include "CoordinatorXbee.h"

#include "Config.h"
#include "Configuration.h"
#include "TCPServerCom.h"
#include "SensorDataCollection.h"
#include "Util.h"

extern Serial terminal;

enum { HeaderChar = '~' };

// Initialisation du coordinateur du xbee.
CoordinatorXbee::CoordinatorXbee() :
    xbee( p13, p14, p12 )
{
    
}

// Exécution du coodinateur, il ne fait que  reçevoir les données du xbee.
void CoordinatorXbee::exec( const Configuration& config_ )
{   
    this->xbee.reset();
    
    DEBUG_DISPLAY( config_.display( terminal ); )
    
    // Appel conditionnel à la boucle de xctu.
    CALL_XCTU_LOOP( XBee::xctuLink( this->xbee, terminal ); )
    
    this->xbee.init( config_ );
    
    DEBUG_DISPLAY( terminal.printf( "Coordinator ready.\r\n" ); )
    
    while(1) 
    {
        collectAvaibleData();
    }
}

// Tente de lire une trame de réception de données venant du xbee.
void CoordinatorXbee::collectAvaibleData()
{
    XBeeTrame xbeeTrame;
           
    if( xbee.receive( xbeeTrame ) )
    {       
        union
        {
            CommandType dataReceived;
            uint8_t rawData[ sizeof( CommandType ) ];
        };
        
        dataReceived = ( *(const CommandType*)xbeeTrame.trame.data );
                
        DEBUG_DISPLAY( displayHexArray( terminal, rawData, sizeof( CommandType ) ); )
        
        terminal.putc( HeaderChar );
        
        for( size_t index = 0; index < sizeof( CommandType ); ++index )
        {
            terminal.putc( rawData[ index ] );
        }
    }
}
    