#ifndef CONFIG_H_INCLUDED 
#define CONFIG_H_INCLUDED

// Mettre à 1 pour utiliser le code de l'accéléromètre.
#define ENABLE_ACCELEROMETER 1

// Mettre à 1 pour utiliser entrer dans la boucle qui fait le liens
// entre xctu et le xbee
#define USE_XCTU             0

// Mettre à 0 pour activer l'affichage.
#define NDEBUG               0

#if NDEBUG == 0
#   define DEBUG_DISPLAY( Code ) Code
#else
#   define DEBUG_DISPLAY( Code )
#endif

#if USE_XCTU == 1
#   define CALL_XCTU_LOOP( Code ) Code
#else
#   define CALL_XCTU_LOOP( Code )
#endif

#define StaticArraySize( arrayName ) ( sizeof( arrayName ) / sizeof( arrayName[ 0 ] ) )

#endif
