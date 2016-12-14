

//////////////////////////////////////////// RPI_INPUT ///////////////////////////////////////////////
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
//        Analisis del input, siempre y cuando la logica del juego permita entrada de datos.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rpi_input.h"


extern pinsT buttons[];
extern bool exit_simon, player_lost;

bool exit_teclado = false;


////////////////////////////////////// buttons_teclado_input /////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//  Si esta corriendo el juego, si el jugador no perdio y si el ingreso de datos por botones esta
//  habilitado, entonces se leen chequea si se ingresan colores. En caso de tocar un boton, se prende
//  el color correspondiente y se envia el color para ser comparado con el que se debia haber ingresado.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_teclado_input (void)
{
        int color;
    
        while (!exit_simon && !player_lost && !exit_teclado)
        {
                usleep(3000);
            
                if(!digitalRead(buttons[LED_RED].pin))              // Si se ingreso ROJO
                {
                        color = LED_RED;
                    
                        printf("CLICK: %d\n", color);
                                
                        set_color_mode (color, ON);
                    
                        while (!digitalRead(buttons[LED_RED].pin))  // Se contempla el caso en el que se mantiene
                        {                                           // apretada una tecla.
                                continue;
                        
                        }
                    
                        printf("UP: %d\n", color);
                    
                        comparacion_validacion(color);
                    
                        set_color_mode (color, OFF);
                                 
                }
                else if(!digitalRead(buttons[LED_GREEN].pin))       // Si se ingreso VERDE
                {
                        color = LED_GREEN;
                            
                        printf("CLICK: %d\n", color);
                    
                        set_color_mode (color, ON);
                            
                        while (!digitalRead(buttons[LED_GREEN].pin))
                        {
                                continue;
                        }
                        printf("UP: %d\n", color);
                    
                        comparacion_validacion(color);
                            
                        set_color_mode (color, OFF);
                }
                else if(!digitalRead(buttons[LED_BLUE].pin))        // Si se ingreso AZUL
                {
                        color = LED_BLUE;
                    
                        printf("CLICK: %d\n", color);
                                
                        set_color_mode (color, ON);
                        while (!digitalRead(buttons[LED_BLUE].pin))
                        {
                                continue;
                        }
                        printf("UP: %d\n", color);
                    
                        comparacion_validacion(color);
                    
                        set_color_mode (color, OFF);
                                
                }
                else if(!digitalRead(buttons[LED_YELLOW].pin))      // Si se ingreso AMARILLO
                {
                        color = LED_YELLOW;
                    
                        printf("CLICK: %d\n", color);
                                
                        set_color_mode (color, ON);
                        while (!digitalRead(buttons[LED_YELLOW].pin))
                        {
                                continue;
                        }
                        printf("UP: %d\n", color);
                    
                        comparacion_validacion(color);
                    
                        set_color_mode (color, OFF);
                }
        }
}
