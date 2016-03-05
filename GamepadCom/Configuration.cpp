#include "Configuration.h"

#include <fstream>

#include "mbed.h"
#include "Util.h"

// Lecture de données en hexédécimal d'un flux d'entré.
static void readHexArray( std::istream& in, uint8_t data[], size_t length )
{    
    in >> std::hex;
    
    int value;
    
    for( size_t index = 0; index < length; ++index )
    {
        in >> value;
        data[ index ] = value;
    }
}

// Lecture de la configuation.
// @param configurationPath_ configuration général: pan id, temps entre les lectures, mac address du coordinateur
// @param hostConfigurationPath_ Fichier qui contient l'url du serveur pour la communication websocket.
Configuration::Configuration( const char* configurationPath_, const char* hostConfigurationPath_ )
{
    this->loadConfiguration( configurationPath_ );
    
    if( this->isCoordinator() )
    {
        this->loadHostNameConfiguration( hostConfigurationPath_ );
    }
}

// Retourne vrai si la configuration indique que le device sera un coordinateur.
bool Configuration::isCoordinator() const
{
    return this->coordinatorRole;
}

// Retourne le temps entre la lecture des senseurs.
size_t Configuration::getSensorUpdateTimeMs() const
{
    return this->sensorUpdateTimeMsc;
}

// Retourne le pan id du réseau.
void Configuration::getPanId( PanIdType panId_ ) const
{
    std::copy( this->panId, this->panId + PanIdByteCount, panId_ );
}

// Retourne la MAC adresse du device qui est supposé reçevoir les données des senseurs.
void Configuration::getMacAdress( MacAdressType macAdress_ ) const
{
    std::copy( this->coordinatorMacAdress, this->coordinatorMacAdress + PanIdByteCount, macAdress_ );
}

// Retourne le nom de l'hôte pour la communication websocket.
std::string Configuration::getHostname() const
{
    return this->hostname;
}

// Affiche la configuration dans une communication sérial.
void Configuration::display( mbed::Serial& out ) const
{
    out.printf( "Configuration:\r\n" );
    out.printf( "Is coordinator: %i\r\n", (int)this->coordinatorRole );
    out.printf( "sensorUpdateTimeMsc: %i\r\n", sensorUpdateTimeMsc);
    
    out.printf( "Pan Id: " );
    displayHexArray( out, this->panId, PanIdByteCount ); 
    out.printf( "\r\n" );
    
    out.printf( "MAC adress: " );
    displayHexArray( out, this->coordinatorMacAdress, MacAdressByteCount ); 
    out.printf( "\r\n" );
    
    out.printf( "Hostname: %s\r\n", this->hostname.c_str() );
    out.printf( "End Configuration\r\n\r\n" );
}

// Retourne vrai si la configuration a pu être lu correctement.
bool Configuration::loadConfiguration( const char* configurationPath_ )
{
    std::ifstream in( configurationPath_, std::ios::in );
    
    if( in.is_open() )
    {
        in >> std::dec >> coordinatorRole;
        in >> sensorUpdateTimeMsc;
        readHexArray( in, panId, PanIdByteCount );
        readHexArray( in, coordinatorMacAdress, MacAdressByteCount );
        in.close();
        
        return false;
    }
    
    return true;
}

// Charge le fichier de configuration qui contient le nomd de l'hôte pour la communication websocket.
bool Configuration::loadHostNameConfiguration( const char* configurationPath_ )
{
    std::ifstream in( configurationPath_, std::ios::in );
    
    if( in.is_open() )
    {
        getline( in, hostname );
        in.close();
        
        return false;
    }
    
    return true;
}

