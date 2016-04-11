#include "EndPointXbee.h"

#include <sstream>

extern Serial terminal;

// Mailbox pour la communication entre la prise de données
// et l'envoi de données par le xbee.
Mail< CommandType, 5 > dataCollectedMailbox;

// Initialisation d'un xbee routeur.
EndpointXbee::EndpointXbee() :
    xbee( p13, p14, p12 )
{
    std::fill( this->sensorDataCollectFn, this->sensorDataCollectFn + SENSOR_COUNT, (CollectSensorDataFn)NULL );
} 

void EndpointXbee::setCollectionFn( CollectSensorDataFn collectionFn_, size_t index_ )
{
    this->sensorDataCollectFn[ index_ ] = collectionFn_;
}

// Commence l'exécution de la capture des données.
void EndpointXbee::exec( const Configuration& config_ )
{
    const size_t triggerTimeRateMs = config_.getSensorUpdateTimeMs();
    Thread dataSender( &sendDataToCoordinator, this );
    
    this->xbee.reset();        
    config_.getMacAdress( this->coordinatorMacAdress );
    
    DEBUG_DISPLAY( config_.display( terminal ); )
    CALL_XCTU_LOOP( XBee::xctuLink( this->xbee, terminal ); )
    
    this->xbee.init( config_ );
    
    wait( 5 );
    
    while(1) 
    {
        processSensorData();         
        wait_ms( triggerTimeRateMs ); // Temps d'attente spécifier dans la configuration.    
    }
}

// Prends les données des capteurs.
void EndpointXbee::processSensorData()
{
    CommandType* pSensorData = dataCollectedMailbox.alloc();
    
    for( size_t index = 0; index < SENSOR_COUNT; ++index )
    {
        CollectSensorDataFn fn = this->sensorDataCollectFn[ index ];
        
        if( fn != NULL )
        {
            *pSensorData = fn();
        }  
    }
    
    dataCollectedMailbox.put( pSensorData );
    DEBUG_DISPLAY(  terminal.printf( "Data sended\r\n" ) );
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
            CommandType* pSensorData = (CommandType*)evt.value.p;  
            /*
            std::stringstream sensorValueStream;
            std::string sensorValues;
            
            sensorValueStream << *pSensorData;
            sensorValues = sensorValueStream.str();*/
            DEBUG_DISPLAY( displayHexArray( terminal, (const uint8_t*)pSensorData, sizeof(*pSensorData) ) );
            
            pEnpointXbee->xbee.sendTx( pEnpointXbee->coordinatorMacAdress, Coordinator16BitsAddress, (uint8_t*)pSensorData, sizeof(*pSensorData) );              
            dataCollectedMailbox.free( pSensorData );
        }
        else DEBUG_DISPLAY(  terminal.printf( "Unexpected data received\r\n" ) );
    }
}
    
    