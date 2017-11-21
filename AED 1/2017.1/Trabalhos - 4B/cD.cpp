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
void imprimirPeriodo(no *main, int x);
void procurarDisciplina(no *main);
int imprimirDisciplina(no *main);
no* procurar(no *main, char *nome);

int main(){
    string nome, professor, ementa;
    no *main = NULL, *temp;
    int choice, periodo, c;
    while(choice != 5){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para inserir disciplina\n");
        printf("2 - Para remover disciplina\n");
        printf("3 - Busca de disciplina\n");
        printf("4 - Mostrar disciplinas por periodo\n");
        printf("5 - Para Sair\n");
        printf("\n\n");
        printf("Informe a Opcao: ");
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
                imprimirPeriodo(main, periodo);
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
            printf("removido: %s", retorno);
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

void procurarDisciplina(no *main){
    int c = 1;
    string nome;
    while(c){
        printf("\nQual disciplina?:\t");
        getline (cin, nome);
        c = imprimirDisciplina(procurar(main, nome));
    }
}

int imprimirDisciplina(no *main){
    int op;
	if(main){
        imprimir(main);
        no *aux = main;
        do{
            printf("\nSelecione uma opcao:\n\n1.\tAnterior\n2.\tProximo\n3.\tVoltar\nOutro numero:\tMenu\n\nOpcao:\t");
            scanf("%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    if(!(aux->anterior)){
                        while(aux->proximo)
                            aux = aux->proximo;
                        imprimir(aux);
                    }
                    else{
                        aux = aux->anterior;
                        imprimir(aux);
                    }
                break;
                case 2:
                    system("cls");
                    if(!(aux->proximo)){
                        while(aux->anterior)
                            aux = aux->anterior;
                        imprimir(aux);
                    }
                    else{
                        aux = aux->proximo;
                        imprimir(aux);
                    }
                break;
                case 3:
                    procurarDisciplina(main);
                    return 1;
                break;
            default:
                return 0;
            }
        }while(op != 3);
	}
    return 0;
}

void imprimirPeriodo(no *main, int x){
    string toFind;
	no *aux = main, *ant;
	int op, i = 0;
	if(main){
        printf("\n\nPeriodo:\t%i", x);
        while(aux){
            if(aux->dados->periodo == x){
                printf("\nMateria:\t%s", aux->dados->nome);
                ant = aux;
                if(!i){
                    string change(ant->dados->nome);
                    toFind = change;
                }
                i++;
            }
            aux = aux->proximo;
        }
        do{
            printf("\n\nSelecione uma opcao:\n\n1.\tAnterior\n2.\tProximo\n3.\tDetalhar\n4.\tMenu\n\nOpcao:\t");
            scanf("%d", &op);
            no *ant2;
            switch(op){
                case 1:
                    system("cls");
                    while(ant && ant->dados->periodo == x){
                        ant2 = ant;
                        ant = ant->anterior;
                    }
                    if(ant2->anterior){
                        imprimirPeriodo(main, ant2->anterior->dados->periodo);
                    }
                    else{
                        while(ant2->proximo){
                            ant2 = ant2->proximo;
                        }
                        imprimirPeriodo(main, ant2->dados->periodo);
                    }
                break;
                case 2:
                    system("cls");
                    while(ant && ant->dados->periodo == x){
                        ant2 = ant;
                        ant = ant->proximo;
                    }
                    if(ant2->proximo){
                        imprimirPeriodo(main, ant2->proximo->dados->periodo);
                    }
                    else{
                        while(ant2->anterior){
                            ant2 = ant2->anterior;
                        }
                        imprimirPeriodo(main, ant2->dados->periodo);
                    }
                break;
                case 3:
                    imprimirDisciplina(procurar(main, toFind));
                break;
            }
        }while(op < 1 || op > 4);
    }
}

void imprimir(no *main){
    if(main){
        printf("\nPeriodo:\t%i", main->dados->periodo);
        printf("\nDisciplina:\t%s", main->dados->nome);
        printf("\nProfessor:\t%s", main->dados->professor);
        printf("\nEmenta:\t%s\n", main->dados->ementa);
    }
}
