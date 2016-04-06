#ifndef COORDINATORXBEE_H_INCLUDED
#define COORDINATORXBEE_H_INCLUDED

#include "XBee.h"

class TCPServerCom;
class Configuration;

class CoordinatorXbee
{
public:
    CoordinatorXbee();
    
    void exec( const Configuration& config_ );
    void collectAvaibleData();
protected:
    XBee xbee;
};

#endif
