#include "CoordinatorXbee.h"
#include "EndPointXbee.h"
#include "Config.h"

// Communication avec le teminal.
Serial terminal( USBTX, USBRX );

// Mandatoire pour l'accès au système de fichiers.
LocalFileSystem local("local");  

extern Sensors* pSensors;

int main() 
{    
    DEBUG_DISPLAY( terminal.printf( "Started...\r\n" ); )

    // Chargement de la configuration.
    Configuration config( "/local/config.txt", "/local/hostname.txt" );
    
    terminal.baud( SERIAL_BAUD_RATE );
    
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
        
        Sensors sensors( config );
        pSensors = &sensors;
        
        EndpointXbee enpoint;
        enpoint.setCollectionFn( &fetchAccelerometerData, 0 );
        enpoint.exec( config );
        
    }
    
    return 0;
}


