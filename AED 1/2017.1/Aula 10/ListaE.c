#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

int main()
{
    printf("Hello world!\n");
    return 0;
}

Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista *li){
    if(li != NULL){
        Lista *aux;
        while(*li != NULL){
            no = *li
            *li = (*li)->prox;
            free(aux);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Lista *aux = aux;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;    
}

int lista_vazia(Lista *li){
    if(li == NULL)
        return 1;
    return 0;
}

int insere_lista_inicio(Lista *li, int num){
    if(li == null)
        return 0;
    Lista *aux = (Lista*) malloc(sizeof(Lista));
    if(aux == NULL)
        return 0;
    aux->info = num;
    aux->prox = aux;
    li = aux;
    return 1;
}

int insere_lista_final(Lista *li, int num){
    if(li == NULL)
        return 0;
    Lista *aux = malloc(sizeof(Lista));
    if(aux == NULL)
        return 0;
    aux->info = num;
    aux->prox = NULL;
    if((*li) == NULL)
        li = aux;
    else{
        Lista *temp = li;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = aux;
    }
    return 1;
}

int insere_lista_ordenada(Lista *li, int num){
    if(li == NULL)
        return 0;
    Lista *aux = malloc(sizeof(Lista));
    if(aux == NULL)
        return 0;
    aux->info = num;
    if(lista_vazia(li)){
        aux->prox = li;
        li = aux;
        return 1;
    }
    else{
        Lista *ant, *atual = li;
        while(atual != NULL && atual->info < num){
            ant = atual;
            atual = atual->prox/
        }
        if(atual = li){
            aux->prox = li;
            li = aux;
        }
        else{
            aux->prox = ant->prox;
            ant->prox = aux;
        }
        return 1;
    }
}
