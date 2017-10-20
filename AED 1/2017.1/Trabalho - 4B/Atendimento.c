#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    char *nome;
    struct reg *prox;
}fila;

fila *em;
fila *pEm;
fila *ur;
fila *pUr;
fila *nur;
fila *pNur;

void inserir();
void remover();
void imprimir();

int main(){
    em = NULL;  ur = NULL;  nur = NULL;

    int op;
    do{
        printf("Qual a opcao?\n\n1\tInserir paciente\n2\tRemover paciente\n3\tImprimir pacientes\n\n0\tSair\n\nOpcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                inserir();
            break;
            case 2:
                remover();
            break;
            case 3:
                imprimir();
            break;
        }
    }while(op);
    return 0;
}

void inserir(){
    char nome[32];
    printf("\nQual o nome?\t");
    scanf("%s", &nome);
    int prioridade;
    do{
        printf("Qual a prioridade?\n\n1\tEmergencia\n2\tUrgencia\n3\tNao-urgencia\n\n0\tSair\n\nOpcao: ");
        scanf("%d", &prioridade);
        switch(prioridade){
            case 0:
                printf("\nPaciente nao inserido\n");
            break;
            case 1:
                enqueue(&em, &pEm, &nome);
            break;
            case 2:
                enqueue(&ur, &pUr, &nome);
            break;
            case 3:
                enqueue(&nur, &pNur, &nome);
            break;
            default:
                printf("\nOpcao invalida\n");
        }
    }while(prioridade < 0 || prioridade > 3);

}

void remover(){

}

int enqueue (fila **ultimo, fila **primeiro, char *nome) {
    fila *aux = malloc(sizeof(fila));    //  auxiliar
	if(aux){
        strcpy(aux->nome, nome);
		aux->prox = NULL;
		if(*ultimo)
			(*ultimo)->prox = aux;
		else
            (*primeiro) = aux;
		*ultimo = aux;
		return 1;
    }
	return NULL;
}


void imprimir(){
    fila *aux1 = pEm;
	if(!pEm)
		printf("\nEmergencia Vazia\n");
	else
		while(aux1){
			printf("\nEmergencia: %s\n", aux1->nome);
			aux1 = aux1->prox;
		}
    fila *aux2 = pUr;
	if(!pUr)
		printf("\nUrgencia Vazia\n");
	else
		while(aux2){
			printf("\nUrgencia: %s\n", aux2->nome);
			aux2 = aux2->prox;
		}
    fila *aux3 = pNur;
	if(!pNur)
		printf("\nNao-urgencia Vazia\n");
	else
		while(aux3){
			printf("\nNao-urgencia: %s\n", aux3->nome);
			aux3 = aux3->prox;
		}
}
