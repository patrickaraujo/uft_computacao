/**
* @author Patrick Araújo
*Listas com descritor em C para a aula de Algorismo e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct reg {
    int x;
    struct reg *prox;
}lista;

typedef struct no{
    int qntd;
    lista *primeiro, *ultimo;
}noDescritor;


int count(lista *primeiro);
void push(lista **aux, noDescritor **prim, int num);
void imprimir(noDescritor **principal);
void pop(lista **primeiro);

int main() {
    lista *P = NULL;
    noDescritor *info = NULL;
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
                push(&P, &info, x);
            break;
            case 2:
                pop(&(info->primeiro));
            break;
            case 3:
                imprimir(&info);
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

void push(lista **aux, noDescritor **prim, int num) {
    lista *p;   //  auxiliar
    noDescritor *primeiro;
	if(((p = malloc(sizeof(lista))) == NULL) || ((primeiro = malloc(sizeof(noDescritor))) == NULL))	//	erro
		printf("\nMemory Failure");
	else{
		p->x = num; //recebendo valor
		p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
		if(*aux != NULL){    //  se a lista não for nula então a esquerda recebe o valor
			(*aux)->prox = p;
			primeiro->primeiro = (*prim)->primeiro;
        }
		else
            primeiro->primeiro = p;
		(*aux) = p; //lista recebe valor da direita
		primeiro->ultimo = p;
		primeiro->qntd = count(primeiro->primeiro);
		(*prim) = primeiro;
	}
}

int count(lista *primeiro){
    lista *aux = primeiro;
	int i = 0;
	if(aux == NULL)    //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			i++;
			aux = aux->prox; //o ponteiro volta imprimindo
		}
    return i;
}

void pop(lista **primeiro){
    int j = 0, i;
    lista *aux = *primeiro;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			j++;
			aux = aux->prox;
		}
    aux = *primeiro;
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
        (*primeiro) = NULL;
    }
}

void imprimir(noDescritor **principal){
    lista *aux = (*principal)->primeiro;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("\nElemento: %d\n", aux->x);
			aux = aux->prox; //o ponteiro volta imprimindo
		}
}
