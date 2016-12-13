
//////////////////////////////////// SIMON - HEADER ////////////////////////////////////

#ifndef _SIMON_H_
#define _SIMON_H_


//#include <unistd.h>
#include <time.h>

//#include "rpi_input.h"
//#include "rpi_output.h"
//#include "allegro_input.h"
//#include "allegro_output.h"


int simon_main(void);
void carga_secuencia_colores (int secuencia_colores []); //ver si dejar int [] o si queda mejor int*
void muestra_secuencia(int secuencia[], int level, double time);//, int time_color_on, int time_color_off);
void game_over (int level);

int comparacion_validacion (int color);

#endif // _SIMON_H_
