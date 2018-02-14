#include <stdio.h>
#include <stdlib.h>

struct binaryTree{
	int info;
	struct binaryTree *esq;
	struct binaryTree *dir;
};
typedef struct binaryTree TBT;

void insereR (TBT **T, int x){
    if(*T == NULL){
        *T = novo;
        novo = (TBT*) malloc(sizeof(TBT));
        novo->info = x;
        novo->esq = novo->dir = NULL;
        *T = novo;
    }
    else{
        if( x < (*T)->info )
            insereR(&((*T)->esq), x);
        else
            insereR(&((*T)->dir), x);
    }
}

int main(){c
    printf("Hello world!\n");
    return 0;
}
