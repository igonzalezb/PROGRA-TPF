
//Ver como identificar la plataforma correctamente
// definir las plataformas en algun lado y poner de donde vienen
// ver que cosas poner en threads y cuales no
// hacer funcion que reinice juego cuando se apreta SPACE
// las dos configuraciones en realidad habria que pasarlas al main posta (probablemente)
// falta definir los tiempos DOUBLE time_color_on y time_color_off
// hacer el timer

#include "game_main.h"
#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"

enum platforms {allegro,raspberryPi};
enum colores {RED, GREEN, BLUE, YELLOW};

#define         ON      1
#define         OFF     0

int configuration_start (int platform);
int configuration_start (int platform);
void carga_secuencia_colores (int []); //ver si dejar int [] o si queda mejor int*
void* muestra_secuencia(int secuencia[], int level, int platform, double time_color_on, double time_color_off);
void* timer (int);

int platform; //en algun momento al principio de todo, esto se iguala a allegro o a raspberryPi


////////////    ///////////     //////////      /////////     /////////
int platform; //en algun momento al principio de todo, esto se iguala a allegro o a raspberryPi

int configuration_start (platform) //poner que devuelva indicacion de exito o error.
{
    switch (platform)
    {
        case allegro:  //PONER INICIALIZACIONES DE ALLEGRO
            break;
            
        case raspberryPi:
            pinsT leds[] = {{"RED","4","out","OFF","OFF"}, //VERRRR los "OFF"
                {"GREEN","17","out","OFF","OFF"},
                {"BLUE","18","out","OFF","OFF"},
                {"YELLOW","27","out","OFF","OFF"}};
            inicio_estado_pines (leds); //funcion que esta en hardware.c
            break;
    }
}

/////////////////////////
int configuration_end (platform) //poner que devuelva indicacion de exito o error.
{
    switch (platform)
    {
        case allegro:  //PONER FINALIZACIONES DE ALLEGRO
            break;
            
        case raspberryPi:
            unexport_all_pins(leds);
            break;
    }
    
    
    //////////////////////////////////////////////////////////////////////////
    
    int level;
    
    int game_main(void)
    {
        int secuencia[MAX_LEVEL] = NULL;
        pthread_t tid1, tid2, tid3, tid4;
        carga_secuencia_colores(secuencia);
    }
    
    
    void carga_secuencia_colores (int secuencia[])
    {
        int i;
        for (i = 0; i <= MAX_LEVEL; ++i)
        {
            srand(time(NULL));
            int random_number = (rand() % (3));
            secuencia[i] = random_number;
        }
    }
    
    ////////////////////////////// muestra_secuencia() //////////////////////////////
    // Recibe: nivel hasta el que tiene que mostrar la secuencia.
    // Devuelve: (?)
    /////////////////////////////////////////////////////////////////////////////////
    // ver lo de time_color_on y off
    //ver si devuelve algo de error y si lo ponemos como thread o no.
    
    void* muestra_secuencia (int secuencia[], int level, int platform, double time_color_on, double time_color_off)
    {
        int i;
        for (i = 0; i <= level; i++)
        {
            set_color_mode(secuencia[i], "ON", platform);
            timer(time_color_on);   //HACER EL TIMER. como esta en un thread, esto poner tambien en thread (para permitir esc) REVISAR, BUSCAR ALTERNATIVA
            set_color_mode(secuencia[i], "OFF", platform);
            time(time_color_off);
        }
    }
    
    ////////////////////////////// set_color_mode() //////////////////////////////
    //
    void set_color_mode (int color, char color_mode, int platform)
    {
        switch (platform)
        {
            case allegro:   //poner aca que se prenda/aapgue el color en allegro, usando: color,  color_mode
                break;
                
            case raspberryPi:
                leds[color].value = color_mode; // ver si hay que poner tambien en value_copy
                set_pin_zero_or_one (color, pinsT leds[]);
                break;  //poner aca que se prenda/apague el led usando: color, color_mode.
        }
    }
    
    /////////////////////////////
    //int
    
    
    
    
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////////
    void* thread_teclado_allegro()
    {
        
    }
    
    void* thread_teclado_rpi()
    {
        
    }
    
    unsigned int time_left;
    
    void* thread_timer(double time)
    {
        usleep(time); //ver si usar usleep o sleep
        if(time_left)
        {
            time_left--;
        }
    }
    
    void* thread_set_timer(int time) //En realidad esto no haria falta porque se deberia iniciar el timer directo sin while 1.
    {   //lo malo de esto es que el tiempo se estaria reiniciando todo el tiempo
        static int r=0;
        while (1)//VER QUE PONER EN EL LUGAR DEL 1
        {
            if(!time_left) //wait for thred_timer
            {
                time_left = time_delay(500);
            }
        }
    }
    
    //void* thread_comparacion()
    //{
    //	int perdiste = FALSE;
    //	while (!perdiste)
    //	{
    //		for (i=0; (i <= level) && (!perdiste) ; ++i)
    //		{
    //
    //			if (!(buffer_circular == arreglo[i])) //puntero lectura del buffer
    //			{
    //				perdiste = TRUE;
    //			}
    //			++buffer_circular
    //
    //		}
    //	}
    //}
    
    
    
 