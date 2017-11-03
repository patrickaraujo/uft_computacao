/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Trabalho 3, Hotel UFT em C para a aula de Algoritmos e Estrutura de Dados 1 usando listas ordenadas encadeadas
*   Assignment Hotel UFT in C language from the subject Algorithms and Data Structures 1 using ordered linked lists
*   Finalizado em 03/11/2017 - Concluded in 11/03/2017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    char *name;
    char *endereco;
    char *telefone;
    char *observacoes;
}Hospede;

typedef struct no {
    int num;
    Hospede *hospede;
    struct reg *prox;
}Quartos;

int verifica(int quarto, int pavimentos);
void printAll(Quartos *main);
char* EntraString();
Quartos* find(Quartos *main, int num);
void print(Quartos *main);
int remove_lista(Quartos **main, int num);

int insere_lista_ordenada(Quartos **main, int quarto, char *nome, char *endereco, char *telefone, char *obs);

int main(){
    Quartos* main = NULL;
    int op, quarto, pavimentos = 6, obs;
    char *nome, *endereco, *observacoes, *telefone;
    do{
        printf("Qual a opcao?\n\n1\tAdicionar hospede\n2\tRemover hospede\n3\tConsulta de quarto\n\n0\tSair\n\nOpcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                do{
                    printf("\nQual o quarto?:\t");
                    scanf("%d", &quarto);
                    free(getchar());
                }while(!verifica(quarto, pavimentos));
                printf("\nInformacoes do Hospede\n\nNome: \t");
                nome = EntraString();
                printf("\nEndereco: \t");
                endereco = EntraString();
                printf("\nTelefone: \t");
                telefone = EntraString();
                do{
                    printf("\nObservacoes?\n1\tSIM\n0\tNAO\nOpcao:\t");
                    scanf("%d", &obs); free(getchar());
                }while(obs < 0 || obs > 1);
                observacoes = "";
                if(obs){
                    printf("\nTexto:\t");
                    observacoes = EntraString();
                }
                insere_lista_ordenada(&main, quarto, nome, endereco, telefone, observacoes);
                system("pause");
                //  inserir();
            break;
            case 2:
                do{
                    printf("\nNumero do quarto: \t");
                    scanf("%d", &quarto);
                    free(getchar());
                }while(!verifica(quarto, pavimentos));
                remove_lista(&main, quarto);
            break;
            case 3:
                do{
                    printf("\nNumero do quarto: \t");
                    scanf("%d", &quarto);
                    free(getchar());
                }while(!verifica(quarto, pavimentos));
                print(find(main, quarto));
                system("pause");
            break;
        }
        system("cls");
    }while(op);
    return 0;
}

int insere_lista_ordenada(Quartos **main, int quarto, char *nome, char *endereco, char *telefone, char *obs){
    Quartos *aux = malloc(sizeof(Quartos));
    if(aux){
        aux->num = quarto;
        aux->hospede = malloc(sizeof(Hospede));
        aux->hospede->name = malloc(sizeof(nome));
        strcpy(aux->hospede->name, nome);
        aux->hospede->endereco = malloc(sizeof(endereco));
        strcpy(aux->hospede->endereco, endereco);
        aux->hospede->observacoes = malloc(sizeof(obs));
        strcpy(aux->hospede->observacoes, obs);
        aux->hospede->telefone = malloc(sizeof(telefone));
        strcpy(aux->hospede->telefone, telefone);
        if(*main){
            Quartos *ant, *atual = *main;
            while(atual && atual->num < quarto){
                ant = atual;
                atual = atual->prox;
            }
            if(atual == *main){ //  insere início
                aux->prox = (*main);
                *main = aux;
            }
            else{
                aux->prox = atual;
                ant->prox = aux;
            }
            return 1;
        }
        else{
            aux->prox = NULL;
            *main = aux;
            return 1;
        }
    }
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

int verifica(int quarto, int pavimentos){
    if((quarto/100) <= pavimentos && (quarto/100) >= 1)
        if((quarto%100) <= 10 && (quarto%100) >= 1)
            return 1;
    return NULL;
}

void print(Quartos *main){
    if(main){
        printf("\nQuarto: %d\n", main->num);
        printf("\nHospede: %s\n", main->hospede->name);
        printf("Endereco: %s\n", main->hospede->endereco);
        printf("Telefone: %s\n", main->hospede->telefone);
        printf("Observacoes: %s\n", main->hospede->observacoes);
    }
    else
        printf("\nQuarto vazio\n");
}

void printAll(Quartos *main){
    Quartos *aux = main;
	if(!main)
		printf("\nLista Vazia\n");
	else
		while(aux){
			printf("\nQuarto: %d\n", aux->num);
			printf("\nHospede: %s\n", aux->hospede->name);
			printf("Endereco: %s\n", aux->hospede->endereco);
			printf("Telefone: %s\n", aux->hospede->telefone);
			printf("Observacoes: %s\n", aux->hospede->observacoes);
			aux = aux->prox;
		}
}

Quartos* find(Quartos *main, int num){
	Quartos *retorno = main;
	if(main)
        while(retorno){
            if((retorno->num) == num)
                return retorno;
            retorno = retorno->prox;
        }
    return NULL;
}

int remove_lista(Quartos **main, int num){
    if(*main){
        Quartos *ant, *aux = *main;
        while(aux && aux->num != num){
            ant = aux;
            aux = aux->prox;
        }
        if(!aux)//não encontrado
            return 0;
        if(aux == *main)//remover o primeiro?
            *main = aux->prox;
        else
            ant->prox = aux->prox;
        free(aux);
        return 1;
    }
    return 0;
}
