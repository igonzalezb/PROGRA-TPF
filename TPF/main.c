

#include "main.h"

#include "allegro_display.h"


int main(void)
{
    pthread_t tid1;
    pthread_create(&tid1,NULL,thread_timer,double);
    if (ALLEGRO)
    {
        if (allegro_display_main())		//Llamo a la funcion de allegro de forma defensiva
        {
            fprintf(stderr, "Failed to initialize allegro!\n");
            return -1;
        }
    }
    
    else
    {
        
    }
    
    pthread_join(tid1,NULL);
    return 0;
}
