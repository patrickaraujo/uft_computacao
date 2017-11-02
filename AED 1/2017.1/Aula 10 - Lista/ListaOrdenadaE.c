/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Encadeada Ordenada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

void imprimir(Lista *main);
Lista* cria_lista();
int insere_lista_ordenada(Lista **li, int num);

int main(){
    Lista* li = NULL;
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
                insere_lista_ordenada(&li, x);
            break;
            case 2:
                //  dequeue(&prim);
            break;
            case 3:
                imprimir(li);
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

int insere_lista_ordenada(Lista **main, int num){
    Lista *aux = malloc(sizeof(Lista));
    if(aux){
        aux->info = num;
        if((*main) == NULL){//lista vazia: insere início
            aux->prox = NULL;
            *main = aux;
            return 1;
        }
        else{
            Lista *ant, *atual = *main;
            while(atual != NULL && atual->info < num){
                ant = atual;
                atual = atual->prox;
            }
            if(atual == *main){//insere início
                aux->prox = (*main);
                *main = aux;
            }
            else{
                aux->prox = atual;
                ant->prox = aux;
            }
            return 1;
        }
    }
    return 0;
}

void imprimir(Lista *main){
    Lista *aux = main;
	if(!main)
		printf("\nLista Vazia\n");
	else
		while(aux){
			printf("\nElemento: %d\n", aux->info);
			aux = aux->prox;
		}
}
