#ifndef FUCIONALIDADES_H_INCLUDED
#define FUCIONALIDADES_H_INCLUDED
#include <iostream>

//TEMPLATE CLASE, FUNCIONALIDAD
template <class type1,class type2>
class Funcionalidad //type1 = int, type2 = BOOL
{
    type1 contador;
    type1 resultado;
    type1 nivel;
    type1 tiempo;
    type1 disparos;
    type1 propulsion;
    type1 mensaje;
    type2 ventana;
    type2 Portada;
    type2 nuevo;

    public:
    Funcionalidad () {
        contador = 0;
        resultado = 0;
        nuevo = false;
        nivel = 1;
        ventana = false;
        Portada = false;
        tiempo++;
    }

    void setNivel ( type1 nivel ) {
        this->nivel = nivel;
    }

    void setContador ( type1 contador ) {
        this->contador = contador;
    }

    void setResultado ( type1 resultado ) {
        this->resultado = resultado;
    }

    void setNuevo ( type2 nuevo ) {
        this->nuevo = nuevo;
    }

    void setVentana ( type2 ventana ) {
        this->ventana = ventana;
    }

    void setPortada ( type2 Portada ) {
        this->Portada = Portada;
    }

    void setTiempo ( type1 Tiempo ) {
        this->tiempo = Tiempo;
    }

    void setPropulsion ( type1 Propulsion ) {
        this->propulsion = Propulsion;
    }

    void setMensaje ( type1 Mensaje ) {
        this->mensaje = Mensaje;
    }

    type1 getMensaje () {
        return mensaje;
    }

    type1 getPropulsion () {
        return propulsion;
    }

    type1 getContador () {
        return contador;
    }

    type1 getResultado () {
        return resultado;
    }

    type1 getTiempo () {
        return tiempo;
    }

    type1 getNivel ( ) {
        return nivel;
    }

    type2 getVentana () {
        return ventana;
    }

    type2 getNuevo () {
        return nuevo;
    }

    type2 getPortada () {
        return Portada;
    }
};

#endif // FUCIONALIDADES_H_INCLUDED
