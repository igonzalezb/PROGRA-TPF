
#include "simon.h"

#include "main.h"
int level = 0;
bool exit_simon = false;

int secuencia [MAX_LEVEL];

bool player_lost = false;
int input_color_number;
extern bool exit_teclado;

int simon_main (void)
{
	carga_secuencia_colores(secuencia);
	double time = BASE_TIME;
        
                for (level = 0; (level <= MAX_LEVEL) && (player_lost != true) && (exit_simon != true); level++)
                {
			
			muestra_secuencia (secuencia, level, time);//, time_color_on, time_color_off);
                        input_color_number = 0;
                       
			buttons_teclado_input();
			
			exit_teclado = false;
			printf("simon for\n");
			if (time >= MIN_TIME)
			{
				time = time - MIN_TIME;
			}
			

                }
        
                
        game_over (level); //definir y declarar esta funcion
	level = 0;
	printf("Perdiste\n");
	
	if(game_lost())
		return ERROR;
	
	
	return 0;
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
	WAIT_T(time);
        set_color_mode (secuencia[i], ON);
        WAIT_T(time);
        set_color_mode (secuencia[i], OFF);
        WAIT_T(time);
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
		
		
	}
	
	else if (color != secuencia[input_color_number])
	{
	        player_lost = true;
		printf("validacion perdiste\n");
	       
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
 
	 


