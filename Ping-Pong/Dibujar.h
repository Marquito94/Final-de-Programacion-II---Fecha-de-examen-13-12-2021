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
void dibujar_pelota ( BITMAP *Buffer , Pelota<int,float> &pelota );

#endif // DIBUJAR_H_INCLUDED
