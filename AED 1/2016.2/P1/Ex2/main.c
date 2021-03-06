/**
* @author Patrick Araújo
* Link para o enunciado: https://www.passeidireto.com/arquivo/29072879/prova-1-de-algoritmos-e-estrutura-de-dados-1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    char info;
    struct reg *prox;
}Lista;

typedef struct info{
    char info;
    struct info *prox;
}Pilha;

Lista *primeiro;
Pilha *prim;

void erase(Lista **lista);
int funcX(char v[1024]);
void push (Lista **aux, int num);
int* create();
int Pilha_desempilha(Pilha *pilha, int *in);
int Lista_remove(Lista *lista, int *in);
void Pilha_empilha (Pilha **aux, char num);
void Lista_insere (Lista **aux, char num);


void main(){
    printf("%d, %d, %d, %d", funcX("barrabas"), funcX("asouosa"), funcX("eh ou nao eh"), funcX("SAIPPUAKIVIKAUPPIAS"));
    return 0;
}

int* create(){
    int *F = NULL;
    return F;
}

int funcX(char v[1024]){
    int i = 0;
    int j = 0;
    Lista *F = create();
    Pilha *P = create();
    //  *P = create();
    for(; i < strlen(v); i++){
        Lista_insere(&F, v[i]);
        Pilha_empilha(&P, v[i]);
    }
    while((Pilha_desempilha(P, &i)) && (Lista_remove(F, &j))){
        if((i == 0) && (j == 0)){
            return 0;
        }
    }
    return 1;
}

void Lista_insere (Lista **aux, char let) {
    Lista *p;   //  auxiliar
	if((p = malloc(sizeof(Lista))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->info = let;  //  recebendo valor
		p->prox = NULL; //  esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
		else
            primeiro = p;
		*aux = p;   //  lista recebe valor da direita
	}
}

void Pilha_empilha(Pilha **aux, char num) {
    Pilha *p;   //  auxiliar
	if((p = malloc(sizeof(Pilha))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->info = num;  //  recebendo valor
		p->prox = NULL; //  esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
		else
            prim = p;
		(*aux) = p; //  lista recebe valor da direita
	}
}

int Lista_remove(Lista *lista, int *in) {
	*in = 0;
	int j = 0, i;
    Lista *aux = primeiro;
	if(primeiro == NULL){
        printf("Nao ha elementos na pilha\n");
		return 0;
    }
	else
		while(aux != NULL){ //  enquanto não houver objetos nulos, da direita
			j++;
			aux = aux->prox;
		}
	aux = primeiro;
	if((j !=0) && (j != 1)){
        for(i = 0; i < j-1; i++){
            if(i == j-2){
                //  printf("\nPilha->info: %c\n", (aux->prox->info));
                if((aux->prox->info) == (primeiro->info))
                    *in = 1;
                aux->prox = 0;
            }
            aux = aux->prox;
        }
    }
    else{
		*in = 0;
        primeiro = NULL;
        return 0;
    }
	if(primeiro != NULL){
        Lista *temp = (primeiro)->prox;
        free(primeiro);
        primeiro = temp;
    }
    return 1;
}

int Pilha_desempilha(Pilha *pilha, int *in) {
    *in = 0;
    int j = 0, i;
    Pilha *aux = prim;
	if(prim == NULL){   //  lista vazia
        printf("\nLista Vazia\n");
		return 0;
	}
	else
		while(aux != NULL){ //  enquanto não houver objetos nulos, da direita
			j++;
			aux = aux->prox;
		}
    aux = prim;
    if((j !=0) && (j != 1)){
        for(i = 0; i < j-1; i++){
            if(i == j-2){
                if((aux->prox->info) == (prim->info))
                    *in = 1;
                aux->prox = 0;
            }
            aux = aux->prox;
        }
    }
    else{
        *in = 0;
        prim = NULL;
        return 0;
    }
    if(prim != NULL){
        Pilha *temp = (prim)->prox;
        free(prim);
        prim = temp;
    }
    return 1;
}
