#include "allegro_display.h"

int allegro_setup()
{
	if (!al_init()) { //Inicializo Allegro
		fprintf(stderr, "Failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_image_addon()) {
		fprintf(stderr, "Failed to initialize image addon !\n");
		al_uninstall_system();
		return -1;
	}

	if (!al_install_keyboard()) { 
		fprintf(stderr, "Failed to initialize the keyboard!\n");
		al_uninstall_system();
		al_shutdown_image_addon();
		return -1;
	}

	if (!al_install_mouse())
	{
		fprintf(stderr, "Failed to initialize mouse!\n");
		al_shutdown_image_addon();
		al_uninstall_system();
		al_uninstall_keyboard();
		return -1;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to initialize the primitives!\n");
		al_shutdown_image_addon();
		al_uninstall_keyboard();
		al_uninstall_system();
		al_uninstall_mouse();
		return -1;
	}

	return 0;
}

void allegro_uninstall()
{
	al_shutdown_image_addon();
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_shutdown_primitives_addon();
	al_uninstall_system();
}