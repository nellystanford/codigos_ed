#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 10

struct pilha {
    int vetor[TAM_PILHA];
    int topo;
}; 

// fazer func de verificacao se pilha esta vazia ou cheia 
void cria_pilha(struct pilha *);
void esvazia_pilha(struct pilha *);
void insere_topo(struct pilha *, int);
void mostra_topo(struct pilha);
void remove_topo(struct pilha *);


void main () {
    struct pilha p;

    cria_pilha(&p);
    insere_topo(&p, 20);
    insere_topo(&p, 25);
    mostra_topo(p);
    remove_topo(&p);
    mostra_topo(p);
    esvazia_pilha(&p);
    remove_topo(&p);
    mostra_topo(p);


}

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

// push pilha
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

// pop pilha
void remove_topo(struct pilha *pp) {
    if(pp->topo == -1) {
        printf("\nA remocao do topo nao pode ser executada pois a pilha esta vazia!\n");
        return;
    }

    pp->topo = pp->topo - 1;
}