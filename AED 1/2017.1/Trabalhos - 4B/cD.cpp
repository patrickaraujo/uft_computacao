/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Trabalho 4, Cadastro de Disciplinas em C++ para a aula de Algoritmos e Estrutura de Dados 1 usando Listas Ordenadas Duplamente Encadeadas
*   Assignment Subject Register in C++ language from the subject Algorithms and Data Structures 1 using Doubly Ordered Linked Lists
*   Finalizado em 21/11/2017 - Concluded in 11/21/2017
*/

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

typedef struct disciplina{
    int periodo;
    char *nome;
    char *professor;
    char *ementa;
}disciplina;

typedef struct no{
    struct no *anterior;
    disciplina *dados;
    struct no *proximo;
}no;

int insere_lista_ordenada(no **main, int periodo, string disciplina, string professor, string ementa);
char* remove_lista(no **main, string nome);
void imprimir(no *main);
char* imprimirPeriodo(no *main, int x);
void mPeriodo(no *main, int x);
int procurarDisciplina(no *main);
void mDisciplinas(no *main);
void imprimirDisciplina(no *main);
no* procurar(no *main, char *nome);
int verificaNUM(no *main, int x);

int main(){
    string nome, professor, ementa;
    no *main = NULL, *temp;
    int choice, periodo, c;
    while(choice != 5){
        printf("\n\tMENU\t\n\n");
        printf("1\t->\tPara inserir disciplina\n");
        printf("2\t->\tPara remover disciplina\n");
        printf("3\t->\tBusca de disciplina\n");
        printf("4\t->\tMostrar disciplinas por periodo\n");
        printf("5\t->\tPara Sair\n");
        printf("\n\n");
        printf("Informe a opcao: ");
        cin >> choice;
        cin.ignore(1,'\n');
        switch(choice) {
            case 1:
                printf("\nPeriodo:\t");
                cin >> periodo;
                cin.ignore(1,'\n');
                printf("Nome da disciplina:\t");
                getline (cin, nome);
                printf("Professor:\t");
                getline (cin, professor);
                printf("Ementa:\t");
                getline (cin, ementa);
                insere_lista_ordenada(&main, periodo, nome, professor, ementa);
            break;
            case 2:
                printf("\n\nQual disciplina?:\t");
                getline (cin, nome);
                remove_lista(&main, nome);
            break;
            case 3:
                procurarDisciplina(main);
            break;
            case 4:
                printf("\nQual periodo?:\t");
                cin >> periodo;
                cin.ignore(1,'\n');
                mPeriodo(main, periodo);
                system("pause");
            break;
            default:
                printf("\nOpcao invalida");
        }
        system("cls");
    }
    system("pause");
    return 0;
}

int insere_lista_ordenada(no **main, int periodo, string nome, string professor, string ementa){
    no *aux = (no *)malloc(sizeof(no));
    if(aux){
        aux->dados = (disciplina *)malloc(sizeof(disciplina));
        aux->dados->periodo = periodo;
        aux->dados->nome = (char*)malloc(strlen(nome.c_str())+1);
        strcpy(aux->dados->nome, nome.c_str());
        aux->dados->professor = (char *)malloc(strlen(professor.c_str())+1);
        strcpy(aux->dados->professor, professor.c_str());
        aux->dados->ementa = (char*)malloc(strlen(ementa.c_str())+1);
        strcpy(aux->dados->ementa, ementa.c_str());
        if(*main){
            no *temp, *atual = (*main);
            while(atual && (atual->dados->periodo <= periodo)){
                if((atual->dados->periodo == periodo) && ((strcmp(atual->dados->nome, nome.c_str()) < 0))){
                    temp = atual;
                    atual = atual->proximo;
                }
                else if(atual->dados->periodo < periodo){
                    temp = atual;
                    atual = atual->proximo;
                }
                else
                    break;
            }
            if(atual == (*main)){
                aux->anterior = NULL;
                (*main)->anterior = aux;
                aux->proximo = (*main);
                (*main) = aux;
            }
            else{
                aux->proximo = temp->proximo;
                aux->anterior = temp;
                temp->proximo = aux;
                if(atual)
                    atual->anterior = aux;
            }
            return 1;
        }
        else{
            aux->anterior = NULL;
            aux->proximo = NULL;
            (*main) = aux;
            return 1;
        }
    }
    return NULL;
}

char* remove_lista(no **main, string nome){
    if(*main){
        no *aux = (*main);
        while(aux && (strcmp(aux->dados->nome, nome.c_str()))){
            aux = aux->proximo;
        }
        if(aux){
            if(!(aux->anterior))
                (*main) = aux->proximo;
            else
                aux->anterior->proximo = aux->proximo;
            if(aux->proximo)
                aux->proximo->anterior = aux->anterior;
            char *retorno = aux->dados->nome;
            printf("Materia %s removida", retorno);
            free(aux);
            return retorno;
        }

    }
    return NULL;
}

no* procurar(no *main, string nome){
	no *retorno = main;
	if(main)
        while(retorno){
            if(!strcmp(retorno->dados->nome, nome.c_str()))
                return retorno;
            retorno = retorno->proximo;
        }
    return NULL;
}

int procurarDisciplina(no *main){
    string nome;
    printf("\nQual disciplina?:\t");
    getline (cin, nome);
    no *aux = procurar(main, nome);
    if(aux){
        mDisciplinas(aux);
        return 1;
    }
    return 0;
}

void mDisciplinas(no *main){
    int op;
	if(main){
        imprimirDisciplina(main);
        no *aux = main;
        do{
            printf("\nOPCOES\n1\t->\tAnterior\n2\t->\tProximo\n3\t->\tMostrar disciplinas por periodo\nOutro numero\t->\tMenu\n\nSelecione uma opcao:\t");
            scanf("%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    if(!(aux->anterior)){
                        while(aux->proximo)
                            aux = aux->proximo;
                        imprimirDisciplina(aux);
                    }
                    else{
                        aux = aux->anterior;
                        imprimirDisciplina(aux);
                    }
                break;
                case 2:
                    system("cls");
                    if(!(aux->proximo)){
                        while(aux->anterior)
                            aux = aux->anterior;
                        imprimirDisciplina(aux);
                    }
                    else{
                        aux = aux->proximo;
                        imprimirDisciplina(aux);
                    }
                break;
            }
        }while(op >= 1 && op <= 2);
        if(op == 3)
            mPeriodo(main, aux->dados->periodo);
	}
}

char* imprimirPeriodo(no *main, int x){
    int i = 0;
    no *aux = main;
    char *retorno;
    if(main)
        printf("\nPeriodo:\t%i\n", x);
        while(main){
            if(main->dados->periodo == x){
                printf("\nMateria:\t%s", main->dados->nome);
                if(!i){
                    retorno = (char *) malloc(sizeof(main->dados->nome));
                    strcpy(retorno, aux->dados->nome);
                }
                i++;
            }
            main = main->proximo;
        }
    main = aux;
    return retorno;
}

int verificaNUM(no *main, int x){
    no *aux = main;
	if(main)
        while(aux){
            if(aux->dados->periodo == x)
                return aux->dados->periodo;
            aux = aux->proximo;
        }
    printf("\nNao encontrado\n");
    return NULL;
}

void mPeriodo(no *main, int x){
    char *found;
	int op;
	int c = x;
	if(main && verificaNUM(main, x)){
        do{
            no *aux = main, *ant;
            found = imprimirPeriodo(aux, x);
            printf("\n\nOPCAO\n1\t->\tAnterior\n2\t->\tProximo\n3\t->\tDetalhar\n4\t->\tMenu\n\nSelecione uma opcao:\t");
            scanf("%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    while(aux){
                        if(aux->dados->periodo == x){
                            ant = aux;
                            break;
                        }
                        aux = aux->proximo;
                    }
                    if(ant->anterior)
                        x = ant->anterior->dados->periodo;
                    else{
                        while(ant->proximo){
                            ant = ant->proximo;
                        }
                        x = ant->dados->periodo;
                    }
                break;
                case 2:
                    system("cls");
                    while(aux){
                        if(aux->dados->periodo == x)
                            ant = aux;
                        aux = aux->proximo;
                    }
                    if(ant->proximo)
                        x = ant->proximo->dados->periodo;
                    else{
                        while(ant->anterior){
                            ant = ant->anterior;
                        }
                        x = ant->dados->periodo;
                    }
                break;
            }
        }while(op >= 1 &&  op <= 2);
        if(op == 3){
            string toFind(found);
            cin.ignore(1,'\n');
            mDisciplinas(procurar(main, toFind));
        }
    }
}

void imprimirDisciplina(no *main){
    if(main){
        printf("\nDisciplina:\t%s", main->dados->nome);
        printf("\nPeriodo:\t%i", main->dados->periodo);
        printf("\nProfessor:\t%s", main->dados->professor);
        printf("\nEmenta:\t%s\n", main->dados->ementa);
    }
}
