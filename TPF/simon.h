
//////////////////////////////////// SIMON - HEADER ////////////////////////////////////

#ifndef _SIMON_H_
#define _SIMON_H_

#include <time.h>
#include "main.h"

void simon_main(void);
void carga_secuencia_colores (int secuencia []); //ver si dejar int [] o si queda mejor int*
void muestra_secuencia(int secuencia[], int level, double time);//, int time_color_on, int time_color_off);
int comparacion_validacion (int color);
void game_over (int level);



#endif // _SIMON_H_
