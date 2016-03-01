#ifndef GAMEPADMSG_H
#define GAMEPADMSG_H

#include <QtCore>

typedef quint16 GamePadMsgType;

inline size_t getGamepadIndex( GamePadMsgType message_ )
{
    return message_ & 0x3;
}

inline bool isGamepadShutdown( GamePadMsgType message_ )
{
    return message_ & ( 1 << 2 );
}

#endif // GAMEPADMSG_H
