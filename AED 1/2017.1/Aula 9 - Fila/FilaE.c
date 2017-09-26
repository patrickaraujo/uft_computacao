/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Listas Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct reg {
    int info;
    struct reg *prox;
}fila;

void enqueue (fila **aux, fila **primeiro, int x);
void dequeue(fila **primeiro);

void imprimir(fila *auxa){
    fila *aux = auxa;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("\nElemento: %d\n", aux->info);
			aux = aux->prox; //o ponteiro volta imprimindo
		}
}

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
                printf("\nOpção inválida");
        }
        //  limpa a tela
        //system("cls");
    }

    system("pause");
    return 0;
}

void enqueue (fila **main, fila **primeiro, int x) {
    fila *aux;    //  auxiliar
	if((aux = malloc(sizeof(fila))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		aux->info = x;  //  recebendo valor
		aux->prox = NULL;   //  esquerda é nulo pois a inseção é no inicio
		if(*main != NULL)   //  se a lista não for nula então a esquerda recebe o valor
			(*main)->prox = aux;
		else
            (*primeiro) = aux;
		*main = aux;    //  lista recebe valor da direita
	}
}

void dequeue(fila **primeiro) {
	if(*primeiro != NULL){
        fila *temp = (*primeiro)->prox;
        free(primeiro);
        *primeiro = temp;
    }
}
