#ifndef PELOTAS_H_INCLUDED
#define PELOTAS_H_INCLUDED
#include <allegro.h>
#include <iostream>
#include "Fucionalidades.h"
#include "Paletas.h"


#define ANCHO 1000
#define ALTO 500

//TEMPLATE CLASE PELOTA. HEREDADA DE PALETA
template <class type1,class type2>//type1 = int - type2 = bool
class Pelota: public Paleta<int>
{
    type1 X;
    type1 Y;
    type1 alto;
    type1 ancho;
    type1 dirX;
    type1 dirY;
    type2 velocidadX;
    type2 velocidadY;
    type1 velocidad;

    public:

    Pelota() {
        X=0;
        Y=0;
        dirX=0;
        dirY=0;
    }

    void setVel( type1 velocidad ) {
        this->velocidad = velocidad;
    }

    void setVelX ( type2 velocidadX ) {
        this->velocidadX = velocidadX;
    }

    void setVelY ( type2 velocidadY ) {
        this->velocidadY = velocidadY;
    }

    void setX( type1 x) {
        this->X = x;
    }

    void setY ( type1 y) {
        this->Y = y;
    }

    void setAlto ( type1 alto) {
        this->alto = alto;
    }

    void setAncho ( type1 ancho ) {
        this->ancho = ancho;
    }

    void setDirX ( type1 dirX) {
        this->dirX = dirX;
    }

    void setDirY ( type1 dirY ) {
        this->dirY = dirY;
    }

    type1 getVel () {
        return velocidad;
    }

    type2 getVelX () {
        return velocidadX;
    }

    type2 getVelY () {
        return velocidadY;
    }

    type1 getX () {
        return X;
    }

    type1 getY () {
        return Y;
    }

    type1 getAncho () {
        return ancho;
    }

    type1 getAlto () {
        return alto;
    }

    type1 getDirX () {
        return dirX;
    }

    type1 getDirY () {
        return dirY;
    }
};

//SOBRECARGA DE FUNCIONES
void resetPelota( Pelota<int,float> &pelota , Funcionalidad<int,bool> &funciones );
void resetPelota( Pelota<int,float> &pelota , Paleta<int> paleta , int a, Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones, BITMAP *buffer , BITMAP *jugador1 , BITMAP *jugador2 , SAMPLE *level_up , SAMPLE *winner );
//MOVIMIENTO DE PELOTA
void moverPelota( Pelota<int,float> &pelota , Paleta<int> &paleta1 , Paleta<int> &paleta2 , Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones , BITMAP *buffer , BITMAP *jugador1 , BITMAP *jugador2 , SAMPLE *level_up , SAMPLE *winner , SAMPLE *wall ,  SAMPLE *hit , SAMPLE *punto );
void golpe_especialp1( Pelota<int,float> &pelota , Paleta<int> paleta , BITMAP *buffer , int propulsion , Funcionalidad<int,bool> &funciones , int diry , Jugador<int> &jugadores );
void golpe_especialp2( Pelota<int,float> &pelota , Paleta<int> paleta , BITMAP *buffer , int propulsion , Funcionalidad<int,bool> &funciones , int diry , Jugador<int> &jugadores );

#endif // PELOTAS_H_INCLUDED
