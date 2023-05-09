#ifndef BIBLIOTECA_FILAS_SIMPLES
#define BIBLIOTECA_FILAS_SIMPLES

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct fila {
    int dados[5];
    int head, tail;
    // insere pela tail e quando remove head++
   // vetor tem formato circular, conta de 0 até x e depois volta para o 0 
};

#endif