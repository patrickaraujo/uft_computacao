/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Trabalho 2, Controle de Atendimento em C++ para a aula de Algoritmos e Estrutura de Dados 1 usando pilhas encadeadas
*   Assignment Waiting List in C++ language from the subject Algorithms and Data Structures 1 using Stacks
*   Finalizado em 20/10/2017 - Concluded in 10/20/2017
*/

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

typedef struct reg {
    char *name;
    struct reg *prox;
}fila;

fila *em;
fila *ur;
fila *urN;

void inserir();
int enqueue (fila **main, string nome);
char* dequeue(fila **primeiro);
void remover();
void imprimir();

int main(){
    em = NULL;  ur = NULL;  urN = NULL;
    int op;
    do{
        cout << "Qual a opcao?\n\n1\tInserir paciente\n2\tAtender/Remover paciente\n3\tImprimir pacientes\n\n0\tSair\n\nOpcao: ";
        cin >> op;
        cin.ignore(1,'\n');
        switch(op){
            case 1:
                inserir();
            break;
            case 2:
                remover();
            break;
            case 3:
                imprimir();
                system("pause");
            break;
        }
        system("cls");
    }while(op);
    return 0;
}

void inserir(){
    string nome;
    cout << "\nQual o nome?\t";
    getline (cin, nome);
    int prioridade;
    do{
        cout << "Qual a prioridade?\n\n1\tEmergencia\n2\tUrgencia\n3\tNao-urgencia\n\n0\tSair\n\nOpcao: ";
        cin >> prioridade;
        switch(prioridade){
            case 0:
                cout << "\nPaciente nao inserido\n";
            break;
            case 1:
                enqueue(&em, nome);
            break;
            case 2:
                enqueue(&ur, nome);
            break;
            case 3:
                enqueue(&urN, nome);
            break;
            default:
                cout << "\nOpcao invalida\n";
        }
    }while(prioridade < 0 || prioridade > 3);
}

int enqueue (fila **main, string nome) {
    fila *aux = (fila*)malloc(sizeof(fila));    //  auxiliar
	if(aux){
        aux->name = (char *)malloc(strlen(nome.c_str())+1);
        strcpy(aux->name, nome.c_str());
		aux->prox = NULL;
		if(*main){
            fila *temp = *main;
            while(temp->prox){
                temp = temp->prox;
            }
            temp->prox = aux;
		}
		else
            *main = aux;
		return 1;
    }
	return NULL;
}

char* dequeue(fila **main) {
	if(*main){
        char *retorno = (*main)->name;
        fila *aux = *main;
        *main = aux->prox;
        free(aux);
        return retorno;
    }
    return NULL;
}

void remover(){
    if(em)
        dequeue(&em);
    else if(ur)
        dequeue(&ur);
    else if(urN)
        dequeue(&urN);
    else
        cout << "Nenhum paciente";
}

void imprimir(){
    fila *aux1 = em;
    printf("\nLista de Atendimento\n\n");
	if(!em)
		printf("\nEmergencia Vazia\n");
	else
		while(aux1){
			printf("\nEmergencia: %s\n", aux1->name);
			aux1 = aux1->prox;
		}
    fila *aux2 = ur;
	if(!ur)
		printf("\nUrgencia Vazia\n");
	else
		while(aux2){
			printf("\nUrgencia: %s\n", aux2->name);
			aux2 = aux2->prox;
		}
    fila *aux3 = urN;
	if(!urN)
		printf("\nNao-urgencia Vazia\n\n");
	else{
		while(aux3){
			printf("\nNao-urgencia: %s\n", aux3->name);
			aux3 = aux3->prox;
		}
		printf("\n");
    }
}
