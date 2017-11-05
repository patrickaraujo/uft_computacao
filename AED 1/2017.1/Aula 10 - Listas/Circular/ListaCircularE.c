/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Circular Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

int insere_lista_inicio(Lista **main, int x);
int remove_lista_final(Lista **main);
void imprimir(Lista *main);
int lista_vazia(Lista *main);
int tamanho_lista(Lista *main);
Lista* find(Lista *main, int valor);
void libera_lista(Lista **main);

int main(){
    Lista *main = NULL;
    int choice, x;

    while(choice != 5){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para inserir elemento no topo\n");
        printf("2 - Para remover elemento final\n");
        printf("3 - Mostrar todos elementos\n");
        printf("4 - Achar indice de um numero\n");
        printf("5 - Para Sair\n");
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
                printf("\nTamanho:\t%i\n", tamanho_lista(main));
                system("pause");
            break;
            case 4:
                printf("Digite o numero a ser achado\n");
                scanf("%d", &x);
                printf("\nIndice: %x\n", find(main, x));
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

int insere_lista_inicio(Lista **main, int x) {
    Lista *aux = malloc(sizeof(Lista));  //  auxiliar
	if(aux){
        aux->info = x;
		if(*main){
            Lista *temp = (*main);
			while(temp->prox != (*main)){
                temp = temp->prox;
			}
			temp->prox = aux;
			aux->prox = (*main);
			(*main) = aux;
		}
		else{
            (*main) = aux;
            aux->prox = aux;
        }
		return 1;
	}
    return NULL;
}

int remove_lista_final(Lista **main){	//	remove_lista_inicio
	if(*main){
        int retorno = (*main)->info;
        if((*main)->prox == (*main))
            (*main) = NULL;
        else{
            Lista *ant, *aux = (*main);
            while(aux->prox != (*main)){
                ant = aux;
                aux = aux->prox;
            }
            retorno = aux->info;
            ant->prox = aux->prox;
            free(aux);
        }
        return retorno;
    }
    return NULL;
}

int tamanho_lista(Lista *main){
    if(main){
        int cont = 0;
        Lista *aux = main;
        do{
            cont++;
            aux = aux->prox;
        }while(aux != main);
        return cont;
    }
    return NULL;
}

Lista* find(Lista *main, int valor){
	Lista *retorno = main;
	if(main)
        do{
            if((retorno->info) == valor)
                return retorno;
            retorno = retorno->prox;
        }while(retorno != main);
    return NULL;
}

int lista_vazia(Lista *main){
    if(main)
        return NULL;
    return 1;
}

void imprimir(Lista *main){
    Lista *aux = main;
	if(!main)
		printf("\nLista Vazia\n");
	else
		do{ //  while(aux != NULL && (aux->prox != main))
			printf("\nElemento: %d\n", aux->info);
			aux = aux->prox;
		}while(aux != main);
}

void libera_lista(Lista **main){
    if(*main){
        Lista *temp, *aux = *main;
        while((*main) != aux->prox){
            temp = aux;
            aux = aux->prox;
            free(temp);
        }
        free(aux);
        *main = NULL;
    }
}
