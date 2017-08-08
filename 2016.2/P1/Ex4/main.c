/**
* @author Patrick Araújo
* Link para o enunciado: https://www.passeidireto.com/arquivo/29072879/prova-1-de-algoritmos-e-estrutura-de-dados-1
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct info{
    char info;
    struct info *prox;
}Pilha;


Pilha *prim;

void pop(Pilha **aux, char num);
int maiorMenor(int meio, int tam);
int verificaCC(char num[1024]);

void main(){
    printf("verifica: %d", verificaCC("1479331"));
    return 0;
}

int verificaCC(char num[1024]){
    int i;
    Pilha *P = NULL;
    for (i = 0; num[i] != '\0'; ++i) {
        pop(&P, num[i]);
    }
    if((i % 2) == 0)
        return 0;
    int meio = i/2;
    return maiorMenor(meio, i);
}

int maiorMenor(int meio, int tam){
    Pilha *aux = prim;
    int i, j;
    for(i = 0; i < tam; i++){
        if(i <= meio-1){
            if (aux->prox->info <= aux->info)
                return 0;
        }
        else{
            if(i < (tam-1))
                if (aux->prox->info > aux->info)
                    return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

void pop(Pilha **aux, char num) {
    Pilha *p;   //  auxiliar
	if((p = malloc(sizeof(Pilha))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->info = num; //recebendo valor
		p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
		else
            prim = p;
		(*aux) = p; //lista recebe valor da direita
	}
}
