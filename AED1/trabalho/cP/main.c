/**
* @author Patrick Araújo
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct reg{
    char info;
    struct reg *prox ;
}Lista;

typedef struct word{
    char *info;
    struct reg *prox ;
}Palavras;

void push(Lista **aux, Lista **prim, char letra);
void imprimir(Lista *auxa, int i, int j);

int main(){
    FILE *fp;
    char buff;
    fp = fopen("C:\\Users\\Patrick\\Documents\\C\\cP\\File\\cP.txt", "r");
    int i = 0, j = 0;
    Lista *prim;
    Lista *p = NULL;
    char letra;
    do{
        letra = fgetc(fp);
        if((letra == 9) && (i == 0)){
            j++;
        }
        else if((letra == 10)){
            i++;
        }
        else if((letra != 9) && (letra != 10) && (letra != -1)){
            buff = letra;
            push(&p, &prim, buff);
        }
    }while(letra != EOF);
    i++;
    j++;
    imprimir(prim, i, j);
    fclose(fp);

    FILE *w;
    w = fopen("C:\\Users\\Patrick\\Documents\\C\\cP\\File\\palavras.txt", "r");
    char words[30];
    int k = 0;
    Palavras *primPalavras;
    Palavras *pPalavras = NULL;
    printf("\nPalavras: \n");
    while(fgets(words, 30, w)) {
        printf("%s\n", words);
        pushWords(&pPalavras, &primPalavras, &words);
        k++;
    }
    fclose(w);


    return 0;
}

void push(Lista **aux, Lista **prim, char letra) {
    Lista *p;   //  auxiliar
    if((p = malloc(sizeof(Lista))) == NULL)	//	erro
        printf("\nMemory Failure");
    else{
        p->info = letra; //recebendo valor
        p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
        if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
            (*aux)->prox = p;
        else
            (*prim) = p;
        (*aux) = p; //lista recebe valor da direita
    }
}

void pushWords(Palavras **aux, Palavras **prim, char *palavras) {
    Palavras *p;   //  auxiliar
    if((p = malloc(sizeof(Palavras))) == NULL)	//	erro
        printf("\nMemory Failure");
    else{
        p->info = palavras; //recebendo valor
        p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
        if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
            (*aux)->prox = p;
        else
            (*prim) = p;
        (*aux) = p; //lista recebe valor da direita
    }
}


void imprimir(Lista *auxa, int i, int j){
    int k = 0, l = 0;
    Lista *aux = auxa;
    if(aux == NULL) //  lista vazia
        printf("\nLista Vazia\n");
    else
        for(k = 0; k < i; k++){	//	enquanto não houver objetos nulos, da direita
            for(l = 0; l < j; l++){
                printf("%c\t", aux->info);
                aux = aux->prox; //o ponteiro volta imprimindo
            }
            printf("\n");
            //  char a = '@';
            //  printf("a: %i", a);
        }
}
