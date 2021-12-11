#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <allegro.h>
#include "Paletas.h"
#include "Pelotas.h"
#include "Jugadores.h"
#include "juego.h"
#include "Fucionalidades.h"
#include "Dibujar.h"

#define ANCHO 1000
#define ALTO 500

int main()
{
    //INICIALIZACIONES
    inicializaciones( );

    //LOOP DEL JUEGO
    loop_del_juego( );

    //DESTRUCTORES
    destructores( );

    //SALIDA DEL JUEGO
    allegro_exit( );

return 0;
}
END_OF_MAIN( )
