/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Fila Sequencial Estática em C para a aula de Algoritmo e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int inicio, fim;
int fila[MAX];

void enqueue(int x){
    if ( !filaCheia() ){
        fila[fim++] = x;
        return 1;
    }
    return NULL;
}

int dequeue(){
    int aux = fila[0];
    if( aux ){
        int i;
        for(i = 0; fila[i+1]; i++)
            fila[i] = fila[i+1];
        fila[i] = NULL;
        fim = i;
    }
    return aux;
}

int filaCheia(){
    return (fim == MAX);
}

void imprimeFila(){
    int i;
    printf("\nElementos do vetor:\n");
    for(i = 0; i < MAX; i++)
        printf("%d\n", fila[i]);
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
                enqueue(num);
            break;
            case 2:
                dequeue();
            break;
            default:
                printf("Opcao invalida");
        }
        imprimeFila();
        printf("fim: %i\n", fim);
    }while(op);
    return 0;
}
