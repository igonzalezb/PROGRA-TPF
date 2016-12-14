

/////////////////////////////////////////// ALLEGRO_SETUP ////////////////////////////////////////////
                                       // S I M O N - Allegro //

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Trabajo Práctico Final - Programacion 1
//
//  Entrega: 15 de Diciembre de 2016                       ////////////////
//                                                        //  S I M O N //
//  Grupo 6:González Bigliardi, Iñaki                    ////////////////
//          Lago, Valentina
//          Müller, Malena
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           Configuraciones necesarias para jugar, utilizando la libreria de Allegro.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include "allegro_setup.h"


//////////////////////////////////////// configuration_start //////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: ERROR o 0.
//
//  Installa e inicializa allegro y sus addons
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

int allegro_setup(void)
{
	if (!al_init())
        {
		fprintf(stderr, "Failed to initialize allegro!\n");
                
		return ERROR;
	}
	if (!al_init_image_addon())
        {
		fprintf(stderr, "Failed to initialize image addon !\n");
                
		al_uninstall_system();
                
		return ERROR;
	}
	if (!al_install_keyboard())
        {
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
	if (!al_install_audio())
        {
		fprintf(stderr, "failed to initialize audio!\n");
                
		return ERROR;
	}
	if (!al_init_acodec_addon())
        {
		fprintf(stderr, "failed to initialize audio codecs!\n");
                
		return ERROR;
	}
	if (!al_reserve_samples(RESERVED_SAMPLES))
        {
		fprintf(stderr, "failed to reserve samples!\n");
                
		return ERROR;
	}
	al_init_font_addon();
	
	al_init_ttf_addon();

	return 0;
}


//////////////////////////////////////// configuration_end ////////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//  Apaga y desinstala allegro y sus addons
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void configuration_end(void)
{
	al_uninstall_system();
        
	al_shutdown_image_addon();
        
	al_uninstall_keyboard();
        
	al_uninstall_mouse();
        
	al_shutdown_primitives_addon();
        
	al_uninstall_audio();
        
	al_shutdown_font_addon();
        
	al_shutdown_ttf_addon();
	
}
