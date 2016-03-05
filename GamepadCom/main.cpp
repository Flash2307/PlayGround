#include "CoordinatorXbee.h"
#include "EndPointXbee.h"

// Communication avec le teminal.
Serial terminal( USBTX, USBRX );

// Mandatoire pour l'accès au système de fichiers.
LocalFileSystem local("local");  

int main() 
{    
    // Chargement de la configuration.
    Configuration config( "/local/config.txt", "/local/hostname.txt" );
    
    // La configuration détemine si le device est un coordinateur ou un routeur.
    if( config.isCoordinator() )
    {
        DigitalOut led1( LED1 );
        led1 = 1;
        
        CoordinatorXbee coordinator;
        coordinator.exec( config );
    }
    else
    {
        DigitalOut led2( LED2 );
        led2 = 1;
        
        EndpointXbee enpoint;
        enpoint.exec( config );
    }
    
    return 0;
}