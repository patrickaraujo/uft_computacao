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
int remove_lista(Lista **main, int x);
void imprimir(no *main);
int lista_vazia(Lista *main);
Lista* find(Lista *main, int valor);
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
                printf("Periodo:\t");
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
                printf("Digite o numero a remover\n");
                scanf("%d", &periodo);
                //  remove_lista(&main, periodo);
            break;
            case 3:
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
            while(atual && atual->dados->periodo <= periodo){
                if((atual->dados->periodo == periodo) && ((strcmp(atual->dados->nome, nome) < 0))){
                    temp = atual;
                    atual = atual->proximo;
                }
                else{
                    temp = atual;
                    atual = atual->proximo;
                }
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

int remove_lista(Lista **main, int x){
    if(*main){
        Lista *aux = (*main);
        while(aux && aux->info != x){
            aux = aux->prox;
        }
        if(aux){
            if(!(aux->ant))
                (*main) = aux->prox;
            else
                aux->ant->prox = aux->prox;
            if(aux->prox)
                aux->prox->ant = aux->ant;
            int retorno = aux->info;
            free(aux);
            printf("\nremovido:\t%i\n", retorno);
            system("pause");
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

Lista* find(Lista *main, int valor){
	Lista *retorno = main;
	if(main)
        while(retorno){
            if((retorno->info) == valor)
                return retorno;
            retorno = retorno->prox;
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
