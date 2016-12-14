

///////////////////////////////////////// ALLEGRO_DISPLAY ////////////////////////////////////////////
                                     // S I M O N - Allegro //

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Trabajo Pr‡ctico Final - Programacion 1
//
//  Entrega: 15 de Diciembre de 2016                       ////////////////
//                                                        //  S I M O N //
//  Grupo 6:Gonz‡lez Bigliardi, I–aki                    ////////////////
//          Lago, Valentina
//          MŸller, Malena
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                   Muestra en pantalla aquello indicado por la logica del juego.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include "main.h"
#include "allegro_display.h"
#include "allegro_setup.h"
extern int level;

ALLEGRO_DISPLAY * display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_FONT * font = NULL;
ALLEGRO_SAMPLE *sample_red = NULL;
ALLEGRO_SAMPLE *sample_blue = NULL;
ALLEGRO_SAMPLE *sample_green = NULL;
ALLEGRO_SAMPLE *sample_yellow = NULL;


////////////////////////////////////// configuration_start ///////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: ERROR o 0.
//
//  Se lleva a cabo la configuracion necesaria para el correcto funcionamiento del juego.
//  
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

int configuration_start (void)

{
	const char *title = { "SIMON" };
	
	ALLEGRO_BITMAP *icon = NULL;

	ALLEGRO_BITMAP *cursor_image = NULL;

	ALLEGRO_MOUSE_CURSOR *cursor;

	if (allegro_setup())                // Inicializacion de allegro, creacion de display y se cargan imagenes.
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

	font = al_load_ttf_font("resources/phreak.ttf", 34, 0);
	if (!font) {
		fprintf(stderr, "Could not load font ttf.\n");
		return ERROR;
	}
	
	sample_red = al_load_sample("resources/sounds/red.wav");

	if (!sample_red) {
		printf("Audio clip sample not loaded!\n");
		return ERROR;
	}
	sample_blue = al_load_sample("resources/sounds/blue.wav");

	if (!sample_blue) {
		printf("Audio clip sample not loaded!\n");
		return ERROR;
	}
	sample_green = al_load_sample("resources/sounds/green.wav");

	if (!sample_green) {
		printf("Audio clip sample not loaded!\n");
		return ERROR;
	}
	sample_yellow = al_load_sample("resources/sounds/yellow.wav");

	if (!sample_yellow) {
		printf("Audio clip sample not loaded!\n");
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
	
	//FIJARSE SI FALTA ALGUNO
	al_destroy_display(display);
	al_destroy_bitmap(icon);
	al_destroy_mouse_cursor(cursor);
	al_destroy_bitmap(cursor_image);
	al_destroy_event_queue(event_queue);
	configuration_end();
	
	return 0;
}

/////////////////////allegro_draw_simon_off/////////////////////////////////
//
//	Recibe: nada
//
//	Devuelve: 
//
//
//
//
////////////////////////////////////////////////////////////////////

int allegro_draw_simon_off()
{
	al_clear_to_color(al_color_name("white"));
	al_draw_filled_circle(CENTER_W, CENTER_H, CENTER_H, al_color_name("black"));
	al_draw_filled_circle(CENTER_W, CENTER_H, (CENTER_H / 3), al_color_name("grey"));

	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI, PI / 2, al_color_name("lightgreen"), ARC_THICKNESS);
	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI / 2, PI / 2, al_color_name("lightyellow"), ARC_THICKNESS);
	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, 2 * PI, PI / 2, al_color_name("lightblue"), ARC_THICKNESS);
	al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, -PI / 2, PI / 2, al_color_name("lightcoral"), ARC_THICKNESS);

	al_draw_text(font, al_color_name("white"), CENTER_W, CENTER_H, ALLEGRO_ALIGN_CENTER, "S I M O N");
	
	al_draw_textf(font, al_color_name("black"), LEVEL_X, LEVEL_Y, ALLEGRO_ALIGN_CENTER, "LEVEL: %d",  (level+1));
	al_flip_display();
	
	return 0;
}


/////////////////////allegro_turn_led_on/////////////////////////////////
//
//	Recibe: 
//
//	Devuelve: nada
//
//
//
//
////////////////////////////////////////////////////////////////////

void allegro_turn_led_on(int leds)
{
	

	switch (leds)
	{
	case LED_RED:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, -PI / 2, PI / 2, al_color_name("red"), ARC_THICKNESS);
		al_play_sample(sample_red, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		break;
	case LED_BLUE:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, 2 * PI, PI / 2, al_color_name("blue"), ARC_THICKNESS);
		al_play_sample(sample_blue, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		break;
	case LED_GREEN:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI, PI / 2, al_color_name("green"), ARC_THICKNESS);
		al_play_sample(sample_green, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		break;
	case LED_YELLOW:
		al_draw_arc(CENTER_W, CENTER_H, ARC_RADIUS, PI / 2, PI / 2, al_color_name("yellow"), ARC_THICKNESS);
		al_play_sample(sample_yellow, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		break;
	}

	al_flip_display();
}



/////////////////////allegro_draw_bitmap_scaled///////////////////////
//
//	Recibe: 
//
//	Devuelve: nada
//
//
//
//
////////////////////////////////////////////////////////////////////

void allegro_draw_bitmap_scaled(ALLEGRO_BITMAP * bitmap)
{

	al_draw_scaled_bitmap(bitmap,
		0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), //TAMAÑO DE IMAGEN
		0, 0, al_get_display_width(display), al_get_display_height(display), // TE LO DIBUJA DEL TAMAÑO DEL DISPLAY ACTUAL
		0);
}


/////////////////////game_lost////////////////////////////////////
//
//	Recibe: nada
//
//	Devuelve: 
//
//
//
//
////////////////////////////////////////////////////////////////////

int game_lost(void)
{
	ALLEGRO_FONT * font1 = NULL;
	ALLEGRO_FONT * font2 = NULL;
	ALLEGRO_SAMPLE *sample_game_over = NULL;
	font1 = al_load_ttf_font("resources/phreak.ttf", 64, 0);
	if (!font) {
		fprintf(stderr, "Could not load font ttf.\n");
		return ERROR;
	}
	font2 = al_load_ttf_font("resources/phreak.ttf", 34, 0);
	if (!font) {
		fprintf(stderr, "Could not load font ttf.\n");
		return ERROR;
	}
	sample_game_over = al_load_sample("resources/sounds/game_over.wav");

	if (!sample_game_over) {
		printf("Audio clip sample not loaded!\n");
		return ERROR;
	}


	al_play_sample(sample_game_over, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	al_clear_to_color(al_color_name("black"));
	al_draw_text(font1, al_color_name("white"), (CENTER_W), (CENTER_H/2), ALLEGRO_ALIGN_CENTER, "GAME OVER");
	al_draw_textf(font2, al_color_name("white"),CENTER_W, CENTER_H, ALLEGRO_ALIGN_CENTER, "LEVEL: %d", (level));

	al_flip_display();
	
	al_rest(3.0);
	al_destroy_font(font1);
	al_destroy_font(font2);
	al_destroy_sample(sample_game_over);

	return 0;
}



/////////////////////set_color_mode////////////////////////////////
//
//	Recibe: 
//
//	Devuelve: nada
//
//
//
//
////////////////////////////////////////////////////////////////////

void set_color_mode(int color, int color_mode) // color_mode es ON OFF
{
	if (color_mode == OFF)
	{
		allegro_draw_simon_off();
		al_stop_samples();
	}

	else if (color_mode == ON)
	{
		allegro_turn_led_on(color);
	}
}
