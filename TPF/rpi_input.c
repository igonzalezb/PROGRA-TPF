
//////////////////////////////////// RPI_INPUT ////////////////////////////////////

#include "rpi_input.h"
#include "main.h"
#include "rpi_output.h"
#include "simon.h"
extern pinsT buttons[];


extern bool exit_simon;
extern bool player_lost;
bool exit_teclado = false;
//////////////// thread_buttons ////////////////

void buttons_teclado_input(void);
{
        int color;
        while (!exit_simon && !player_lost && !exit_teclado)
        {
                
                        //printf("while de botones\n");
                        //printf("wDigital read1: %d\n", digitalRead(buttons[RED].pin ));
                        usleep(3000);
                        if(!digitalRead(buttons[LED_RED].pin))
                        {
                                color = LED_RED;
                                printf("CLICK: %d\n", color);
                                
                                set_color_mode (color, ON);
                                while (!digitalRead(buttons[LED_RED].pin))// estos whiles contemplan el caso de que se mantenga apretada una tecla
                                {
                                        continue;
                                }
                                printf("UP: %d\n", color);
                                comparacion_validacion(color);
                                set_color_mode (color, OFF);
                                 
                        }
                
                        else if(!digitalRead(buttons[LED_GREEN].pin))
                        {
                                color = LED_GREEN;
                                printf("CLICK: %d\n", color);
                                
                                set_color_mode (color, ON);
                                while (!digitalRead(buttons[LED_GREEN].pin))// estos whiles contemplan el caso de que se mantenga apretada una tecla
                                {
                                        continue;
                                }
                               printf("UP: %d\n", color);
                                 comparacion_validacion(color);
                                 set_color_mode (color, OFF);
                                 
                        }
                
                        else if(!digitalRead(buttons[LED_BLUE].pin))
                        {
                                color = LED_BLUE;
                                printf("CLICK: %d\n", color);
                                
                                set_color_mode (color, ON);
                                while (!digitalRead(buttons[LED_BLUE].pin))// estos whiles contemplan el caso de que se mantenga apretada una tecla
                                {
                                        continue;
                                }
                               printf("UP: %d\n", color);
                                comparacion_validacion(color);
                                set_color_mode (color, OFF);
                                
                        }
            
                        else if(!digitalRead(buttons[LED_YELLOW].pin))
                        {
                                color = LED_YELLOW;
                                printf("CLICK: %d\n", color);
                                
                                set_color_mode (color, ON);
                                while (!digitalRead(buttons[LED_YELLOW].pin))// estos whiles contemplan el caso de que se mantenga apretada una tecla
                                {
                                        continue;
                                }
                                printf("UP: %d\n", color);
                                comparacion_validacion(color);
                                set_color_mode (color, OFF);

                        }
                }
        
}

// NO OLVIDAR CREAR UN BUFFER CIRCULAR, EL MAIN DEBERIA CONTENER:
/*
 CIRCULAR_BUFFER nombre_del_buffer;
 create_buffer(&nombre_del_buffer, TAMANO_BUFFER);  // TAMANNO_BUFFER es un #depausee
 
 //UNA VEZ QUE SE TERMINA DE USAR EL BUFFER CIRCULAR:
 end_buffer(&prueba);
 */

