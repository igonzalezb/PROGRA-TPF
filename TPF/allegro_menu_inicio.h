#ifndef ALLEGRO_MENU_INICIO_H
#define ALLEGRO_MENU_INICIO_H


#include "main.h"
#include "allegro_display.h"
#define PLAY_BUTTON_X	(al_get_display_width(display) / 2)
#define PLAY_BUTTON_Y	((al_get_display_height(display) / 4) * 3)
#define INFO_BUTTON_X	(al_get_display_width(display) / 10)
#define INFO_BUTTON_Y	((al_get_display_height(display) / 16) * 15)



int allegro_menu_inicio();



#endif // ALLEGRO_MENU_INICIO_H