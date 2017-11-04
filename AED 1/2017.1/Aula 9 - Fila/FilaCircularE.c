/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Circular Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
}fila;

int enqueue (fila **main, int x);
int dequeue(fila **main);
void imprimir(fila *main);

int main(){
    fila *main = NULL;
    int choice, x;

    while(choice != 4){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para inserir elemento\n");
        printf("2 - Para remover topo\n");
        printf("3 - Mostrar todos elementos\n");
        printf("4 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                enqueue(&P, x);
            break;
            case 2:
                dequeue(&P);
            break;
            case 3:
                imprimir(P);
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

int enqueue (fila **main, int x) {
    fila *aux = malloc(sizeof(fila));  //  auxiliar
	if(aux){
        aux->info = x;
		if(*main){
            fila *temp = (*main);
			while(temp->prox != (*main)){
                temp = temp->prox;
			}
			temp->prox = aux;
			aux->prox = (*main);
		}
		else{
            (*main) = aux;
            aux->prox = aux;
        }
		return 1;
	}
    return NULL;
}

int dequeue(fila **main){
	if(*main){
        int retorno = (*main)->info;
        if((*main)->prox == (*main))
            (*main) = NULL;
        else{
            fila *aux = (*main);
            while(aux->prox != (*main)){
                aux = aux->prox;
            }
            fila *temp = (*main);
            aux->prox = temp->prox;
            (*main) = temp->prox;
            free(temp);
        }
        return retorno;
    }
    return NULL;
}

void imprimir(fila *main){
    fila *aux = main;
	if(!main)
		printf("\nLista Vazia\n");
	else
		do{ //  while(aux != NULL && (aux->prox != main))
			printf("\nElemento: %d\n", aux->info);
			aux = aux->prox;
		}while(aux != main);
}
