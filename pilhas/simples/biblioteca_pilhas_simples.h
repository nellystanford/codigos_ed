#ifndef BIBLIOTECA_PILHAS_SIMPLES_H
#define BIBLIOTECA_PILHAS_SIMPLES_H

#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 10

struct pilha {
    int vetor[TAM_PILHA];
    int topo;
}; 

void cria_pilha(struct pilha *);
void esvazia_pilha(struct pilha *);
void insere_topo(struct pilha *, int);
void mostra_topo(struct pilha);
void remove_topo(struct pilha *);

void cria_pilha(struct pilha *pp) {
    pp->topo = -1;
}

void esvazia_pilha(struct pilha *pp) {
    if(pp->topo == -1) {
        printf("\nLista ja esta vazia\n");
        return;
    }
    
    pp->topo = -1;
    printf("\nA pilha foi esvaziada!\n");
}

void insere_topo(struct pilha *pp, int num) {
    if(pp->topo == TAM_PILHA - 1) {
        printf("\nA insercao de elementos nao pode ser feita pois a pilha esta cheia!\n");
        return;
    }

    pp->vetor[pp->topo+1] = num;
    pp->topo = pp->topo+1;
}

void mostra_topo(struct pilha pp) {
    if(pp.topo == -1) {
        printf("\nO topo não possui elemento pois a pilha esta vazia!\n");
        return;
    }

    printf("\nAtualmente a pilha possui %d elemento(s). O valor armazenado no topo da pilha e: %d\n", pp.topo+1, pp.vetor[pp.topo]);
}

void remove_topo(struct pilha *pp) {
    if(pp->topo == -1) {
        printf("\nA remocao do topo nao pode ser executada pois a pilha esta vazia!\n");
        return;
    }

    pp->topo = pp->topo - 1;
}



#endif