#include "allegro_display.h"
#include "allegro_teclado.h"
#include "main.h"

ALLEGRO_DISPLAY * display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;



int allegro_display_setup(void)

{
	const char *title = { "SIMON" };
	
	ALLEGRO_BITMAP *icon = NULL;

	ALLEGRO_BITMAP *cursor_image = NULL;

	ALLEGRO_MOUSE_CURSOR *cursor;

//=====================================================================================================
//		INICIALIZO ALLEGRO, CREO DISPLAY Y CARGO IMAGENES
//=====================================================================================================

	if (configuration_start())
	{
		fprintf(stderr, "Failed to setup allegro!\n");
		return ERROR;
	}

	
//===============================DISPLAY=============================================================================
	int min_w, min_h, max_w, max_h;
	
	
	al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED);
	//ARREGLAR PONER UN MINIMO DISPLAY
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		return ERROR;
	}
	al_get_window_constraints(display, &min_w, &min_h, &max_w, &max_h);
	al_set_window_constraints(display, SCREEN_W, SCREEN_H, max_w, max_h);

	icon = al_load_bitmap("resources/simon_icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
		al_destroy_display(display);
		return ERROR;
	}

//==================================CUSTOM-MOUSE=========================================================	
	cursor_image = al_load_bitmap("resources/cursor.png");
	if (!cursor_image) {
		fprintf(stderr, "Failed to create simon!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		return ERROR;
	}


	cursor = al_create_mouse_cursor(cursor_image, 0, 0);
	if (!cursor) {
		fprintf(stderr, "Failed to create cursor!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		al_destroy_bitmap(cursor_image);
		return ERROR;
	}
	

	if (!al_set_mouse_cursor(display, cursor))
	{
		fprintf(stderr, "Failed to set cursor!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		al_destroy_mouse_cursor(cursor);
		al_destroy_bitmap(cursor_image);
		return ERROR;
	}
	

//================================= TITLE & ICON ========================================================================

	al_set_window_title(display, title); //Le pongo un titulo al display

	al_set_display_icon(display, icon);  //Icono del programa

//==================================== EVENTE QUEUE=====================================================================
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event_queue!\n");
		//DESTROY
		return ERROR;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//al_register_event_source(event_queue1, al_get_timer_event_source(timer1));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	
//===========================================================================================================================	
	
	
	if (allegro_menu_inicio())
	{
		fprintf(stderr, "Failed allegro_welcome!\n");
		al_destroy_display(display);
		al_destroy_bitmap(icon);
		al_destroy_mouse_cursor(cursor);
		al_destroy_bitmap(cursor_image);
		//
		configuration_end();
		return ERROR;
	}
	
	al_destroy_display(display);
	al_destroy_bitmap(icon);
	al_destroy_mouse_cursor(cursor);
	al_destroy_bitmap(cursor_image);
	al_destroy_event_queue(event_queue);
	configuration_end();
	
	return 0;
}

int allegro_draw_simon_off()
{
	
	ALLEGRO_FONT * font = NULL;

	font = al_load_ttf_font("resources/phreak.ttf", 34, 0);
	if (!font) {
		fprintf(stderr, "Could not load font ttf.\n");
		return ERROR;
	}

	al_clear_to_color(al_color_name("white"));
	al_draw_filled_circle(CENTER_W, CENTER_H, CENTER_H, al_color_name("black"));
	al_draw_filled_circle(CENTER_W, CENTER_H, (CENTER_H / 3), al_color_name("grey"));

	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI, PI / 2, al_color_name("lightgreen"), ARC_THICKNESS);
	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI / 2, PI / 2, al_color_name("lightyellow"), ARC_THICKNESS);
	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, 2 * PI, PI / 2, al_color_name("lightblue"), ARC_THICKNESS);
	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, -PI / 2, PI / 2, al_color_name("lightcoral"), ARC_THICKNESS);

	al_draw_text(font, al_color_name("white"), CENTER_W, CENTER_H, ALLEGRO_ALIGN_CENTER, "S I M O N");
	al_draw_text(font, al_color_name("black"), LEVEL_X, LEVEL_Y, ALLEGRO_ALIGN_CENTER, "LEVEL: ");
	
	al_flip_display();
	
	return 0;
}

void allegro_turn_led_on(int leds)
{
	
	switch (leds)
	{
	case LED_RED:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, -PI / 2, PI / 2, al_color_name("red"), ARC_THICKNESS);
		break;
	case LED_BLUE:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, 2 * PI, PI / 2, al_color_name("blue"), ARC_THICKNESS);
		break;
	case LED_GREEN:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI, PI / 2, al_color_name("green"), ARC_THICKNESS);
		break;
	case LED_YELLOW:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI / 2, PI / 2, al_color_name("yellow"), ARC_THICKNESS);
		break;
	}

	al_flip_display();
}






void allegro_draw_bitmap_scaled(ALLEGRO_BITMAP * bitmap)
{
	//al_draw_bitmap(bitmap, (al_get_display_width(display) - al_get_bitmap_width(bitmap)) / 2, (al_get_display_height(display) - al_get_bitmap_height(bitmap)) / 2, 0);

	al_draw_scaled_bitmap(bitmap,
		0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), //TAMAÑO DE IMAGEN
		0, 0, al_get_display_width(display), al_get_display_height(display), // TE LO DIBUJA DEL TAMAÑO DEL DISPLAY ACTUAL
		0);
}


