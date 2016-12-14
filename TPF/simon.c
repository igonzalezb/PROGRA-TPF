

/////////////////////////////////////////////// SIMON /////////////////////////////////////////////////
                                // S I M O N - Multiplataforma //

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
//                  Logica del juego y manejo de datos de entrada y salida.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include "simon.h"

extern bool exit_teclado;

int level = 0, input_color_number;
int secuencia [MAX_LEVEL];
bool exit_simon = false, player_lost = false;;


////////////////////////////////////////// simon_main /////////////////////////////////////////////////
//
//  Recibe: Nada.
//
//  Devuelve: 0.
//
//  El juego corre mientras el jugador no haya perdido. Primero se carga la secuencia de colores random
//  que luego debera ir respetando el jugador. Muestra la secuencia con un solo color, espera a que el
//  jugador la ingrese correctamente. A partir de una entrada, analiza que hacer. Si es correcta,
//  espera que se ingrese el color siguiente. Si ya se completo toda la secuencia del nivel, pasa al
//  siguiente. Si habia mostrado n colores, muestra n+1. Si el jugador ingresa un color incorrecto,
//  pierde y termina el juego.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void simon_main (void)
{
        carga_secuencia_colores (secuencia);
    
        double time = BASE_TIME;
        
        for (level = 0; (level <= MAX_LEVEL) && (player_lost != true) && (exit_simon != true); level++)
        {
                muestra_secuencia (secuencia, level, time);
            
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
    
        printf("Perdiste\n");
}


//////////////////////////////////// carga_secuencia_colores /////////////////////////////////////////
//
//  Recibe: secuencia (el arreglo en el que se guardan los colores aleatorios).
//
//  Devuelve: Nada.
//
//  De manera aleatoria se guardan los colores en secuencia. Esta secuencia dura hasta que el jugador
//  pierde o hasta que se cierre el programa (lo primero que suceda).
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void carga_secuencia_colores (int secuencia[])
{
        int i;
    
        time_t t;
    
        int random_number;
    
        srand ((unsigned) time(&t));
    
        for (i = 0; i <= MAX_LEVEL; ++i)
        {
                random_number = (rand() % 4);
            
                secuencia[i] = random_number;
        }
}


/////////////////////////////////////// muestra_secuencia /////////////////////////////////////////////
//
//  Recibe: secuencia (los colores que se guardaron aleatoriamente para una jugada).
//         level     (el nivel del momento).
//         time      (tiempo que se muestra un color y tiempo en el que permanecen todos apagados).
//
//  Devuelve: Nada.
//
//  Si el jugador esta en el nivel n, muestra los primeros n niveles (Desde n=0), siendo el primer color
//  el elemento 0.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

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


/////////////////////////////////////// comparacion_validacion ////////////////////////////////////////
//
//  Recibe: color (input)
//
//  Devuelve: 0.
//
//  Si el numero de color ingresado (input_color_number) es igual al nivel en el que esta el jugador,
//  se sale del teclado. De todos modos, se compara el color ingresado con el color guardado en la
//  secuencia. Si son iguales, el juego continua. De lo contrario, termina el juego.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

int comparacion_validacion (int color)
{
        printf ("color(click): %d, secuencia[]: %d\n", color, secuencia[input_color_number]);
    
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


////////////////////////////////////////////// game_over /////////////////////////////////////////////
//
//  Recibe: level (el nivel hasta el que llego el jugador).
//
//  Devuelve: Nada.
//
//  Se guarda el puntaje maximo en un archivo llamado highest_score:
//  Si el archivo no existe, es creado y se le guarda el puntaje obtenido en esta jugada (el puntaje
//  es equivalente al nivel maximo alcanzado).
//  Si el archivo ya existia, se lee el puntaje maximo que habia sido guardado de jugadas anteriores.
//  La funcion compara el puntaje actual con el puntaje maximo. El mayor de los dos es reescrito en el 
//  archivo
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

void game_over (int last_score)
{
    
    FILE *file_pointer;

    int old_highest_score, best_score;

    file_pointer=fopen ("highest_score.txt", "r");
    
    if (file_pointer == NULL)
    {
        file_pointer=fopen ("highest_score.txt", "w");

        fprintf(file_pointer, "%d", last_score);

        fclose(file_pointer);
    }
    

    else 
    {

            fscanf (file_pointer, "%d", &old_highest_score);

            fclose (file_pointer);

            file_pointer=fopen ("highest_score.txt", "w");        

            if (old_highest_score >= last_score)
            {
                    best_score = old_highest_score;
            }
            else
            {
                    best_score = last_score;
            }
    
            fprintf (file_pointer,"%d",best_score);

            fclose(file_pointer);
    }
}
 
	 


