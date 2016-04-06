// Fichier qui définit les fonctions et les objets pour le contrôle de l'accéléromètre.

#ifndef ACCELEROMETER_H_INCLUDED
#define ACCELEROMETER_H_INCLUDED

#include <stdint.h>

#include "mbed.h"
#include "Config.h"

class Accelerometer
{
public:
    Accelerometer( PinName sda_, PinName scl_ );
    void getXYZ( int16_t& x, int16_t& y, int16_t& z );
    
#if ENABLE_ACCELEROMETER == 1
private:
    mbed::I2C i2c;
#endif
};

#endif
