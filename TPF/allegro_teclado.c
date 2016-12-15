

//////////////////////////////////////// ALLEGRO_TECLADO /////////////////////////////////////////////
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
//      Analisis del ingreso de colores por teclado, siempre que la logica del juego lo permita.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include "allegro_teclado.h"

extern ALLEGRO_DISPLAY * display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern bool exit_simon;
extern bool player_lost;
bool exit_teclado = false;


////////////////////////////////////// buttons_teclado_input /////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: Nada.
//
//  Si esta corriendo el juego, si el jugador no perdio y si el ingreso de datos por teclado esta
//  habilitado, entonces se chequea si se ingresan colores. En caso de tocar una tecla, se prende
//  el color correspondiente y se envia el color para ser comparado con el que se debia haber ingresado.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_teclado_input(void)
{

	struct Point a;

	bool led_pressed[4] = { false, false, false, false};

	bool redraw = false;

	al_flush_event_queue(event_queue);

	while (!exit_simon && !player_lost && !exit_teclado)
	{
		ALLEGRO_EVENT ev;
		int color;
		al_wait_for_event(event_queue, &ev);
		

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			redraw = false;
                        
			exit_simon = true;
                        
			exit_teclado = true;
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

			if (CLICK_GREEN)
			{
				led_pressed[LED_GREEN] = true;
                                
				allegro_turn_led_on(LED_GREEN);
                                
				color = LED_GREEN;
			}
			else if (CLICK_RED)
			{
				led_pressed[LED_RED] = true;
                                
				allegro_turn_led_on(LED_RED);
                                
				color = LED_RED;
			}
			else if (CLICK_BLUE)
			{
				led_pressed[LED_BLUE] = true;
                                
				allegro_turn_led_on(LED_BLUE);
                                
				color = LED_BLUE;
			}
			else if (CLICK_YELLOW)
			{
				led_pressed[LED_YELLOW] = true;
                                
				allegro_turn_led_on(LED_YELLOW);
                                
				color = LED_YELLOW;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (led_pressed[LED_GREEN])
			{
				led_pressed[LED_GREEN] = false;
                                
				comparacion_validacion(color);
                                
				redraw = true;
			}
			else if (led_pressed[LED_RED])
			{
				led_pressed[LED_RED] = false;
                                
				comparacion_validacion(color);
                                
				redraw = true;
			}
			else if (led_pressed[LED_BLUE])
			{
				led_pressed[LED_BLUE] = false;
				
				comparacion_validacion(color);
                                
				redraw = true;
			}
			else if (led_pressed[LED_YELLOW])
			{
				led_pressed[LED_YELLOW] = false;
				
				comparacion_validacion(color);
                                
				redraw = true;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode) 
			{
				case ALLEGRO_KEY_SPACE:
					break;

				case ALLEGRO_KEY_UP:
					led_pressed[KEY_UP] = true;
					allegro_turn_led_on(LED_GREEN);
					al_flip_display();
					printf("UP\n");
					comparacion_validacion(LED_GREEN);
					break;

				case ALLEGRO_KEY_DOWN:
					led_pressed[KEY_DOWN] = true;
					allegro_turn_led_on(LED_BLUE);
					al_flip_display();
					printf("DOWM\n");
					comparacion_validacion(LED_BLUE);
					break;

				case ALLEGRO_KEY_LEFT:
					led_pressed[KEY_LEFT] = true;
					allegro_turn_led_on(LED_YELLOW);
					al_flip_display();
					printf("LEFT\n");
					comparacion_validacion(LED_YELLOW);
					break;
				case ALLEGRO_KEY_RIGHT:
					led_pressed[KEY_RIGHT] = true;
					allegro_turn_led_on(LED_RED);
					al_flip_display();
					printf("RIGHT\n");
					comparacion_validacion(LED_RED);
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
                                        exit_simon = true;
                                        exit_teclado = true;
                                        break;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) 
		{
			redraw = false;
			
                        al_rest(0.1);
                        
			al_clear_to_color(al_color_name("white"));
                        
			al_stop_samples();
                        
			allegro_draw_simon_off();
                        
			al_flip_display();
		}
	}
}


////////////////////////////////////// getDistance /////////////////////////////////////////
//
//  Recibe:	estructura con las coordenadas x y
//
//  Devuelve: la distancia del centro del display al punto
//
//  Calcula distancia del centro del display a un punto
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

double getDistance (struct Point a)
{
	double distance;
        
	distance = sqrt((a.x - (CENTER_W)) * (a.x - (CENTER_W)) + (a.y - (CENTER_H)) *(a.y - (CENTER_H)));
        
	return distance;
}

