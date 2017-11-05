/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Ordenada Circular Encadeada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

int insere_lista_ordenada(Lista **main, int x);
int remove_lista(Lista **main, int x);
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
                insere_lista_ordenada(&main, x);
            break;
            case 2:
                printf("Digite o numero a remover\n");
                scanf("%d", &x);
                remove_lista(&main, x);
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

int insere_lista_ordenada(Lista **main, int x) {
	Lista *aux = malloc(sizeof(Lista));  //  auxiliar
	if(aux){
        aux->info = x;
		if(*main){
            Lista *temp = (*main);
            if((*main)->info > x){  //  insere início
                while(temp->prox != (*main)){
                    temp = temp->prox;
                }
                temp->prox = aux;
                aux->prox = (*main);
                (*main) = aux;
            }
            Lista *ant = *main;
            temp = (*main)->prox;
            while(temp != (*main) && temp->info < x){
                ant = temp;
                temp = temp->prox;
            }
            ant->prox = aux;
            aux->prox = temp;
            return 1;
		}
		else{
            (*main) = aux;
            aux->prox = aux;
            return 1;
		}
	}
	else
        return NULL;
}

int remove_lista(Lista **main, int x){	//	remove_lista_inicio
	if(*main){
        int retorno;
        Lista *aux = (*main);
        if(aux->info == x){
            retorno = aux->info;
            if(aux == aux->prox){
                free(aux);
                (*main) = NULL;
                return retorno;
            }
            else{
                Lista *ult = (*main);
                while(ult->prox != (*main)){
                    ult = ult->prox;
                }
                ult->prox = (*main)->prox;
                (*main) = (*main)->prox;
                free(aux);
                return retorno;
            }
        }
        Lista *temp = aux;
        aux = aux->prox;
        while(aux != (*main) && aux->info != x){
            temp = aux;
            aux = aux->prox;
        }
        if(aux == *main)    //  não encontrado
            return NULL;
        temp->prox = aux->prox;
        retorno = aux->info;
        free(aux);
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
