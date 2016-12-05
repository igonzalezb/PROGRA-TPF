#include "allegro_display.h"

int allegro_setup()
{
	if (!al_init()) { //Inicializo Allegro
		fprintf(stderr, "Failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_image_addon()) { // Inicializo ADDON de las imagenes
		fprintf(stderr, "failed to initialize image addon !\n");
		return -1;
	}

	if (!al_install_keyboard()) {    //Inicializo el teclado
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	if (!al_install_mouse())
	{
		fprintf(stderr, "failed to initialize mouse!\n");
		return -1;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "failed to initialize the primitives!\n");
		return -1;
	}

	return 0;
}