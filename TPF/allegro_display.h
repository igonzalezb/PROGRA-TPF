#ifndef ALLEGRO_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h>
#include "allegro5/allegro_primitives.h"
#include <allegro5/allegro_font.h> //manejo de fonts
#include <allegro5/allegro_ttf.h> //Manejo de ttfs

#define SCREEN_W    1000
#define SCREEN_H    700
#define FPS         60.0

//#define CENTER1(x)	(#x, (al_get_display_width(display) - al_get_bitmap_width(#x)) / 2, (al_get_display_height(display) - al_get_bitmap_height(#x)) / 2, 0)	
//#define CENTER(x)	CENTER1(x)


int allegro_display_main(void);

int allegro_setup();

void allegro_uninstall();

void allegro_draw_bitmap_center(ALLEGRO_BITMAP * , ALLEGRO_DISPLAY * );

int allegro_welcome(ALLEGRO_DISPLAY * display);

#endif // !ALLEGRO_DISPLAY_H

