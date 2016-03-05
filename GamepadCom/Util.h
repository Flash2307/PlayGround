#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdint.h>
#include <stddef.h>

namespace mbed
{

class Serial;

}

void displayHexArray( mbed::Serial& out, const uint8_t data[], size_t length );

#endif
