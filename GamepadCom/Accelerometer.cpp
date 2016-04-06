// Fichier qui implémente les fonctions et les objets pour le contrôle de l'accéléromètre.

#include "Accelerometer.h"

#include "mbed.h"

#define MMA8452_OUT_X_MSB     0x01
#define MMA8452_XYZ_DATA_CFG  0x0E
#define MMA8452_SLAVE_ADRESS  0x3A
#define MMA8452_CTRL_REGISTER 0x2A

static uint16_t get12BitsValue( char* buf );
static void writeRegister( I2C& i2c, char registerAdress, char *data, int nbBytes ) ;
static void readRegister( I2C& i2c, int registerAdress, char buff[], size_t nbBytes );

#if ENABLE_ACCELEROMETER == 1

Accelerometer::Accelerometer( PinName sda_, PinName scl_ ) :
    i2c( sda_, scl_ )
{
    char data;
    
    readRegister( i2c, MMA8452_CTRL_REGISTER, &data, 1 );
    
    data = data | 5;
    data = data & 0x0FD;
    
    writeRegister( i2c, MMA8452_CTRL_REGISTER, &data, 1 );
    
    data = 0;
    writeRegister( i2c, MMA8452_XYZ_DATA_CFG, &data, 1 );
}

#else

Accelerometer::Accelerometer( PinName, PinName )
{
    
}

#endif

void Accelerometer::getXYZ( int16_t& x, int16_t& y, int16_t& z )
{
#if ENABLE_ACCELEROMETER == 1
    char coord[ 6 ];
    
    readRegister( this->i2c, MMA8452_OUT_X_MSB, coord, 6 );
    x = get12BitsValue( coord ) ;
    y = get12BitsValue( coord + 2 ) ;
    z = get12BitsValue( coord + 4 ) ;
#else
    x = 0;
    y = 0;
    z = 0;
#endif
}

#if ENABLE_ACCELEROMETER == 1

void writeRegister( I2C& i2c, char registerAdress, char *data, int nbBytes ) 
{
    if( nbBytes == 0 ) return;
    
    i2c.start();

    int ack = i2c.write( MMA8452_SLAVE_ADRESS );
    if( ack == 0 ) return;
    
    ack = i2c.write( registerAdress );
    if( ack == 0 ) return;

    for( int i = 0; i < nbBytes; i++ ) 
    {
       if( i2c.write(data[i]) != 1 ) 
       {
          return;
       }
    }
    
    i2c.stop();
}

void readRegister( I2C& i2c, int registerAdress, char buff[], size_t nbBytes )
{
    if( nbBytes == 0 ) return;
    
    i2c.start();        
    int ack = i2c.write( MMA8452_SLAVE_ADRESS );
    if( ack == 0 ) return;
    
    ack = i2c.write( registerAdress );
    if( ack == 0 ) return;
    
    i2c.start();
    ack = i2c.write( MMA8452_SLAVE_ADRESS | 1 );
    if( ack == 0 ) return;
        
    for( int i = 0; i < nbBytes; ++i )
    {
        buff[ i ] = i2c.read( i == nbBytes - 1 ? 0 : 1 );   
    }
  
    i2c.stop();
}

uint16_t get12BitsValue( char* buf )
{
   int16_t x = 0;

   ((char*)&x)[1] = buf[0];
   ((char*)&x)[0] = buf[1];

   return x >> 4;
} 

#endif
