#ifndef COORDINATORXBEE_H_INCLUDED
#define COORDINATORXBEE_H_INCLUDED

#include "XBee.h"

class WebSocketCom;
class Configuration;

class CoordinatorXbee
{
public:
    CoordinatorXbee();
    
    void exec( const Configuration& config_ );
protected:
    XBee xbee;
};

#endif
