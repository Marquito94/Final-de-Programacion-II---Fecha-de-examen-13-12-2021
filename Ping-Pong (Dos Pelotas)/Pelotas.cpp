#include "Pelotas.h"

void resetPelota1( Pelota<int,float> &pelota1 , Funcionalidad<int,bool> &funciones )
{
    //SETTERS DE PELOTA
    pelota1.setX( ANCHO / 2 );
	pelota1.setY( 100 + ALTO / 2 );
	srand( time( 0 ) );
	int direccion1X = ( rand() % 2) + 1; //DIRECCION X RAND 0/1
	int direccion1Y = ( rand() % 2) + 1; //DIRECCION Y RAND 0/1
	direccion1X = ( direccion1X == 1 ) ? - 1 : 1;//1 = -1 , 2 = 1
	direccion1Y = ( direccion1Y == 1 ) ? - 1 : 1;//1 = -1 , 2 = 1
	pelota1.setDirX( direccion1X );//SETTER
	pelota1.setDirY( direccion1Y );//SETTER
	funciones.setResultado( 1 );//MARCA DE INICIO
}
void resetPelota2( Pelota<int,float> &pelota2 , Funcionalidad<int,bool> &funciones )
{
    //SETTERS DE PELOTA
    pelota2.setX( ANCHO / 2 );
	pelota2.setY( ALTO / 2 - 100 );
	srand( time( 0 ) );
	int direccion2X = ( rand() % 2) + 1; //DIRECCION X RAND 0/1
	int direccion2Y = ( rand() % 2) + 1; //DIRECCION Y RAND 0/1
	direccion2X = ( direccion2X == 1 ) ? - 1 : 1;//1 = -1 , 2 = 1
	direccion2Y = ( direccion2Y == 1 ) ? - 1 : 1;//1 = -1 , 2 = 1
	pelota2.setDirX( direccion2X );//SETTER
	pelota2.setDirY( direccion2Y );//SETTER
	funciones.setResultado( 1 );//MARCA DE INICIO
}

void resetPelota( Pelota<int,float> &pelota1 , Pelota<int,float> &pelota2 , Paleta<int> paleta , int a , Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones , BITMAP *buffer , BITMAP *jugador1 , BITMAP *jugador2 , SAMPLE *level_up , SAMPLE *winner)
{
    if ( a == 1 )
    {
    //GANA PALETA2
    //PELOTA SETTEADA EN PALETA1
        pelota1.setX( paleta.getX() + paleta.getAncho() + pelota1.getAncho() - 3 );
        pelota1.setY( paleta.getY() + paleta.getAlto() / 2 );
        pelota1.setDirX( 1 );
        pelota2.setX( paleta.getX() + paleta.getAncho() + pelota2.getAncho() - 3 );
        pelota2.setY( paleta.getY() + paleta.getAlto() / 2 );
        pelota2.setDirX( 1 );
        jugadores.setPuntaje2( jugadores.getPuntaje2() + 1 );
    }
    else
    {
    //GANA PALETA1
    //PELOTA SETTEADA EN PALETA2
        pelota1.setX( paleta.getX() - paleta.getAncho() / 2 - pelota1.getAncho() + 7 );
        pelota1.setY( paleta.getY() + paleta.getAlto() / 2 );
        pelota1.setDirX( -1 );
        pelota2.setX( paleta.getX() - paleta.getAncho() / 2 - pelota2.getAncho() + 7 );
        pelota2.setY( paleta.getY() + paleta.getAlto() / 2 );
        pelota2.setDirX( -1 );
        jugadores.setPuntaje1( jugadores.getPuntaje1() + 1 );
    }

    if( funciones.getContador() == 3 )
    {
        //CAMBIO DE VELOCIDAD1 - NIVEL2 - MENSAJE DE CAMBIO
        play_sample( level_up , 200 , 150 , 1000 , 0 );
        pelota1.setVel( 7 );
        pelota2.setVel( 4 );
    }
    else if( funciones.getContador() == 7 )
    {
        //CAMBIO DE VELOCIDAD2 - NIVEL3 - MENSAJE DE CAMBIO
        play_sample( level_up , 200 , 150 , 1000 , 0 );
        pelota1.setVel( 9 );
        pelota2.setVel( 6 );
    }
    else if( funciones.getContador() == 11 )
    {
        //CAMBIO DE VELOCIDAD3 - NIVEL4 - MENSAJE DE CAMBIO
        play_sample( level_up , 200 , 150 , 1000 , 0 );
        pelota1.setVel( 11 );
        pelota2.setVel( 8 );
    }
    else if( funciones.getContador() == 15 )
    {
        //CAMBIO DE VELOCIDAD4 - NIVEL5 - MENSAJE DE CAMBIO
        play_sample( level_up , 200 , 150 , 1000 , 0 );
        pelota1.setVel( 13 );
        pelota2.setVel( 13 );
    }

    if( jugadores.getPuntaje1() == 10 )
    //GANADOR PALETA1/PLAYER1
    {
        play_sample( winner , 200 , 150 , 1000 , 0 );
        while( ! key[KEY_ENTER] )
        {
            //CASE ENTER: SETTER E INICIALIZACION DE JUEGO DESDE 0
            blit( jugador1 , screen , 0 , 0 , 0 , 0 , ANCHO , ALTO );
            jugadores.setPuntaje1( 0 );
            jugadores.setPuntaje2( 0 );
            funciones.setContador( 0 );
            pelota1.setVelX( 5 );
            pelota1.setVelY( 5 );
            pelota1.setVel( 5 );
            pelota2.setVelX( 5 );
            pelota2.setVelY( 5 );
            pelota2.setVel( 5 );
            jugadores.setDisparos1( 5 );
            jugadores.setDisparos2( 5 );
            funciones.setNuevo( true );
            resetPelota1( pelota1 , funciones );
            resetPelota2( pelota2 , funciones );
        }
        if( key[KEY_ESC] )
        {
            //CASE ESC: EXIT GAME
            allegro_exit();
        }
    }
    else if( jugadores.getPuntaje2() == 10 )
    {
    //GANADOR PALETA2/PLAYER2
        play_sample( winner , 200 , 150 , 1000 , 0 );
        while( ! key[KEY_ENTER] )
        {
            //CASE ENTER: SETTERS E INICIALIZACION DE JUEGO DESDE 0
            blit( jugador2 , screen , 0 , 0 , 0 , 0 , ANCHO , ALTO );
            jugadores.setPuntaje1( 0 );
            jugadores.setPuntaje2( 0 );
            funciones.setContador( 0 );
            pelota1.setVelX( 5 );
            pelota1.setVelY( 5 );
            pelota1.setVel( 5 );
            pelota2.setVelX( 5 );
            pelota2.setVelY( 5 );
            pelota2.setVel( 5 );
            jugadores.setDisparos1( 5 );
            jugadores.setDisparos2( 5 );
            funciones.setNuevo( true );
            resetPelota1( pelota1 , funciones );
            resetPelota2( pelota2 , funciones );
        }
        if( key[KEY_ESC] )
        {
            //CASE ESC: EXIT GAME
            allegro_exit();
        }
    }
    if( funciones.getNuevo() == true )
    {
        //CASE ENTER: NUEVO = FALSE
        funciones.setNuevo( false );
    }

    //SETTER DE VELOCIDAD LUEGO DEL RESTART, CONTADOR DE TURNOS, MARCA DE RESULTADO/INICIALIZACION
    pelota1.setVelX( pelota1.getVel() );
    pelota1.setVelY( pelota1.getVel() );
    pelota2.setVelX( pelota2.getVel() );
    pelota2.setVelY( pelota2.getVel() );
    funciones.setContador( funciones.getContador() + 1 );
    funciones.setResultado( 1 );
}
void moverPelota( Pelota<int,float> &pelota1 , Pelota<int,float> &pelota2 , Paleta<int> &paleta1 , Paleta<int> &paleta2 , Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones , BITMAP *buffer , BITMAP *jugador1 , BITMAP *jugador2 , SAMPLE *level_up , SAMPLE *winner , SAMPLE *wall ,  SAMPLE *hit , SAMPLE *punto)
{
    //DECLARACION DE COORDENADAS Y DIRECCIONES
	int dirx = pelota1.getDirX( );
	int diry = pelota1.getDirY( );
	int px = pelota1.getX( );
	int py = pelota1.getY( );
	int y1 = paleta1.getY( );
	int y2 = paleta2.getY( );
	int dirxB = pelota2.getDirX( );
	int diryB = pelota2.getDirY( );
	int pxB = pelota2.getX( );
	int pyB = pelota2.getY( );

	if ( pxB <= paleta1.getAncho() + pelota2.getAncho() / 2 )
    //GOLPE BORDE INTERIOR DE PALETA1 PELOTA2
	{
	    if ( ( pyB + pelota2.getAncho() / 2 ) >= y1 && ( pyB - pelota2.getAncho() / 2 ) <= y1 + paleta1.getAlto() )
        //GOLPE LIMITES LARGO DE PALETA
        {
            if( pyB + pelota2.getAncho() / 2 >= y1 && pyB <= y1 + paleta1.getAlto() - 63 )
            //GOLPE ESQUINA SUPERIOR DE PALETA1. EJE Y>X
            {
                if( diryB == 1 )
                {
                    diryB = -1;
                }
                play_sample( hit , 200 , 150 , 1000 , 0 );
                pelota2.setVelX( pelota2.getVel() - 1 );
                pelota2.setVelY( pelota2.getVel() + 1 );
            }
            else if( pyB >= y1 + 62 && ( pyB - pelota2.getAncho() / 2 )  <= y1 + paleta1.getAlto() )
            //GOLPE ESQUINA INFERIOR DE PALETA1. EJE Y>X
            {
                if( diryB == -1 )
                {
                    diryB = 1;
                }
                play_sample( hit , 200 , 150 , 1000 , 0 );
                pelota2.setVelX( pelota2.getVel() - 1 );
                pelota2.setVelY( pelota2.getVel() + 1 );
            }
            else if( pyB >= y1 + 31 && pyB <= y1 + paleta1.getAlto() - 32 )
            //GOLPE EN EL MEDIO DE LA PALETA. Y=X
            {
                play_sample( hit , 200 , 150 , 1000 , 0 );
                pelota2.setVelX( pelota2.getVel() );
                pelota2.setVelY( pelota2.getVel() );
            }
            dirxB *= -1;
        }
        else
        //PALETA1 PIERDE
        {
            if( ( pyB > y1 + paleta1.getAlto() ) && ( pxB > paleta1.getAncho() + pelota2.getAncho() / 2 ) && ( diryB == -1 ) && ( pxB > 0 ) )
            //PALETA1 REBOTE 0
            {
                play_sample( hit , 200 , 150 , 1000 , 0 );
                diryB = -1;
            }
            else if( ( pyB < y1 ) && ( pxB > paleta1.getAncho() + pelota2.getAncho() / 2 ) && ( diryB == 1 ) && ( pxB > 0 ) )
            {
                play_sample( hit , 200 , 150 , 1000 , 0 );
                diryB = 1;
            }
            if( pxB <= 0 )
            {
                funciones.setMensaje( 1 );
                play_sample( punto , 200 , 150 , 1000 , 0 );
                resetPelota( pelota1 , pelota2 , paleta1 , 1 , jugadores , funciones , buffer , jugador1 , jugador2 , level_up , winner);
                return;
            }
        }
	}
    else if ( pxB >= ANCHO - paleta2.getAncho() - pelota2.getAncho() / 2 )
    //GOLPE BORDE INTERIOR DE PALETA2
	{
	   if ( ( pyB + pelota2.getAncho() / 2 ) >= y2 && ( pyB - pelota2.getAncho() / 2 ) <= y2 + paleta2.getAlto())
           //GOLPE LIMITES LARGO DE PALETA
           {
               if( ( pyB + pelota2.getAncho() / 2 ) >= y2 && pyB <= y2 + paleta2.getAlto() - 63 )
               //GOLPE ESQUINA SUPERIOR. VELOCIDAD DE EJE Y>X
               {
                   if( diryB == 1 )
                   {
                       diryB = -1;
                   }
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   pelota2.setVelX( pelota2.getVel() - 1 );
                   pelota2.setVelY( pelota2.getVel() + 1 );
               }
               else if( pyB >= y2 + 62 && ( pyB - pelota2.getAncho() / 2 ) <= y2 + paleta2.getAlto() )
               //GOLPE ESQUINA INFERIOR. VELOCIDAD DE EJE Y>X
               {
                   if( diryB == -1 )
                   {
                       diryB = 1;
                   }
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   pelota2.setVelX( pelota2.getVel() - 1 );
                   pelota2.setVelY( pelota2.getVel() + 1 );
               }
               else if( pyB >= y2 + 31 && pyB <= y2 + paleta2.getAlto() - 32 )
               //GOLPE MEDIO DE LA PALETA
               {
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   pelota2.setVelX( pelota2.getVel() );
                   pelota2.setVelY( pelota2.getVel() );
               }
               dirxB *= -1;
           }
           else
           //PIERDE PALETA2
           {
               if(( ( pyB - pelota2.getAncho() / 2 ) > y2 + paleta2.getAlto() ) && ( pxB > ANCHO - paleta2.getAncho() - pelota2.getAncho() / 2 ) && ( diry == -1 ) && ( pxB < ANCHO ) )
               //PALETA2 REBOTE 0
               {
                    play_sample( hit , 200 , 150 , 1000 , 0 );
                    diryB = 1;
               }
               else if( ( ( pyB + pelota2.getAncho() / 2 ) < y2 ) && ( pxB > ANCHO - paleta2.getAncho() - pelota2.getAncho() / 2 ) && ( diry == 1 ) && ( pxB < ANCHO ) )
               {
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   diryB = -1;
               }
               if( pxB >= ANCHO )
               {
                   //PUNTO
                   funciones.setMensaje( 1 );
                   play_sample( punto , 200 , 150 , 1000 , 0 );
                   resetPelota( pelota1 , pelota2 , paleta2 , 2 , jugadores , funciones , buffer , jugador1 , jugador2 , level_up , winner);
                   return;
               }
          }
	}
	else if (( diryB < 0 && pyB <= 0 ) || ( diryB > 0 &&  pyB >= ( ALTO-pelota2.getAlto() ) ))
    //REBOTE PARED
    {
	    play_sample( wall , 200 , 150 , 1000 , 0 );
        diryB *= -1;
	}

	if( ( pelota2.getX() <= paleta1.getAncho() + pelota2.getAncho() / 2 )  && ( pelota2.getY() >= paleta1.getY() ) && ( pelota2.getY() <= paleta1.getY() + paleta1.getAlto() ) && ( key[KEY_ALT] ) )
    //PROPULSION PALETA1
    {
        funciones.setPropulsion( 1 );
        jugadores.setDisparos1( jugadores.getDisparos1() - 1 );
    }
    if( ( funciones.getPropulsion() == 1 ) && ( jugadores.getDisparos1 () >= 0 ) )
    {
        golpe_especialp1( pelota2 , paleta1 , buffer , funciones.getPropulsion() , funciones , diry , jugadores );
    }

    //PROPULSION PALETA2
    if( ( pelota2.getX() >= ANCHO - paleta2.getAncho() - pelota2.getAncho() / 2 ) && ( pelota2.getY() >= paleta2.getY() ) && ( pelota2.getY() <= paleta2.getY() + paleta2.getAlto() ) && ( key[KEY_ALTGR] ) )
    {
        funciones.setPropulsion( 2 );
        jugadores.setDisparos2( jugadores.getDisparos2() - 1 );
    }
    if( funciones.getPropulsion() == 2 && jugadores.getDisparos2() >= 0  )
    {
        golpe_especialp2( pelota2 , paleta2 , buffer , funciones.getPropulsion() , funciones , diry , jugadores );
    }

	//#########################################################################################################//
	if ( px <= paleta1.getAncho() + pelota1.getAncho() / 2 )
    //GOLPE BORDE INTERIOR DE PALETA1
	{
	    if ( ( py + pelota1.getAncho() / 2 ) >= y1 && ( py - pelota1.getAncho() / 2 ) <= y1 + paleta1.getAlto() )
        //GOLPE LIMITES LARGO DE PALETA
        {
            if( py + pelota1.getAncho() / 2 >= y1 && py <= y1 + paleta1.getAlto() - 63 )
            //GOLPE ESQUINA SUPERIOR DE PALETA1. EJE Y>X
            {
                if( diry == 1 )
                {
                    diry = -1;
                }
                play_sample( hit , 200 , 150 , 1000 , 0 );
                pelota1.setVelX( pelota1.getVel() - 1 );
                pelota1.setVelY( pelota1.getVel() + 1 );
            }
            else if( py >= y1 + 62 && ( py - pelota1.getAncho() / 2 )  <= y1 + paleta1.getAlto() )
            //GOLPE ESQUINA INFERIOR DE PALETA1. EJE Y>X
            {
                if( diry == -1 )
                {
                    diry = 1;
                }
                play_sample( hit , 200 , 150 , 1000 , 0 );
                pelota1.setVelX( pelota1.getVel() - 1 );
                pelota1.setVelY( pelota1.getVel() + 1 );
            }
            else if( py >= y1 + 31 && py <= y1 + paleta1.getAlto() - 32 )
            //GOLPE EN EL MEDIO DE LA PALETA. Y=X
            {
                play_sample( hit , 200 , 150 , 1000 , 0 );
                pelota1.setVelX( pelota1.getVel() );
                pelota1.setVelY( pelota1.getVel() );
            }
            dirx *= -1;
        }
        else
        //PALETA1 PIERDE
        {
            if( ( py > y1 + paleta1.getAlto() ) && ( px > paleta1.getAncho() + pelota1.getAncho() / 2 ) && ( diry == -1 ) && ( px > 0 ) )
            //PALETA1 REBOTE 0
            {
                play_sample( hit , 200 , 150 , 1000 , 0 );
                diry = -1;
            }
            else if( ( py < y1 ) && ( px > paleta1.getAncho() + pelota1.getAncho() / 2 ) && ( diry == 1 ) && ( px > 0 ) )
            {
                play_sample( hit , 200 , 150 , 1000 , 0 );
                diry = 1;
            }
            if( px <= 0 )
            {
                funciones.setMensaje( 1 );
                play_sample( punto , 200 , 150 , 1000 , 0 );
                resetPelota( pelota1 , pelota2 , paleta1 , 1 , jugadores , funciones , buffer , jugador1 , jugador2 , level_up , winner);
                return;
            }
        }
	}
    else if ( px >= ANCHO - paleta2.getAncho() - pelota1.getAncho() / 2 )
    //GOLPE BORDE INTERIOR DE PALETA2
	{
	   if ( ( py + pelota1.getAncho() / 2 ) >= y2 && ( py - pelota1.getAncho() / 2 ) <= y2 + paleta2.getAlto())
           //GOLPE LIMITES LARGO DE PALETA
           {
               if( ( py + pelota1.getAncho() / 2 ) >= y2 && py <= y2 + paleta2.getAlto() - 63 )
               //GOLPE ESQUINA SUPERIOR. VELOCIDAD DE EJE Y>X
               {
                   if( diry == 1 )
                   {
                       diry = -1;
                   }
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   pelota1.setVelX( pelota1.getVel() - 1 );
                   pelota1.setVelY( pelota1.getVel() + 1 );
               }
               else if( py >= y2 + 62 && ( py - pelota1.getAncho() / 2 ) <= y2 + paleta2.getAlto() )
               //GOLPE ESQUINA INFERIOR. VELOCIDAD DE EJE Y>X
               {
                   if( diry == -1 )
                   {
                       diry = 1;
                   }
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   pelota1.setVelX( pelota1.getVel() - 1 );
                   pelota1.setVelY( pelota1.getVel() + 1 );
               }
               else if( py >= y2 + 31 && py <= y2 + paleta1.getAlto() - 32 )
               //GOLPE MEDIO DE LA PALETA
               {
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   pelota1.setVelX( pelota1.getVel() );
                   pelota1.setVelY( pelota1.getVel() );
               }
               dirx *= -1;
           }
           else
           //PIERDE PALETA2
           {
               if(( ( py - pelota1.getAncho() / 2 ) > y2 + paleta2.getAlto() ) && ( px > ANCHO - paleta2.getAncho() - pelota1.getAncho() / 2 ) && ( diry == -1 ) && ( px < ANCHO ) )
               //PALETA2 REBOTE 0
               {
                    play_sample( hit , 200 , 150 , 1000 , 0 );
                    diry = 1;
               }
               else if( ( ( py + pelota1.getAncho() / 2 ) < y2 ) && ( px > ANCHO - paleta2.getAncho() - pelota1.getAncho() / 2 ) && ( diry == 1 ) && ( px < ANCHO ) )
               {
                   play_sample( hit , 200 , 150 , 1000 , 0 );
                   diry = -1;
               }
               if( px >= ANCHO )
               {
                   //PUNTO
                   funciones.setMensaje( 1 );
                   play_sample( punto , 200 , 150 , 1000 , 0 );
                   resetPelota( pelota1 , pelota2 , paleta2 , 2 , jugadores , funciones , buffer , jugador1 , jugador2 , level_up , winner);
                   return;
               }
          }
	}
	else if (( diry < 0 && py <= 0 ) || ( diry > 0 &&  py >= ( ALTO-pelota1.getAlto() ) ))
    //REBOTE PARED
    {
	    play_sample( wall , 200 , 150 , 1000 , 0 );
        diry *= -1;
	}
/*
	if( ( pelota1.getX() <= paleta1.getAncho() + pelota1.getAncho() / 2 )  && ( pelota1.getY() >= paleta1.getY() ) && ( pelota1.getY() <= paleta1.getY() + paleta1.getAlto() ) && ( key[KEY_ALT] ) )
    //PROPULSION PALETA1
    {
        funciones.setPropulsion( 1 );
        jugadores.setDisparos1( jugadores.getDisparos1() - 1 );
    }
    if( ( funciones.getPropulsion() == 1 ) && ( jugadores.getDisparos1 () >= 0 ) )
    {
        golpe_especialp1( pelota1 , paleta1 , buffer , funciones.getPropulsion() , funciones , diry , jugadores );
    }

    //PROPULSION PALETA2
    if( ( pelota1.getX() >= ANCHO - paleta2.getAncho() - pelota1.getAncho() / 2 ) && ( pelota1.getY() >= paleta2.getY() ) && ( pelota1.getY() <= paleta2.getY() + paleta2.getAlto() ) && ( key[KEY_ALTGR] ) )
    {
        funciones.setPropulsion( 2 );
        jugadores.setDisparos2( jugadores.getDisparos2() - 1 );
    }
    if( funciones.getPropulsion() == 2 && jugadores.getDisparos2() >= 0  )
    {
        golpe_especialp2( pelota1 , paleta2 , buffer , funciones.getPropulsion() , funciones , diry , jugadores );
    }
*/
    //MOVIMIENTOS CONSTANTES DE PELOTA
    pelota1.setX( pelota1.getX() + pelota1.getVelX() * dirx );
    pelota1.setDirX( dirx );
    pelota1.setDirY( diry );
    pelota1.setY( pelota1.getY() + pelota1.getVelY() * diry );
    pelota1.setDirX( dirx );
    pelota1.setDirY( diry );
    pelota2.setX( pelota2.getX() + pelota2.getVelX() * dirxB );
    pelota2.setDirX( dirxB );
    pelota2.setDirY( diryB );
    pelota2.setY( pelota2.getY() + pelota2.getVelY() * diryB );
    pelota2.setDirX( dirxB );
    pelota2.setDirY( diryB );
}
void golpe_especialp1( Pelota<int,float> &pelota , Paleta<int> paleta , BITMAP *buffer , int propulsion , Funcionalidad<int,bool> &funciones , int diry , Jugador<int> &jugadores )
{
    int i;
    int j = rand() % 80; //EJE X
    int k = rand() % 50; //EJE Y ( Y*2 = 100 )


    if( pelota.getX() < 700 && diry > 0 )
    //DIBUJOS ESTELA DE PELOTA PALETA1. DIRECCION DE Y POSITIVA
    {
        for( i=0 ; i<1000 ; i++ )
        {
            line( buffer , pelota.getX() - j , pelota.getY() - k , pelota.getX() - j , pelota.getY() - k , 0xFFFFFF);
            line( buffer , pelota.getX() - j - 5 , pelota.getY() - ( k + 3 ) , pelota.getX() - j - 5 , pelota.getY() - ( k + 3 ) , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 15 , pelota.getY() - ( k + 7 ) , pelota.getX() - j - 15 , pelota.getY() - ( k + 7 ) , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 3 , pelota.getY() - ( k + 3 ) , pelota.getX() - j - 3 , pelota.getY() - ( k + 3 ) , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 10 , pelota.getY() - ( k + 7 ) , pelota.getX() - j - 10 , pelota.getY() - ( k + 7 ) , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 7 , pelota.getY() - k , pelota.getX() - j - 7 , pelota.getY() - k , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 12 , pelota.getY() - ( k + 1 ) , pelota.getX() - j - 12 , pelota.getY() - ( k + 1 ) , 0x00FCFE );
            line( buffer , pelota.getX() - j - 30 , pelota.getY() - ( k+ 8 ) , pelota.getX() - j - 30 , pelota.getY() - ( k + 8 ) , 0x00FCFE );
            line( buffer , pelota.getX() - j - 32 , pelota.getY() - ( k+ 10 ) , pelota.getX() - j - 32 , pelota.getY() - ( k + 10 ) , 0x00FCFE );
            line( buffer , pelota.getX() - j - 37 , pelota.getY() - ( k + 1 ) , pelota.getX() - j - 37 , pelota.getY() -( k + 1 ), 0x00FCFE );
            line( buffer , pelota.getX() - j - 40 , pelota.getY() - ( k + 8 ) , pelota.getX() - j - 40 , pelota.getY() -( k + 8 ), 0x00FCFE );
            line( buffer , pelota.getX() - j - 14, pelota.getY() - ( k + 10 ), pelota.getX() - j - 14 , pelota.getY() -( k + 10 ), 0x00FCFE );
        }
    }
    else if( pelota.getX() < 700 && diry < 0 )
    //DIBUJOS ESTELA DE PELOTA PALETA1. DIRECCION DE Y NEGATIVA
    {
        for( i=0 ; i<1000 ; i++ )
        {
            line( buffer , pelota.getX() - j , pelota.getY() + k , pelota.getX() - j , pelota.getY() + k , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 5 , pelota.getY() + k + 3 , pelota.getX() - j - 5 , pelota.getY() + k + 3 , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 15 , pelota.getY() + k + 7 , pelota.getX() - j - 15 , pelota.getY() + k + 7 , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 3 , pelota.getY() + k + 3 , pelota.getX() - j - 3 , pelota.getY() + k + 3 , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 10 , pelota.getY() + k + 7 , pelota.getX() - j - 10 , pelota.getY() + k + 7 , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 7 , pelota.getY() + k , pelota.getX() - j - 7 , pelota.getY() + k , 0xFFFFFF );
            line( buffer , pelota.getX() - j - 12 , pelota.getY() + k + 1 , pelota.getX() - j - 12 , pelota.getY() + k + 1 , 0x00FCFE );
            line( buffer , pelota.getX() - j - 30 , pelota.getY() + k + 8 , pelota.getX() - j - 30 , pelota.getY() + k + 8 , 0x00FCFE );
            line( buffer , pelota.getX() - j - 32 , pelota.getY() + k + 10 , pelota.getX() - j - 32 , pelota.getY() + k + 10 , 0x00FCFE );
            line( buffer , pelota.getX() - j - 37 , pelota.getY() + k + 1 , pelota.getX() - j - 37 , pelota.getY() + k + 1, 0x00FCFE );
            line( buffer , pelota.getX() - j - 40 , pelota.getY() + k + 8 , pelota.getX() - j - 40 , pelota.getY() + k + 8, 0x00FCFE );
            line( buffer , pelota.getX() - j - 14 , pelota.getY() + k + 10 , pelota.getX() - j - 14 , pelota.getY() + k + 10, 0x00FCFE );
        }
    }
    else if ( pelota.getX() > 700 )
    //PROPULSOR SET 0, PARA ASI DEJAR DE TENER ESTELA
    {
        funciones.setPropulsion( 0 );
    }

    if( pelota.getX() <= paleta.getAncho() + pelota.getAncho() / 2 )
    //ACUMULADOR DE VELOCIDAD
    {
        pelota.setVelX( pelota.getVelX() + 1.2 );
        pelota.setVelY( pelota.getVelY() + 1.2 );
    }
}
void golpe_especialp2( Pelota<int,float> &pelota , Paleta<int> paleta , BITMAP *buffer , int propulsion , Funcionalidad<int,bool> &funciones , int diry , Jugador<int> &jugadores)
{
    int i = 0;
    int j = rand() % 80; // EJE X
    int k = rand() % 50; // EJE Y ( Y*2 = 100)

    //DIBUJOS ESTELA DE PELOTA PALETA2. DIRECCION DE Y POSITIVA
    if( pelota.getX() > 300 && diry > 0 )
    {
        for( i=0 ; i<1000 ; i++ )
        {
            line( buffer , pelota.getX() + j , pelota.getY() - k , pelota.getX() + j , pelota.getY() - k , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 5 , pelota.getY() - ( k + 3 ) , pelota.getX() + j + 5 , pelota.getY() - ( k + 3 ) , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 15 , pelota.getY() - ( k + 7 ) , pelota.getX() + j + 15 , pelota.getY() -( k + 7 ) , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 3 , pelota.getY() - ( k + 3 ) , pelota.getX() + j + 3 , pelota.getY() - ( k + 3 ), 0xFFFFFF );
            line( buffer , pelota.getX() + j + 10 , pelota.getY() - ( k + 7 ) , pelota.getX() + j + 10 , pelota.getY() - ( k + 7 ) , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 7 , pelota.getY() - k , pelota.getX() + j + 7 , pelota.getY() - k , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 12 , pelota.getY() - ( k + 1 ) , pelota.getX() + j + 12 , pelota.getY() - ( k + 1 ) , 0x00FCFE );
            line( buffer , pelota.getX() + j + 30 , pelota.getY() - ( k + 8 ) , pelota.getX() + j + 30 , pelota.getY() - ( k + 8 ) , 0x00FCFE );
            line( buffer , pelota.getX() + j + 32 , pelota.getY() - ( k + 10 ) , pelota.getX() + j + 32 , pelota.getY() - ( k + 10 ) , 0x00FCFE );
            line( buffer , pelota.getX() + j + 37 , pelota.getY() - ( k + 1 ) , pelota.getX() + j + 37 , pelota.getY() -(k + 1 ) , 0x00FCFE );
            line( buffer , pelota.getX() + j + 40 , pelota.getY() - ( k + 8 ), pelota.getX() + j + 40 , pelota.getY() -(k + 8 ) , 0x00FCFE );
            line( buffer , pelota.getX() + j + 14 , pelota.getY() - ( k + 10 ), pelota.getX() + j + 14 , pelota.getY() -(k + 10 ) , 0x00FCFE );
        }
    }
    else if( pelota.getX() > 300 && diry < 0 )
    //DIBUJOS ESTELA DE PELOTA PALETA2. DIRECCION DE Y NEGATIVA
    {
        for( i=0 ; i<1000 ; i++ )
        {
            line( buffer , pelota.getX() + j , pelota.getY() + k , pelota.getX()+j , pelota.getY() + k , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 5 , pelota.getY() + k + 3 , pelota.getX() + j + 5 , pelota.getY() + k + 3 , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 15 , pelota.getY() + k + 7 , pelota.getX() + j + 15 , pelota.getY() + k + 7 , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 3 , pelota.getY() + k + 3 , pelota.getX() + j + 3 , pelota.getY() + k + 3, 0xFFFFFF );
            line( buffer , pelota.getX() + j + 10 , pelota.getY() + k + 7 , pelota.getX() + j + 10 , pelota.getY() + k + 7, 0xFFFFFF );
            line( buffer , pelota.getX() + j + 7 , pelota.getY() + k , pelota.getX() + j + 7 , pelota.getY() + k , 0xFFFFFF );
            line( buffer , pelota.getX() + j + 12 , pelota.getY() + k + 1 , pelota.getX() + j + 12 , pelota.getY() + k+ 1 , 0x00FCFE );
            line( buffer , pelota.getX() + j + 30 , pelota.getY() + k + 8 , pelota.getX() + j + 30 , pelota.getY() + k + 8 , 0x00FCFE );
            line( buffer , pelota.getX() + j + 32 , pelota.getY() + k + 10 , pelota.getX() + j + 32 , pelota.getY() + k+ 10 , 0x00FCFE );
            line( buffer , pelota.getX() + j + 37 , pelota.getY() + k + 1 , pelota.getX() + j + 37 , pelota.getY() + k + 1 , 0x00FCFE );
            line( buffer , pelota.getX() + j + 40 , pelota.getY() + k + 8 , pelota.getX() + j + 40 , pelota.getY() + k + 8 , 0x00FCFE );
            line( buffer , pelota.getX() + j + 14 , pelota.getY() + k + 10, pelota.getX() + j + 14 , pelota.getY() + k + 10 , 0x00FCFE );
        }
    }
    else if ( pelota.getX() < 300 )
    //PROPULSOR SET 0. PARA ASI DEJAR DE TENER ESTELA
    {
        funciones.setPropulsion( 0 );
    }

    if( pelota.getX() >= ANCHO - paleta.getAncho() - pelota.getAncho() / 2 )
    //ACUMULADOR DE VELOCIDAD
    {
        pelota.setVelX( pelota.getVelX() + 1.2 );
        pelota.setVelY( pelota.getVelY() + 1.2 );
    }
}
