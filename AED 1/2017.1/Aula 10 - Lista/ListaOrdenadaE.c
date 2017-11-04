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
int insere_lista_ordenada(Lista **main, int num);
int remove_lista(Lista **li, int num);
int lista_vazia(Lista *main);
Lista* find(Lista *main, int valor);
void libera_lista(Lista **main);
int tamanho_lista(Lista *main);

int main(){
    Lista* main = NULL;
    int choice, x;

    while(choice != 5){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para inserir numero\n");
        printf("2 - Para remover numero\n");
        printf("3 - Mostrar elementos armazenados\n");
        printf("4 - Achar indice de um numero\n");
        printf("5 - Para Sair\n");
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
                printf("\n\nQuantidade: %i\n", tamanho_lista(main));
                system("pause");
            break;
            case 4:
                printf("Digite o numero a ser achado\n");
                scanf("%d", &x);
                printf("Indice: %x", find(main, x));
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
        if(*main){
            Lista *ant, *atual = *main;
            while(atual && atual->info < num){
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
        else{
            aux->prox = NULL;
            *main = aux;
            return 1;
        }
    }
    return 0;
}

int remove_lista(Lista **main, int num){
    if(*main){
        Lista *ant, *aux = *main;
        while(aux && aux->info != num){
            ant = aux;
            aux = aux->prox;
        }
        if(!aux)//não encontrado
            return 0;
        if(aux == *main)//remover o primeiro?
            *main = aux->prox;
        else
            ant->prox = aux->prox;
        free(aux);
        return 1;
    }
    return 0;
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

int lista_vazia(Lista *main){
    if(main)
        return 1;
    return NULL;
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
