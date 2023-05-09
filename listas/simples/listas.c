#include "biblioteca_listas.h"

void main() {
    struct lista l;

    cria_lista(&l);
    for(int i = 0; i<3; i++) {
        insere_fim(&l, i);
    }
    mostra_lista(l);
    remove_fim(&l);
    mostra_lista(l);
    esvazia_lista(&l);
    mostra_lista(l);

}