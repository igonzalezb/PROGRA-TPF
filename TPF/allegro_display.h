#ifndef ALLEGRO_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h> //manejo de fonts
#include <allegro5/allegro_ttf.h> //Manejo de ttfs

#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h>

#define SCREEN_W    1100
#define SCREEN_H    600
#define FPS         60.0


#define PI	3.141593

//#define CENTER1(x)	(#x, (al_get_display_width(display) - al_get_bitmap_width(#x)) / 2, (al_get_display_height(display) - al_get_bitmap_height(#x)) / 2, 0)	
//#define CENTER(x)	CENTER1(x)


int allegro_display_main(void);

int allegro_setup_install();


void allegro_setup_uninstall();

void allegro_draw_bitmap_center(ALLEGRO_BITMAP * , ALLEGRO_DISPLAY * );

void allegro_draw_button_center(ALLEGRO_BITMAP * bitmap, ALLEGRO_DISPLAY * display);

void allegro_draw_simon_off(ALLEGRO_DISPLAY * display);

int allegro_menu_inicio(ALLEGRO_DISPLAY * display);

void allegro_turn_led_on(ALLEGRO_DISPLAY * display, int led);

#endif // !ALLEGRO_DISPLAY_H

