#include "Pelotas.h"


void resetPelota( Pelota<int,float> &pelota , Funcionalidad<int,bool> &funciones )
{
	pelota.setX( ANCHO / 2 );
	pelota.setY( ALTO / 2 );
	srand( time( 0 ) );
	int direccionX = ( rand()%2)+1;
	int direccionY = ( rand()%2)+1;
	direccionX = ( direccionX == 1 )? - 1 : 1;
	direccionY = ( direccionY == 1 )? - 1 : 1;
	pelota.setDirX( direccionX );
	pelota.setDirY( direccionY );
	funciones.setResultado(1);

}

void resetPelota( Pelota<int,float> &pelota , Paleta<int> paleta , int a , Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones , BITMAP *buffer , BITMAP *jugador1 , BITMAP *jugador2 , SAMPLE *level_up , SAMPLE *winner)
{
	if ( a == 1 )
    {
		pelota.setX( paleta.getX() + paleta.getAncho() + pelota.getAncho() - 3 );
		pelota.setY( paleta.getY() + paleta.getAlto() / 2 );
		pelota.setDirX( 1 );
        jugadores.setPuntaje2(jugadores.getPuntaje2()+1);
	}
	else
	{
		pelota.setX( paleta.getX() - paleta.getAncho() / 2 - pelota.getAncho() + 7 );
		pelota.setY( paleta.getY() + paleta.getAlto() / 2 );
		pelota.setDirX( -1 );
		jugadores.setPuntaje1(jugadores.getPuntaje1()+1);
	}
	if( funciones.getContador() == 3 )
    {
        play_sample(level_up,200,150,1000,0);
        allegro_message("Cambio de nivel!!!!\nAceleracion aumentada!!!!");
        pelota.setVel(7);
    }
    else if( funciones.getContador() == 7 )
    {
        play_sample(level_up,200,150,1000,0);
        allegro_message("Cambio de nivel!!!!\nAceleracion aumentada!!!!");
        pelota.setVel(9);
    }
    else if( funciones.getContador() == 11 )
    {
        play_sample(level_up,200,150,1000,0);
        allegro_message("Cambio de nivel!!!!\nAceleracion aumentada!!!!");
        pelota.setVel(11);
    }
    else if( funciones.getContador() == 15 )
    {
        play_sample(level_up,200,150,1000,0);
        allegro_message("Cambio de nivel!!!!\nAceleracion aumentada!!!!");
        pelota.setVel(13);
    }

	if(jugadores.getPuntaje1() == 10) {
        play_sample(winner,200,150,1000,0);
        while(!key[KEY_ENTER])
        {
            blit(jugador1,screen,0,0,0,0,ANCHO,ALTO);
            jugadores.setPuntaje1(0);
            jugadores.setPuntaje2(0);
            funciones.setContador(0);
            pelota.setVelX(5);
            pelota.setVelY(5);
            pelota.setVel(5);
            jugadores.setDisparos1(5);
            jugadores.setDisparos2(5);
            funciones.setNuevo(true);
            resetPelota(pelota,funciones);
        }
        if(key[KEY_ESC])
        {
            allegro_exit();
        }
    }
    else if(jugadores.getPuntaje2() == 10) {
        play_sample(winner,200,150,1000,0);
        while(!key[KEY_ENTER])
        {
            blit(jugador2,screen,0,0,0,0,ANCHO,ALTO);
            jugadores.setPuntaje1(0);
            jugadores.setPuntaje2(0);
            funciones.setContador(0);
            pelota.setVelX(5);
            pelota.setVelY(5);
            pelota.setVel(5);
            jugadores.setDisparos1(5);
            jugadores.setDisparos2(5);
            funciones.setNuevo(true);
            resetPelota(pelota,funciones);
        }
        if(key[KEY_ESC])
        {
            allegro_exit();
        }
    }

    if( funciones.getNuevo() == true)
    {
        funciones.setNuevo(false);
    }

    pelota.setVelX(pelota.getVel());
    pelota.setVelY(pelota.getVel());
    funciones.setContador(funciones.getContador()+1);
	funciones.setResultado(1);
}

void moverPelota( Pelota<int,float> &pelota , Paleta<int> &paleta1 , Paleta<int> &paleta2 , Jugador<int> &jugadores , Funcionalidad<int,bool> &funciones , BITMAP *buffer , BITMAP *jugador1 , BITMAP *jugador2 , SAMPLE *level_up , SAMPLE *winner , SAMPLE *wall ,  SAMPLE *hit , SAMPLE *punto)
{
	int dirx = pelota.getDirX();
	int diry = pelota.getDirY();
	int px = pelota.getX();
	int py = pelota.getY();
	int y1 = paleta1.getY();
	int y2 = paleta2.getY();

	if (px <= (paleta1.getAncho()+8))
	{
		if (py>=y1 && py <= y1 + paleta1.getAlto())
		{
            if(py >= y1 && py <= y1 + paleta1.getAlto()-65)
                {
                    if(diry==1)
                    {
                        diry*=-1;
                    }
                    pelota.setVelX(pelota.getVel()-1);
                    pelota.setVelY(pelota.getVel()+1);
                }
            else if(py >= y1 + 65 && py <= y1 + paleta1.getAlto())
                {
                    if(diry==-1)
                    {
                        diry*=-1;
                    }
                    pelota.setVelX(pelota.getVel()-1);
                    pelota.setVelY(pelota.getVel()+1);
                }
            else if(py > y1 + 35 && py < y1 + paleta1.getAlto()-35)
                {
                    pelota.setVelX(pelota.getVel());
                    pelota.setVelY(pelota.getVel());
                }
            play_sample(hit,200,150,1000,0);
            dirx*=-1;
		}else{
		    if((py>y1+paleta1.getAlto()) || py<y1)
            {
                if(px<paleta1.getAncho())
                {
                    play_sample(punto,200,150,1000,0);
                    resetPelota(pelota,paleta1,1,jugadores,funciones,buffer,jugador1,jugador2,level_up,winner);
                    return;
                }
            }
		}
	}
	else if (px>= (ANCHO-(paleta2.getAncho()+8)))
	{
		if (py>=y2 && py <= y2 + paleta2.getAlto())
            {
                if(py >= y2 && py <= y1 + paleta1.getAlto()-63)
                {
                    if(diry==1)
                    {
                        diry*=-1;
                    }
                    pelota.setVelX(pelota.getVel()-1);
                    pelota.setVelY(pelota.getVel()+1);
                }
            else if(py >= y2 + 62 && py <= y2 + paleta1.getAlto())
                {
                    if(diry==-1)
                    {
                        diry*=-1;
                    }
                    pelota.setVelX(pelota.getVel()-1);
                    pelota.setVelY(pelota.getVel()+1);
                }
            else if(py > y2 + 31 && py < y2 + paleta1.getAlto()-32)
                {
                    pelota.setVelX(pelota.getVel());
                    pelota.setVelY(pelota.getVel());
                }
                play_sample(hit,200,150,1000,0);
                dirx*=-1;
            }
        else
		{
		    if(py>y2 + paleta2.getAlto() || py<y2)
            {
                if(px>=ANCHO - (paleta2.getAncho()+9))
                {
                    play_sample(punto,200,150,1000,0);
                    resetPelota(pelota,paleta2,2,jugadores,funciones,buffer,jugador1,jugador2,level_up,winner);
                    return;
                }
            }
		}
	}else if ((diry<0 && py<=0) || (diry>0 &&  py>= ( ALTO-pelota.getAlto() ))){
	    play_sample(wall,200,150,1000,0);
        diry*=-1;
	}

    if( pelota.getX() < 27 && dirx>0 && key[KEY_ALT] && (pelota.getY() < paleta1.getY()+paleta1.getY())
       && (pelota.getY() > paleta1.getY()))
    {
        funciones.setPropulsion(1);
    }
    if(funciones.getPropulsion()== 1 && jugadores.getDisparos1()>0)
    {
        golpe_especialp1(pelota, paleta1,buffer,funciones.getPropulsion(),funciones,diry,jugadores);
        if( px <= (paleta1.getAncho()+8) )
        {
            jugadores.setDisparos1(jugadores.getDisparos1()-1);
        }
    }

    if( pelota.getX() >972 && dirx<0 && key[KEY_ALTGR] && (pelota.getY() < paleta2.getY()+paleta2.getY())
       && (pelota.getY() > paleta2.getY()))
    {
        funciones.setPropulsion(2);
    }
    if(funciones.getPropulsion()== 2 && jugadores.getDisparos2()>0)
    {
        golpe_especialp2(pelota, paleta2,buffer,funciones.getPropulsion(),funciones,diry,jugadores);
        if(px>= (ANCHO-(paleta2.getAncho()+8)))
        {
            jugadores.setDisparos2(jugadores.getDisparos2()-1);
        }
    }

    pelota.setX( pelota.getX() + pelota.getVelX() * dirx );
    pelota.setDirX( dirx );
    pelota.setDirY( diry );
    pelota.setY( pelota.getY() + pelota.getVelY() * diry );
    pelota.setDirX( dirx );
    pelota.setDirY( diry );
}
void golpe_especialp1( Pelota<int,float> &pelota , Paleta<int> paleta , BITMAP *buffer , int propulsion , Funcionalidad<int,bool> &funciones , int diry , Jugador<int> &jugadores )
{
    int i;
    int j = rand()%80;
    int k = rand()%50;

    if( pelota.getX()<700 && diry>0)
    {
        for(i=0;i<1000;i++)
        {
            line( buffer , pelota.getX()-j, pelota.getY() - k , pelota.getX()-j , pelota.getY() -k , 0xFFFFFF);
            line( buffer , pelota.getX()-j-5, pelota.getY() - (k+3) , pelota.getX()-j-5 , pelota.getY() -(k+3) , 0xFFFFFF);
            line( buffer , pelota.getX()-j-15, pelota.getY() - (k+7) , pelota.getX()-j-15 , pelota.getY() -(k+7) , 0xFFFFFF);
            line( buffer , pelota.getX()-j-3, pelota.getY() - (k +3) , pelota.getX()-j-3 , pelota.getY() -(k +3) , 0xFFFFFF);
            line( buffer , pelota.getX()-j-10, pelota.getY() - (k +7) , pelota.getX()-j-10 , pelota.getY() -(k +7), 0xFFFFFF);
            line( buffer , pelota.getX()-j-7, pelota.getY() - k , pelota.getX()-j-7 , pelota.getY() -k , 0xFFFFFF);
            line( buffer , pelota.getX()-j -12, pelota.getY() - (k +1) , pelota.getX()-j -12 , pelota.getY() -(k+1) , 0x00FCFE);
            line( buffer , pelota.getX()-j- 30, pelota.getY() - (k+8) , pelota.getX()-j-30 , pelota.getY() -(k+8) , 0x00FCFE);
            line( buffer , pelota.getX()-j-32, pelota.getY() - (k+10) , pelota.getX()-j-32 , pelota.getY() -(k+10) , 0x00FCFE);
            line( buffer , pelota.getX()-j-37, pelota.getY() - (k +1) , pelota.getX()-j-37 , pelota.getY() -(k +1), 0x00FCFE);
            line( buffer , pelota.getX()-j-40, pelota.getY() - (k +8) , pelota.getX()-j-40 , pelota.getY() -(k +8), 0x00FCFE);
            line( buffer , pelota.getX()-j-14, pelota.getY() - (k +10), pelota.getX()-j-14 , pelota.getY() -(k +10), 0x00FCFE);
        }
    }
    else if( pelota.getX()<700 && diry<0)
    {
        for(i=0;i<1000;i++)
        {
            line( buffer , pelota.getX()-j, pelota.getY() + k , pelota.getX()-j , pelota.getY() +k , 0xFFFFFF);
            line( buffer , pelota.getX()-j-5, pelota.getY() + k+3 , pelota.getX()-j-5 , pelota.getY() +k+3 , 0xFFFFFF);
            line( buffer , pelota.getX()-j-15, pelota.getY() + k+7 , pelota.getX()-j-15 , pelota.getY() +k+7 , 0xFFFFFF);
            line( buffer , pelota.getX()-j-3, pelota.getY() + k +3 , pelota.getX()-j-3 , pelota.getY() +k +3, 0xFFFFFF);
            line( buffer , pelota.getX()-j-10, pelota.getY() + k + 7 , pelota.getX()-j-10 , pelota.getY() +k +7, 0xFFFFFF);
            line( buffer , pelota.getX()-j-7, pelota.getY() + k , pelota.getX()-j-7 , pelota.getY() +k , 0xFFFFFF);
            line( buffer , pelota.getX()-j -12, pelota.getY() + k +1 , pelota.getX()-j -12 , pelota.getY() +k+1 , 0x00FCFE);
            line( buffer , pelota.getX()-j- 30, pelota.getY() + k+8 , pelota.getX()-j-30 , pelota.getY() +k+8 , 0x00FCFE);
            line( buffer , pelota.getX()-j-32, pelota.getY() + k+10 , pelota.getX()-j-32 , pelota.getY() +k+10 , 0x00FCFE);
            line( buffer , pelota.getX()-j-37, pelota.getY() + k +1 , pelota.getX()-j-37 , pelota.getY() +k +1, 0x00FCFE);
            line( buffer , pelota.getX()-j-40, pelota.getY() + k +8 , pelota.getX()-j-40 , pelota.getY() +k +8, 0x00FCFE);
            line( buffer , pelota.getX()-j-14, pelota.getY() + k +10, pelota.getX()-j-14 , pelota.getY() +k +10, 0x00FCFE);
        }
    }
    else if ( pelota.getX()>700)
    {
        funciones.setPropulsion(0);
    }

    if( pelota.getX() <972 )
    {
        pelota.setVelX(pelota.getVelX()+0.1);
        pelota.setVelY(pelota.getVelY()+0.1);
    }

}
void golpe_especialp2( Pelota<int,float> &pelota , Paleta<int> paleta , BITMAP *buffer , int propulsion , Funcionalidad<int,bool> &funciones , int diry , Jugador<int> &jugadores)
{
    int i = 0;
    int j = rand()%80;
    int k = rand()%50;

    if( pelota.getX()>300 && diry<0)
    {
        for(i=0;i<1000;i++)
        {
            line( buffer , pelota.getX()+j, pelota.getY() - k , pelota.getX()+j , pelota.getY() -k , 0xFFFFFF);
            line( buffer , pelota.getX()+j+5, pelota.getY() - (k+3) , pelota.getX()+j+5 , pelota.getY() -(k+3) , 0xFFFFFF);
            line( buffer , pelota.getX()+j+15, pelota.getY() - (k+7) , pelota.getX()+j+15 , pelota.getY() -(k+7) , 0xFFFFFF);
            line( buffer , pelota.getX()+j+3, pelota.getY() - (k +3) , pelota.getX()+j+3 , pelota.getY() -(k +3), 0xFFFFFF);
            line( buffer , pelota.getX()+j+10, pelota.getY() - (k +7) , pelota.getX()+j+10 , pelota.getY() -(k +7), 0xFFFFFF);
            line( buffer , pelota.getX()+j+7, pelota.getY() - k , pelota.getX()+j+7 , pelota.getY() -k , 0xFFFFFF);
            line( buffer , pelota.getX()+j+12, pelota.getY() - (k +1) , pelota.getX()+j+12 , pelota.getY() -(k+1) , 0x00FCFE);
            line( buffer , pelota.getX()+j+30, pelota.getY() - (k+8) , pelota.getX()+j+30 , pelota.getY() -(k+8) , 0x00FCFE);
            line( buffer , pelota.getX()+j+32, pelota.getY() - (k+10) , pelota.getX()+j+32 , pelota.getY() -(k+10) , 0x00FCFE);
            line( buffer , pelota.getX()+j+37, pelota.getY() - (k +1) , pelota.getX()+j+37 , pelota.getY() -(k +1), 0x00FCFE);
            line( buffer , pelota.getX()+j+40, pelota.getY() - (k + 8), pelota.getX()+j+40 , pelota.getY() -(k +8), 0x00FCFE);
            line( buffer , pelota.getX()+j+14, pelota.getY() - (k +10), pelota.getX()+j+14 , pelota.getY() -(k +10), 0x00FCFE);
        }
    }
    else if( pelota.getX()>300 && diry>0)
    {
        for(i=0;i<1000;i++)
        {
            line( buffer , pelota.getX()+j, pelota.getY() + k , pelota.getX()+j , pelota.getY() +k , 0xFFFFFF);
            line( buffer , pelota.getX()+j+5, pelota.getY() + k+3 , pelota.getX()+j+5 , pelota.getY() +k+3 , 0xFFFFFF);
            line( buffer , pelota.getX()+j+15, pelota.getY() + k+7 , pelota.getX()+j+15 , pelota.getY() +k+7 , 0xFFFFFF);
            line( buffer , pelota.getX()+j+3, pelota.getY() + k +3 , pelota.getX()+j+3 , pelota.getY() +k +3, 0xFFFFFF);
            line( buffer , pelota.getX()+j+10, pelota.getY() + k + 7 , pelota.getX()+j+10 , pelota.getY() +k +7, 0xFFFFFF);
            line( buffer , pelota.getX()+j+7, pelota.getY() + k , pelota.getX()+j+7 , pelota.getY() +k , 0xFFFFFF);
            line( buffer , pelota.getX()+j+12, pelota.getY() + k +1 , pelota.getX()+j+12 , pelota.getY() +k+1 , 0x00FCFE);
            line( buffer , pelota.getX()+j+30, pelota.getY() + k+8 , pelota.getX()+j+30 , pelota.getY() +k+8 , 0x00FCFE);
            line( buffer , pelota.getX()+j+32, pelota.getY() + k+10 , pelota.getX()+j+32 , pelota.getY() +k+10 , 0x00FCFE);
            line( buffer , pelota.getX()+j+37, pelota.getY() + k +1 , pelota.getX()+j+37 , pelota.getY() +k +1, 0x00FCFE);
            line( buffer , pelota.getX()+j+40, pelota.getY() + k +8 , pelota.getX()+j+40 , pelota.getY() +k +8, 0x00FCFE);
            line( buffer , pelota.getX()+j+14, pelota.getY() + k +10, pelota.getX()+j+14 , pelota.getY() +k +10, 0x00FCFE);
        }
    }
    else if ( pelota.getX()<300)
    {
        funciones.setPropulsion(0);
    }

    if( pelota.getX() > 28 )
    {
        pelota.setVelX(pelota.getVelX()+0.1);
        pelota.setVelY(pelota.getVelY()+0.1);
    }

}
