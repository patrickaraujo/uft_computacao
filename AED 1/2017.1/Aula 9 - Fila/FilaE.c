/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Fila Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct reg {
    int info;
    struct reg *prox;
}fila;

int enqueue (fila **aux, fila **primeiro, int x);
int dequeue(fila **primeiro);
void imprimir(fila *main);

int main(){
    fila *P = NULL;
    fila *prim;
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
                enqueue(&P, &prim, x);
            break;
            case 2:
                dequeue(&prim);
            break;
            case 3:
                imprimir(prim);
                system("pause");
            break;
            default:
                printf("\nOpcao invalida");
        }
        system("cls");
    }
    system("pause");
    return 0;
}

int enqueue (fila **ultimo, fila **primeiro, int x) {
    fila *aux;    //  auxiliar
	if((aux = malloc(sizeof(fila))) == NULL)	//	erro
		return NULL;
	else{
		aux->info = x;
		aux->prox = NULL;
		if(*ultimo != NULL)
			(*ultimo)->prox = aux;
		else
            (*primeiro) = aux;
		*ultimo = aux;
		return 1;
	}
}

int dequeue(fila **primeiro) {
	if(*primeiro != NULL){
        int aux = (*primeiro)->info;
        fila *temp = (*primeiro)->prox;
        free(primeiro);
        *primeiro = temp;
        return aux;
    }
    return NULL;
}

void imprimir(fila *main){
    fila *temp = main;
	if(main == NULL)
		printf("\nLista Vazia\n");
	else
		while(temp != NULL){
			printf("\nElemento: %d\n", temp->info);
			temp = temp->prox;
		}
}
