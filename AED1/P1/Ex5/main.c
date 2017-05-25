/**
* @author Patrick Araújo
* Link para o enunciado: https://www.passeidireto.com/arquivo/29072879/prova-1-de-algoritmos-e-estrutura-de-dados-1
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

void pop(Lista **prim, Lista **aux, int num);
void imprimir(Lista *auxa);
Lista* sub(Lista* L1, Lista* L2);

void main(){
    int aI = 3;
    int bI = 4, i, j;
    int a[3] = {2, 3, 1};
    int b[4] = {3, 2, 1, 5};
    Lista *primL1;
    Lista *primL2;
    Lista *L1 = NULL;
    Lista *L2 = NULL;
    for(i = 0; i < aI; i++){
        pop(&primL1, &L1, a[i]);
    }
    for(i = 0; i < bI; i++){
        pop(&primL2, &L2, b[i]);
    }
    imprimir(primL1);
    imprimir(primL2);
    Lista *result = sub(primL1, primL2);
    imprimir(result);
    printf("binge");
    return 0;
}

Lista* sub(Lista *L1, Lista *L2){
    int i = 0, j = 0, this = 0, k;
    Lista *aux = L1;
    Lista *aux2 = L2;
    Lista *result = NULL;
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    while(aux2 != NULL){
        j++;
        aux2 = aux2->prox;
    }
    if(i>j)
        this = j;
    else
        this = i;
    free(aux);
    for(k = 0; k < this; k++){
        if(L1->info>=L2->info)
            pop(&result, &aux, ((L1->info)-(L2->info)));
        else
            pop(&result, &aux, (((L2->info))-(L1->info)));
        L1 = L1->prox;
        L2 = L2->prox;
    }
    return result;
}

void pop(Lista **prim, Lista **aux, int num) {
    Lista *p;   //  auxiliar
	if((p = malloc(sizeof(Lista))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->info = num; //recebendo valor
		p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
        else{
            (*prim) = p; //lista recebe valor da direita
        }
        (*aux) = p; //lista recebe valor da direita
	}
}

void imprimir(Lista *auxa){
    Lista *aux = auxa;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("\nElemento: %d\n", aux->info);
			aux = aux->prox; //o ponteiro volta imprimindo
		}
}
