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
    if ( filaCheia() ){
        fim = inicio; //  fila circular
    }
    printf("Inserindo: %i\n", x);
    fila[fim++] = x;
}

int pop(){
    int temp = fila[0];
    if( !filaVazia() ){
        int i;
        for(i = 0; i < fim; i++)
            fila[i] = fila[i+1];
        fim--;
        printf("Removido com sucesso\n");
        return temp;
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
    int num, op;
    do{
        printf("Insercao de numeros\n1 - Para inserir\n2 - Para retirar\nO - Desistir\n\nOpcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Numero: ");
                scanf("%d", &num);
                push(num);
            break;
            case 2:
                pop();
            break;
            imprimeFila();
            default:
                printf("Opcao invalida");
        }
        imprimeFila();
    }while(op);
    return 0;
}
