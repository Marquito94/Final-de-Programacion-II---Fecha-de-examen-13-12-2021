#include "Dibujar.h"

void dibujar_mesa( BITMAP* buffer )
//DIBUJAR MESA
{
	int i = 0;
	int j = 20;

	while( j <= ALTO )
    {
		rectfill( buffer , ANCHO/2 , i , ANCHO/2 , j , 0xFFFFFF );
		i = j + 10 ;
		j = i + 20 ;
	}
	line( buffer , ( ANCHO / 2) / 2 , ALTO / 2 , ( ANCHO / 2 ) * 1.5 , ALTO / 2 , 0x666666 );
	line( buffer , ( ANCHO / 2) / 2 , ALTO - ALTO , ( ANCHO / 2 ) / 2 , ALTO , 0x666666 );
	line( buffer , ( ANCHO / 2) * 1.5 , ALTO - ALTO , ( ANCHO / 2 ) * 1.5 , ALTO , 0x666666 );

	//MESA GASTADA (?)
	dibujar_puntos( buffer );

}
void tablero( BITMAP *Buffer , Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones )
//DIBUJAR TABLERO
{
    line( Buffer , ANCHO - 140 , 0 , ANCHO - 140 , 80 , 0xFFFFFF );
    line( Buffer , ANCHO - 142 , 0 , ANCHO - 142 , 82 , 0xFFFFFF );
    line( Buffer , ANCHO - 142 , 82 , ANCHO , 82 , 0xFFFFFF );
    line( Buffer , ANCHO - 140 , 80 , ANCHO , 80 , 0xFFFFFF );

    line( Buffer , 140 , 0 , 140 , 80 , 0xFFFFFF );
    line( Buffer , 142 , 0 , 142 , 82 , 0xFFFFFF );
    line( Buffer , 142 , 82 , 0 , 82 , 0xFFFFFF );
    line( Buffer , 140 , 80 , 0 , 80 , 0xFFFFFF );

    textprintf_ex( Buffer , font , 10 , 20 , 0xD1D1D1 , - 1 , "Puntos P1: %d" , jugadores.getPuntaje1() );
    textprintf_ex( Buffer , font , 880 , 20 , 0xD1D1D1 , - 1 , "Puntos P2: %d" , jugadores.getPuntaje2() );
    if( jugadores.getDisparos1() >= 0)
    {
        textprintf_ex( Buffer , font , 10 , 40 , 0xD1D1D1 , - 1 , "Disparos 1: %d" , jugadores.getDisparos1() );
    }
    else
    {
        textprintf_ex( Buffer , font , 10 , 40 , 0xD1D1D1 , - 1 , "Disparos 1: 0" );
    }
    if( jugadores.getDisparos2() >= 0)
    {
        textprintf_ex( Buffer , font , 880 , 40 , 0xD1D1D1 , - 1 , "Disparos 2: %d" , jugadores.getDisparos2() );
    }
    else
    {
        textprintf_ex( Buffer , font , 880 , 40 , 0xD1D1D1 , - 1 , "Disparos 2: 0" );
    }
    textprintf_ex( Buffer , font , 900 , 480 , 0xD1D1D1 , - 1 , "LEVEL %d" , funciones.getNivel() );

}
void dibujar_puntos ( BITMAP *buffer )
//DIBUJAR PUNTOS
{
    line( buffer , 20 , 100 , 20 ,100 , 0xD1D1D1 ); line( buffer , 30 ,70 , 30 , 70 , 0xD1D1D1 ); line( buffer , 54 , 343 , 54 , 343 , 0xD1D1D1 );
    line( buffer , 56 , 250 , 56 ,250 , 0xD1D1D1 ); line( buffer , 67 , 120 , 67 , 120 , 0xD1D1D1 ); line( buffer , 12 , 123 , 12 , 123 , 0xD1D1D1 );
    line( buffer , 87 , 150 , 87 ,150 , 0xD1D1D1 ); line( buffer , 113 , 230 , 113 , 230 , 0xD1D1D1 ); line( buffer , 76 , 222 , 76 , 222 , 0xD1D1D1 );
    line( buffer , 92 , 300 , 92 ,300 , 0xD1D1D1 ); line( buffer , 143 , 430 , 143 , 430 , 0xD1D1D1 ); line( buffer , 101 , 111 , 101 , 111 , 0xD1D1D1 );
    line( buffer , 105 , 200 , 105 ,200 , 0xD1D1D1 ); line( buffer , 152 , 300 , 152 , 300 , 0xD1D1D1 ); line( buffer , 123 , 43 , 123 , 43 , 0xD1D1D1 );
    line( buffer , 520 , 406 , 520 ,406 , 0xD1D1D1 ); line( buffer , 187 , 465 , 187 , 465 , 0xD1D1D1 ); line( buffer , 322 , 54 , 322 , 54 , 0xD1D1D1 );
    line( buffer , 400 , 300 , 400 ,300 , 0xD1D1D1 ); line( buffer , 200 , 343 ,  200 , 343 , 0xD1D1D1 ); line( buffer , 876 , 12 , 876 , 12 , 0xD1D1D1 );
    line( buffer , 300 , 356 , 300 ,356 , 0xD1D1D1 ); line( buffer , 221 , 303 , 221 , 303 , 0xD1D1D1 ); line( buffer , 654 , 98 , 654 , 98 , 0xD1D1D1 );
    line( buffer , 320 , 743 , 320 ,743 , 0xD1D1D1 ); line( buffer , 234 , 222 , 234 , 222 , 0xD1D1D1 ); line( buffer , 634 , 76 , 634 , 76 , 0xD1D1D1 );
    line( buffer , 380 , 765 , 380 ,765 , 0xD1D1D1 ); line( buffer , 256 , 123 , 256 , 123 , 0xD1D1D1 ); line( buffer , 342 , 343 , 342 , 343 , 0xD1D1D1 );
    line( buffer , 380 , 220 , 380 ,220 , 0xD1D1D1 ); line( buffer , 298 , 76 , 298 , 76 , 0xD1D1D1 ); line( buffer , 654 , 434 , 654 , 434 , 0xD1D1D1 );
    line( buffer , 420 , 160 , 420 ,160 , 0xD1D1D1 ); line( buffer , 303 , 54 , 303 , 54 , 0xD1D1D1 ); line( buffer , 761 , 422 , 761 , 422 , 0xD1D1D1 );
    line( buffer , 900 , 150 , 900 ,150 , 0xD1D1D1 ); line( buffer , 376 , 230 , 376 , 230 , 0xD1D1D1 ); line( buffer , 982 , 477 , 982 , 477 , 0xD1D1D1 );
    line( buffer , 870 , 120 , 870 ,120 , 0xD1D1D1 ); line( buffer , 354 , 333 , 354 , 333 , 0xD1D1D1 ); line( buffer , 422 , 223 , 422 , 223 , 0xD1D1D1 );
    line( buffer , 630 , 240 , 630 ,240 , 0xD1D1D1 ); line( buffer , 331 , 232 , 331 , 232 , 0xD1D1D1 ); line( buffer , 500 , 342 , 500 , 342 , 0xD1D1D1 );
    line( buffer , 333 , 230 , 333 ,230 , 0xD1D1D1 ); line( buffer , 400 , 276 , 400 , 276 , 0xD1D1D1 ); line( buffer , 744 , 211 , 744 , 211 , 0xD1D1D1 );
    line( buffer , 443 , 87 , 443 , 87 , 0xD1D1D1 ); line( buffer , 442 , 290 , 442 , 290 , 0xD1D1D1 ); line( buffer , 433 , 155 , 433 , 155 , 0xD1D1D1 );
    line( buffer , 657 , 97 , 657 , 97 , 0xD1D1D1 ); line( buffer , 412 , 360 , 412 , 360 , 0xD1D1D1 ); line( buffer , 765 , 165 , 765 , 165 , 0xD1D1D1 );
    line( buffer , 823 , 170 , 823 , 170 , 0xD1D1D1 ); line( buffer , 456 , 387 , 456 , 387 , 0xD1D1D1 ); line( buffer , 333 , 187 , 333 , 187 , 0xD1D1D1 );
    line( buffer , 723 , 150 , 723 , 150 , 0xD1D1D1 ); line( buffer , 476 , 456 , 476 , 456 , 0xD1D1D1 ); line( buffer , 223 , 165 , 223 , 165 , 0xD1D1D1 );
    line( buffer , 354 , 245 , 354 , 245 , 0xD1D1D1 ); line( buffer , 490 , 410 , 490 , 410 , 0xD1D1D1 ); line( buffer , 254 , 187 , 254 , 187 , 0xD1D1D1 );
    line( buffer , 987 , 322 , 987 , 322 , 0xD1D1D1 ); line( buffer , 501 , 402 , 501 , 402 , 0xD1D1D1 ); line( buffer , 987 , 376 , 987 , 376 , 0xD1D1D1 );
    line( buffer , 965 , 467 , 965 , 467 , 0xD1D1D1 ); line( buffer , 520 , 489 , 520 , 489 , 0xD1D1D1 ); line( buffer , 543 , 465 , 543 , 465 , 0xD1D1D1 );
    line( buffer , 654 , 321 , 654 , 321 , 0xD1D1D1 ); line( buffer , 550 , 123 , 550 , 123 , 0xD1D1D1 ); line( buffer , 656 , 423 , 656 , 423 , 0xD1D1D1 );
    line( buffer , 876 , 460 , 876 , 460 , 0xD1D1D1 ); line( buffer , 860 , 410 , 860 , 410 , 0xD1D1D1 ); line( buffer , 760 , 410 , 760 , 410 , 0xD1D1D1 );
    line( buffer , 769 , 322 , 769 , 322 , 0xD1D1D1 ); line( buffer , 932 , 402 , 932 , 402 , 0xD1D1D1 ); line( buffer , 987 , 376 , 987 , 376 , 0xD1D1D1 );
    line( buffer , 930 , 467 , 930 , 467 , 0xD1D1D1 ); line( buffer , 965 , 489 , 965 , 489 , 0xD1D1D1 ); line( buffer , 840 , 465 , 840 , 465 , 0xD1D1D1 );
    line( buffer , 950 , 321 , 950 , 321 , 0xD1D1D1 ); line( buffer , 870 , 276 , 870 , 276 , 0xD1D1D1 ); line( buffer , 760 , 423 , 760 , 423 , 0xD1D1D1 );
}
void dibujar_pelota1( BITMAP *Buffer , Pelota<int,float> &pelota1 )
//DIBUJAR PELOTA 1
{
	circlefill ( Buffer , pelota1.getX() , pelota1.getY() , pelota1.getAncho() / 2 , 0xFFFFFF );
	circlefill ( Buffer , pelota1.getX() , pelota1.getY() , pelota1.getAncho() / 6 , 0x000000 );
}
void dibujar_pelota2( BITMAP *Buffer , Pelota<int,float> &pelota2 )
//DIBUJAR PELOTA 2
{
	circlefill ( Buffer , pelota2.getX() , pelota2.getY() , pelota2.getAncho() / 2 , 0xFFFFFF );
	circlefill ( Buffer , pelota2.getX() , pelota2.getY() , pelota2.getAncho() / 6 , 0x000000 );
}
