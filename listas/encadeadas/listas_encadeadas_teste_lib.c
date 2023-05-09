#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_listas_encadeadas.h"

void main () {
    // declaração de lista não inicializada
    struct no * l;

    // inicializacao da lista
    criar_lista(&l);

    insere_inicio(&l, 10);
    insere_inicio(&l, 24);
    insere_inicio(&l, 3);
    insere_inicio(&l, 6);

    printf("Lista apos adicao de valor(es) no inicio:\n");
    mostrar_lista(l);

    remove_inicio(&l);

    printf("\nLista apos remocao de valor(es) do inicio:\n");
    mostrar_lista(l);

    insere_inicio(&l, 70);
    insere_inicio(&l, 21);

    printf("\nLista apos segunda adicao de valor(es) no inicio:\n");
    mostrar_lista(l);

    int elem_rm = 3;
    remove_meio(&l, elem_rm);
    printf("\nLista apos remocao do elemento 3:\n");
    mostrar_lista(l);

    esvazia_lista(&l);
    mostrar_lista(l);

}