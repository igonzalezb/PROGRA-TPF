#include "allegro_display.h"
#include "allegro_teclado.h"
#include "main.h"



int allegro_display_main(void)

{
	const char *title = { "SIMON" };
	
	ALLEGRO_DISPLAY * display = NULL;

	ALLEGRO_BITMAP *icon = NULL;

	ALLEGRO_BITMAP *cursor_image = NULL;

	ALLEGRO_MOUSE_CURSOR *cursor;

	ALLEGRO_DISPLAY_MODE   disp_data;

//=====================================================================================================
//		INICIALIZO ALLEGRO, CREO DISPLAY Y CARGO IMAGENES
//=====================================================================================================

	if (allegro_setup_install())
	{
		fprintf(stderr, "Failed to setup allegro!\n");
		return ERROR;
	}

	
//===============================DISPLAY=============================================================================
	
	//al_get_display_mode(al_get_num_display_modes() - 2, &disp_data);

	al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED); //ALLEGRO_MAXIMIZED |
	
	//display = al_create_display(disp_data.width, disp_data.height);
	
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		return ERROR;
	}

	icon = al_load_bitmap("resources/simon_icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
		al_destroy_display(display);
		return ERROR;
	}

	
	cursor_image = al_load_bitmap("resources/cursor.png");
	if (!cursor_image) {
		fprintf(stderr, "Failed to create simon!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		return ERROR;
	}

//==================================CUSTOM-MOUSE=========================================================
	cursor = al_create_mouse_cursor(cursor_image, 0, 0);
	if (!cursor) {
		fprintf(stderr, "Failed to create cursor!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		//al_destroy_bitmap(simon);
		al_destroy_bitmap(cursor_image);
		return ERROR;
	}
	

	if (!al_set_mouse_cursor(display, cursor))
	{
		fprintf(stderr, "Failed to set cursor!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		//al_destroy_bitmap(simon);
		al_destroy_bitmap(cursor_image);
		return ERROR;
	}
	

//================================= TITLE & ICON ========================================================================

	al_set_window_title(display, title); //Le pongo un titulo al display

	al_set_display_icon(display, icon);  //Icono del programa

//=========================================================================================================
	
	//if (allegro_menu_inicio(display))
	//{
	//	fprintf(stderr, "Failed allegro_welcome!\n");
	//	//FALTAN LOS DISTROY
	//	return ERROR;
	//}
	
	//al_clear_to_color(al_color_name("black"));
	//al_draw_circle(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display)/ 2.5, al_color_name("white"), al_get_display_height(display) / 20);
	
	/*al_draw_filled_circle(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 2.7, al_color_name("red"));
	al_draw_filled_rectangle(al_get_display_width(display) / 2, 0, al_get_display_width(display), al_get_display_height(display), al_color_name("black"));
	al_draw_filled_rectangle(0, al_get_display_height(display)/2, al_get_display_width(display), al_get_display_height(display), al_color_name("black"));
	
	al_draw_filled_circle(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 2.7, al_color_name("blue"));
	
	
	
	
	al_draw_circle(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 2.5, al_color_name("white"), al_get_display_height(display) / 20);
	al_draw_filled_circle(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 6, al_color_name("grey"));
	*/

	float pi = 3.141593;
	
	al_clear_to_color(al_color_name("white"));
	al_draw_filled_circle(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 2, al_color_name("black"));
	al_draw_filled_circle(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 6, al_color_name("grey"));

	al_draw_arc(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 3, pi, pi/2, al_color_name("lightgreen"), al_get_display_height(display) / 4);
	al_draw_arc(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 3, pi/2, pi/2, al_color_name("lightyellow"), al_get_display_height(display) / 4);
	al_draw_arc(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 3, 2* pi, pi/2, al_color_name("lightblue"), al_get_display_height(display) / 4);
	al_draw_arc(al_get_display_width(display) / 2, al_get_display_height(display) / 2, al_get_display_height(display) / 3, -pi/2, pi/2, al_color_name("lightcoral"), al_get_display_height(display) / 4);

	al_flip_display();
	
	al_rest(5.0);
	//FIJARSE BIEN LOS DISTROY
	al_destroy_display(display);
	al_destroy_bitmap(icon);
	al_destroy_bitmap(cursor_image);
	//al_destroy_bitmap(simon);
	//al_uninstall_system();
	allegro_setup_uninstall();
	
	return 0;
}



void allegro_draw_bitmap_center(ALLEGRO_BITMAP * bitmap, ALLEGRO_DISPLAY * display)
{
	//al_draw_bitmap(bitmap, (al_get_display_width(display) - al_get_bitmap_width(bitmap)) / 2, (al_get_display_height(display) - al_get_bitmap_height(bitmap)) / 2, 0);

	al_draw_scaled_bitmap(bitmap,
		0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), //TAMA�O DE IMAGEN
		0, 0, al_get_display_width(display), al_get_display_height(display), // TE LO DIBUJA DEL TAMA�O DEL DISPLAY ACTUAL
		0);
}


