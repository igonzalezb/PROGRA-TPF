#include "allegro_display.h"
#include "allegro_teclado.h"
#include "main.h"



int allegro_display_main(void)

{
	const char *title = { "SIMON" };
	
	ALLEGRO_DISPLAY * display = NULL;

	ALLEGRO_BITMAP * simon = NULL;

	ALLEGRO_BITMAP *icon = NULL;

	ALLEGRO_BITMAP *cursor_image = NULL;

	ALLEGRO_MOUSE_CURSOR *cursor;

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

	icon = al_load_bitmap("resources/simon_icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
		al_destroy_display(display);
		return -1;
	}

	simon = al_load_bitmap("resources/simon_all_off.png");
	if (!simon) {
		fprintf(stderr, "Failed to create simon!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		return -1;
	}
	cursor_image = al_load_bitmap("resources/cursor.png");
	if (!cursor_image) {
		fprintf(stderr, "Failed to create simon!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		al_destroy_bitmap(simon);
		return -1;
	}

//==================================CUSTOM-MOUSE=========================================================
	cursor = al_create_mouse_cursor(cursor_image, 0, 0);
	if (!cursor) {
		fprintf(stderr, "Failed to create simon!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		al_destroy_bitmap(simon);
		al_destroy_bitmap(cursor_image);
		return -1;
	}
	

	if (!al_set_mouse_cursor(display, cursor))
	{
		fprintf(stderr, "Failed to create simon!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		al_destroy_bitmap(simon);
		al_destroy_bitmap(cursor_image);
		return -1;
	}
	

//=========================================================================================================

	al_set_window_title(display, title); //Le pongo un titulo al display

	al_set_display_icon(display, icon);  //Icono del programa

//=========================================================================================================
	if (allegro_welcome(display))
	{
		fprintf(stderr, "Failed allegro_welcome!\n");
		return -1;
	}
	
	al_clear_to_color(al_color_name("white"));	//Fondo Blanco

	//allegro_draw_bitmap_center(simon, display);

	//al_flip_display();		//Actualizo Pantalla
	
	allegro_teclado_main(display, simon);

	
	al_destroy_display(display);
	al_destroy_bitmap(simon);
	al_uninstall_system();
	return 0;
}

void allegro_draw_bitmap_center(ALLEGRO_BITMAP * bitmap, ALLEGRO_DISPLAY * display)
{
	//al_draw_bitmap(bitmap, (al_get_display_width(display) - al_get_bitmap_width(bitmap)) / 2, (al_get_display_height(display) - al_get_bitmap_height(bitmap)) / 2, 0);

	al_draw_scaled_bitmap(bitmap,
		0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), //imagen
		0, 0, al_get_display_width(display), al_get_display_height(display), // TE LO DIBUJA DEL TAMAÑO DEL DISPLAY ACTUAL
		0);
}


int allegro_welcome(ALLEGRO_DISPLAY * display)	//NO ANDA!!!
{
	ALLEGRO_BITMAP *menu_simon = NULL;

	ALLEGRO_BITMAP *menu_simon_play = NULL;

	ALLEGRO_MOUSE_STATE mouse_state;

	bool on_button = false;

	bool play = false;

	ALLEGRO_KEYBOARD_STATE kst;

//=====================================================================================================================================================================
	menu_simon = al_load_bitmap("resources/menu_simon.png");
	if (!menu_simon) {
		fprintf(stderr, "Failed to create menu_simon!\n");
		return -1;
	}

	menu_simon_play = al_load_bitmap("resources/menu_simon_play.png");
	if (!menu_simon_play) {
		fprintf(stderr, "Failed to create menu_simon_play!\n");
		return -1;
	}
//======================================================================================================================================================================
	allegro_draw_bitmap_center(menu_simon, display);
	//allegro_draw_bitmap_center(menu_simon_play, display);
	al_draw_bitmap(menu_simon_play, (al_get_display_width(display) - al_get_bitmap_width(menu_simon_play)) / 2, (al_get_display_height(display) - al_get_bitmap_height(menu_simon_play)) / 2, 0);
	al_flip_display();
	while (!play)
	{
		al_get_mouse_state(&mouse_state);
		if ((mouse_state.x == al_get_bitmap_x(menu_simon_play)) 
			|| (mouse_state.y == al_get_bitmap_y(menu_simon_play)))
		{
			al_draw_bitmap(menu_simon_play, (al_get_display_width(display) - al_get_bitmap_width(menu_simon_play)) / 2, (al_get_display_height(display) - al_get_bitmap_height(menu_simon_play)) / 2, 0);

			al_flip_display();
			//on_button = true;
					
		}
		if (al_mouse_button_down(&mouse_state, 1))
		{
			return 0;
		}
		else if (on_button)
		{
			return 0;
		}
		al_get_keyboard_state(&kst);
		if (al_key_down(&kst, ALLEGRO_KEY_ESCAPE)) {
			return 0;
			
		}

	}
	
	
	

	//al_rest(2.0);
	
	//HAY QUE PONER QUE CON ENTER O APRETANDO PLAY EMPIEZE EL JUEGO


	return 0;
}
