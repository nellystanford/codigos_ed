#include "biblioteca_listas_duplas.h"

void main (){
    struct no *listai;
    struct no *listaf;

    cria_lista(&listai);
    insere_inicio(&listai, 22);
    insere_fim(&listai, 4);
    insere_meio(&listai, 10, 22);
    imprime_lista(listai);
    remove_item(&listai, 22);
    imprime_lista(listai);
    define_listaf(&listai, &listaf);
    imprime_inverso(listaf);


}