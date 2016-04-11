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
    size_t getGamepadId() const;
    void getPanId( PanIdType panId_ ) const;
    void getMacAdress( MacAdressType macAdress_ ) const;
    std::string getHostname() const;
    
    size_t getUpKeyPinIndex() const;
    size_t getDownKeyPinIndex() const;
    size_t getLeftKeyPinIndex() const;
    size_t getRigthKeyPinIndex() const;
    size_t getAKeyPinIndex() const;
    size_t getBKeyPinIndex() const;
    size_t getAccSda() const;
    size_t getAccScl() const;
    
    void display( mbed::Serial& out ) const;
private:
    // Retourne vrai si la configuration a pu être lu correctement.
    bool loadHostNameConfiguration( const char* configurationPath );
    
    // Retourne vrai si la configuration a pu être lu correctement.
    bool loadConfiguration( const char* configurationPath );

    bool coordinatorRole;
    size_t sensorUpdateTimeMsc;
    
    size_t gamepadId;
    size_t upKeyPinIndex;
    size_t downKeyPinIndex;
    size_t leftKeyPinIndex;
    size_t rigthKeyPinIndex;
    size_t aKeyPinIndex;
    size_t bKeyPinIndex;
    size_t accSda;
    size_t accScl;
    
    PanIdType panId;
    MacAdressType coordinatorMacAdress;
    std::string hostname;
};

#endif
