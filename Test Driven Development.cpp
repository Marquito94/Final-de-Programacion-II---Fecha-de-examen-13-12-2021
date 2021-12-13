#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "Jugadores.h"
#include "Pelotas.h"
#include "Fucionalidades.h"
#include "Paletas.h"

//TEST DRIVEN DEVELOPMENT + SOBRECARGA DE FUNCIONES
using namespace std;

int TesteoDeClases( int a )
{
return a;
}
float TesteoDeClases( float a )
{
return a;
}
bool TesteoDeClases( bool a )
{
    if( a == true )
    {
        return true;
    }
    else if( a == false )
    {
        return false;
    }
}
TEST_CASE( "Test de clase Jugadores.h - [Getters y Setters]" )
{
    int JugadoresTest;
    int Testeo;
    Jugador<int> Jugadores;

    //SETTER DE CLASE JUGADOR. VARIABLE ESCOJIDA ALEATORIAMENTE. CASO PUNTAJE1
    Jugadores.setPuntaje1(13);
    JugadoresTest = Jugadores.getPuntaje1();
    Testeo = TesteoDeClases( JugadoresTest );

    REQUIRE( JugadoresTest == 13 );
    REQUIRE( Testeo == Jugadores.getPuntaje1() );
}
TEST_CASE( "Test de clase Pelotas.h - [Getters y Setters]" )
{
    float PelotasTest;
    float Testeo;
    Pelota<int,float> Pelotas;

    //SETTER DE CLASE PELOTA. VARIABLE ESCOJIDA ALEATORIAMENTE. CASO VELOCIDADX
    Pelotas.setVelX( 5.5 )
    PelotasTest = Pelotas.getVelX();
    Testeo = TesteoDeClases( PelotasTest );

    REQUIRE( PelotasTest == 5.5 );
    REQUIRE( Testeo == Pelotas.getVelX() );
}
TEST_CASE( "Test de clase Funcionalidades.h - [Getters y Setters]" )
{
    bool FuncionalidadesTest;
    bool Testeo;
    Funcionalidad<int,bool> Funcionalidades;

    //SETTER DE CLASE FUNCIONALIDADES. VARIABLE ESCOJIDA ALEATORIAMENTE. CASO PORTADA
    Funcionalidades.setPortada( false );
    FuncionalidadesTest = Funcionalidades.getPortada();
    Testeo = TesteoDeClases( FuncionalidadesTest );

    REQUIRE( FuncionalidadesTest = false );
    REQUIRE( Testeo == Funcionalidades.getPortada() );
}
TEST_CASE( "Test de clase Paletas.h - [Getters y Setters]" )
{
    int PaletasTest;
    int Testeo;
    Paleta<int> Paletas;

    //SETTER DE CLASE PALETA. VARIABLE ESCOJIDA ALEATORIAMENTE. CASO ANCHO
    Paletas.setAncho( 13 );
    PaletasTest = Paletas.getAncho() ;
    Testeo = TesteoDeClases( PaletasTest );

    REQUIRE( PaletasTest == 13 );
    REQUIRE( Testeo == Jugadores.getAncho() );
}
