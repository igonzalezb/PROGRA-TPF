
//////////////////////////////////// SIMON - HEADER ////////////////////////////////////

#ifndef _SIMON_H_
#define _SIMON_H_

#include <time.h>
#include "main.h"

void simon_main(void);
void carga_secuencia_colores (int secuencia []);
void muestra_secuencia(int secuencia[], int level, double time);
int comparacion_validacion (int color);
void game_over (int level);



#endif // _SIMON_H_
