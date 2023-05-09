#include <stdio.h>
#include <stdlib.h>

struct pilha {
    int valor;
    struct pilha *prox;
}; 

void cria_pilha(struct pilha **);
void esvazia_pilha(struct pilha **);
void insere_topo(struct pilha **, int);
void mostra_topo(struct pilha *);
void remove_topo(struct pilha **);

void main () {
    struct pilha *p;

    cria_pilha(&p);
    insere_topo(&p, 22);
    insere_topo(&p, 4);
    mostra_topo(p);
    esvazia_pilha(&p);
    remove_topo(&p);
    mostra_topo(p);
}

// ponteiro para a pilha é declarado como nulo quando a mesma está vazia
void cria_pilha(struct pilha **pp) {
    *pp = NULL;
}

// herda função de esvaziamento das listas encadeadas
void esvazia_pilha(struct pilha **pp) {
    printf("\nEntrou na funcao de limpar pilha\n");
    int count = 1;
    struct pilha * aux;
    
    // se a pilha já for vazia a função retorna 
    if(pp == NULL) {
        printf("Nao foi possivel esvaziar a pilha pois ela ja esta vazia!\n");
        return;
    }

    //enquanto valor apontado for diferente de 0
    while (*pp)
    {
        // aux aponta para o elemento da vez (quando entra é o primeiro)
        aux = *pp;

        // pp aponta para elemento seguinte (quando entra é o segundo)
        *pp = (*pp)->prox;

        // aux é liberado (elemento anterior ao apontado por pp)
        free (aux);
        //printf("Limpou o elemento %d da pilha\n", count);
        //count++;
    }

    // pp é iniciado novamente, apontando para null já que está vazio
    *pp = NULL;
}

// herda função de inserir no inicio das listas encadeadas
void insere_topo(struct pilha **pp, int num) {
    struct pilha * nova;
    nova = (struct pilha*) malloc(sizeof(struct pilha));

    // if serve para o caso da alocação não ser feita
    if(!nova) { 
        return; 
    }

    // preenche o valor
    nova->valor = num;

    // aponta o prox como o atual inicio da lista  
    nova->prox = *pp;

    // coloca nova na lista (pp que indica o comeco passa a apontar para nova)
    *pp = nova;

    //OBS: O conteúdo apontado por pp é o começo da lista (endereço)
}

void mostra_topo(struct pilha *pp) {
    if(pp == NULL) {
        printf("\nA pilha está vazia!\n");
        return;
    }

    printf("\nO valor que o topo da pilha armazena eh: %d\n", pp->valor);
}

// herda função de remmover no inicio das listas encadeadas
void remove_topo(struct pilha **pp) {
    // variavel auxiliar que aponta para o comeco da lista 
    struct pilha * aux;
    aux = *pp;

    // se o comeco da pilha for nulo avisa que ela esta vazia e retorna 
    if(aux == NULL) { 
        printf("Retorno da funcao remocao pela pilha estar vazia\n"); 
        return;
    }

    // faz com que pl aponte para o proximo item da lista (nesse caso, o segundo)
    *pp = aux->prox;

    // libera a memoria de aux 
    free(aux);
}
