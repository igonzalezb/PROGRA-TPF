
//////////////////////////////////// RPI_OUTPUT ////////////////////////////////////

#include "rpi_output.h"
#include "main.h"
#include "rpi_setup.h"

extern pinsT leds[];
extern char AudioFile_RED[];
extern char AudioFile_GREEN[];
extern char AudioFile_BLUE[];
extern char AudioFile_YELLOW[];
////////////////////////////// set_color_mode() ////////////////////////////////



void set_color_mode (int color, int color_mode) // color_mode es ON OFF. ver si usar WIRING PI EN VEZ DE HARDWARE.H
{
        	//printf("Pongo el %d, en %d\n", color, color_mode);
        	leds[color].value = color_mode;
        	digitalWrite (leds[color].pin, leds[color].value);
        	if (color_mode == ON)
        	{
        		switch(color)
        		{
        			case LED_RED:
        			play_color(AudioFile_RED);
        			do_something();
        			break;
        			case LED_GREEN:
        			play_color(AudioFile_GREEN);
        			do_something();
        			break;
        			case LED_BLUE:
        			play_color(AudioFile_BLUE);
        			do_something();
        			break;
        			case LED_YELLOW:
        			play_color(AudioFile_YELLOW);
        			do_something();
        			break;
        		}
        	}
        	else if (color_mode == OFF)
        		stop_sound();

}


void play_color(char * AudioFile) // Non blocking Audio File
{
	
 	stop_sound();						  // stop previous audio track (Just in case)
 	
	if(player_status()==READY)
	{
			
		printf("Playing: %s \n",AudioFile);
	
		set_file_to_play(AudioFile);      // Load file 			
	
		play_sound(); 					  // Play File (Non Blocking)

		return;
	}
	else
	{
			
		printf("System not ready did you run init_sound() ? \n");
				
		exit(-1);		
	}
	
}

void do_something(void)
{
	int i;
				
	for(i=0;i<PLAY_TIME;i++)  // Do someting else for a while (change i)
	{
		
		printf("Playing ...\n"); // show this every 300 ms while playing the sound in background
	    SDL_Delay(300);
	}
	
	
}

int game_lost(void)
{
	return 0;
}