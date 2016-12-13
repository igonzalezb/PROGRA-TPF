#ifndef ALLEGRO_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h>

#define SCREEN_W    800
#define SCREEN_H    600
#define FPS         60.0
#define RESERVED_SAMPLES   6

#define PI	3.141593

#define CENTER_W	(al_get_display_width(display) / 2)
#define CENTER_H	(al_get_display_height(display) / 2)

//===================FIJARSE DE USAR OTRA COSA EN VEZ DEL HEIGHT================
#define ARC_RADIUS	(al_get_display_height(display) / 3)
#define ARC_THICKNESS	(al_get_display_height(display) / 4)
//==============================================================================
#define LEVEL_X	(al_get_display_width(display) / 6)
#define LEVEL_Y	((al_get_display_height(display) / 16) * 15)


int configuration_start(void);

int allegro_setup(void);

void configuration_end(void);

void allegro_draw_bitmap_scaled(ALLEGRO_BITMAP *);

void allegro_draw_button_center(ALLEGRO_BITMAP *);

int allegro_draw_simon_off();

int allegro_menu_inicio();

void allegro_turn_led_on(int led);

int allegro_lost(void);

void set_color_mode(int color, int color_mode);

#endif // !ALLEGRO_DISPLAY_H

