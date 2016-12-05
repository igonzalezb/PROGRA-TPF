
#include "allegro_teclado.h"



int allegro_teclado_main (ALLEGRO_DISPLAY * display, ALLEGRO_BITMAP * simon)
{
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	ALLEGRO_BITMAP * led_red_on = NULL;
	ALLEGRO_BITMAP * led_blue_on = NULL;
	ALLEGRO_BITMAP * led_yellow_on = NULL;
	ALLEGRO_BITMAP * led_green_on = NULL;
	ALLEGRO_BITMAP * led_button_off = NULL;

	bool key_pressed[6] = { false, false, false, false, false, false};

	bool redraw = false;

	bool do_exit = false;

//=========================================================================================================
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "Failed to create timer!\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event_queue!\n");
		al_destroy_timer(timer);
		
		return -1;
	}

	led_red_on = al_load_bitmap("simon_red_on.png");
	if (!led_red_on) {
		fprintf(stderr, "Failed to create led!\n");
		//destroy
		return -1;
	}

	led_blue_on = al_load_bitmap("simon_blue_on.png");
	if (!led_red_on) {
		fprintf(stderr, "Failed to create led!\n");
		//destroy
		return -1;
	}

	led_green_on = al_load_bitmap("simon_green_on.png");
	if (!led_red_on) {
		fprintf(stderr, "Failed to create led!\n");
		//destroy
		return -1;
	}

	led_yellow_on = al_load_bitmap("simon_yellow_on.png");
	if (!led_red_on) {
		fprintf(stderr, "Failed to create led!\n");
		//destroy
		return -1;
	}

	led_button_off = al_load_bitmap("simon_button_off.png");
	if (!led_red_on) {
		fprintf(stderr, "Failed to create button!\n");
		//destroy
		return -1;
	}
//=========================================================================================================

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!do_exit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)		//PONER EN CADA IF LO QUE TIENE QUE HACER (LLAMAR A VALIDACION CON ESA TECLA)
		{
			//if (key_pressed[KEY_SPACE])
			//	//Restart GAME
			//	al_draw_bitmap(led_button_on, 0, 0, 0);
			//		//prendo el led, pero se actualiza en pantalla al fondo del while
			//	//validacion		//en validacion tiene que fijarse si esta bien

			//if (key_pressed[KEY_UP])
			//{
			//	al_draw_bitmap(led_red_on, 0, 0, 0);
			//	printf("UP\n");
			//	//validacion
			//}
			//	
			//	

			//if (key_pressed[KEY_DOWN])
			//	al_draw_bitmap(led_blue_on, 0, 0, 0);
			//	//validacion
			//	

			//if (key_pressed[KEY_LEFT])
			//	al_draw_bitmap(led_yellow_on, 0, 0, 0);
			//	//validacion
			//	

			//if (key_pressed[KEY_RIGHT])
			//	al_draw_bitmap(led_green_on, 0, 0, 0);
			//	//validacion


			//redraw = true;
		} //Nose para que sirve

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			do_exit = true;
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
		{
			al_flip_display();
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode) 
			{
				case ALLEGRO_KEY_SPACE:
					key_pressed[KEY_SPACE] = true;
					allegro_draw_bitmap_center(led_button_off, display);
					al_flip_display();
					printf("SPACE\n");
					//validacion
					break;

				case ALLEGRO_KEY_UP:
					key_pressed[KEY_UP] = true;
					allegro_draw_bitmap_center(led_yellow_on, display);
					al_flip_display();
					printf("UP\n");
					//validacion
					break;

				case ALLEGRO_KEY_DOWN:
					key_pressed[KEY_DOWN] = true;
					allegro_draw_bitmap_center(led_blue_on, display);
					al_flip_display();
					printf("DOWM\n");
					//validacion
					break;

				case ALLEGRO_KEY_LEFT:
					key_pressed[KEY_LEFT] = true;
					allegro_draw_bitmap_center(led_green_on, display);
					al_flip_display();
					printf("LEFT\n");
					//validacion
					break;
				case ALLEGRO_KEY_RIGHT:
					key_pressed[KEY_RIGHT] = true;
					allegro_draw_bitmap_center(led_red_on, display);
					al_flip_display();
					printf("RIGHT\n");
					//validacion
					break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			/*switch (ev.keyboard.keycode) 
			{
				case ALLEGRO_KEY_SPACE:
					key_pressed[KEY_SPACE] = false;
					break;

				case ALLEGRO_KEY_UP:
					key_pressed[KEY_UP] = false;
					break;

				case ALLEGRO_KEY_DOWN:
					key_pressed[KEY_DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					key_pressed[KEY_LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					key_pressed[KEY_RIGHT] = false;
					break;
				case ALLEGRO_KEY_ESCAPE:
					do_exit = true;
					break;
			}*/
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_SPACE: case ALLEGRO_KEY_UP: case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_RIGHT:
				redraw = true;
				break;

		
			case ALLEGRO_KEY_ESCAPE:
				do_exit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) 
		{

			redraw = false;
			
			//al_flip_display();
			al_rest(0.1);
			al_clear_to_color(al_color_name("white"));
			allegro_draw_bitmap_center(simon, display);
			al_flip_display();
			

		}
	}
	
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}
