#ifndef ENDPOINTXBEE_H_INCLUDED
#define ENDPOINTXBEE_H_INCLUDED

#include "Config.h"
#include "Configuration.h"
#include "XBee.h"
#include "TCPServerCom.h"
#include "SensorDataCollection.h"
#include "Util.h"
#include "XBee.h"

// Point de colelcte de données.
// Ce xbee possède les capteurs.
class EndpointXbee
{
public:
    typedef CommandType (*CollectSensorDataFn)();
    
    enum { SENSOR_COUNT = 1 };

    EndpointXbee();
    
    void exec( const Configuration& config_ );
    void processSensorData();
    
    void setCollectionFn( CollectSensorDataFn collectionFn, size_t index_ );
private:
    static void sendDataToCoordinator( const void* pData );

    XBee xbee;
    CollectSensorDataFn sensorDataCollectFn[ SENSOR_COUNT ];
    MacAdressType coordinatorMacAdress;
};    

#endif