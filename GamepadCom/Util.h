#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdint.h>
#include <stddef.h>

#include "mbed.h"

void displayHexArray( mbed::Serial& out, const uint8_t data[], size_t length );
PinName mapPinNameFromIndex( size_t pinIndex_ );

#endif
