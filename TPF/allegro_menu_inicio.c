#include "allegro_display.h"
#include "main.h"
#include "allegro_teclado.h"


#define PLAY_BUTTON_X	(al_get_display_width(display) / 2)
#define PLAY_BUTTON_Y	((al_get_display_height(display) / 4) * 3)

#define INFO_BUTTON_X	(al_get_display_width(display) / 10)
#define INFO_BUTTON_Y	((al_get_display_height(display) / 16) * 15)


int allegro_menu_inicio(ALLEGRO_DISPLAY * display)
{
	ALLEGRO_BITMAP *menu_simon = NULL;

	ALLEGRO_BITMAP *menu_simon_play = NULL;

	ALLEGRO_EVENT_QUEUE *event_queue1 = NULL;

	ALLEGRO_FONT * font = NULL;
	ALLEGRO_FONT * font2 = NULL;

	//ALLEGRO_MOUSE_STATE mouse_state;

	/*ALLEGRO_TIMER *timer1 = NULL;*/

	//bool on_button = false;

	bool do_exit1 = false;

	bool play = false;

	//ALLEGRO_KEYBOARD_STATE kst;

	bool redraw1 = false;

	//=====================================================================================================================================================================
	menu_simon = al_load_bitmap("resources/menu_simon.png");
	if (!menu_simon) {
		fprintf(stderr, "Failed to create menu_simon!\n");
		return ERROR;
	}

	menu_simon_play = al_load_bitmap("resources/menu_simon_play.png");
	if (!menu_simon_play) {
		fprintf(stderr, "Failed to create menu_simon_play!\n");
		return ERROR;
	}

	event_queue1 = al_create_event_queue();
	if (!event_queue1) {
		fprintf(stderr, "Failed to create event_queue!\n");
		//DESTROY
		return ERROR;
	}

	font = al_load_ttf_font("resources/disney.ttf", 54, 0); //HAY CREAR UN FONT PARA CADA TAMAÑO DE LETRA 

	if (!font) {
		fprintf(stderr, "Could not load 'disney.ttf'.\n");
		return ERROR;
	}

	font2 = al_load_ttf_font("resources/disney.ttf", 26, 0); //HAY CREAR UN FONT PARA CADA TAMAÑO DE LETRA 

	if (!font) {
		fprintf(stderr, "Could not load 'disney.ttf'.\n");
		return ERROR;
	}


	/*timer1 = al_create_timer(1.0 / FPS);
	if (!timer1) {
		fprintf(stderr, "Failed to create timer!\n");
		return ERROR;
	}*/
	//======================================================================================================================================================================
	al_register_event_source(event_queue1, al_get_display_event_source(display));
	//al_register_event_source(event_queue1, al_get_timer_event_source(timer1));
	al_register_event_source(event_queue1, al_get_keyboard_event_source());
	al_register_event_source(event_queue1, al_get_mouse_event_source());


	//=======================================================================================================================================================================	
	//al_acknowledge_resize(display);
	//al_flip_display();
	allegro_draw_bitmap_center(menu_simon, display);
	al_draw_text(font, al_color_name("white"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");
	al_draw_text(font2, al_color_name("white"), INFO_BUTTON_X, INFO_BUTTON_Y, ALLEGRO_ALIGN_CENTER, "INFO");
	//allegro_draw_bitmap_center(menu_simon_play, display);
	//al_draw_bitmap(menu_simon_play, (al_get_display_width(display) - al_get_bitmap_width(menu_simon_play)) / 2, (al_get_display_height(display) - al_get_bitmap_height(menu_simon_play)) / 2, 0);


	al_flip_display();
	printf("CP2\n");
	
	int x1, x2, y1, y2, w, h;
	int mx, my;
	//METER INSTRUCCIONES

	//al_start_timer(timer1);

	while (!do_exit1)
	{
		ALLEGRO_EVENT ev1;

		al_wait_for_event(event_queue1, &ev1);
		
		printf("CP3\n");

		if (ev1.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			//QUIT
			do_exit1 = true;
		else if (ev1.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
		{
			if (!al_acknowledge_resize(ev1.display.source))
			{
				fprintf(stderr, "Failed to create event_queue!\n");
				//DESTROY
				return ERROR;
			}
			redraw1 = true;
		}

		else if (ev1.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			al_get_text_dimensions(font, ":: PLAY ::", &x1, &y1, &w, &h);
			printf("x1: %X", x1);
			x1 = PLAY_BUTTON_X - w / 2;
			y1 = y1 + PLAY_BUTTON_Y;
			x2 = w + x1;
			y2 = h + y1;
			
			mx = ev1.mouse.x;
			my = ev1.mouse.y;
			printf("mx %X, my %X\n", mx, my);
			
			if (((x1 <= mx) && (mx <= x2))  && ((my >= y1) && (my <= y2)))
			{
				allegro_draw_bitmap_center(menu_simon_play, display);
				al_draw_text(font, al_color_name("green"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");
				al_flip_display();
			}
			
		}
		//PODRIA AGREGAR QUE CUANDO PASE POR ARRRIBA DEL BOTON CAMBIE DE COLOR
		else if (ev1.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (((mx >= x1) && (mx <= x2)) && ((my >= y1) && (my <= y2)))
			{
				redraw1 = true;
				play = true;
			}
			

		}


		else if (ev1.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (ev1.keyboard.keycode == ALLEGRO_KEY_SPACE)
			{
				allegro_draw_bitmap_center(menu_simon_play, display);
				al_draw_text(font, al_color_name("green"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");
				al_flip_display();
				printf("SPACE\n");
				
			}
		}

		else if (ev1.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev1.keyboard.keycode)
			{
			case ALLEGRO_KEY_SPACE:
				redraw1 = true;
				play = true;
				break;


			case ALLEGRO_KEY_ESCAPE:
				//QUIT
				do_exit1 = true;
				break;
			}
		}

		if (redraw1 && al_is_event_queue_empty(event_queue1))
		{


			//al_flip_display();
			//al_rest(0.1);
			al_clear_to_color(al_color_name("black"));
			allegro_draw_bitmap_center(menu_simon, display);
			al_draw_text(font, al_color_name("white"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");
			al_draw_text(font2, al_color_name("white"), INFO_BUTTON_X, INFO_BUTTON_Y, ALLEGRO_ALIGN_CENTER, "INFO");

			//allegro_draw_bitmap_center(simon, display);
			al_flip_display();
			redraw1 = false;

			printf("CP4\n");


		}

		if (play && al_is_event_queue_empty(event_queue1))
		{
			al_clear_to_color(al_color_name("black"));
			al_draw_text(font, al_color_name("white"), (al_get_display_width(display) / 2), (al_get_display_height(display) / 2), ALLEGRO_ALIGN_CENTER, "LOADING...");
			al_flip_display();

			//VOY AL JUEG0
			if (allegro_teclado_main(display))
			{
				fprintf(stderr, "Failed allegro_teclado_main!\n");
				//DISTROY
				return ERROR;
			}
			//VUELVO AL MENU PRINCIPAL
			play = false;
			printf("CP5\n");
			redraw1 = true;
			al_flush_event_queue(event_queue1);
			
		}

	}

	//DISTROY
	al_destroy_event_queue(event_queue1);
	return 0;
}


void allegro_draw_button_center(ALLEGRO_BITMAP * bitmap, ALLEGRO_DISPLAY * display)
{
	//al_draw_bitmap(bitmap, (al_get_display_width(display) - al_get_bitmap_width(bitmap)) / 2, (al_get_display_height(display) - al_get_bitmap_height(bitmap)) / 2, 0);

	al_draw_scaled_bitmap(bitmap,
		0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), //TAMAÑO DE IMAGEN
		PLAY_BUTTON_X, PLAY_BUTTON_Y, al_get_display_width(display)/4, al_get_display_height(display)/6, // TE LO DIBUJA DEL TAMAÑO DEL DISPLAY ACTUAL
		0);
}

