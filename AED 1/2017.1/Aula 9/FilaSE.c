/**
* @author Patrick Araújo
*Pilha Estática em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int inicio, fim;
int pilha[MAX];

void push(int x){
    if ( !pilhaCheia() ){
        printf("Inserindo: %i\n", x);
        pilha[fim++] = x;
    }
    else
        printf("Pilha está cheia!\n");
}

int pop(){
    if( !pilhaVazia() ){
        int i;
        for(i = 0; i < fim; i++)
            pilha[i] = pilha[i+1];
        fim--;
        printf("Removido com sucesso\n");
        return 1;
    }
    printf("Pilha vazia\n");
    return -1;
}

int pilhaVazia(){
    return (inicio == fim);
}

int pilhaCheia(){
    return (fim == MAX);
}

void imprimePilha(){
    int i;
    printf("\nElementos do vetor:\n");
    for(i = 0; i < MAX; i++){
        printf("%d\n", pilha[i]);
    }
    printf("\n");
}

int main(){
    inicio = 0;
    fim = 0;
    push(12);
    push(34);
    push(35);
    push(36);
    push(37);
    push(38);
    imprimePilha();

    pop();
    imprimePilha();
    pop();
    pop();
    imprimePilha();
    return 0;
}
