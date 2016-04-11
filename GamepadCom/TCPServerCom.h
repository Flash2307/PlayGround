#pragma once 

#include "EthernetInterface.h"

#include <string>

#include "Config.h"

class TCPServerCom
{
public:
    TCPServerCom( const std::string& url_ );
    
    static void echoData( const void* pData_ );
    
    void send( const std::string& str_ );
    void send( CommandType val_ );
private:
    EthernetInterface eth;
    TCPSocketConnection socket;
};

