#ifndef PALETAS_H_INCLUDED
#define PALETAS_H_INCLUDED
#include <allegro.h>
#include <iostream>
#include "Jugadores.h"

//TEMPLATE CLASE PALETA. HERENCIA DE JUGADOR
template <class type1>//type1 = int
class Paleta: public Jugador<int>
{
    type1 X;
    type1 Y;
    type1 alto;
    type1 ancho;

    public:
    Paleta() {
        X = 0;
        Y = 0;
        alto = 10;
        ancho = 2;
    }

    void setTamano( type1 ancho , type1 alto ) {
        this->alto = alto;
        this->ancho = ancho;
    }

    void setX( type1 x ) {
        this->X = x;
    }

    void setY( type1 y ) {
        this->Y = y;
    }

    type1 getX() {
        return X;
    }

    type1 getY() {
        return Y;
    }

    type1 getAlto() {
        return alto;
    }

    type1 getAncho() {
        return ancho;
    }
};

#endif // PALETAS_H_INCLUDED
