#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#define FAST_BAUD_RATE 1
#define USE_KEYBOARD_FOR_LOCAL_DEBUG 1
#define AUTO_DETECT_COM_PORT 0
#define NDEBUG 1

#if NDEBUG == 0
#   define SHOW_COMMAND_DATA
#endif

#if AUTO_DETECT_COM_PORT == 0
#   ifdef _MSC_VER
#       define COM_PORT_NAME "COM4"
#   else
#       define COM_PORT_NAME "/dev/ttyACM0"
#   endif
#   define CALL_AUTO_DETECT_COM_PORT( CALL )
#else
#   define CALL_AUTO_DETECT_COM_PORT( CALL ) CALL
#endif

#ifdef _MSC_VER
#   define GAME_APP_EXE_NAME "game.exe"
#else
#   define GAME_APP_EXE_NAME "game"
#endif

#if defined( _MSC_VER ) && _MSC_VER <= 2013
#   define constexpr const
#endif

#if FAST_BAUD_RATE == 1
#   define SERIAL_BAUD_RATE QSerialPort::Baud115200
#else
#   define SERIAL_BAUD_RATE QSerialPort::Baud9600
#endif

#if USE_KEYBOARD_FOR_LOCAL_DEBUG == 1
#   define ON_USE_GAMEPAD( CALL )
#else
#   define ON_USE_GAMEPAD( CALL ) CALL
#endif


#endif // CONFIG_H

