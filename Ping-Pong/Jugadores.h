#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED
#include <iostream>

//TEMPLATE CLASE, JUGADOR
template <class type1>//type1 = int
class Jugador
{
    type1 puntaje1;
    type1 puntaje2;
    type1 disparos1;
    type1 disparos2;

    public:

    Jugador() {
        puntaje1 = 0;
        puntaje2 = 0;
        disparos1 = 0;
        disparos2 = 0;
    }

    ~Jugador () {

    }

    void setPuntaje1 ( type1 Puntaje1 ) {
        this->puntaje1 = Puntaje1;
    };

    void setPuntaje2 ( type1 Puntaje2 ) {
        this->puntaje2 = Puntaje2;
    };

    void setDisparos1( type1 disparos1 ) {
        this->disparos1 = disparos1;
    }

    void setDisparos2( type1 disparos2 ) {
        this->disparos2 = disparos2;
    }

    type1 getDisparos2 () {
        return disparos2;
    }
    type1 getDisparos1 () {
        return disparos1;
    }

    type1 getPuntaje1 () {
        return puntaje1;
    }

    type1 getPuntaje2 () {
        return puntaje2;
    }
};

#endif // JUGADORES_H_INCLUDED
