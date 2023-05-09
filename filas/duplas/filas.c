#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct fila {
    struct no *head;
    struct no *tail;
};

void inicia_fila(struct fila **);
void insere_elem(struct fila **, int);
void mostra_proximo(struct fila*);
void remove_inicio(struct fila **);

void main () {
    struct fila * f = (struct fila*)malloc(sizeof(struct fila));

    inicia_fila(&f);
    insere_elem(&f, 8);
    mostra_proximo(f);
    insere_elem(&f, 9);
    mostra_proximo(f);
    insere_elem(&f, 10);
    mostra_proximo(f);
    remove_inicio(&f);
    mostra_proximo(f);
}

void inicia_fila(struct fila **pf){
    (*pf)->head = NULL;
    (*pf)->tail = NULL;
}

// insere no fim
void insere_elem(struct fila **pf, int num){
    struct no *novo = (struct no *)malloc(sizeof(struct no));;

        //novo = (struct no *)malloc(sizeof(struct no));

        // verificacao da alocacao 
        if(!novo) {
            printf("Fila sem espaco\n");
            return;
        }

        // atribuicao de valores a novo
        novo->dado = num;
        novo->prox = NULL;

    // excecoes: fila vazia, fila com apenas 1 elem 
    if((*pf)->head == NULL){

        // ajuste de head e tail
        (*pf)->head = novo;
        (*pf)->tail = novo;

        return;
    }

    // antigo tail->prox agora aponta para o novo
    (*pf)->tail->prox = novo;

    // ajuste de tail pq head continua apontando para o mesmo elemento 
    (*pf)->tail = novo; 
}

// mostra do comeco
void mostra_proximo(struct fila *ff){
    if(ff->head == NULL) {
        printf("A fila esta vazia\n");
        return;
    }

    printf("O proximo valor da fila eh %d\n", ff->head->dado);
}

// remove do comeco
void remove_inicio(struct fila **pf){
    struct no *aux = (*pf)->head;

    if((*pf)->head == NULL){ 
        printf("Nao pode remover pois a lista esta vazia\n");
        return;
    }

    (*pf)->head = aux->prox;
    free(aux);
}