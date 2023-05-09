#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct fila {
    int dados[5];
    int head, tail;
    // insere pela tail e quando remove head++
   // vetor tem formato circular, conta de 0 até x e depois volta para o 0 
};

void inicia_fila(struct fila *);
void insere_elem(struct fila *, int);
void mostra_proximo(struct fila);
void remove_inicio(struct fila *);


void main () {
    struct fila f;

    inicia_fila(&f);

    for(int i = 0; i < 5; i++) {
        insere_elem(&f, i + 1);
    }

    printf("\nO valor do head é %d e do tail é %d\n", f.head, f.tail);
    mostra_proximo(f);

    for(int i = 0; i < 4; i++) {
        remove_inicio(&f);
    }

    printf("\nO valor do head é %d e do tail é %d\n", f.head, f.tail);
    mostra_proximo(f);

    insere_elem(&f, 22);
    remove_inicio(&f);
    printf("\nO valor do head é %d e do tail é %d\n", f.head, f.tail);
    mostra_proximo(f);

}

void inicia_fila(struct fila *pf) {
    pf->head = -1;
    pf->tail = -1;
}

void insere_elem(struct fila *pf, int elem) {

    // verifica se está cheia
    if(pf->head == pf->tail + 1 || pf->head == 0 && pf->tail == TAM - 1) {
        printf("\nNao podemos adicionar elementos pois a fila esta cheia!\n");
        return;
    } 

    // faz com que seja circular pq volta para zero se tail apontar para ultima posicao
    if(pf->tail == TAM - 1) {
        pf->dados[0] = elem;
        pf->tail = 0;
    } else {
        pf->dados[pf->tail+1] = elem;
        pf->tail = pf->tail + 1;
    }

    if(pf->head == -1) pf->head = 0;
}

void mostra_proximo(struct fila ff) {
    if(ff.head == -1) {
        printf("\nA fila esta vazia!\n");
        return;
    }

    printf("\nO proximo valor da fila e %d\n", ff.dados[ff.head]);
}

void remove_inicio(struct fila *ff) {
    if(ff->head == -1) {
        printf("\nNenhum elemento pode ser removido pois a fila ja esta vazia!\n");
        return;
    }

    // faz com que seja circular pq volta para zero se head apontar para ultima posicao
    if(ff->head == TAM - 1) {
        ff->head = 0;
    } else {
        ff->head = ff->head + 1;
    }
}