#include "Util.h"

// Affiche un tableau en hexadecimal sur une communnication serial.
void displayHexArray( mbed::Serial& out, const uint8_t data[], size_t length )
{   
    for( size_t index = 0; index < length; ++index )
    {
        out.printf( "%2x ", data[ index ] );
    }
    
    out.printf( "\r\n" );
}

PinName mapPinNameFromIndex( size_t pinIndex_ )
{
    switch( pinIndex_ )
    {
        case 5:
            return p5;
        case 6:
            return p6;
        case 7:
            return p7;
        case 8:
            return p8;
        case 9:
            return p9;
        case 10:
            return p10;
        case 11:
            return p11;
        case 12:
            return p12;
        case 13:
            return p13;
        case 14:
            return p14;
        case 16:
            return p16;
        case 17:
            return p17;
        case 18:
            return p18;
        case 19:
            return p19;
        case 20:
            return p20;
        case 21:
            return p21;
        case 22:
            return p22;
        case 23:
            return p23;
        case 24:
            return p24;
        case 25:
            return p25;
        case 26:
            return p26;
        case 27:
            return p27;
        case 28:
            return p28;
        case 29:
            return p29;
        case 30:
            return p30;
        default:
            break;
    };
    
    return p30;
}
