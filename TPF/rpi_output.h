
//////////////////////////////////// RPI_OUTPUT - HEADER ////////////////////////////////////

#ifndef _RPI_OUTPUT_H_
#define _RPI_OUTPUT_H_


#include <wiringPi.h>

#define PLAY_TIME 1

void set_color_mode (int color, int color_mode);
void play_color(char * AudioFile);
void do_something(void);
int game_lost(void);
#endif // _RPI_OUTPUT_H_
