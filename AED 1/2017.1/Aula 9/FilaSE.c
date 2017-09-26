/**
*   @author Patrick Araújo
*   Fila Sequencial Estática em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int inicio, fim;
int fila[MAX];

void push(int x){
    if ( !filaCheia() ){
        printf("Inserindo: %i\n", x);
        fila[fim++] = x;
    }
    else
        printf("Fila está cheia!\n");
}

int pop(){
    if( !filaVazia() ){
        int i;
        for(i = 0; i < fim; i++)
            fila[i] = fila[i+1];
        fim--;
        printf("Removido com sucesso\n");
        return 1;
    }
    printf("Fila vazia\n");
    return 0;
}

int filaVazia(){
    return (inicio == fim);
}

int filaCheia(){
    return (fim == MAX);
}

void imprimeFila(){
    int i;
    printf("\nElementos do vetor:\n");
    for(i = 0; i < MAX; i++){
        printf("%d\n", fila[i]);
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
    imprimeFila();

    pop();
    imprimeFila();
    pop();
    pop();
    imprimeFila();
    return 0;
}
