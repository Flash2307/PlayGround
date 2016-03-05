#ifndef ENDPOINTXBEE_H_INCLUDED
#define ENDPOINTXBEE_H_INCLUDED

#include "Config.h"
#include "Configuration.h"
#include "XBee.h"
#include "Util.h"

// Point de colelcte de données.
// Ce xbee possède les capteurs.
class EndpointXbee
{
public:   
    EndpointXbee();
    
    void exec( const Configuration& config_ );
private:
    static void sendDataToCoordinator( const void* pData );

    XBee xbee;
    MacAdressType coordinatorMacAdress;
};    

#endif