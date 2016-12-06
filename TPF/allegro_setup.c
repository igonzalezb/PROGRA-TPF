#include "allegro_display.h"
#include "main.h"

int allegro_setup_install()
{
	if (!al_init()) {			//Inicializo Allegro
		fprintf(stderr, "Failed to initialize allegro!\n");
		return ERROR;
	}
	if (!al_init_image_addon()) {
		fprintf(stderr, "Failed to initialize image addon !\n");
		al_uninstall_system();
		return ERROR;
	}

	if (!al_install_keyboard()) { 
		fprintf(stderr, "Failed to initialize the keyboard!\n");
		al_uninstall_system();
		al_shutdown_image_addon();
		return ERROR;
	}

	if (!al_install_mouse())
	{
		fprintf(stderr, "Failed to initialize mouse!\n");
		al_shutdown_image_addon();
		al_uninstall_system();
		al_uninstall_keyboard();
		return ERROR;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to initialize the primitives!\n");
		al_shutdown_image_addon();
		al_uninstall_keyboard();
		al_uninstall_system();
		al_uninstall_mouse();
		return ERROR;
	}

	al_init_font_addon(); // FIJARSE LO DE ERROR
	al_init_ttf_addon();// 

	return 0;
}



void allegro_setup_uninstall()
{
	al_shutdown_image_addon();
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_shutdown_primitives_addon();
	al_uninstall_system();
}