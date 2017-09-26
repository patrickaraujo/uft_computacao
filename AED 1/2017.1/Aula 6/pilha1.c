/**
* @author Patrick Araújo
*Pilha Sequencial Estática em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int inicio, fim;
int pilha[MAX];

void empilha(int x){
    printf("Inserindo %i: ", x);
    if(push(x))
        printf("OK\n");
    else
        printf("Pilha Cheia\n");
}

int push(int x){
    if ( !pilhaCheia() ){
        pilha[fim++] = x;
        return 1;
    }
    return 0;
}

int pop(){
    if( !pilhaVazia() ){
        pilha[(fim - 1)] = 0;
        fim--;
        return 1;
    }
    return -1;
}

void desempilha(){
    if(pop() == 1)
        printf("Removido com sucesso\n");
    else
        printf("Pilha vazia\n");
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
    int choice, x;
    while(choice != 4){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para Empilhar(PUSH)\n");
        printf("2 - Para Desempilhar(POP)\n");
        printf("3 - Mostrar elementos da pilha\n");
        printf("4 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                empilha(x);
                system("pause");
                break;
            case 2:
                desempilha();
                system("pause");
                break;
            case 3:
                imprimePilha();
                system("pause");
            break;
            default:
                printf("\nOpção inválida");
        }
        system("cls");
    }
    system("pause");
    return 0;
}
