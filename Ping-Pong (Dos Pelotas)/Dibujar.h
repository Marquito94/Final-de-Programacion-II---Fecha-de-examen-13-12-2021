#ifndef DIBUJAR_H_INCLUDED
#define DIBUJAR_H_INCLUDED
#include <allegro.h>
#include "Pelotas.h"
#include "Jugadores.h"
#include "Fucionalidades.h"

#define ANCHO 1000
#define ALTO 500

//FUNCIONES DIBUJAR
void dibujar_mesa( BITMAP *Buffer );
void tablero( BITMAP *Buffer , Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones );
void dibujar_puntos( BITMAP *Buffer );
void dibujar_pelota1 ( BITMAP *Buffer , Pelota<int,float> &pelota1 );
void dibujar_pelota2 ( BITMAP *Buffer , Pelota<int,float> &pelota2 );

#endif // DIBUJAR_H_INCLUDED
