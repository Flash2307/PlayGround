#include "Util.h"

#include "mbed.h"

// Affiche un tableau en hexadecimal sur une communnication serial.
void displayHexArray( mbed::Serial& out, const uint8_t data[], size_t length )
{   
    for( size_t index = 0; index < length; ++index )
    {
        out.printf( "%2x ", data[ index ] );
    }
    
    out.printf( "\r\n" );
}


