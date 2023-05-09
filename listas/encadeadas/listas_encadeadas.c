#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variável guarda o dado (int) e um ponteiro para o próximo item da lista, 
// caso não tenha próximo item, o valor armazenado será NULL
struct no {
    int valor;
    struct no *prox;
};

void criar_lista(struct no **);
void esvazia_lista(struct no **);
void insere_inicio(struct no **, int);
void mostrar_lista(struct no *);
void remove_inicio(struct no **);
void remove_meio(struct no **, int);

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

// como l já era *, fica ** (um dos * representa o tipo de variável)
void criar_lista(struct no **pl) {
    *pl = NULL;
}

void esvazia_lista(struct no **pl) {
    printf("\nEntrou na funcao de limpar lista\n");
    int count = 1;
    struct no * aux;
    
    // se a lista já for vazia a função retorna 
    if(pl == NULL) {
        printf("Nao foi possivel esvaziar a lista pois ela ja esta vazia!\n");
        return;
    }

    //enquanto valor apontado for diferente de 0
    while (*pl)
    {
        // aux aponta para o elemento da vez (quando entra é o primeiro)
        aux = *pl;

        // pl aponta para elemento seguinte (quando entra é o segundo)
        *pl = (*pl)->prox;

        // aux é liberado (elemento anterior ao apontado por pl)
        free (aux);
        printf("Limpou o elemento %d da lista\n", count);
        count++;
    }

    // pl é iniciado novamente, apontando para null já que está vazio
    *pl = NULL;
}

void insere_inicio(struct no **pl, int v) {
    struct no * nova;
    nova = (struct no*) malloc(sizeof(struct no));
    if(!nova) { 
        return; 
    }

    // preenche
    nova->valor = v;
    nova->prox = *pl;

    // coloca nova na lista
    *pl = nova;

    //OBS: O conteúdo apontado por ll é o começo da lista (endereço)
}

void mostrar_lista(struct no *ll) {
    // o uso do aux permite que possamos acessar o início da lista na função, pois preserva o ll
    struct no * aux;
    int i = 1;

    aux = ll;

    if(aux == NULL) { 
        printf("\nLista vazia!\n");
        return;
    }

    // enquanto o endereco apontado for diferente de null continua printando
    for(aux = ll; aux != NULL; aux = aux->prox) {
        printf("O valor %d da lista é %d\n", i, aux->valor);
        i++;
    }
}

void remove_inicio(struct no **pl) {
    // variavel auxiliar que aponta para o comeco da lista 
    struct no * aux;
    aux = *pl;

    // se o comeco da lista for nula avisa que ela esta vazia e retorna 
    if(aux == NULL) { 
        printf("Retorno da funcao remocao pela lista estar vazia\n"); 
        return;
    }

    // faz com que pl aponte para o proximo item da lista (nesse caso, o segundo)
    *pl = aux->prox;

    // libera a memoria de aux 
    free(aux);
}

void remove_meio(struct no **pl, int elem) {
    // exceções: lista vazia, lista com 1 elemento (remove inicio), lista com 2 elementos
    // https://gabrielbueno072.github.io/rea-aed/aula_list.html

    struct no *remover = NULL;


    if (pl == NULL) {
        printf("Não da para remover elementos, lista vazia!\n");
        return;
    }
    
    if((*pl)->valor == elem) {
        // função de remover no início 
        remover = *pl;
        // faz com que pl aponte para o proximo item da lista (nesse caso, o segundo)
        *pl = remover->prox;
        // libera a memoria de aux 
        free(remover);
        return;
    }

    struct no *aux;

    aux = *pl;
    // laço para encontrar valor que desejamos remover, para no elemento anterior ao que buscamos
    while(aux->prox != NULL & aux->prox->valor != elem){
        aux = aux->prox;
    }

    // valor do prox é o que queremos remover, caso o valor não tenha sido encontrado não entra no if pois aux vira null
    if(aux->prox) {
        // remover igual ao elemento que queremos excluir 
        remover = aux->prox;

        // linkagem entre elemento e próxima posição
        aux->prox = remover->prox;

        free(remover);
    }


}
