#ifndef ALLEGRO_TECLADO_H

#include "allegro_display.h"

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE, KEY_ESC
};


#define CLICK_GREEN ((ev.mouse.x >= 0 && ev.mouse.x <= CENTER_W) && (ev.mouse.y >= 0 && ev.mouse.y <= CENTER_H) && (getDistance(display, a) >= ((ARC_RADIUS) - ARC_THICKNESS / 2)) && (getDistance(display, a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))

#define CLICK_RED ((ev.mouse.x >= (CENTER_W) && ev.mouse.x <= CENTER_W * 2) && (ev.mouse.y >= 0 && ev.mouse.y <= CENTER_H) && (getDistance(display, a) >= ((ARC_RADIUS) - ARC_THICKNESS/ 2)) && (getDistance(display, a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))

#define CLICK_BLUE ((ev.mouse.x >= (CENTER_W) && ev.mouse.x <= CENTER_W * 2) && (ev.mouse.y >= (CENTER_H) && ev.mouse.y <= CENTER_H * 2) && (getDistance(display, a) >= ((ARC_RADIUS) - ARC_THICKNESS / 2)) && (getDistance(display, a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))

#define CLICK_YELLOW ((ev.mouse.x >= 0 && ev.mouse.x <= CENTER_W) && (ev.mouse.y >= (CENTER_H) && ev.mouse.y <= CENTER_H * 2) && (getDistance(display, a) >= ((ARC_RADIUS) - ARC_THICKNESS / 2)) && (getDistance(display, a) <= ((ARC_RADIUS) + ARC_THICKNESS / 2)))



int allegro_teclado_main(ALLEGRO_DISPLAY * display);


#endif // !ALLEGRO_TECLADO_H
