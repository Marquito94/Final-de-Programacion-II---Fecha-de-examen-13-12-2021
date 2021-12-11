#ifndef PALETAS_H_INCLUDED
#define PALETAS_H_INCLUDED
#include <allegro.h>
#include <iostream>
#include "Jugadores.h"

template <class type1>
class Paleta: public Jugador<int>
{
    //type1 = int
    type1 X;
    type1 Y;
    type1 alto;
    type1 ancho;

    public:
    static int count;

    Paleta() {
        X = 0;
        Y = 0;
        alto = 10;
        ancho = 2;
        count ++;
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
