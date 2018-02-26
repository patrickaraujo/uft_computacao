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

int empty(TBT *main){
    //  Retorna 1 se a árvore for vazia e 0 caso contrário
    return main == NULL;
}

void print(TBT* main){
    //  Essa função imprime os elementos de forma recursiva

    printf("(");    //  notação para organizar na hora de mostrar os elementos
    if(!empty(main)) {  //  se a árvore não for vazia...
        //  Mostra os elementos em pré-ordem
        printf("%d ", main->info);  //  mostra a raiz
        print(main->esq);   //  mostra a sae (subárvore à esquerda)
        print(main->dir);   //  mostra a sad (subárvore à direita)
    }
    printf(")");    //  notação para organizar na hora de mostrar os elementos
}

int busca(TBT* main, int num) {
    if(empty(main))   //  Se a árvore estiver vazia, então retorna 0
        return 0;
    //  O operador lógico || interrompe a busca quando o elemento for encontrado
    return main->info == num || busca(main->esq, num) || busca(main->dir, num);
}

int bigger(int a, int b){
    return ( (a>b) ? a : b);
}

int alturaR(TBT *main){
    if((main == NULL) || (!(main->esq) && (!(main->dir))))
        return NULL;
    else
        return ( 1 + bigger( alturaR(main->esq), alturaR(main->dir) ) );
}

int altura(TBT *main){  //  função altura iterativa
    int altura1 = 0, altura2 = 0;
    TBT *aux = main;
    while((aux->esq) || (aux->dir)){
        altura1++;
        if(!(aux->esq))
            aux = aux->dir;
        else
            aux = aux->esq;
    }
    aux = main;
    while((aux->esq) || (aux->dir)){
        altura2++;
        if(!(aux->dir))
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    return (bigger(altura1, altura2));
}

int contarFolhas(TBT *main){
   if(!main)
        return 0;
   if((!(main->esq)) && (!(main->dir)))
        return 1;
   return contarFolhas(main->esq) + contarFolhas(main->dir);
}

void exibirEmOrdem(TBT *main){
    if(main){
        exibirEmOrdem(main->esq);
        printf("\n%i", main->info);
        exibirEmOrdem(main->dir);
    }
}

void exibirPreOrdem(TBT *main){
    if(main){
        printf("\n%i", main->info);
        exibirPreOrdem(main->esq);
        exibirPreOrdem(main->dir);
    }
}

void exibirPosOrdem(TBT *main){
    if(main){
        exibirPosOrdem(main->esq);
        exibirPosOrdem(main->dir);
        printf("\n%i", main->info);
    }
}

int cheia(TBT *main){
    // If empty tree
    if (!(main))
        return 1;

    // If leaf node
    if ((!(main->esq)) && (!(main->dir)))
        return 1;

    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ((main->esq) && (main->dir))
        return (cheia(main->esq) && cheia(main->dir));

    // We reach here when none of the above if conditions work
    return NULL;
}

TBT* espelho(TBT *main) {
    if(main){
        TBT *retorno = (TBT*) malloc(sizeof(TBT));

        retorno->info = main->info;
        retorno->esq = espelho(main->dir);
        retorno->dir = espelho (main->esq);
        return retorno;
    }
    return NULL;
}

TBT *maior(TBT **main){
    if((*main)->dir)
        return maior(&((*main)->dir));
    else{
        TBT *pAux = *main;
        if((*main)->esq)
            (*main) = (*main)->esq;
        else
            (*main) = NULL;
        return (pAux);
    }
}

void remover(TBT **main, int x){
    if(*main)
        if(x < (*main)->info)
            remover(&((*main)->esq), x);
        else if(x > (*main)->info)
            remover(&((*main)->dir), x);
        else{
            TBT *pAux = (*main);
            if( (!(pAux->esq)) && (!(pAux->dir)) )
                pAux = NULL;    //  free(pAux);
            else
                if(!(pAux->esq)){
                    (*main) = pAux->dir;
                    pAux = NULL;    //  free(pAux);
                }
                else if(!(pAux->dir)){
                    (*main) = pAux->esq;
                    pAux = NULL;    //  free(pAux);
                }
                else{
                    pAux = maior(&((*main)->esq));
                    pAux->esq = (*main)->esq;
                    pAux->dir = (*main)->dir;
                    (*main)->dir = (*main)->esq = NULL;
                    (*main) = NULL; //  free(*main);
                    (*main) = pAux;
                }
        }
}

#endif // TBT_H_INCLUDED
