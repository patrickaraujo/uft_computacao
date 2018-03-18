#ifndef TRB_H_INCLUDED
#define TRB_H_INCLUDED

typedef struct RB{
    int info, cor;
    struct RB *esq, *dir, *p;

    /* Construtor
    RB(int info){
       this->info = info;
       esq = dir = p = NULL;
    }
    */
}TRB;

void insere(TRB **raiz, int num){
    TRB *temp = (TRB *) malloc(sizeof(TRB));
    temp->cor = 4;  //  RED
    temp->info = num;
    temp->dir = temp->esq = NULL;

    TRB *y = NULL, *x = (*raiz);

    while(x){
        y = x;
        if(temp->info < x->info)
            x = x->esq;
        else
            x = x->dir;
    }
    temp->p = y;
    if(!y)
        (*raiz) = temp;
    else if(temp->info < y->info)
        y->esq = temp;
    else
        y->dir = temp;
    rotacoes(*raiz, temp);
}

void rotacoes(TRB *raiz, TRB *z){

    while( (z != raiz) && (!(z->cor)) && ((z->p->cor) == 4) ){
        printf("bingo, %i", z->info);
        TRB *y = (TRB *) malloc(sizeof(TRB));
        if(z->p == z->p->p->esq){
            y = z->p->p->dir;
            if(y->cor == 4){
                y->cor = z->p->cor = 0;
                z->p->p->cor = 4;
                z = z->p->p;
            }
            else if(z == z->p->dir){
                z = z->p;
                rotacaoEsquerda(raiz, z);
                z->p->cor = 0;
                z->p->p->cor = 4;
                rotacaoDireita(raiz, z->p->p);
            }
        }
        else{
            y = z->p->p->esq;
            if(y->cor == 4){
                y->cor = z->p->cor = 0;
                z->p->p->cor = 4;
                z = z->p->p;
            }
            else if(z == z->p->esq){
                z = z->p;
                rotacaoDireita(raiz, z);
                z->p->cor = 0;
                z->p->p->cor = 4;
                rotacaoEsquerda(raiz, z->p->p);
            }
        }
    }
    raiz->cor = 0;
}

void rotacaoEsquerda(TRB *raiz, TRB *x) {
    TRB *y = x->dir;	//	declara y
    x->dir = y->esq;	//	altera a sub-árvore esquerda y pela sub-árvore direita y

    if (x->dir)
        y->dir->p = x;

    y->p = x->p;    //
    if (x->p == NULL)
        raiz = y;
    else if (x == x->p->esq)
		x->p->esq = y;
	else
		x->p->dir = y;
    y->esq = x;	//	coloca x na esquerda de y
	x->p = y;
}

void rotacaoDireita(TRB *raiz, TRB *x) {
    TRB *y = x->esq;
    x->esq = y->dir;

    if (x->dir)
        x->dir->p = x;

    y->p = x->p;	//
    if (x->p == NULL)
        raiz = y;
    else if (x == x->p->esq)
		x->p->esq = y;
	else
		x->p->dir = y;
    y->dir = x;	//	coloca x na esquerda de y
	x->p = y;
}

#endif // TRB_H_INCLUDED
