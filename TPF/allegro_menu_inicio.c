

///////////////////////////////////// ALLEGRO_MENU_INICIO ////////////////////////////////////////////
                                   // S I M O N - Allegro //

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Trabajo Practico Final - Programacion 1
//
//  Entrega: 15 de Diciembre de 2016                       ////////////////
//                                                        //  S I M O N //
//  Grupo 6:Gonz‡lez Bigliardi, I–aki                    ////////////////
//          Lago, Valentina
//          MŸller, Malena
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                Menu del juego, en pantalla.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include "allegro_menu_inicio.h"

#include "simon.h"
extern ALLEGRO_DISPLAY * display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern bool exit_simon, player_lost;

////////////////////////////////////// allegro_menu_inicio  ///////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: 0 o ERROR
//
//  Muestra un menu de inicio (con musica de fondo). Cuando se apreta SPACE o se clickea en PLAY
//  entra al juego.
///////////////////////////////////////////////////////////////////////////////////////////////////////

int allegro_menu_inicio()
{
	ALLEGRO_BITMAP *menu_simon = NULL;

	ALLEGRO_BITMAP *menu_simon_play = NULL;

	ALLEGRO_SAMPLE *sample_menu = NULL;

	ALLEGRO_FONT * font_menu = NULL;
	
	bool do_exit1 = false;

	bool play = false;

	bool redraw1 = false;

//================================================================================================
	menu_simon = al_load_bitmap("resources/menu_simon.png");
	if (!menu_simon) {
		fprintf(stderr, "Failed to create menu_simon!\n");
		return ERROR;
	}

	menu_simon_play = al_load_bitmap("resources/menu_simon_play.png");
	if (!menu_simon_play) {
		fprintf(stderr, "Failed to create menu_simon_play!\n");
		al_destroy_bitmap(menu_simon);
		return ERROR;
	}

	

	font_menu = al_load_ttf_font("resources/phreak.ttf", 54, 0);

	if (!font_menu) {
		fprintf(stderr, "Could not load 'atari.ttf'.\n");
		al_destroy_bitmap(menu_simon);
		al_destroy_bitmap(menu_simon_play);
		return ERROR;
	}


	sample_menu = al_load_sample("resources/sounds/menu_inicio.wav");

	if (!sample_menu) {
		printf("Audio clip sample not loaded!\n");
		al_destroy_bitmap(menu_simon);
		al_destroy_bitmap(menu_simon_play);
		al_destroy_font(font_menu);
		return ERROR;
	}
//=======================================================================================================================================================================
	allegro_draw_bitmap_scaled(menu_simon);
        
	al_draw_text(font_menu, al_color_name("white"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ": : PLAY : :");
        
	al_flip_display();
                
	al_play_sample(sample_menu, 1.0, 0.0,1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
        
	int x1, x2, y1, y2, w, h;	//Coordenadas del boton Play
        
	int mx, my;			//Coordenadas del mouse

	while (!do_exit1)
	{
		ALLEGRO_EVENT ev1;

		al_wait_for_event(event_queue, &ev1);

		if (ev1.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			do_exit1 = true;
                
		else if (ev1.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
		{
			al_acknowledge_resize(ev1.display.source);
			redraw1 = true;
		}

		else if (ev1.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			al_get_text_dimensions(font_menu, ": : PLAY : :", &x1, &y1, &w, &h);
                        
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
				allegro_draw_bitmap_scaled(menu_simon_play);
                                
				al_draw_text(font_menu, al_color_name("green"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ": : PLAY : :");
                                
				al_flip_display();
			}
		}
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
                                allegro_draw_bitmap_scaled(menu_simon_play);
                                
				al_draw_text(font_menu, al_color_name("green"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ": : PLAY : :");
                                
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
					do_exit1 = true;
					break;
			}
		}
		if (play && al_is_event_queue_empty(event_queue))
		{
			al_stop_samples();
		//==========================CARTEL DE LOADING=======================================
			al_clear_to_color(al_color_name("black"));
			al_draw_text(font_menu, al_color_name("white"), (CENTER_W), (CENTER_H), ALLEGRO_ALIGN_CENTER, "LOADING...");
			al_flip_display();
			al_rest(1.5);
		//====================================================================================
			simon_main();
			
			if(game_lost())
            		{
                		return ERROR;
            		}
			al_flush_event_queue(event_queue);
                        
			al_play_sample(sample_menu, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
                        
			exit_simon = false;

			player_lost = false;
			
			play = false;
                        
			redraw1 = true;
                        
			al_flush_event_queue(event_queue);
                        
		}
		if (redraw1 && al_is_event_queue_empty(event_queue))
		{
			al_clear_to_color(al_color_name("black"));
                        
			allegro_draw_bitmap_scaled(menu_simon);
                        
			al_draw_text(font_menu, al_color_name("white"), PLAY_BUTTON_X, PLAY_BUTTON_Y, ALLEGRO_ALIGN_CENTER, ": : PLAY : :");
                        
			al_flip_display();
                        
			redraw1 = false;
                        
			play = false;
		}
	}
	
	al_destroy_bitmap(menu_simon);
	al_destroy_bitmap(menu_simon_play);
	al_destroy_font(font_menu);
	al_destroy_sample(sample_menu);
	return 0;
}
