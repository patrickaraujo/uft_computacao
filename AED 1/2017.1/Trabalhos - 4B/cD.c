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

typedef struct reg{
    int info;
    struct reg *ant;
    struct reg *prox;
}Lista;

int insere_lista_ordenada(no **main, int periodo, char *disciplina, char *professor, char *ementa);
char* remove_lista(no **main, char *nome);
void imprimir(no *main);
int imprimirDisciplina(no *main);
int lista_vazia(Lista *main);
no* find(no *main, char *nome);
void libera_lista(Lista **main);
int tamanho_lista(Lista *main);
char* EntraString();

int main(){
    char *nome, *professor, *ementa;
    no *main = NULL;
    int choice, periodo;
    //  ret = strcmp(str1, str2);
    while(choice != 5){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para inserir disciplina\n");
        printf("2 - Para remover disciplina\n");
        printf("3 - Busca de disciplina\n");
        printf("4 - Mostrar disciplinas por periodo\n");
        printf("5 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
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
                printf("Qual disciplina?\n");
                nome = EntraString();
                remove_lista(&main, nome);
            break;
            case 3:
                free(getchar());
                int c;
                no *temp;
                do{
                    printf("Qual disciplina?\n");
                    nome = EntraString();
                    temp = find(main, nome);
                    c = imprimirDisciplina(temp);
                }while(!c && temp);
                system("pause");
            break;
            case 4:
                imprimir(main);
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

int lista_vazia(Lista *main){
    if(main)
        return NULL;
    return 1;
}

void libera_lista(Lista **main){
    Lista *aux;
    while(*main){
        aux = *main;
        *main = (*main)->prox;
        free(aux);
    }
    free(*main);
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

int tamanho_lista(Lista *main){
    if(main){
        int cont = 0;
        Lista *aux = main;
        while(aux){
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
    return NULL;
}

int imprimirDisciplina(no *main){
    int op;
	if(main){
        printf("\nPeriodo:\t%i", main->dados->periodo);
        printf("\nDisciplina:\t%s", main->dados->nome);
        printf("\nProfessor:\t%s", main->dados->professor);
        printf("\nEmenta:\t%s\n", main->dados->ementa);

        do{
            printf("\nSelecione uma opcao:\n\n1.\tAnterior\n2.\tProximo\n3.\tVoltar\n4.\tMenu\n");
            scanf("%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    if(!(main->anterior)){
                        no *aux = main;
                        while(aux->proximo){
                            aux = aux->proximo;
                        }
                        imprimirDisciplina(aux);
                    }
                    else
                        imprimirDisciplina(main->anterior);
                break;
                case 2:
                    imprimirDisciplina(main->proximo);
                break;
                case 3:
                    return 0;
                break;
                case 4:
                    return 1;
                break;
            default:
                printf("\nOpcao invalida");
            }
        }while(op < 1 || op > 4);
	}
	return 0;
}

void imprimir(no *main){
	no *aux = main;
	if(!main)
        printf("\nLista Vazia\n");
	else
		while(aux){
			printf("\nDisciplina: %s\nPeriodo: %i\n", aux->dados->nome, aux->dados->periodo);
			aux = aux->proximo;
		}
}
