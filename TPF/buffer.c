
//////////////////////////////////// BUFFER ////////////////////////////////////

#include "buffer.h"

////////////////// create_buffer //////////////////

void create_buffer(CIRCULAR_BUFFER *p_struct, int size)
{
        
        (*p_struct).tamano = size;
        (*p_struct).puntero_buffer = (int *) calloc (size, sizeof(int));
        ((*p_struct).contador) = FALSE;
        ((*p_struct).escritura) = FALSE;
        ((*p_struct).lectura) = FALSE;
        
}


////////////////// state_buffer //////////////////

int state_buffer (CIRCULAR_BUFFER * p_struct)
{
        return ((*p_struct).contador);
}


////////////////// write_buffer //////////////////

void write_buffer (CIRCULAR_BUFFER * p_struct,int button)
{
        if ((state_buffer(p_struct))!=ERROR)
        {
                if ((state_buffer(p_struct)+1)>((*p_struct).tamano))
                {
                        ((*p_struct).contador)=ERROR;
                }
                else
                {
                        ((*p_struct).puntero_buffer)[((*p_struct).escritura)]=button;
                        ((*p_struct).contador)++;
                        ((*p_struct).escritura)++;
                        
                        if (((*p_struct).escritura)>(((*p_struct).tamano)-1))
                        {
                                ((*p_struct).escritura) = FALSE;
                        }
                        
                }
        }
        
        printf ("\ncontador= %d\n",(*p_struct).contador); //borrar????
        
        
        int i;
        
        for (i=0; i < TAMANO_BUFFER; i++)
        {
                printf("buf%d = %c\n", i, ((*p_struct).puntero_buffer)[i]); // borrar???
        }
        
}


////////////////// read_buffer //////////////////

int read_buffer (CIRCULAR_BUFFER * p_struct)
{
        int button=FALSE;
        
        if (((*p_struct).contador)!=FALSE)
        {
                if(((*p_struct).contador)==ERROR)
                {
                        ((*p_struct).contador)=((*p_struct).tamano);
                }
                
                button=((*p_struct).puntero_buffer)[((*p_struct).lectura)];
                
                ((*p_struct).contador)--;
                ((*p_struct).lectura)++;
                
                if(((*p_struct).lectura)>(((*p_struct).tamano)-1))
                {
                        ((*p_struct).lectura)=FALSE;
                }
        }
        return button;
}


////////////////// end_buffer //////////////////

void end_buffer (CIRCULAR_BUFFER * p_struct)
{
        free(((*p_struct).puntero_buffer));
}


