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

TBT *maiorD(TBT **main){    //  maiorDireita
    if((*main)->dir)
        return maiorD(&((*main)->dir));
    else{
        TBT *pAux = *main;
        if((*main)->esq)
            (*main) = (*main)->esq;
        else
            (*main) = NULL;
        return (pAux);
    }
}

TBT *menorE(TBT **main){    //  menorEsquerda
    if((*main)->esq)
       return menorE(&(*main)->esq);
    else{
       TBT *aux = *main;
       if((*main)->dir) //  se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *main = (*main)->dir;
       else
          *main = NULL;
       return aux;
    }
}

TBT *remove_atual(TBT *main) {
    TBT *no1, *no2;
    if(!(main->esq)){
        no2 = main->dir;
        free(main);
        return no2;
    }
    no1 = main;
    no2 = main->esq;
    while(no2->dir){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != main){
        no1->dir = no2->esq;
        no2->esq = main->esq;
    }
    no2->dir = main->dir;
    free(main);
    return no2;
}

int remover(TBT **main, int valor){
    if(*main){
        TBT *ant = NULL;
        TBT *atual = *main;
        while(atual){
            if(valor == atual->info){
                if(atual == *main)
                    *main = remove_atual(atual);
                else{
                    if(ant->dir == atual)
                        ant->dir = remove_atual(atual);
                    else
                        ant->esq = remove_atual(atual);
                }
                return 1;
            }
            ant = atual;
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
    }
    return 0;
}

void removerR(TBT **main, int x){
    if(*main)
        if(x < (*main)->info)
            removerR(&((*main)->esq), x);
        else if(x > (*main)->info)
            removerR(&((*main)->dir), x);
        else{
            TBT *pAux = (*main);
            if( (!(pAux->esq)) && (!(pAux->dir)) )  //  se nao houver filhos...
                pAux = NULL;    //  free(pAux);
            else
                if(!(pAux->esq)){
                    (*main) = pAux->dir;    //  so tem filho da esquerda
                    pAux = NULL;    //  free(pAux);
                }
                else if(!(pAux->dir)){  //  so tem o filho da direita
                    (*main) = pAux->esq;
                    pAux = NULL;    //  free(pAux);
                }
                else{   //  Escolhi fazer o maior filho direito da subarvore esquerda.
                    pAux = maiorD(&((*main)->esq)); //  pAux = menorE(&(*main)->dir);
                    pAux->esq = (*main)->esq;
                    pAux->dir = (*main)->dir;
                    (*main)->dir = (*main)->esq = NULL;
                    (*main) = NULL; //  free(*main);
                    (*main) = pAux;
                    pAux = NULL;
                }
        }
}

#endif // TBT_H_INCLUDED
