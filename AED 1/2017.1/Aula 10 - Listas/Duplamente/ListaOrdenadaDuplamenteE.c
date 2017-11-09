/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Ordenada Duplamente Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *ant;
    struct reg *prox;
}Lista;

int insere_lista_ordenada(Lista **main, int x);
int remove_lista(Lista **main, int x);
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
        printf("1 - Para inserir elemento\n");
        printf("2 - Para remover elemento\n");
        printf("3 - Mostrar todos elementos\n");
        printf("4 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                insere_lista_ordenada(&main, x);
            break;
            case 2:
                printf("Digite o numero a remover\n");
                scanf("%d", &x);
                remove_lista(&main, x);
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

int insere_lista_ordenada(Lista **main, int x){
    Lista *aux = malloc(sizeof(Lista));
    if(aux){
        aux->info = x;
        if(*main){
            Lista *temp, *atual = (*main);
            while(atual && atual->info < x){
                temp = atual;
                atual = atual->prox;
            }
            if(atual == (*main)){
                aux->ant = NULL;
                (*main)->ant = aux;
                aux->prox = (*main);
                (*main) = aux;
            }
            else{
                aux->prox = temp->prox;
                aux->ant = temp;
                temp->prox = aux;
                if(atual)
                    atual->ant = aux;
            }
            return 1;
        }
        else{
            aux->ant = NULL;
            aux->prox = NULL;
            (*main) = aux;
            return 1;
        }
    }
    return NULL;
}

int remove_lista(Lista **main, int x){
    if(*main){
        Lista *aux = (*main);
        while(aux && aux->info != x){
            aux = aux->prox;
        }
        if(aux){
            if(!(aux->ant))
                (*main) = aux->prox;
            else
                aux->ant->prox = aux->prox;
            if(aux->prox)
                aux->prox->ant = aux->ant;
            int retorno = aux->info;
            free(aux);
            printf("\nremovido:\t%i\n", retorno);
            system("pause");
            return retorno;
        }

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
