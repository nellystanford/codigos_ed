#ifndef BIBLIOTECA_LISTAS_H
#define BIBLIOTECA_LISTAS_H

#include <stdio.h>

#define TAM_VETOR 10

// TIPO
struct lista {
    int dados[TAM_VETOR];
    int controle;
};

// FUNCOES
void cria_lista(struct lista *); 
void insere_fim(struct lista *, int);
void remove_fim(struct lista *);
void esvazia_lista(struct lista *);
void mostra_lista (struct lista);

void cria_lista(struct lista *pl){
    pl -> controle = -1; // ou (*pl).controle = -1;
}

void insere_fim(struct lista *pl, int num) {
    if(pl -> controle == TAM_VETOR - 1) {
        printf("A lista esta cheia!\n");
    } else {
        pl -> dados[(*pl).controle + 1] = num;
        pl -> controle = pl -> controle + 1;
    }
}

void mostra_lista (struct lista ll) {

    if(ll.controle == -1) {
        printf("A lista esta vazia!\n");
        return;
    }
    
    for(int i = 0; i <= ll.controle; i++) {
    printf("O valor %d da lista e igual a %d\n", i+1, ll.dados[i]);
    }
}

void remove_fim(struct lista *pl) {

    if(pl->controle == -1) {
        printf("A lista esta vazia, nao podemos remover itens!\n");
    }

    pl->controle = pl->controle - 1;
    printf("Item removido\n");
}

void esvazia_lista(struct lista *pl) {

    if(pl->controle == -1) {
        printf("A lista ja esta vazia!\n");
        return;
    }

    pl->controle = -1;
    printf("Lista esvaziada\n");
}

#endif