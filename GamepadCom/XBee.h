#ifndef XBEE_H_INCLUDED
#define XBEE_H_INCLUDED

#include "mbed.h"

class Configuration;

enum 
{ 
    PanIdByteCount = 8, 
    MacAdressByteCount = 8,
    StartDelimiter = 0x7E,
    EscapeByte = 0x7D,
    XON = 0x11,
    XOFF = 0x13,
    TransmitStatus = 0x8B,
    Coordinator16BitsAddress = 0
};

struct XBeeTrame
{
    struct Trame
    {
        uint16_t size;
        uint8_t frameType;
        uint8_t macAdress[ MacAdressByteCount ];
        uint16_t adress16Bits; 
        //uint8_t receiveOption;
        uint8_t data[ 40 ];
        uint8_t checksum;
    };

    union
    {
        Trame trame;
        uint8_t rawData[ sizeof( Trame ) ];
    };
    
    size_t lastValueIndex;
};

class XBee
{
public:
    XBee( PinName tx_, PinName rx_, PinName rst_ );
    
    static void xctuLink( XBee& xbee_, Serial& terminal );

    void init( uint8_t panId[ PanIdByteCount ] );
    void init( const Configuration& config_ );
    
    void reset();
    void flushReceiveBuffer();
    void sendTx( const uint8_t macAdress[ MacAdressByteCount ], uint16_t adress16Bits, const uint8_t data[], size_t length );
    void sendTransmitStatus( uint16_t adress16Bits );
    bool receive( XBeeTrame& xbeeTrame_ );
    
    Serial& serialRef();
private:
    Serial xbeeIO;
    DigitalOut rst;
};

#endif
