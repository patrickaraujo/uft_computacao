#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

typedef struct reg {
    string name;
    struct reg *prox;
}fila;

fila *em;
fila *pEm;
fila *ur;
fila *pUr;
fila *urN;
fila *pUrN;

void inserir();
int enqueue (fila **ultimo, fila **primeiro, string nome);
void remover();
void imprimir();

int main(){
    em = NULL;  ur = NULL;  urN = NULL;

    int op;
    do{
        cout << "Qual a opcao?\n\n1\tInserir paciente\n2\tRemover paciente\n3\tImprimir pacientes\n\n0\tSair\n\nOpcao: ";
        cin >> op;
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

    /*
    string mystr;
    cout << "What's your name? ";
    getline (cin, mystr);
    cout << "Hello world!" << endl;
    */
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
                enqueue(&em, &pEm, nome);
            break;
            case 2:
                enqueue(&ur, &pUr, nome);
            break;
            case 3:
                enqueue(&urN, &pUrN, nome);
            break;
            default:
                cout << "\nOpcao invalida\n";
        }
    }while(prioridade < 0 || prioridade > 3);

}

int enqueue (fila **ultimo, fila **primeiro, string nome) {
    fila *aux = (fila*)malloc(sizeof(fila));    //  auxiliar
	if(aux){
        aux->name = nome;
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

void remover(){

}

void imprimir(){

}
