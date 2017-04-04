

/////////////////////////////////////////////// RPI_SETUP /////////////////////////////////////////////////
                                       // S I M O N - Raspberry Pi //

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Trabajo Práctico Final - Programacion 1
//
//  Entrega: 15 de Diciembre de 2016                       ////////////////
//                                                        //  S I M O N //
//  Grupo 6:González Bigliardi, Iñaki                    ////////////////
//          Lago, Valentina
//          Müller, Malena
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           Configuraciones necesarias para jugar con botones y leds, desde la Raspberry Pi.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include "rpi_setup.h"


char AudioFile_RED[] = "./resources/sounds/red.wav";
char AudioFile_GREEN[] = "./resources/sounds/green.wav";
char AudioFile_BLUE[] = "./resources/sounds/blue.wav";
char AudioFile_YELLOW[] = "./resources/sounds/yellow.wav";

pinsT leds[] = {{"RED",7,OUTPUT,LOW},           // Informacion inicial de cada LED.
                {"GREEN",1,OUTPUT,LOW},
                {"BLUE",5,OUTPUT,LOW},
                {"YELLOW",2,OUTPUT,LOW}};
        
pinsT buttons[] = {{"RED",0,INPUT,LOW},         // Informacion inicial de cada BOTON.
                   {"GREEN",4,INPUT,LOW},
                   {"BLUE",6,INPUT,LOW},
                   {"YELLOW",3,INPUT,LOW}};


////////////////////////////////////// configuration_start ///////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: 0.
//
//  Se lleva a cabo la configuracion necesaria para el correcto funcionamiento del juego.
//  Se prepara el hardware necesario en el modo deseado: Sonido, direccion y valor inicial de pines.
//  Se llama al juego en si (simon_main).
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

int configuration_start (void)
{
        wiringPiSetup();

        init_sound();
        
        pin_out_or_in ();
    
        set_pin_zero_or_one ();
    
        leds_game ();
        
        simon_main ();
            
        return 0;
}


//////////////////////////////////////// configuration_end ////////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void configuration_end (void)
{
	char AudioFile_game_over[] = "./resources/sounds/buzz.wav";
    
	play_color(AudioFile_game_over);
    
    do_something();
    
    leds_game ();
}


////////////////////////////////////////// pin_out_or_in //////////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//  Configura la direccion de cada pin que sera usado de la Raspberry Pi.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void pin_out_or_in (void)
{
    int i;
    
    for (i=0 ; i <= CANT_COLORS ;i++ )
    {
            pinMode (leds[i].pin, leds[i].direction);
        
            pinMode (buttons[i].pin, buttons[i].direction);
    }
}


//////////////////////////////////////// set_pin_zero_or_one //////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//  Configura el valor inicial de cada pin que sera usado como led, de la Raspberry Pi.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void set_pin_zero_or_one (void)
{
    int i;
    
    for (i=0 ;i <= CANT_COLORS ;i++ )
    {
            digitalWrite (leds[i].pin, leds[i].value);
    }
}

