

#include "main.h"

#include "allegro_display.h"


int main(void)
{
    pthread_t tid1;
//    pthread_create(&tid1,NULL,thread_timer,double);
    int platforms = ALLEGRO;
   
    switch (platforms)
    {
    case ALLEGRO:
	    if (allegro_display_main())		//Llamo a la funcion de allegro de forma defensiva
	    {
		    fprintf(stderr, "Failed to initialize allegro!\n");
		    return ERROR;
	    }
	    allegro_setup_uninstall();
	    break;
    case RASPBERRYPI:

	    break;
    }
    
  
    printf("CP1\n");
   // pthread_join(tid1,NULL);
    return 0;
}
