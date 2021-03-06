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
    else{
        printf("Pilha está cheia!\n");
    }
}

int pop(){
    if( !pilhaVazia() ){
        pilha[(fim - 1)] = NULL;
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
    imprimePilha();

    pop();
    pop();
    pop();
    imprimePilha();
    return 0;
}
