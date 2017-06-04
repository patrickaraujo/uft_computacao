/**
* @author Patrick Araújo
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pl{
    char palavras[30];
    struct pl *next;
}Palavras;

typedef struct reg{
    char info;
    struct reg *prox ;
}Lista;


void push(Lista **aux, Lista **prim, char letra);
void imprimir(Lista *auxa, int i, int j);
void pushWords(Palavras **auxP, Palavras **primP, char *palav);
void procurarPalavras(Lista *prim, Palavras *primP, int i, int j, int k);
void procurarDirecoes(char *palavra, Lista *prim, int i, int j);

int main(){
    Palavras *primPalavras;
    Palavras *pPalavras = NULL;

    Lista *prim;
    Lista *p = NULL;

    FILE *fp;
    char buff;
    fp = fopen("C:\\Users\\Patrick\\Documents\\C\\cP\\File\\cP.txt", "r");
    int i = 0, j = 0;
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
    printf("i: %i\nj: %i", i, j);
    imprimir(prim, i, j);
    fclose(fp);

    FILE *w;
    w = fopen("C:\\Users\\Patrick\\Documents\\C\\cP\\File\\palavras.txt", "r");
    char words[30];
    int k = 0;

    printf("\nPalavras: \n");
    while(fgets(words, 30, w)) {
        printf("%s\n", words);
        pushWords(&pPalavras, &primPalavras, &words);
        k++;
    }
    fclose(w);

    procurarPalavras(prim, primPalavras, i, j, k);

    return 0;
}

void pushWords(Palavras **auxP, Palavras **primP, char *palav) {
    Palavras *plv;   //  auxiliar
    if((plv = malloc(sizeof(Palavras))) == NULL)	//	erro
        printf("\nMemory Failure");
    else{
        strcpy(plv->palavras, palav); //recebendo valor
        plv->next = NULL;	//	esquerda é nulo pois a inseção é no inicio
        if(*auxP != NULL)    //  se a lista não for nula então a esquerda recebe o valor
            (*auxP)->next = plv;
        else
            (*primP) = plv;
        (*auxP) = plv; //lista recebe valor da direita
    }
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

void procurarPalavras(Lista *prim, Palavras *primP, int i, int j, int k){
    int l = 0;
    for(l = 0; l < k; l++){
        procurarDirecoes(primP->palavras, prim, i, j);
        primP = primP->next;
    }
}

void procurarDirecoes(char *palavra, Lista *prim, int i, int j){
    printf("palavra: %s", palavra);
    pSVH(prim, palavra, i, j);
}

void pSVH(Lista *prim, char *palavra, int i, int j){
    char word[30];
    strcpy(word, palavra);

    int k = 0, m = 0;
    for(k = 0; k < i; k++){
        for(m = 0; m < j; m++){

        }
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
