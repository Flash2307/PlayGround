#include "EndPointXbee.h"

#include "rtos.h"
#include <stdint.h>

extern Serial terminal;

// Mailbox pour la communication entre la prise de données
// et l'envoi de données par le xbee.
Queue< uint16_t, 5 > dataCollectedMailbox;

// Initialisation d'un xbee routeur.
EndpointXbee::EndpointXbee() :
    xbee( p13, p14, p12 )
{

} 

// Commence l'exécution de la capture des données.
void EndpointXbee::exec( const Configuration& config_ )
{
    const size_t triggerTimeRateMs = config_.getSensorUpdateTimeMs();
    Thread dataSender( &sendDataToCoordinator, this );
    
    this->xbee.reset();        
    config_.getMacAdress( this->coordinatorMacAdress );
    
    DEBUG_DISPLAY( config_.display( terminal ); )
    CALL_XCTU_LOOP( XBee::xctuLink(  this->xbee, terminal ); )
    
    this->xbee.init( config_ );
    
    wait( 5 );
    
    while(1) 
    {
        uint16_t value = 1;
        
        dataCollectedMailbox.put( (uint16_t*)value );
        DEBUG_DISPLAY(  terminal.printf( "Data sended\r\n" ) );     
        wait_ms( triggerTimeRateMs ); // Temps d'attente spécifier dans la configuration.    
    }
}

// Thread d'envoi de données au coordinateur.
void EndpointXbee::sendDataToCoordinator( const void* pData )
{
    EndpointXbee* pEnpointXbee = (EndpointXbee*)pData;
    
    while(1)
    {
        osEvent evt = dataCollectedMailbox.get();
        
        if( evt.status == osEventMail ) 
        {
            uint16_t gamepadState = (uint16_t)evt.value.p;  
            DEBUG_DISPLAY( terminal.printf( "Data: %s \r\n", gamepadState ) );
            
            pEnpointXbee->xbee.sendTx( pEnpointXbee->coordinatorMacAdress, Coordinator16BitsAddress, (uint8_t*)&gamepadState, sizeof( uint16_t ) );
        }
        else DEBUG_DISPLAY(  terminal.printf( "Unexpected data received\r\n" ) );
    }
}
    
    