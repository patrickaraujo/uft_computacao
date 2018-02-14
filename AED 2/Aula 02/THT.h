#ifndef TBT_H_INCLUDED
#define TBT_H_INCLUDED

struct binaryTree{
	int info;
	struct binaryTree *esq;
	struct binaryTree *dir;
};
typedef struct binaryTree TBT;

void insereR (TBT **T, int x){
    if(*T == NULL){
        TBT *novo;
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

#endif // TBT_H_INCLUDED
