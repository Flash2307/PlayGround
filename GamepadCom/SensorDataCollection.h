#include "Accelerometer.h"

#include "Config.h"
#include "Configuration.h"

CommandType fetchAccelerometerData();

struct Sensors
{
    Sensors( const Configuration& config_ );
    
    Accelerometer accelerometer; //( p28, p27 );
    DigitalOut aBtn; //( p5 );
    DigitalOut bBtn; //( p6 );
    DigitalOut downBtn;
    DigitalOut upBtn;
    DigitalOut leftBtn;
    DigitalOut rigthBtn;
    size_t gamepadId;
};
    
