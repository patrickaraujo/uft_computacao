/**
*   @author Patrick Araújo
*   Pilha Sequencial Estática em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

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
        int retorno = pilha[(fim - 1)];
        pilha[(fim - 1)] = NULL;
        fim--;
        return retorno;
    }
    return 0;
}

void desempilha(){
    int removido = pop();
    if(removido)
        printf("%i removido com sucesso\n", removido);
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
