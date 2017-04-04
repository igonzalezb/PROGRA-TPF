
//////////////////////////////////// RPI_SETUP - HEADER ////////////////////////////////////

#ifndef _RPI_SETUP_H_
#define _RPI_SETUP_H_

#include <wiringPi.h>

#include "libaudio.h"
#include "simon.h"
#include "rpi_input.h"
#include "main.h"
#include "rpi_output.h"

#define CANT_COLORS 4

typedef struct
{
        char led_name [15]; 
        int pin;
        int direction;
        int value;
}pinsT;


int configuration_start (void);
void configuration_end (void);
void pin_out_or_in (void);
void set_pin_zero_or_one (void);

#endif // _RPI_SETUP_H_
