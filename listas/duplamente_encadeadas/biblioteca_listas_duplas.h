#ifndef BIBLIOTECA_LISTAS_DUPLAS_H
#define BIBLIOTECA_LISTAS_DUPLAS_H

#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no * ant;
    int valor;
    struct no * prox;
};

void busca_na_lista(struct no **, int);
void cria_lista(struct no **);
void imprime_inverso(struct no *);
void imprime_lista(struct no *);
void define_listaf(struct no**, struct no**);
void insere_fim(struct no **, int);
void insere_inicio(struct no **, int);
void insere_meio(struct no **, int, int);
void remove_item(struct no **, int);

// FINALIZAR IMPLEMENTAÇÃO EM FORMATO DE FUNÇÃO
void busca_na_lista(struct no **pli, int num) {
    struct no *aux, *no = NULL;

    aux = *pli;
    while(aux && aux->valor != num) {
        aux = aux->prox;
    }

    if(aux) {
        no = aux;
    }

    //return no (??)
}

void cria_lista(struct no **pli) {
    *pli = NULL;
}

void imprime_inverso(struct no *llf) {
    printf("\nImpressao de lista inversa:\n");
    while(llf){
        printf("Valor %d\n", llf->valor);
        llf = llf->ant;
    }
}

void imprime_lista(struct no *lli) {
    int i = 1;
    printf("\nImpressao de lista:\n");
    while(lli){
        printf("O valor %d da lista e: %d\n", i, lli->valor);
        i++;
        lli = lli->prox;
    }
}

void define_listaf(struct no **pli, struct no **plf) {
    // auxiliar recebe início da nossa lista 
    struct no *aux = *pli;

    // percorremos nossa lista até o final, quando nossa repetição terminar significa que o próximo não existe
    while(aux->prox) {
        aux = aux->prox;
    }

    *plf = aux;
}

void insere_fim(struct no **pli, int num){
    // cria o "quadrado" com o valor e uma variável auxiliar
    // pode ser reescrito assim: struct no *aux, *novo = malloc(sizeof(struct no));
    struct no *aux;
    struct no *novo = malloc(sizeof(struct no));

    // se consseguir fazer o malloc entra no if
    if(novo) {
        novo->valor = num;
        // como a inserção é no fim, podemos dizer que o próximo valor é nulo
        novo->prox = NULL;

        // verifica se o item que estamos inserindo é o primeiro da lista 
        if(pli == NULL) {
            // em caso positivo da lista estar vazia, transforma novo no primeiro item da lista
            novo->ant = NULL;
            *pli = novo;
        } else {
            // em caso negativo da lista estar vazia
            aux = *pli;
            // caminha até o final da lista
            while(aux->prox) { // enquando o prox item for diferente de NULL
                aux = aux->prox;
            }
            // faz com que o último item deixe de apontar para NULL e aponte para o novo item
            aux->prox = novo;
            // anterior do novo item é o antigo último item (salvo em aux por conta do laço while)
            novo->ant = aux;
        }
    } else {
        printf("\nErro ao alocar memoria para inserir item ao fim da lista!\n");
    }

}


void insere_inicio(struct no **pli, int num) {
    // cria o "quadrado" com o valor 
    struct no * novo = malloc(sizeof(struct no));

    // se consseguir fazer o malloc entra no if
    if(novo) {
        // coloca o num no espaço de valor do quadrado
        novo->valor = num;
        // como prox item o novo item aponta para o começo da lista (marcado por pli)
        novo->prox = *pli;
        // como item anterior o novo item aponta para NULL, já que está sendo inserido no início
        novo->ant = NULL;

        // se ja existir alguém na lista, o anterior desse tem que apontar para o novo item
        // se conteúdo da lista é diferente de nulo...(tem alguém na lista)
        if(*pli != NULL) {
            (*pli)->ant = novo; // (anterior do primeiro item da lista é o novo item)
        }

        // começo da lista agora é o novo
        *pli = novo;

    } else {
        printf("\nErro ao alocar memoria para inserir item no inicio da lista!\n");
    }
}

void insere_meio(struct no **pli, int num, int ant) {
    struct no *aux, *novo = malloc(sizeof(struct no));

    if(novo) {
        novo->valor = num;
        // e o primeiro item da lista?
        if(pli == NULL) {
            // novo é inserido como primeiro item da lista
            novo->prox = NULL;
            novo->ant = NULL;
            *pli = novo;
        } else {
            aux = *pli;
            // enquanto não chegar no valor de referencia para descobrir onde inserir (ant) nem no fim da lista 
            while(aux->valor != ant && aux->prox != NULL) {
                // se valor é diferente E existe um próximo, iremos caminhar para esse próximo
                aux = aux->prox;
            }

            // aux salva o numero que tem que vir antes do que iremos inserir, ou seja,
            // nosso novo numero será inserido logo após o aux

            // nosso novo numero aponta para o numero que vinha após o aux
            novo->prox = aux->prox;
            // o numero que vinha depois do aux aponta o novo como seu anterior
            aux->prox->ant = novo;
            // o novo aponta o aux como seu anterior
            novo->ant = aux;
            // o aux agora aponta para o novo como seu proximo
            aux->prox = novo;
        }

    } else {
        printf("\nErro ao alocar memoria para inserir item no meio da lista!\n");
    }
}

void remove_item(struct no **pli, int num) {
    struct no *aux, *remover = NULL;

    // se a lista não tiver vazia entra no if 
    if(*pli){
       // se o elemento que o usuario quer remover está no primeiro nó da lista   
        if((*pli)->valor == num) {
            // ponteiro remover aponta para o primeiro no
            remover = *pli;
            // atualiza inicio da lista para o antigo segundo item
            *pli = remover->prox;

            // verifica se lista ficou vazia, se não ficou entra no if
            if(*pli){
                // atualiza para que o anterior apontado pelo segundo item seja NULL ja que ele se tornou o primeiro item 
                (*pli)->ant = NULL;
            }

            free(remover);

        // se o elemento que o usuario deseja remover não estiver no primeiro nó da lista  
        } else {
            aux = *pli;
            // enquanto ainda tiver itens na lista e o valor consecutivo for diferente do que se deseja remover...
            while(aux->prox && aux->prox->valor != num) {
                aux = aux->prox;
            }

            // quando terminar o while, se existir um próximo(encontramos o nó que se deseja remover), entra no if
            if(aux->prox) {
                // o numero que queremos remover é o aux->prox
                remover = aux->prox;
                // remover->prox é = a "aux->prox->prox"
                aux->prox = remover->prox;

                // o próximo pode ser nulo(se remover for o último nó da lista), se não for, entra no if 
                if(aux->prox) {
                    aux->prox->ant = aux;
                }
            }

            free(remover);
        }
    }
}

#endif