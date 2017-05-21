/**
* @author Patrick Araújo
*
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int info;
    struct reg *prox;
}no;

int busca(no* aux, int dado);
//  int busca(int dado);
void criar(no **aux);
void push (no **aux, int num);
void imprimir(no *lista);

int main(){
    no *L;
    criar(&L);
    //  Código para criação da lista 15 busca(L, x);
    int arr[10] = {1, 2, 3, 4, 5, 6, 10, 400, 500, 550};

    int i;
    for(i = 0; i < 10; i++)
        push(&L, arr[i]);
    imprimir(L);
    printf("%i", busca(L, 400));
    return 0;
}

void criar(no **aux){
    *aux = NULL;
}


int busca(no* aux, int dado){
//  int busca(int dado){
    puts("Busca");
    if(aux){
        if(aux->info == dado)
            return 1;
        else
            return busca(aux->prox, dado);
    }
    else
        return 0;
}

void push (no **aux, int num) {
    no *pont = malloc(sizeof(no));
    if(pont == NULL)
        printf("Memoria insulficiente\n");
    else{
        pont->info = num;
        if(aux == NULL)
            pont->prox = 0;
        pont->prox = *aux;
    }
    *aux = pont;
}

void imprimir(no *lista){
    no *aux;
    if(lista != NULL)
        for(aux = lista; aux != NULL; aux=aux->prox){
            printf("\n%d\n", aux->info);
            printf("\nimprimir aux: %i\n", aux);
            printf("\nimprimir aux - prox: %i\n", aux->prox);
            }
    else
        printf("Pilha vazia\n");
}
