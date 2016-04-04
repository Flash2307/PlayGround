#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#if _MSC_VER <= 2013
#   define constexpr const
#endif

#ifdef _MSC_VER
#   define COM_PORT_NAME "COM5"
#else
#   define COM_PORT_NAME "/dev/ttyACM0"
#endif

#endif // CONFIG_H

