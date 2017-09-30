/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Pilha Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *anterior;
}ponto;

int push (ponto **main, int num);
int pop(ponto **main);
void imprimir(ponto *Point);
int pointerLength(ponto *Point);

int main(){
    ponto *P = NULL;
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
                push(&P, x);
            break;
            case 2:
                pop(&P);
            break;
            case 3:
                imprimir(P);
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

int push (ponto **main, int num){
    ponto *aux = malloc(sizeof(ponto));
    if(aux != NULL){
        aux->anterior = *main;
        aux->info = num;
        *main = aux;
        return 1;
    }
    return NULL;
}

int pop(ponto **main){
	if((*main) != NULL){
        int auxiliar = (*main)->info;
        ponto *aux = (*main)->anterior;
        free(*main);
        (*main) = aux;
        return auxiliar;
    }
    return NULL;
}

void imprimir(ponto *Point){
    int j = 0, k;
    ponto *aux;
    if(Point != NULL){
        int auxiliar[pointerLength(Point)];
        for(aux = Point; aux != NULL; aux = aux->anterior)
            auxiliar[j++] = aux->info;
        j--;
        for(k = j; k >= 0; k--)
            printf("\nElemento: %d\n", auxiliar[k]);
    }
    else
        printf("Pilha vazia\n");
}

int pointerLength(ponto *Point){
    int i = 0, j = 0, k;
    ponto *aux;
    if(Point != NULL)
        for(aux = Point; aux != NULL; aux = aux->anterior)
            i++;
    return i;
}
