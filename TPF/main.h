
#ifdef _WIN32		//SOLO PARA QUE ME ANDE (iña)THREADS EN WINDOWS
//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_WARNINGS
#define HAVE_STRUCT_TIMESPEC
#endif
#ifndef MAIN_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <pthread.h>


enum platform { RASPBERRYPI, ALLEGRO };
enum colores { RED, GREEN, BLUE, YELLOW };

//#define	ALLEGRO 1

#define ON      1
#define OFF     0


#define MAX_LEVEL 10

#define TRUE 1
#define FALSE 0
#define ERROR -1

enum leds {
	LED_RED, LED_GREEN, LED_BLUE, LED_YELLOW, LED_ON_OFF
};

enum buttons { BUTTON_RED, BUTTON_GREEN, BUTTON_BLUE, BUTTON_YELLOW, BUTTON_UP };

//int configuration_start(int platform);
//int configuration_end(int platform);

#endif // MAIN_H

