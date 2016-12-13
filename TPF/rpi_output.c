
//////////////////////////////////// RPI_OUTPUT ////////////////////////////////////

#include "rpi_output.h"
#include "main.h"
#include "rpi_setup.h"
extern pinsT leds[];

////////////////////////////// set_color_mode() ////////////////////////////////

void set_color_mode (int color, int color_mode) // color_mode es ON OFF. ver si usar WIRING PI EN VEZ DE HARDWARE.H
{
        	//printf("Pongo el %d, en %d\n", color, color_mode);
        	leds[color].value = color_mode;
        	digitalWrite (leds[color].pin, leds[color].value);

}

int game_lost (void)
{
	return 0;
}
