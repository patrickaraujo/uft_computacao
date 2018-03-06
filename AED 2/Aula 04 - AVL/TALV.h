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
    TAVL *B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = (*A);
    (*A)->fb = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->fb = maior(altura_NO(B->esq), (*A)->fb) + 1;
    (*A) = B;
}

void RotacaoRR(TAVL **A){	//	RR
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
        /*
            else
                printf("Valor duplicado!!\n");
            return NULL;
        */
    }

    atual->fb = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

TAVL* procuraMenor(TAVL* atual){
    TAVL *no1 = atual, *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(TAVL **main, int valor){
	if(*main == NULL){// valor não existe
	    printf("valor não existe!!\n");
	    return 0;
	}

    int res;
	if(valor < (*main)->info)
	    if((res = remove_ArvAVL(&(*main)->esq,valor)) == 1)
            if(fatorBalanceamento_NO(*main) >= 2){
                if(altura_NO((*main)->dir->esq) <= altura_NO((*main)->dir->dir))
                    RotacaoRR(main);
                else
                    RotacaoRL(main);
            }
    //  if((*main)->info < valor)
	else
	    if((res = remove_ArvAVL(&(*main)->dir, valor)) == 1)
            if(fatorBalanceamento_NO(*main) >= 2){
                if(altura_NO((*main)->esq->dir) <= altura_NO((*main)->esq->esq) )
                    RotacaoLL(main);
                else
                    RotacaoLR(main);
            }

	if((*main)->info == valor){
	    if(((*main)->esq == NULL || (*main)->dir == NULL)){ //  nó tem 1 filho ou nenhum
			TAVL *oldNode = (*main);
			if((*main)->esq != NULL)
                *main = (*main)->esq;
            else
                *main = (*main)->dir;
			free(oldNode);
		}
		else {  //  nó tem 2 filhos
			TAVL *temp = procuraMenor((*main)->dir);
			(*main)->info = temp->info;
			remove_ArvAVL(&(*main)->dir, (*main)->info);
            if(fatorBalanceamento_NO(*main) >= 2){
				if(altura_NO((*main)->esq->dir) <= altura_NO((*main)->esq->esq))
					RotacaoLL(main);
				else
					RotacaoLR(main);
			}
		}
		if (*main)
            (*main)->fb = maior(altura_NO((*main)->esq),altura_NO((*main)->dir)) + 1;
		return 1;
	}

	(*main)->fb = maior(altura_NO((*main)->esq),altura_NO((*main)->dir)) + 1;

	return res;
}

#endif // TAVL_H_INCLUDED
