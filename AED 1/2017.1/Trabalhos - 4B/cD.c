/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Trabalho 4, Cadastro de Disciplinas em C para a aula de Algoritmos e Estrutura de Dados 1 usando Listas Ordenadas Duplamente Encadeadas
*   Assignment Subject Register in C language from the subject Algorithms and Data Structures 1 using Doubly Ordered Linked Lists
*   Finalizado em 19/11/2017 - Concluded in 11/19/2017
*/

#include <stdio.h>
#include <stdlib.h>

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

int insere_lista_ordenada(no **main, int periodo, char *disciplina, char *professor, char *ementa);
char* remove_lista(no **main, char *nome);
void imprimir(no *main);
void imprimirPeriodo(no *main, int x);
void procurarDisciplina(no *main);
int imprimirDisciplina(no *main);
no* find(no *main, char *nome);
char* EntraString();

int main(){
    char *nome, *professor, *ementa;
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
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nPeriodo:\t");
                scanf("%d", &periodo);
                free(getchar());
                printf("Nome da disciplina:\t");
                nome = EntraString();
                printf("Professor:\t");
                professor = EntraString();
                printf("Ementa:\t");
                ementa = EntraString();
                insere_lista_ordenada(&main, periodo, nome, professor, ementa);
            break;
            case 2:
                free(getchar());
                printf("\n\nQual disciplina?:\t");
                nome = EntraString();
                remove_lista(&main, nome);
            break;
            case 3:
                free(getchar());
                procurarDisciplina(main);
            break;
            case 4:
                printf("\nQual periodo?:\t");
                scanf("%d", &periodo);
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

char* EntraString(){
    char tecla;
    char *retorno = NULL;
    int tam = 0;
    do {
        tecla = getchar();
        if(retorno == NULL)
            retorno = (char*)malloc(sizeof(char));
        else
            retorno = (char*)realloc(retorno,tam+1);
        retorno[tam] = tecla;
        tam++;
    } while(tecla != '\n');
    retorno[tam-1] = '\0';
    return retorno;
}

int insere_lista_ordenada(no **main, int periodo, char *nome, char *professor, char *ementa){
    no *aux = malloc(sizeof(no));
    if(aux){
        aux->dados = malloc(sizeof(disciplina));
        aux->dados->periodo = periodo;
        aux->dados->nome = malloc(sizeof(nome));
        strcpy(aux->dados->nome, nome);
        aux->dados->professor = malloc(sizeof(professor));
        strcpy(aux->dados->professor, professor);
        aux->dados->ementa = malloc(sizeof(ementa));
        strcpy(aux->dados->ementa, ementa);
        if(*main){
            no *temp, *atual = (*main);
            while(atual && (atual->dados->periodo <= periodo)){
                if((atual->dados->periodo == periodo) && ((strcmp(atual->dados->nome, nome) < 0))){
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

char* remove_lista(no **main, char *nome){
    if(*main){
        no *aux = (*main);
        while(aux && (strcmp(aux->dados->nome, nome))){
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

no* find(no *main, char *nome){
	no *retorno = main;
	if(main)
        while(retorno){
            if(!strcmp(retorno->dados->nome, nome))
                return retorno;
            retorno = retorno->proximo;
        }
    return NULL;
}

void procurarDisciplina(no *main){
    int c = 1;
    char *nome;
    while(c){
        printf("\nQual disciplina?:\t");
        nome = EntraString();
        c = imprimirDisciplina(find(main, nome));
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
                    free(getchar());
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
    char *toFind;
	no *aux = main, *ant;
	int op, i = 0;
	if(main){
        printf("\n\nPeriodo:\t%i", x);
        while(aux){
            if(aux->dados->periodo == x){
                printf("\nMateria:\t%s", aux->dados->nome);
                ant = aux;
                if(!i){
                    toFind = malloc(sizeof(ant->dados->nome));
                    strcpy(toFind, ant->dados->nome);
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
                    imprimirDisciplina(find(main, toFind));
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
