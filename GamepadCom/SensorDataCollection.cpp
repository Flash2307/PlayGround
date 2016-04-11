#include "SensorDataCollection.h"

Accelerometer accelerometer( p28, p27 );
DigitalOut aBtn( p5 );
DigitalOut bBtn( p6 );
size_t gamepadId;

extern Serial terminal;

// Prend les données de l'accéléromètre.
CommandType fetchAccelerometerData()
{
    union
    {
        struct
        {
            int16_t x;
            int16_t y;
            int16_t z;
            int16_t other;
        } acc;
        
        CommandType cmd;
    };
    
    int aPress = aBtn.read() ? 1 : 0;
    int bPress = bBtn.read() ? 1 : 0;
    
    cmd = 0;
    accelerometer.getXYZ( acc.x, acc.y, acc.z );
    
    acc.other = 0;
    acc.other |= ( gamepadId & 0x3 ) | ( aPress << 7 ) | ( bPress << 8 );
    
    DEBUG_DISPLAY( terminal.printf( "x: %i\r\n", acc.x ) );
    DEBUG_DISPLAY( terminal.printf( "y: %i\r\n", acc.y ) );
    DEBUG_DISPLAY( terminal.printf( "z: %i\r\n", acc.z ) );
    DEBUG_DISPLAY( terminal.printf( "a: %i\r\n", aPress ) );
    DEBUG_DISPLAY( terminal.printf( "b: %i\r\n", bPress ) );
    DEBUG_DISPLAY( terminal.printf( "gamepadId: %i\r\n", gamepadId ) );
    
    return cmd;
}

