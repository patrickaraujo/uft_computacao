#include <stdio.h>
#include <stdlib.h>

struct binaryTree{
	int info;
	struct binaryTree *esq;
	struct binaryTree *dir;
};
typedef struct binaryTree TBT;

void insere (TBT **T, int x){
    TBT *novo;
    novo = (TBT*) malloc(sizeof(TBT));
    novo->info = x;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*T == NULL)
        *T = novo;
    else{
        TBT *aux = *T;
        while( ((aux->esq != NULL) && (x < aux->info)) || (aux->dir != NULL && x >= aux->info) ){
            if( x < aux->info )
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        if( x < aux->info )
            aux->esq = novo;
        else
            aux->dir = novo;
    }
}

int main(){c
    printf("Hello world!\n");
    return 0;
}
