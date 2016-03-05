#include "XBee.h"
#include "Config.h"
#include "Configuration.h"
#include "Util.h"

extern Serial terminal;

// Envoi de données brut au xbee
template< class Sender >
static void sendData( Sender& xbee, const uint8_t* data, size_t length)
{
    for( size_t index = 0; index < length; ++index )
    {
        xbee.putc( data[ index ] );
    }
}

// Envoi des données brut au Xbee et calcul le checksum sur les données envoyées
template< class Sender >
static void sendData( Sender& xbee, const uint8_t* data, size_t length, uint8_t& checksum )
{
    for( size_t index = 0; index < length; ++index )
    {       
        xbee.putc( data[ index ] );
        checksum += data[ index ];
    }
}

// Échange les 8 bits du haut avec les 8 bits du bas d'un entier de 16 bits.
static void swapBytes( uint16_t& value )
{
    value = (value >> 8) | (value << 8 );
}

// Calcul le checksum d'une trame receive de xbee
static uint8_t checksumXbeeTrame( XBeeTrame& trame_ )
{
    uint8_t checksum = 0;
    uint8_t* first = &trame_.trame.frameType;
    uint8_t* last = trame_.trame.data + 40;
    
    while( first != last )
    {
        checksum += *first;
        ++first;
    }
    
    return 0xFF - checksum;
}

// Initialise la communication UART et la pin de reset du xbee
XBee::XBee( PinName tx_, PinName rx_, PinName rst_ ) :
    xbeeIO( tx_, rx_ ),
    rst( rst_ )
{

}

// Initialise la configuration du xbee.
void XBee::init( const Configuration& config_ )
{
    PanIdType panId;
    
    config_.getPanId( panId );
    init( panId );
}

// Fait le liens avec xctu et le xbee.
void XBee::xctuLink( XBee& xbee_, Serial& terminal )
{
    Serial& xbeeIO = xbee_.serialRef();
    
    while(1)
    {
        if( terminal.readable())
        {
            xbeeIO.putc( terminal.getc() );
        }
        
        if( xbeeIO.readable() )
        {
            terminal.putc( xbeeIO.getc() );
        }
    }
}

// Change le pan id sur le xbee.
void XBee::init( uint8_t panId[ PanIdByteCount ] )
{
    uint8_t initCommand1[] = { 0x08, 0x43, 0x49, 0x44 };
    uint8_t checksum = 0;
    uint16_t paquetSize = StaticArraySize(initCommand1) + PanIdByteCount;
    
    swapBytes( paquetSize );
    
    xbeeIO.putc( StartDelimiter );
    sendData( xbeeIO, (const uint8_t*)&paquetSize, 2 );
    sendData( xbeeIO, initCommand1, StaticArraySize(initCommand1), checksum );
    sendData( xbeeIO, panId, PanIdByteCount, checksum );
    xbeeIO.putc( checksum );
}

// Vide le buffer de réception UART.
void XBee::flushReceiveBuffer()
{
    while( xbeeIO.readable() )
    {
        xbeeIO.getc();
    }
}

// Reset le xbee.
void XBee::reset()
{
    this->rst = 0;
    wait_ms( 400 );
    this->rst = 1;
}

// Envoi un transmit request au xbee.
void XBee::sendTx( const uint8_t macAdress[ MacAdressByteCount ], uint16_t adress16Bits, const uint8_t data[], size_t length )
{
    Serial& out = this->xbeeIO;
    uint8_t checksum  = 0x10 + 0x01;
    uint16_t messageSize = 14 + length;
    
    swapBytes( messageSize );
    swapBytes( adress16Bits );
    
    out.putc( 0x7E );                                       // Start delimiter
    sendData( out, (uint8_t*)&messageSize, 2 );             // Length
    out.putc( 0x10 );                                       // Frame type
    out.putc( 0x01 );                                       // Frame ID
    sendData( out, macAdress, 8, checksum );                // Adresse MAC
    sendData( out, (uint8_t*)&adress16Bits, 2, checksum );  // Adresse 16 bits
    out.putc( 0x00 );   
    out.putc( 0x00 );   
    sendData( out, data, length, checksum );                // Payload
    out.putc( 0xFF - checksum );                            // Checksum
}

// Envoi un transmit status au xbee.
void XBee::sendTransmitStatus( uint16_t adress16Bits )
{
    uint8_t checksum  = TransmitStatus + 0x01;
    uint16_t messageSize = 7;
    
    swapBytes( messageSize );
    swapBytes( adress16Bits );
    
    this->xbeeIO.putc( 0x7E );                                      // Start delimiter
    sendData( this->xbeeIO, (uint8_t*)&messageSize, 2 );            // Length
    this->xbeeIO.putc( TransmitStatus );                            // Frame type
    this->xbeeIO.putc( 0x01 );                                      // Frame ID
    sendData( this->xbeeIO, (uint8_t*)&adress16Bits, 2, checksum ); // Adresse 16 bits
    this->xbeeIO.putc( 0x00 );                                      // Tx retry count
    this->xbeeIO.putc( 0x00 );                                      // Delivery status
    this->xbeeIO.putc( 0x00 );                                      // Discovery status
    this->xbeeIO.putc( 0xFF - checksum );                           // Checksum
}

// Fait la réception de données du xbee.
bool XBee::receive( XBeeTrame& trame_ )
{          
    enum 
    { 
        PaquetHeader,
        TrameLength,
        CompleteReception,
        ReceptionCompleted,
        Checksum
    } 
    state = PaquetHeader;
    
    size_t index = 0;
    uint8_t currentByte = 0;
    size_t trameLength = 0;
    
    memset( &trame_, 0, sizeof( trame_ ) );
    
    while( index < sizeof( XBeeTrame ) && state != ReceptionCompleted )
    {
        while( !this->xbeeIO.readable() ) wait_us(1);
        currentByte = this->xbeeIO.getc();

        if( currentByte == 0x7E )
        {
            state = PaquetHeader;
            index = 0;
            trameLength = 0;
        }
        
        switch( state )
        {
            case PaquetHeader:
            {
                if( currentByte == 0x7E )
                {
                    index = 0;
                    trameLength = 0;
                    state = TrameLength;
                }               
                break;
            }
            case TrameLength:
                trame_.rawData[ index++ ] = currentByte;
                
                if( index == 2 )
                {
                    swapBytes( trame_.trame.size );
                    trameLength = trame_.trame.size;
                    state = CompleteReception;            
                }
                break;
            case CompleteReception:
                trame_.rawData[ index++ ] = currentByte; 
                --trameLength;
                
                if( trameLength == 0 )
                {
                    state = Checksum;
                }
                
                break;
            case Checksum:
                trame_.trame.checksum = currentByte;
                state = ReceptionCompleted;
                break;
            default:
                break;
        };
    }
    
    // DEBUG_DISPLAY( displayHexArray( terminal, (const uint8_t*)&trame_, sizeof( trame_ ) ) );
    trame_.lastValueIndex = index;
    
    return state == ReceptionCompleted && trame_.trame.frameType == 0x90 && checksumXbeeTrame( trame_ ) == trame_.trame.checksum ;
}

Serial& XBee::serialRef()
{
    return this->xbeeIO;
}

