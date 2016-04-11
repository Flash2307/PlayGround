#ifndef GAMEPADMSG_H
#define GAMEPADMSG_H

#include <cstdint>

#include "Config.h"

constexpr size_t GameDestinationPort = 7755;
constexpr static size_t MaxUser = 4;
constexpr static int UpArrowBitNum = 3;
constexpr static int DownArrowBitNum = 4;
constexpr static int LeftArrowBitNum = 5;
constexpr static int RigthArrowBitNum = 6;
constexpr static int ABtnBitNum = 7;
constexpr static int BBtnBitNum = 8;

union CommandFrame
{
    CommandFrame()
    {
        cmd = 0;
    }

    explicit CommandFrame(uint64_t cmd_)
    {
        cmd = cmd_;
    }

    struct
    {
        int16_t x;
        int16_t y;
        int16_t z;
        int16_t other;
    } acc;

    uint64_t cmd;
};

typedef CommandFrame GamePadMsgType;

inline size_t getGamepadIndex( GamePadMsgType message_ )
{
    return message_.acc.other & 0x3;
}

inline bool isGamepadShutdown( GamePadMsgType message_ )
{
    return message_.acc.other & ( 1 << 2 );
}

inline bool isGamepadUpArrow( GamePadMsgType message_ )
{
    return message_.acc.other & ( 1 << 3 );
}

inline bool isGamepadDownArrow( GamePadMsgType message_ )
{
    return message_.acc.other & ( 1 << 4 );
}

inline bool isGamepadLeftArrow( GamePadMsgType message_ )
{
    return message_.acc.other & ( 1 << 5 );
}

inline bool isGamepadRigthArrow( GamePadMsgType message_ )
{
    return message_.acc.other & ( 1 << 6 );
}

inline bool isGamepadABtn( GamePadMsgType message_ )
{
    return message_.acc.other & ( 1 << 7 );
}

inline bool isGamepadBBtn( GamePadMsgType message_ )
{
    return message_.acc.other & ( 1 << 8 );
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
    GamePadMsgType cmd;

    cmd.acc.other =
           ( index_ & 0x3 ) |
           ( (uint16_t)up << UpArrowBitNum ) |
           ( (uint16_t)down << 4 ) |
           ( (uint16_t)left << 5 ) |
           ( (uint16_t)rigth << 6 ) |
           ( (uint16_t)a << 7 ) |
           ( (uint16_t)b << 8 ) |
           ( (uint16_t)shutdown << 2 );

    return cmd;
}

inline GamePadMsgType& setUpArrow( GamePadMsgType& message_, bool enable_ )
{
    message_.acc.other = enable_ ?
                ( message_.acc.other | ( 1 << UpArrowBitNum ) ) :
                ( message_.acc.other & ~( 1 << UpArrowBitNum ) );

    return message_;
}

inline GamePadMsgType& setDownArrow( GamePadMsgType& message_, bool enable_ )
{
    message_.acc.other = enable_ ? ( message_.acc.other | ( 1 << DownArrowBitNum ) ) : ( message_.acc.other & ~( 1 << DownArrowBitNum ) );
    return message_;
}

inline GamePadMsgType& setLeftArrow( GamePadMsgType& message_, bool enable_ )
{
    message_.acc.other = enable_ ?
                ( message_.acc.other | ( 1 << LeftArrowBitNum ) ) :
                ( message_.acc.other & ~( 1 << LeftArrowBitNum ) );

    return message_;
}

inline GamePadMsgType& setRigthArrow( GamePadMsgType& message_, bool enable_ )
{
    message_.acc.other = enable_ ?
                ( message_.acc.other | ( 1 << RigthArrowBitNum ) ) :
                ( message_.acc.other & ~( 1 << RigthArrowBitNum ) );

    return message_;
}

inline GamePadMsgType& setABtn( GamePadMsgType& message_, bool enable_ )
{
    message_.acc.other = enable_ ?
                ( message_.acc.other | ( 1 << ABtnBitNum ) ) :
                ( message_.acc.other & ~( 1 << ABtnBitNum ) );

    return message_;
}

inline GamePadMsgType& setBBtn( GamePadMsgType& message_, bool enable_ )
{
    message_.acc.other = enable_ ?
                ( message_.acc.other | ( 1 << BBtnBitNum ) ) :
                ( message_.acc.other & ~( 1 << BBtnBitNum ) );

    return message_;
}


#endif // GAMEPADMSG_H
