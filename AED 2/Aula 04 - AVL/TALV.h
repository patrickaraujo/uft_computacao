#ifndef TAVL_H_INCLUDED
#define TAVL_H_INCLUDED

typedef struct AVL{
    int info;
    int fb;
    struct AVL *esq;
    struct AVL *dir;
}TAVL;

int fatorBalanceamento_NO(TAVL *main){
    return labs(altura_NO(main->esq) - altura_NO(main->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
	return y;
}

int empty(TAVL *main){
    //  Retorna 1 se a árvore for vazia e 0 caso contrário
    return main == NULL;
}

void print(TAVL *main){
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

int altura_NO(TAVL *main){
    if(main){
		return main->fb;
	}
	return -1;
}

void RotacaoLL(TAVL **A){	//	LL
    printf("RotacaoLL\n");
    TAVL *B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = (*A);
    (*A)->fb = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->fb = maior(altura_NO(B->esq), (*A)->fb) + 1;
    (*A) = B;
}

void RotacaoRR(TAVL **A){	//	RR
    printf("RotacaoRR\n");
    TAVL *B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->fb = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->fb = maior(altura_NO(B->dir), (*A)->fb) + 1;
    (*A) = B;
}

void RotacaoLR(TAVL **A){//LR
    RotacaoRR(&((*A)->esq));
    RotacaoLL(A);
}

void RotacaoRL(TAVL **A){//RL
    RotacaoLL(&((*A)->dir));
    RotacaoRR(A);
}

int insere_ArvAVL(TAVL **main, int valor){
    int res;
    if(!(*main)){   //  árvore vazia ou nó folha
            printf("bingo");
        TAVL *novo = (TAVL *) malloc(sizeof(TAVL));
        novo->info = valor;
        novo->fb = 0;
        novo->esq = novo->dir = NULL;
        (*main) = novo;
        return 1;
    }

    TAVL *atual = (*main);
    if(valor < atual->info){
        if((res = insere_ArvAVL((&(atual->esq)), valor)) == 1)
            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor < (*main)->esq->info )
                    RotacaoLL(main);
                else
                    RotacaoLR(main);
            }
    }
    else{
        //  if(valor > atual->info)
            if((res = insere_ArvAVL((&(atual->dir)), valor)) == 1)
                if(fatorBalanceamento_NO(atual) >= 2)
                    if((*main)->dir->info < valor)
                        RotacaoRR(main);
                    else
                        RotacaoRL(main);
        /*else
            printf("Valor duplicado!!\n");
            return NULL;
            */
    }

    atual->fb = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

#endif // TAVL_H_INCLUDED
