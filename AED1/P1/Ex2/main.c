/**
* @author Patrick Araújo
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int info;
    struct reg *prox;
}no;

no *primeiro;

int busca(no* aux, int dado);
void criar(no **aux);
void push (no **aux, int num);
void imprimir(no *lista);
void erase(no **lista);

int main(){
    no *L;
    criar(&L);
    //  Código para criação da lista 15 busca(L, x);
    int arr[10] = {1, 2, 3, 4, 5, 6, 10, 400, 500, 550};
    int i;
    for(i = 0; i < 10; i++)
        push(&L, arr[i]);
    //  imprimir(L);
    busca(primeiro, 3);
    return 0;
}

void criar(no **aux){
    *aux = NULL;
}


int busca(no* aux, int dado){
//  int busca(int dado){
    puts("Busca");
    if(aux){
        if(aux->info == dado)
            return 1;
        else
            return busca(aux->prox, dado);
    }
    else
        return 0;
}

void push (no **aux, int num) {
    no *p; //auxiliar
	if((p = malloc(sizeof(no))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->info = num; //recebendo valor
		p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
		else
            primeiro = p;
		*aux = p; //lista recebe valor da direita
	}
}

void imprimir(no *lista){
    no *aux;
	aux = primeiro;
	if(aux == NULL)//lista vazia
		printf("\nLista Vazia\n");
	else{
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("\nElemento: %d\n", aux->info);
			//  printf("\nEnd - Elemento: %d\n", aux);
			//  printf("\nprox - Elemento: %d\n", aux->prox);
			aux = aux->prox; //o ponteiro volta imprimindo
		}
	}
}

void erase(no **lista) {
    if(*lista == NULL)
        printf("Nao ha elementos na pilha\n");
    no *aux = (primeiro)->prox;
    free(primeiro);
    primeiro = aux;
}