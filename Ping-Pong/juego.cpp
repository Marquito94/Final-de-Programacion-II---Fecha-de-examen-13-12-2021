#include "juego.h"

Paleta<int> paletaV1;
Paleta<int> paletaV2;
Pelota<int,float> pelotaV;
Jugador<int> jugadoresV;
Funcionalidad<int,bool> funcionV;
bitmaps *bits;
samples *audio;

bool ventana = false;
bool portada = false;
long tiempo = 0;

template <class type1>
int Paleta<type1>::count = 0;

void setter_de_clases ()
{
    resetPelota(pelotaV,funcionV);
    pelotaV.setVelX(5);
    pelotaV.setVelY(5);
    pelotaV.setVel(5);
    pelotaV.setAlto(15);
    pelotaV.setAncho(15);
    paletaV1.setX(0);
    jugadoresV.setDisparos1(5);
    jugadoresV.setDisparos2(5);
    funcionV.setContador(0);
    funcionV.setPropulsion(0);
    paletaV1.setY(ALTO/2-50);
    paletaV1.setTamano(15,94);
    paletaV2.setX(ANCHO-paletaV1.getAncho());
    paletaV2.setY(ALTO/2-50);
    paletaV2.setTamano(15,94);
}
void destructores ()
{
    destroy_bitmap( bits[0].mapa_de_bits );
    destroy_bitmap( bits[1].mapa_de_bits );
    destroy_bitmap( bits[2].mapa_de_bits );
    destroy_bitmap( bits[3].mapa_de_bits );
    destroy_bitmap( bits[4].mapa_de_bits );
    destroy_bitmap( bits[5].mapa_de_bits );
    destroy_bitmap( bits[6].mapa_de_bits );
    destroy_bitmap( bits[7].mapa_de_bits );
    destroy_bitmap( bits[8].mapa_de_bits );
    destroy_bitmap( bits[9].mapa_de_bits );
    destroy_bitmap( bits[10].mapa_de_bits );
}
void first_screen()
{
    play_sample(audio[0].muestra_de_audio,200,150,1000,0);
    while(!portada)
    {
        if(key[KEY_ENTER])
            portada = true;

        blit(bits[8].mapa_de_bits,screen,0,0,0,0,ANCHO,ALTO);
    }
}
void inicializaciones()
{
    allegro_init();
    set_window_title("Tennis de Mesa");
    install_keyboard();
    install_timer();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    set_volume(230,200);
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,ANCHO,ALTO,0,0);
    install_int_ex(incremento,BPS_TO_TIMER(70));
    set_close_button_callback(cerrar_ventana);

    SAMPLE *audio1 = load_wav("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/audio/Intro.wav");
    SAMPLE *audio2 = load_wav("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/audio/Hit.wav");
    SAMPLE *audio3 = load_wav("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/audio/Punto.wav");
    SAMPLE *audio4 = load_wav("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/audio/Saque.wav");
    SAMPLE *audio5 = load_wav("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/audio/Level-Up.wav");
    SAMPLE *audio6 = load_wav("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/audio/Winner.wav");
    SAMPLE *audio7 = load_wav("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/audio/WallHit.wav");
    BITMAP *buffer = create_bitmap(ANCHO,ALTO);
    BITMAP *buffer1 = create_bitmap(ANCHO,ALTO);
    //BITMAP *buffer1 = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/nivel1.bmp",NULL);
    BITMAP *buffer2 = create_bitmap(ANCHO,ALTO);
    //BITMAP *buffer2 = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/nivel2.bmp",NULL);
    BITMAP *buffer3 = create_bitmap(ANCHO,ALTO);
    //BITMAP *buffer3 = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/nivel3.bmp",NULL);
    BITMAP *buffer4 = create_bitmap(ANCHO,ALTO);
    //BITMAP *buffer4 = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/nivel4.bmp",NULL);
    BITMAP *buffer5 = create_bitmap(ANCHO,ALTO);
    //BITMAP *buffer5 = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/nivel5.bmp",NULL);
    BITMAP *paleta_izq = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/paleta1.bmp",NULL);
    BITMAP *paleta_der = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/paleta2.bmp",NULL);
    BITMAP *inicio = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/portada.bmp",NULL);
    BITMAP *jugador1w = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/player1_wins.bmp",NULL);
    BITMAP *jugador2w = load_bitmap("C:/Users/marco/OneDrive/Documentos/Programas C-C++/Ping-Pong/imagenes/player2_wins.bmp",NULL);

    bits = (bitmaps *) malloc(sizeof(bitmaps)*11);
    bits[0].mapa_de_bits = buffer;
    bits[1].mapa_de_bits = buffer1;
    bits[2].mapa_de_bits = buffer2;
    bits[3].mapa_de_bits = buffer3;
    bits[4].mapa_de_bits = buffer4;
    bits[5].mapa_de_bits = buffer5;
    bits[6].mapa_de_bits = paleta_izq;
    bits[7].mapa_de_bits = paleta_der;
    bits[8].mapa_de_bits = inicio;
    bits[9].mapa_de_bits = jugador1w;
    bits[10].mapa_de_bits = jugador2w;

    audio = (samples *) malloc(sizeof(samples)*7);
    audio[0].muestra_de_audio = audio1;
    audio[1].muestra_de_audio = audio2;
    audio[2].muestra_de_audio = audio3;
    audio[3].muestra_de_audio = audio4;
    audio[4].muestra_de_audio = audio5;
    audio[5].muestra_de_audio = audio6;
    audio[6].muestra_de_audio = audio7;

    setter_de_clases();

    first_screen();
}
void loop_del_juego ()
{
    while(!funcionV.getVentana())
    {
        if(key[KEY_ESC])
            funcionV.setVentana(true);

        clear_to_color(bits[1].mapa_de_bits,0x003800);
        clear_to_color(bits[2].mapa_de_bits,0x370000);
        clear_to_color(bits[3].mapa_de_bits,0x060739);
        clear_to_color(bits[4].mapa_de_bits,0x363300);
        clear_to_color(bits[5].mapa_de_bits,0x000000);

        //INICIALIZACION Y ACTUALIZACION  DE JUEGO
        while(tiempo>0)
        {
            if (funcionV.getResultado() == 1)
            {
                if(key[KEY_SPACE])
                {
                    play_sample(audio[3].muestra_de_audio,200,150,1000,0);
                    funcionV.setResultado(0);
                }
                tiempo = 0;
                continue;
            }

            //MOVIMIENTOS;
            int posy1 = ALTO - paletaV1.getAlto();
            int posy2 = ALTO - paletaV2.getAlto();
            int posx1 = paletaV1.getY();
            int posx2 = paletaV2.getY();
            int movSpeed = 3;

            if ( key[KEY_W] )
            {
                if( paletaV1.getY() >= 0 && posx1 <= posy1 )
                {
                    paletaV1.setY( paletaV1.getY() - movSpeed );
                }

                else
                {
                    paletaV1.setY( ( paletaV1.getY() < 0 ) ?0 : posy1 );
                }
            }
            else if( key[KEY_S] )
            {
                if( paletaV1.getY() >= 0 && posx1 <= posy1 )
                {
                    paletaV1.setY( paletaV1.getY() + movSpeed );
                }
                else
                {
                    paletaV1.setY( ( paletaV1.getY() < 0 ) ?0 : posy1 );
                }
            }
            if ( key[KEY_UP] )
            {
                if( paletaV2.getY() >= 0 && posx2 <= posy2 )
                {
                    paletaV2.setY( paletaV2.getY() - movSpeed );
                }
                else
                {
                    paletaV2.setY( ( paletaV2.getY() < 0 ) ?0 : posy2 );
                }
            }
            else if( key[KEY_DOWN] )
            {
                if( paletaV2.getY() >= 0 && posx2 <= posy2 )
                {
                    paletaV2.setY( paletaV2.getY() + movSpeed );
                }
                else
                {
                    paletaV2.setY( ( paletaV2.getY() < 0 ) ?0 : posy2 );
                }
            }

            moverPelota( pelotaV , paletaV1 , paletaV2 , jugadoresV , funcionV , bits[0].mapa_de_bits , bits[9].mapa_de_bits , bits[10].mapa_de_bits , audio[4].muestra_de_audio , audio[5].muestra_de_audio , audio[6].muestra_de_audio , audio[1].muestra_de_audio , audio[2].muestra_de_audio );

            tiempo--;

        }

        //FUNCIONES Y SETTERS DE PALETAS, PELOTAS, MESA
        dibujar_mesa( bits[0].mapa_de_bits );
        dibujar_pelota( bits[0].mapa_de_bits , pelotaV );
        tablero( bits[0].mapa_de_bits );
        textprintf_ex( bits[0].mapa_de_bits , font, 10, 20, 0xD1D1D1, -1, "Puntos P1: %d", jugadoresV.getPuntaje1() ) ;
        textprintf_ex( bits[0].mapa_de_bits , font, 880, 20, 0xD1D1D1, -1, "Puntos P2: %d", jugadoresV.getPuntaje2() ) ;
        textprintf_ex( bits[0].mapa_de_bits , font, 10, 40, 0xD1D1D1, -1, "Disparos 1: %d", jugadoresV.getDisparos1() ) ;
        textprintf_ex( bits[0].mapa_de_bits , font, 880, 40, 0xD1D1D1, -1, "Disparos 2: %d", jugadoresV.getDisparos2() ) ;
        textprintf_ex( bits[0].mapa_de_bits , font, 900, 480, 0xD1D1D1, -1, "LEVEL %d", funcionV.getNivel() ) ;

        //BITMAPS
        masked_blit( bits[6].mapa_de_bits , bits[0].mapa_de_bits , 0, 0, paletaV1.getX(), paletaV1.getY(), 15, 94);
        //draw_sprite( bits[0].mapa_de_bits ,bits[6].mapa_de_bits , paleta_1.getX(), paleta_1.getY()) ;
        masked_blit( bits[7].mapa_de_bits , bits[0].mapa_de_bits , 0, 0, paletaV2.getX(), paletaV2.getY(), 15, 94);
        //draw_sprite( bits[0].mapa_de_bits ,bits[7].mapa_de_bits , paleta_2.getX(), paleta_2.getY()) ;

        if(funcionV.getContador()<4)
        {
            funcionV.setNivel(1);
            bits[0].mapa_de_bits = bits[1].mapa_de_bits;
            blit(bits[0].mapa_de_bits,screen,0,0,0,0,ANCHO,ALTO);
        }
        else if(funcionV.getContador()<8)
        {
            funcionV.setNivel(2);
            bits[0].mapa_de_bits = bits[2].mapa_de_bits;
            blit(bits[0].mapa_de_bits,screen,0,0,0,0,ANCHO,ALTO);
        }
        else if(funcionV.getContador()<12)
        {
            funcionV.setNivel(3);
            bits[0].mapa_de_bits = bits[3].mapa_de_bits;
            blit(bits[0].mapa_de_bits,screen,0,0,0,0,ANCHO,ALTO);
        }
        else if(funcionV.getContador()<16)
        {
            funcionV.setNivel(4);
            bits[0].mapa_de_bits = bits[4].mapa_de_bits;
            blit(bits[0].mapa_de_bits,screen,0,0,0,0,ANCHO,ALTO);
        }
        else if(funcionV.getContador()<21)
        {
            funcionV.setNivel(5);
            bits[0].mapa_de_bits = bits[5].mapa_de_bits;
            blit(bits[0].mapa_de_bits,screen,0,0,0,0,ANCHO,ALTO);
        }

        rest( 20 );
        clear_bitmap( bits[0].mapa_de_bits );
    }
}
void cerrar_portada()
{
    portada = true;
}
void cerrar_ventana()
{
    ventana = true;
}
void incremento()
{
    tiempo++;
}
