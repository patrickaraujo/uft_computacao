/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Encadeada Ordenada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    int oc;
    struct reg *prox;
}Quartos;

typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

void imprimir(Lista *main);
Lista* cria_lista();
int insere_lista_ordenada(Lista **main, int num);
int remove_lista(Lista **li, int num);
Lista* find(Lista *main, int valor);
int tamanho_lista(Lista *main);

Quartos* quartos(int andares, int qntQ){
    int i, j;
    for(i = 0; i < andares; i++){
        for(j = 0; j < qntQ; j++){
            quartos
        }
    }
}

int main(){
    int quartos[60] = {101, 102, 103, 104, 105, 106, 10}
    
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
