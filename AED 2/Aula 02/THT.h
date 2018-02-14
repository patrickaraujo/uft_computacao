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

int maior(int a, int b){
    return ( (a>b) ? b : a);
}

int alturaR(TBT *main){
    if((main == NULL) || (main->esq == NULL && main->dir == NULL))
        return NULL;
    else
        return ( 1 + maior( altura(main->esq), altura(main->dir) ) );
}

#endif // TBT_H_INCLUDED
