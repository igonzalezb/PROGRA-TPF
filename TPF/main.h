

#ifndef MAIN_H

#include <stdio.h>
#include <stdlib.h>
#define HAVE_STRUCT_TIMESPEC	//SOLO PARA QUE ME ANDE (i�a)THREADS EN WINDOWS
#include <pthread.h>


enum PLATFORMS { ALLEGRO, RASPBERRYPI };
enum COLORES { RED, GREEN, BLUE, YELLOW };

//#define	ALLEGRO 1

#define ON      1
#define OFF     0


#define MAX_LEVEL 100

#define TRUE 1
#define FALSE 0

enum LEDS {
	LED_RED, LED_GREEN, LED_BLUE, LED_YELLOW, LED_ON_OFF
};

#endif // MAIN_H

