#include "main.h" 
#include "allegro_teclado.h"


extern ALLEGRO_DISPLAY * display;
extern ALLEGRO_EVENT_QUEUE *event_queue;

int allegro_teclado_main ()
{
	//ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	//ALLEGRO_TIMER *timer = NULL;

	struct Point a;

	bool led_pressed[4] = { false, false, false, false};

	bool redraw = false;

	bool do_exit = false;

//=========================================================================================================
	/*timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "Failed to create timer!\n");
		return ERROR;
	}*/

	//event_queue = al_create_event_queue();
	//if (!event_queue) {
	//	fprintf(stderr, "Failed to create event_queue!\n");
	//	//al_destroy_timer(timer);
	//	
	//	return ERROR;
	//}

//=========================================================================================================
	al_clear_to_color(al_color_name("white"));	//Fondo Blanco

	allegro_draw_simon_off();

	al_flip_display();
	
	
//==========================================================================================================	
	
	//al_register_event_source(event_queue, al_get_display_event_source(display));
	////al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//al_register_event_source(event_queue, al_get_keyboard_event_source());
	//al_register_event_source(event_queue, al_get_mouse_event_source());

	//al_start_timer(timer);
		
	while (!do_exit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		printf("CP3\n");
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			redraw = false;
			do_exit = true;
		}
			
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
		{
			al_acknowledge_resize(ev.display.source);
			redraw = true;
		}
		
		
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			a.x = ev.mouse.x;
			a.y = ev.mouse.y;
			//FIJARSE LO DE IF CAMBIARLOS POR ELSE IF O ALGUNA COSA
			if (CLICK_GREEN)
			{
				
				led_pressed[LED_GREEN] = true;
				allegro_turn_led_on(LED_GREEN);
				al_flip_display();
			}
			else if (CLICK_RED)
			{
				led_pressed[LED_RED] = true;
				allegro_turn_led_on(LED_RED);
				al_flip_display();
			}
			else if (CLICK_BLUE)
			{
				led_pressed[LED_BLUE] = true;
				allegro_turn_led_on(LED_BLUE);
				al_flip_display();
			}
			else if (CLICK_YELLOW)
			{
				led_pressed[LED_YELLOW] = true;
				allegro_turn_led_on(LED_YELLOW);
				al_flip_display();
			}
		
		}
		
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if(led_pressed[LED_GREEN] || led_pressed[LED_RED] || led_pressed[LED_BLUE] || led_pressed[LED_YELLOW])
			{
				led_pressed[LED_GREEN] = false;
				led_pressed[LED_RED] = false;
				led_pressed[LED_BLUE] = false;
				led_pressed[LED_YELLOW] = false;
				redraw = true;
			}

		}
		
		
		
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode) 
			{
				case ALLEGRO_KEY_SPACE:
					//RESTART GAME ? o nada
					break;

				case ALLEGRO_KEY_UP:
					led_pressed[KEY_UP] = true;
					allegro_turn_led_on(LED_GREEN);
					al_flip_display();
					printf("UP\n");
					//validacion
					break;

				case ALLEGRO_KEY_DOWN:
					led_pressed[KEY_DOWN] = true;
					//allegro_draw_bitmap_center(led_blue_on, display);
					allegro_turn_led_on(LED_BLUE);
					al_flip_display();
					printf("DOWM\n");
					//validacion
					break;

				case ALLEGRO_KEY_LEFT:
					led_pressed[KEY_LEFT] = true;
					//allegro_draw_bitmap_center(led_yellow_on, display);
					allegro_turn_led_on(LED_YELLOW);
					al_flip_display();
					printf("LEFT\n");
					//validacion
					break;
				case ALLEGRO_KEY_RIGHT:
					led_pressed[KEY_RIGHT] = true;
					//allegro_draw_bitmap_center(led_red_on, display);
					allegro_turn_led_on(LED_RED);
					al_flip_display();
					printf("RIGHT\n");
					//validacion
					break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_SPACE: case ALLEGRO_KEY_UP: case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_RIGHT:
				led_pressed[LED_GREEN] = false;
				led_pressed[LED_RED] = false;
				led_pressed[LED_BLUE] = false;
				led_pressed[LED_YELLOW] = false;
				redraw = true;
				break;

			case ALLEGRO_KEY_ESCAPE:
				redraw = false;
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
			//allegro_draw_bitmap_center(simon, display);
			allegro_draw_simon_off();
			al_flip_display();
			

		}
	}
	
	//al_destroy_timer(timer);
	//al_destroy_event_queue(event_queue);
	
	return 0;
}






double getDistance(struct Point a)
{
	double distance;
	distance = sqrt((a.x - (CENTER_W)) * (a.x - (CENTER_W)) + (a.y - (CENTER_H)) *(a.y - (CENTER_H)));
	return distance;
}