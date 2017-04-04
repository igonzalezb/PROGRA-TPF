

//////////////////////////////////////////// RPI_OUTPUT ///////////////////////////////////////////////
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
//        Acciones del output, siempre y cuando la logica del juego permita salida de datos.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include "rpi_output.h"


extern pinsT leds[];
extern char AudioFile_RED[];
extern char AudioFile_GREEN[];
extern char AudioFile_BLUE[];
extern char AudioFile_YELLOW[];

//////////////////////////////////////// set_color_mode ///////////////////////////////////////////////
//
//  Recibe: color y color_mode (esta ultima es el estado a modificar del pin: HIGH
//
//  Devuelve: Nada.
//
//  Se prende o se apaga el led indicado.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void set_color_mode (int color, int color_mode)
{
        leds[color].value = color_mode;
    
        digitalWrite (leds[color].pin, leds[color].value);
    
        if (color_mode == ON)
        {
                switch(color)
        		{
                        case LED_RED:
                        play_color(AudioFile_RED);
                        do_something();
                        break;
                        
                        case LED_GREEN:
                        play_color(AudioFile_GREEN);
                        do_something();
                        break;
                        
                        case LED_BLUE:
                        play_color(AudioFile_BLUE);
                        do_something();
                        break;
                        
                        case LED_YELLOW:
                        play_color(AudioFile_YELLOW);
                        do_something();
                        break;
        		}
        }
        else if (color_mode == OFF)
        {
                stop_sound();
        }
}


////////////////////////////////////////// play_color /////////////////////////////////////////////////
//
//  Recibe: AudioFile.
//
//  Devuelve: Nada.
//
//  Se prende la musica del color desde el que se llama.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void play_color (char * AudioFile)                      // Non blocking Audio File
{
        stop_sound();                                   // stop previous audio track (Just in case)
 	
        if(player_status()==READY)
        {
			
                printf("Playing: %s \n",AudioFile);
	
                set_file_to_play(AudioFile);            // Load file
	
                play_sound();                           // Play File (Non Blocking)
        }
        else
        {
                printf("System not ready did you run init_sound() ? \n");
				
                exit(-1);
        }
}


////////////////////////////////////////// play_color /////////////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//  Espera.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void do_something (void)
{
        int i;
				
        for(i=0; i<PLAY_TIME; i++)                      // Do someting else for a while
        {
            printf("Playing ...\n");                    // show this every 300 ms while playing the sound in background
	    
            SDL_Delay(300);
        }
}


////////////////////////////////////////// leds_game /////////////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//  Juego de leds para inicio y final del juego
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void leds_game ()
{
    int i;
    
    int round;
    
    for (round = 0; round <= 2; round++)
    {
        for (i = RED; i <= YELLOW; i++)
        {
            digitalWrite (leds[i].pin, HIGH);
        }
        
        WAIT_T(100000);
        
        for (i = RED; i <= YELLOW; i++)
        {
            digitalWrite (leds[i].pin, LOW);
        }
    }
    
    for (round = 0; round < 2; round++)
    {
        for (i = RED; i <= YELLOW; i++)
        {
            digitalWrite (leds[i].pin, HIGH);
            
            WAIT_T(100000);
            
            digitalWrite (leds[i].pin, LOW);
            
            WAIT_T(100000);
        }
    }
    
    for (round = 0; round <= 2; round++)
    {
        for (i = RED; i <= YELLOW; i++)
        {
            digitalWrite (leds[i].pin, HIGH);
        }
        
        WAIT_T(100000);
        
        for (i = RED; i <= YELLOW; i++)
        {
            digitalWrite (leds[i].pin, LOW);
        }
    }
    
    WAIT_T(200000);
}

