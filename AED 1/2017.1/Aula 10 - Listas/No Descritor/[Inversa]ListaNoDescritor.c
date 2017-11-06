/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   [Inversa] Lista com Nó Descritor em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
}Lista;

typedef struct no{
    int qtd;
    Lista *inicio;
    Lista *final;
}nD;

int insere_lista_final(nD *main, int x);
int remove_lista_inicio(nD *main);
nD* cria_lista();
void imprimir(Lista *main);
int lista_vazia(Lista *main);
Lista* find(Lista *main, int valor);
void libera_lista(Lista **main);
int tamanho_lista(Lista *main);

int main(){
    nD *main = cria_lista();
    int choice, x;

    while(choice != 4){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para inserir elemento no topo\n");
        printf("2 - Para remover final\n");
        printf("3 - Mostrar todos elementos\n");
        printf("4 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                insere_lista_final(main, x);
            break;
            case 2:
                remove_lista_inicio(main);
            break;
            case 3:
                imprimir(main->inicio);
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

nD* cria_lista(){
    nD *main = (nD*) malloc(sizeof(nD));
    if(main){
        main->inicio = NULL;
        main->final = NULL;
        main->qtd = 0;
    }
    return main;
}

int insere_lista_final(nD *main, int x){
    Lista *aux = malloc(sizeof(main->inicio));
    if(aux){
        aux->info = x;
        aux->prox = NULL;
        if(main->inicio){
            main->final->prox = aux;
        }
        else{
            main->inicio = aux;
        }
        main->final = aux;
        main->qtd++;
        return 1;
    }
    return NULL;
}

int remove_lista_inicio(nD *main){
    if(main->inicio){
        Lista *aux = main->inicio;
        int retorno = aux->info;
        main->inicio = aux->prox;
        free(aux);
        if(!(main->inicio))
            main->final = NULL;
        main->qtd--;
        return retorno;
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

void imprimir(Lista *main){
    Lista *aux = main;
	if(!main)
		printf("\nLista Vazia\n");
	else
		while(aux){
			printf("\nElemento: %d\n", aux->info);
			aux = aux->prox;
		}
}
