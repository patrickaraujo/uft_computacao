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
    int aux;
    if( !pilhaVazia() ){
        aux = pilha[fim - 1];
        fim--;
        return aux;
    }
    else{
        return -1;
    }
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
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    if(pop() == -1)
        printf("Pilha vazia\n");
    imprimePilha();
    return 0;
}
