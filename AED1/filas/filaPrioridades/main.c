/**
* @author Patrick Araújo
*Listas com descritor em C para a aula de Algorismo e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct reg {
    int info;
    struct reg *prox;
}fila;

void push (fila **aux, fila **primeiro, int x);
void pop(fila **primeiro);
void maior(fila *primeiro, int op);
void popMaior(fila *primeiro, fila *procurar);

void imprimir(fila *auxa){
    fila *aux = auxa;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("\nElemento: %d\n", aux->info);
			aux = aux->prox; //o ponteiro volta imprimindo
		}
}

int main(){
    fila *P = NULL;
    fila *prim;
    int choice, x;

    while(choice != 6){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para Empilhar(PUSH)\n");
        printf("2 - Para Desempilhar(POP)\n");
        printf("3 - Mostrar elementos da pilha\n");
        printf("4 - Mostrar o maior elemento\n");
        printf("5 - Remover o maior elemento\n");
        printf("6 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                push(&P, &prim, x);
            break;
            case 2:
                pop(&prim);
            break;
            case 3:
                imprimir(prim);
                system("pause");
            break;
            case 4:
                maior(prim, 0);
                system("pause");
            break;
            case 5:
                maior(prim, 1);
                system("pause");
            break;
            default:
                printf("\nOpção inválida");
        }
        //  limpa a tela
        //system("cls");
    }

    system("pause");
    return 0;
}

void push (fila **aux, fila **primeiro, int x) {
    fila *p; //auxiliar
	if((p = malloc(sizeof(fila))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->info = x; //recebendo valor
		p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
		else
            (*primeiro) = p;
		*aux = p; //lista recebe valor da direita
	}
}

void maior(fila *primeiro, int op){
    fila *aux = primeiro;
    fila *temp = aux;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			if(aux->prox != NULL){
                if(aux->prox->info > temp->info)
                    temp = aux->prox;
            }
			aux = aux->prox; //o ponteiro volta imprimindo
		}
		printf("\nMaior: %i\n", temp->info);
		if(op==1)
            popMaior(primeiro, temp);
}

void popMaior(fila *primeiro, fila *procurar){
    fila *aux = primeiro;
    while(aux != NULL){
        if(aux->prox == procurar)
            aux->prox = procurar->prox;
        aux = aux->prox;
    }
}

void pop(fila **primeiro) {
	if(*primeiro != NULL){
        fila *temp = (*primeiro)->prox;
        free(primeiro);
        *primeiro = temp;
    }
}
