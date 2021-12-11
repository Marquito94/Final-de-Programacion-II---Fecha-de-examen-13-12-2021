#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <allegro.h>
#include "Fucionalidades.h"
#include "Paletas.h"
#include "Pelotas.h"
#include "Jugadores.h"
#include "Dibujar.h"

#define ANCHO 1000
#define ALTO 500

//DECLARACION DE ESTRUCTURAS
typedef struct
{
    BITMAP *mapa_de_bits;
}
bitmaps;
typedef struct
{
    SAMPLE *muestra_de_audio;
}
samples;

//FUNCIONES JUEGO
void inicializaciones( );
void loop_del_juego( );
void incremento( );
void cerrar_portada( );
void cerrar_ventana( );
void first_screen( );
void destructores( );
void setter_de_clases( );

#endif // JUEGO_H_INCLUDED
