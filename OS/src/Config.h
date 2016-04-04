#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#define FAST_BAUD_RATE 1

#if _MSC_VER <= 2013
#   define constexpr const
#endif

#ifdef _MSC_VER
#   define COM_PORT_NAME "COM5"
#else
#   define COM_PORT_NAME "/dev/ttyACM0"
#endif

#if FAST_BAUD_RATE == 1
#   define SERIAL_BAUD_RATE QSerialPort::Baud115200
#else
#   define SERIAL_BAUD_RATE QSerialPort::Baud9600
#endif

#endif // CONFIG_H

