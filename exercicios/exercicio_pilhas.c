/*

Descrição:
Fazer um programa que confira uma sequencia fornecida de parenteses, chaves e colchetes, 
determinando se ela está correta ou não. Teste com exemplos, tais como: {[()]} {{]] {) 
{{[()()]}} Insira um arquivo zipado com o código e uma imagem de uma simulação.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILHA 10
#define TAM_TESTE 10

struct pilha {
    char vetor[TAM_PILHA];
    int topo;
}; 

void cria_pilha(struct pilha *);
void insere_topo(struct pilha *, char);
int remove_topo(struct pilha *, char);

void main() {
    struct pilha p;
    char teste[TAM_TESTE];
    int retorno = -1;

    //chama funcao para iniciar topo da pilha (vazia)
    cria_pilha(&p); 

    //leitura da string que se deseja testar
    printf("Digite a sequencia de simbolos que voce deseja verificar:\n");
    fgets(teste, TAM_TESTE, stdin);

    //constroi ou remove da pilha com simbolos de abertura
    for(int i = 0; i<strlen(teste) - 1; i++) {  
        //se o valor for de abertura insere no topo
        if(teste[i] == '(' || teste[i] == '[' || teste[i] == '{'){
            insere_topo(&p, teste[i]);

        //se o valor nao for de abertura pede para remover do topo
        } else if(teste[i] == ')' || teste[i] == ']' || teste[i] == '}'){
            retorno = remove_topo(&p, teste[i]);
            if(!retorno) {
                break;
            }
        }
    }

    if(!retorno) {
        printf("A sequencia digitada nao esta formatada de forma correta\n");
    } else {
        printf("A sequencia digitada esta formatada de forma correta\n");
    }

}

void cria_pilha(struct pilha *pp) {
    pp->topo = -1;
}

void insere_topo(struct pilha *pp, char valor) {
    if(pp->topo == TAM_PILHA - 1) {
        printf("\nA insercao de elementos nao pode ser feita pois a pilha esta cheia!\n");
        return;
    }

    pp->vetor[pp->topo+1] = valor;
    pp->topo = pp->topo+1;
}

// pop pilha
int remove_topo(struct pilha *pp, char valor) {
    if(pp->topo == -1) {
        printf("\nA remocao do topo nao pode ser executada pois a pilha esta vazia!\n");
        return 0;
    }

    //verifica se pode remover do topo dependendo do simbolo que foi digitado
    if(valor == ')') {
        if(pp->vetor[pp->topo] != '(') {
            return 0;
        }

    } else if (valor == ']') {
        if(pp->vetor[pp->topo] != '[') {
            return 0;
        }

    } else if (valor == '}') {
        if(pp->vetor[pp->topo] != '{') {
            return 0;
        }

    } else {
        printf("Foi inserido um valor desconhecido, %c\n", valor);
        return 0;
    }

    //caso possa remover chega nessa parte e retorna 1 para indicar que deu certo
    pp->topo = pp->topo - 1;
    return 1;
}