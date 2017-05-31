/**
* @author Patrick Araújo
*Pilha Dinâmica em C para a aula de Algorismo e Estrutura de Dados 1
*/
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct reg_pilha{
      int info;
      struct reg_pilha *lig ;
};
typedef struct reg_pilha *tpont;
typedef tpont pilha;
*/

typedef struct reg{
    int x;
    struct reg *prox ;
}ponto;

ponto *Point;
//  typedef tpoint pilha;

void push(ponto **aux, ponto **prim, int num);
void pop();
void imprimir(ponto *aux);

int main(){
    ponto *P = NULL;
    ponto *primeiro;
    int choice, x;

    while(choice != 4){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para Empilhar(PUSH)\n");
        printf("2 - Para Desempilhar(POP)\n");
        printf("3 - Mostrar elementos da pilha\n");
        printf("4 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                push(&P, &primeiro, x);
            break;
            case 2:
                pop(&primeiro);
            break;
            case 3:
                imprimir(primeiro);
                system("pause");
            break;
            default:
                printf("\nOpção inválida");
        }
        //  limpa a tela
        system("cls");
    }

    system("pause");
    return 0;
}

void push(ponto **aux, ponto **prim, int num) {
    ponto *p;   //  auxiliar
	if((p = malloc(sizeof(ponto))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->x = num; //recebendo valor
		p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
		else
            (*prim) = p;
		(*aux) = p; //lista recebe valor da direita
	}
}


void pop(ponto **primeiro){
    int j = 0, i;
    ponto *aux = (*primeiro);
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			j++;
			aux = aux->prox;
		}
    aux = (*primeiro);
    if((j !=0 ) && (j != 1)){
        for(i = 0; i < j-1; i++){
            if(i == j-2){
                //  printf("aux-info: %i", aux->prox->info);
                aux->prox = 0;
                }
            aux = aux->prox;
        }
    }
    else{
        //  printf("aux-info: %i", aux->info);
        primeiro = NULL;
    }

}

void imprimir(ponto *primeiro){
    ponto *aux = primeiro;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("\nElemento: %d\n", aux->x);
			aux = aux->prox; //o ponteiro volta imprimindo
		}
}
