
#ifndef ALLEGRO_INPUT_H
#define ALLEGRO_INPUT_H

#include "main.h" 
#include "simon.h"

enum MYKEYS { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE, KEY_ESC};

struct Point 
{
	long x, y;
};



#define CLICK_GREEN ((ev.mouse.x >= 0 && ev.mouse.x <= CENTER_W) && (ev.mouse.y >= 0 && ev.mouse.y <= CENTER_H) && (getDistance(a) >= ((ARC_RADIUS) - ARC_THICKNESS / 2)) && (getDistance(a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))

#define CLICK_RED ((ev.mouse.x >= (CENTER_W) && ev.mouse.x <= CENTER_W * 2) && (ev.mouse.y >= 0 && ev.mouse.y <= CENTER_H) && (getDistance(a) >= ((ARC_RADIUS) - ARC_THICKNESS/ 2)) && (getDistance(a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))

#define CLICK_BLUE ((ev.mouse.x >= (CENTER_W) && ev.mouse.x <= CENTER_W * 2) && (ev.mouse.y >= (CENTER_H) && ev.mouse.y <= CENTER_H * 2) && (getDistance(a) >= ((ARC_RADIUS) - ARC_THICKNESS / 2)) && (getDistance(a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))

#define CLICK_YELLOW ((ev.mouse.x >= 0 && ev.mouse.x <= CENTER_W) && (ev.mouse.y >= (CENTER_H) && ev.mouse.y <= CENTER_H * 2) && (getDistance(a) >= ((ARC_RADIUS) - ARC_THICKNESS / 2)) && (getDistance(a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))



void buttons_teclado_input(void);
double getDistance(struct Point a);

#endif // ALLEGRO_INPUT_H
