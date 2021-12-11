#ifndef DIBUJAR_H_INCLUDED
#define DIBUJAR_H_INCLUDED
#include <allegro.h>
#include "Pelotas.h"

#define ANCHO 1000
#define ALTO 500

void dibujar_mesa( BITMAP *Buffer );
void tablero( BITMAP *Buffer );
void dibujar_puntos( BITMAP *Buffer );
void dibujar_pelota ( BITMAP *Buffer , Pelota<int,float> &pelota);

#endif // DIBUJAR_H_INCLUDED
