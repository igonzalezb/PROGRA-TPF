#include "allegro_display.h"
#include "main.h"
#include "allegro_teclado.h"


int allegro_menu_inicio(ALLEGRO_DISPLAY * display)
{
	ALLEGRO_BITMAP *menu_simon = NULL;

	ALLEGRO_BITMAP *menu_simon_play = NULL;

	ALLEGRO_EVENT_QUEUE *event_queue1 = NULL;

	ALLEGRO_FONT * font = NULL;

	//ALLEGRO_MOUSE_STATE mouse_state;

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
	//======================================================================================================================================================================
	al_register_event_source(event_queue1, al_get_display_event_source(display));
	al_register_event_source(event_queue1, al_get_keyboard_event_source());
	al_register_event_source(event_queue1, al_get_mouse_event_source());


	//=======================================================================================================================================================================	
	allegro_draw_bitmap_center(menu_simon, display);
	al_draw_text(font, al_color_name("white"), (al_get_display_width(display) / 2), (al_get_display_height(display) / 4) * 3.5, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");


	//allegro_draw_bitmap_center(menu_simon_play, display);
	//al_draw_bitmap(menu_simon_play, (al_get_display_width(display) - al_get_bitmap_width(menu_simon_play)) / 2, (al_get_display_height(display) - al_get_bitmap_height(menu_simon_play)) / 2, 0);


	al_flip_display();
	printf("CP2\n");
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
			al_flip_display();
		}

		else if (ev1.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{

		}
		else if (ev1.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			/*if ((<= ev1.mouse.x <= ) && (<= ev1.mouse.y <= ))
			{

			}*/
		}


		else if (ev1.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (ev1.keyboard.keycode == ALLEGRO_KEY_SPACE)
			{
				//allegro_draw_bitmap_center(simon, display);
				//allegro_draw_bitmap_center(led_button_off, display);
				//al_flip_display();
				//redraw = true;
				//allegro_teclado_main(display);
				allegro_draw_bitmap_center(menu_simon_play, display);
				al_draw_text(font, al_color_name("green"), (al_get_display_width(display) / 2), (al_get_display_height(display) / 4) * 3.5, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");



				//al_draw_bitmap(menu_simon_play, (al_get_display_width(display) - al_get_bitmap_width(menu_simon_play)) / 2, (al_get_display_height(display) - al_get_bitmap_height(menu_simon_play)) / 2, 0);
				al_flip_display();
				printf("SPACE\n");
				//RESTART GAME
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
			al_draw_text(font, al_color_name("white"), (al_get_display_width(display) / 2), (al_get_display_height(display) / 4) * 3.5, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");

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
			
			al_flush_event_queue(event_queue1);
			al_clear_to_color(al_color_name("black"));
			allegro_draw_bitmap_center(menu_simon, display);
			al_draw_text(font, al_color_name("white"), (al_get_display_width(display) / 2), (al_get_display_height(display) / 4) * 3.5, ALLEGRO_ALIGN_CENTER, ":: PLAY ::");

			//allegro_draw_bitmap_center(simon, display);
			al_flip_display();

		}

		//al_get_mouse_state(&mouse_state);
		//if ((mouse_state.x == al_get_bitmap_x(menu_simon_play)) 
		//	|| (mouse_state.y == al_get_bitmap_y(menu_simon_play)))
		//{
		//	al_draw_bitmap(menu_simon_play, (al_get_display_width(display) - al_get_bitmap_width(menu_simon_play)) / 2, (al_get_display_height(display) - al_get_bitmap_height(menu_simon_play)) / 2, 0);

		//	al_flip_display();
		//	//on_button = true;
		//			
		//}
		//if (al_mouse_button_down(&mouse_state, 1))
		//{
		//	return 0;
		//}
		//else if (on_button)
		//{
		//	return 0;
		//}
		//al_get_keyboard_state(&kst);
		//if (al_key_down(&kst, ALLEGRO_KEY_ESCAPE)) {
		//	return 0;
		//	
		//}

	}

	//DISTROY
	al_destroy_event_queue(event_queue1);
	return 0;
}