/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

int insere_lista_inicio (Lista **main, int x);
int remove_lista_final(Lista **main);
void imprimir(Lista *main);
int lista_vazia(Lista *main);
Lista* find(Lista *main, int valor);
void libera_lista(Lista **main);
int tamanho_lista(Lista *main);

int main(){
    Lista *main = NULL;
    int choice, x;

    while(choice != 4){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para inserir elemento no topo\n");
        printf("2 - Para remover final\n");
        printf("3 - Mostrar todos elementos\n");
        printf("4 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                insere_lista_inicio(&main, x);
            break;
            case 2:
                remove_lista_final(&main);
            break;
            case 3:
                imprimir(main);
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

int insere_lista_inicio(Lista **main, int x){
    Lista *aux = malloc(sizeof(Lista));
    if(aux){
        aux->info = x;
        aux->prox = (*main);
        *main = aux;
        return 1;
    }
    return NULL;
}

int remove_lista_final(Lista **main){
    if(*main){
        Lista *ant, *aux = (*main);
        while(aux->prox){
            ant = aux;
            aux = aux->prox;
        }
        int retorno = aux->info;
        if(aux == (*main))  //  remover o primeiro?
            *main = aux->prox;
        else
            ant->prox = aux->prox;
        free(aux);
        return retorno;
    }
    return NULL;
}

int lista_vazia(Lista *main){
    if(main)
        return NULL;
    return 1;
}

void libera_lista(Lista **main){
    Lista *aux;
    while(*main){
        aux = *main;
        *main = (*main)->prox;
        free(aux);
    }
    free(*main);
}

Lista* find(Lista *main, int valor){
	Lista *retorno = main;
	if(main)
        while(retorno){
            if((retorno->info) == valor)
                return retorno;
            retorno = retorno->prox;
        }
    return NULL;
}

int tamanho_lista(Lista *main){
    if(main){
        int cont = 0;
        Lista *aux = main;
        while(aux){
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
    return NULL;
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
