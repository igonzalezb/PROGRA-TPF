
#include "simon.h"
#include "allegro_teclado.h"
#include "main.h"
int level = 0;
bool exit_simon = false;

int secuencia [MAX_LEVEL];

bool player_lost = false;
int input_color_number;
extern bool exit_teclado;

int simon_main (void)
{
	//int input_color_number;//, time_color_on = 1000, time_color_off = 1000; // ver si esta bien iniciar los times con 1 segundo (1000)
        carga_secuencia_colores(secuencia);
	double time = 0.5;
        //do
        //{
                for (level = 0; (level <= MAX_LEVEL) && (player_lost != true) && (exit_simon != true); level++)
                {
			//al_rest(0.1);
			muestra_secuencia (secuencia, level, time);//, time_color_on, time_color_off);
                        input_color_number = 0;
                        
			//al_rest(0.1);
			//exit_teclado = false;
			allegro_teclado_main();
			exit_teclado = false;
			printf("simon for\n");
			if (time >= 0.1)
			{
				time = time - 0.01;
			}
			

                }
        //} while (!player_lost && !exit_simon);
                
        game_over (level); //definir y declarar esta funcion
	printf("perdiste\n");
	if(allegro_lost())
		return ERROR;
	level = 0;
	return 0;
	//set_color_mode(secuencia[0], OFF);
}


/////////////// carga_secuencia_colores ///////////////


// ESTA AANDANDO PERO TIRA EL ERRROR QUE TE MANDEEEE, VER

void carga_secuencia_colores (int secuencia[])
{
        int i;

        time_t t;

        int random_number;

        srand((unsigned) time(&t));

        for (i = 0; i <= MAX_LEVEL; ++i)
        {
                random_number=(rand() % 4);
                secuencia[i] = random_number;
        }
}


////////////////////////////// muestra_secuencia() //////////////////////////////
// Recibe: nivel hasta el que tiene que mostrar la secuencia.
// Devuelve: (?)
/////////////////////////////////////////////////////////////////////////////////
// ver lo de time_color_on y off
//ver si devuelve algo de error y si lo ponemos como thread o no.

void muestra_secuencia (int secuencia[], int level, double time)
{
    int i;
    for (i = 0; i <= level; i++)
    {
	set_color_mode(secuencia[i], OFF);
	al_rest(time);
        set_color_mode (secuencia[i], ON);
        al_rest (time);   //HACER EL TIMER. como esta en un thread, esto poner tambien en thread (para permitir esc) REVISAR, BUSCAR ALTERNATIVA
        set_color_mode (secuencia[i], OFF);
        al_rest (time);
    }
}

int comparacion_validacion (int color)

{
	
	printf("color(click): %d, secuencia[]: %d\n", color, secuencia[input_color_number]);
	printf("numero de color %d\n", input_color_number);
	if (input_color_number == level)
	{
		exit_teclado = true;
		printf("validacion secuencia final\n");
	}
	if (color == secuencia[input_color_number])
	{
		++input_color_number;
		printf("validacion bien, siguiente\n");
		
		//return 0;
	}
	
	else if (color != secuencia[input_color_number])
	{
	        player_lost = true;
		printf("validacion perdiste\n");
	       // return 1;
	}
	
	printf("salgo de validacion\n");
	return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////

         void game_over (int level) //declararla
         {
                /* FILE *file_pointer;
                 file_pointer = fopen ("highest_score.txt", "a+");
                 int last_level;
                 char c;
                 c = fgetc(file_pointer);
                 if(c==EOF)
                 {
                         fprintf(file_pointer,"Score: %d",level);
                 }
                 else if(c!=EOF)
                 {
                         last_level= c - '0';
                         if (level > last_level)
                         {
				 fflush(file_pointer);
				 fprintf(file_pointer,"Score: %d",level);
                         }
                 }
                 fclose(file_pointer);	*/
         }
 
	 


