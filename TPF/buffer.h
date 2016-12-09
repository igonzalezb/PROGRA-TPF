
//////////////////////////////////// BUFFER - HEADER ////////////////////////////////////

#ifndef _BUFFER_H_
#define _BUFFER_H_



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANO_BUFFER 100


#define FALSE 0
#define TRUE 1
#define ERROR -1



typedef struct
{
        int tamano;
        int contador;
        int escritura;
        int lectura;
        int *puntero_buffer;
} CIRCULAR_BUFFER;



void create_buffer(CIRCULAR_BUFFER *p_struct, int size);

int state_buffer(CIRCULAR_BUFFER * p_struct);

void write_buffer(CIRCULAR_BUFFER * p_struct,int button);

int read_buffer(CIRCULAR_BUFFER * p_struct);

void end_buffer(CIRCULAR_BUFFER * p_struct);



#endif  // _BUFFER_H_
