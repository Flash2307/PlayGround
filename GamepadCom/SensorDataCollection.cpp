#include "SensorDataCollection.h"
#include "Util.h"

extern Serial terminal;

Sensors* pSensors = NULL;

Sensors::Sensors( const Configuration& config_ ) :
    accelerometer( mapPinNameFromIndex( config_.getAccSda() ), mapPinNameFromIndex( config_.getAccScl() ) ),
    aBtn( mapPinNameFromIndex( config_.getAKeyPinIndex() ) ),
    bBtn( mapPinNameFromIndex( config_.getBKeyPinIndex() ) ),
    downBtn( mapPinNameFromIndex( config_.getDownKeyPinIndex() ) ),
    upBtn( mapPinNameFromIndex( config_.getUpKeyPinIndex() ) ),
    leftBtn( mapPinNameFromIndex( config_.getLeftKeyPinIndex() ) ),
    rigthBtn( mapPinNameFromIndex( config_.getRigthKeyPinIndex() ) ),
    gamepadId( config_.getGamepadId() )
{

}

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
    
    if( pSensors == NULL ) 
    {
        cmd = 0;
        return cmd;
    }
    
    int aPress = pSensors->aBtn.read() ? 1 : 0;
    int bPress = pSensors->bBtn.read() ? 1 : 0;
    
    cmd = 0;
    pSensors->accelerometer.getXYZ( acc.x, acc.y, acc.z );
    
    acc.other = 0;
    acc.other |= ( pSensors->gamepadId & 0x3 ) | ( aPress << 7 ) | ( bPress << 8 );
    
    DEBUG_DISPLAY( terminal.printf( "x: %i\r\n", acc.x ) );
    DEBUG_DISPLAY( terminal.printf( "y: %i\r\n", acc.y ) );
    DEBUG_DISPLAY( terminal.printf( "z: %i\r\n", acc.z ) );
    DEBUG_DISPLAY( terminal.printf( "a: %i\r\n", aPress ) );
    DEBUG_DISPLAY( terminal.printf( "b: %i\r\n", bPress ) );
    DEBUG_DISPLAY( terminal.printf( "gamepadId: %i\r\n", pSensors->gamepadId ) );
    
    return cmd;
}

