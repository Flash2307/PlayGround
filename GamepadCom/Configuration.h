#ifndef CONFIGURATION_H_INCLUDED
#define CONFIGURATION_H_INCLUDED

#include <string>
#include <stdint.h>

#include "XBee.h"

namespace mbed
{

class Serial;

}

typedef uint8_t PanIdType [ PanIdByteCount ];
typedef uint8_t MacAdressType [ MacAdressByteCount ];

class Configuration
{    
public:
    Configuration( const char* configurationPath_, const char* hostConfigurationPath_ = "" );

    bool isCoordinator() const;
    size_t getSensorUpdateTimeMs() const;
    void getPanId( PanIdType panId_ ) const;
    void getMacAdress( MacAdressType macAdress_ ) const;
    std::string getHostname() const;
    
    void display( mbed::Serial& out ) const;
private:
    // Retourne vrai si la configuration a pu être lu correctement.
    bool loadHostNameConfiguration( const char* configurationPath );
    
    // Retourne vrai si la configuration a pu être lu correctement.
    bool loadConfiguration( const char* configurationPath );

    bool coordinatorRole;
    size_t sensorUpdateTimeMsc;
    PanIdType panId;
    MacAdressType coordinatorMacAdress;
    std::string hostname;
};

#endif
