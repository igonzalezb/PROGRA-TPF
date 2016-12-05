#include "allegro_display.h"
#include "allegro_teclado.h"
#include "main.h"



int allegro_display_main(void)

{
	const char *title = { "SIMON" };
	
	ALLEGRO_DISPLAY * display = NULL;

	ALLEGRO_BITMAP * simon = NULL;

	ALLEGRO_BITMAP *icon = NULL;

	ALLEGRO_DISPLAY_MODE   disp_data;

//=====================================================================================================
//		INICIALIZO ALLEGRO, CREO DISPLAY Y CARGO IMAGENES
//=====================================================================================================

	if (allegro_setup())
	{
		fprintf(stderr, "Failed to setup allegro!\n");
		return -1;
	}
//=====================================================================================================
	
	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);

	al_set_new_display_flags(ALLEGRO_MAXIMIZED|ALLEGRO_RESIZABLE|ALLEGRO_WINDOWED);
	display = al_create_display(disp_data.width, disp_data.height);
	//display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		return -1;
	}



	icon = al_load_bitmap("simon_icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
		al_destroy_display(display);
		return -1;
	}

	simon = al_load_bitmap("simon_all_off.png");
	if (!simon) {
		fprintf(stderr, "Failed to create welcome!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		return -1;
	}

	

//=========================================================================================================

	al_set_window_title(display, title); //Le pongo un titulo al display

	al_set_display_icon(display, icon);  //Icono del programa

//=========================================================================================================
	al_clear_to_color(al_color_name("white"));	//Fondo Blanco

	allegro_draw_bitmap_center(simon, display);

	al_flip_display();		//Actualizo Pantalla
	
	allegro_teclado_main(display, simon);

	
	al_destroy_display(display);
	al_destroy_bitmap(simon);
	al_uninstall_system();
	return 0;
}

void allegro_draw_bitmap_center(ALLEGRO_BITMAP * bitmap, ALLEGRO_DISPLAY * display)
{
	al_draw_bitmap(bitmap, (al_get_display_width(display) - al_get_bitmap_width(bitmap)) / 2, (al_get_display_height(display) - al_get_bitmap_height(bitmap)) / 2, 0);
}
