#ifndef GAMEPADMSG_H
#define GAMEPADMSG_H

#include <cstdint>

constexpr static size_t MaxUser = 4;

typedef uint64_t GamePadMsgType;

union CommandFrame
{
    struct
    {
        int16_t x;
        int16_t y;
        int16_t z;
        int16_t other;
    } acc;

    GamePadMsgType cmd;
};

inline size_t getGamepadIndex( GamePadMsgType message_ )
{
    return message_ & 0x3;
}

inline bool isGamepadShutdown( GamePadMsgType message_ )
{
    return message_ & ( 1 << 2 );
}

inline bool isGamepadUpArrow( GamePadMsgType message_ )
{
    return message_ & ( 1 << 3 );
}

inline bool isGamepadDownArrow( GamePadMsgType message_ )
{
    return message_ & ( 1 << 4 );
}

inline bool isGamepadLeftArrow( GamePadMsgType message_ )
{
    return message_ & ( 1 << 5 );
}

inline bool isGamepadRigthArrow( GamePadMsgType message_ )
{
    return message_ & ( 1 << 6 );
}

inline bool isGamepadABtn( GamePadMsgType message_ )
{
    return message_ & ( 1 << 7 );
}

inline bool isGamepadBBtn( GamePadMsgType message_ )
{
    return message_ & ( 1 << 8 );
}

inline GamePadMsgType makeMessage(
                        size_t index_,
                        bool up = false,
                        bool down = false,
                        bool left = false,
                        bool rigth = false,
                        bool a = false,
                        bool b = false,
                        bool shutdown = false )
{
    return ( index_ & 0x3 ) |
           ( (GamePadMsgType)up << 3 ) |
           ( (GamePadMsgType)down << 4 ) |
           ( (GamePadMsgType)left << 5 ) |
           ( (GamePadMsgType)rigth << 6 ) |
           ( (GamePadMsgType)a << 7 ) |
           ( (GamePadMsgType)b << 8 ) |
           ( (GamePadMsgType)shutdown << 2 );
}

#endif // GAMEPADMSG_H
