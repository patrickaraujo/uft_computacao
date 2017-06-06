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
int procurar(char *op, char *p, int tam, int a, int *in);
void pSVAH(Lista *prim, char *palavra, int i, int j);
void pSVH(Lista *prim, char *palavra, int i, int j);
void pSHH(Lista *prim, char *palavra, int i, int j);
void pSHAH(Lista *prim, char *palavra, int i, int j);
void pSDH(Lista *prim, char *palavra, int i, int j);

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
    printf("i: %i\nj: %i\n", i, j);
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
    printf("\nPalavras achadas:\n\n");
    for(l = 0; l < k; l++){
        procurarDirecoes(primP->palavras, prim, i, j);
        primP = primP->next;
    }
}

void procurarDirecoes(char *palavra, Lista *prim, int i, int j){
    pSVH(prim, palavra, i, j);
    pSVAH(prim, palavra, i, j);
    pSHH(prim, palavra, i, j);
    pSHAH(prim, palavra, i, j);
    pSDH(prim, palavra, i, j);
}

void pSVAH(Lista *prim, char *palavra, int i, int j){
    char words[j];
    strcpy(words, palavra);
    int a = 0, b = 0;
    while(words[a]!='\0'){
        a++;
    }
    a--;
    char word[a];
    strcpy(word, words);

    Lista *aux = prim;

    char matriz[i][j+1];
    int k = 0, m = 0;

    for(k = 0; k < i; k++){
        for(m = 0; m < j; m++){
            matriz[k][m] = aux->info;
            if(m==j-1){
                matriz[k][m+1] = '\0';
            }
            aux = aux->prox;
        }
        int n = strlen(matriz[k]);
        if (n > 0 && matriz[k][n-1] == '\n')
            matriz[k][n-1] = 0;
        //  printf("matriz[%i]: %s\n", k, matriz[k]);
    }
    char arrTD[i][j+1];
    for(k = 0; k < i; k++){
        strcpy(arrTD[k], strrev(matriz[k]));
        int in = 0;

        if(procurar(arrTD[k], palavra, j+1, a+1, &in)){
            printf("Direcao: Posicao vertical, sentido anti-horario\t");
            printf("Linha: %i\tColuna: %i\n\n", k, (j-1-in));
        }
    }
}

void pSHH(Lista *prim, char *palavra, int i, int j){
    char words[j];
    strcpy(words, palavra);
    int a = 0, b = 0;
    while(words[a]!='\0'){
        a++;
    }
    a--;
    char word[a];
    strcpy(word, words);
    Lista *aux = prim;
    char matriz[i][j+1];
    int k = 0, m = 0;
    for(k = 0; k < i; k++){
        for(m = 0; m < j; m++){
            matriz[k][m] = aux->info;
            if(m==j-1){
                matriz[k][m+1] = '\0';
            }
            aux = aux->prox;
        }
        int n = strlen(matriz[k]);
        if (n > 0 && matriz[k][n-1] == '\n')
            matriz[k][n-1] = 0;
    }

    char arr[j][i+1];
    for(m = 0; m < j; m++) {
        for(k = 0; k < i; k++){
            arr[m][k] = matriz[k][m];
            if(k == i-1){
                arr[m][k+1] = 0;
            }
        }
        int in = 0;
        //printf("m: %i\n", m);
        if(procurar(arr[m], palavra, j+1, a+1, &in)){
            printf("Direcao: Posicao horizontal, sentido horario\t");
            printf("Linha: %i\tColuna: %i\n\n", in, m);
        }

    }

}

void pSHAH(Lista *prim, char *palavra, int i, int j){
    char words[j];
    strcpy(words, palavra);
    int a = 0, b = 0;
    while(words[a]!='\0'){
        a++;
    }
    a--;
    char word[a];
    strcpy(word, words);
    Lista *aux = prim;
    char matriz[i][j+1];
    int k = 0, m = 0;
    for(k = 0; k < i; k++){
        for(m = 0; m < j; m++){
            matriz[k][m] = aux->info;
            if(m==j-1){
                matriz[k][m+1] = '\0';
            }
            aux = aux->prox;
        }
        int n = strlen(matriz[k]);
        if (n > 0 && matriz[k][n-1] == '\n')
            matriz[k][n-1] = 0;
    }

    char arr[j][i+1];
    char arrTD[j][i+1];
    for(m = 0; m < j; m++) {
        for(k = 0; k < i; k++){
            arr[m][k] = matriz[k][m];
            if(k == i-1){
                arr[m][k+1] = 0;
            }
        }
        strcpy(arrTD[m], strrev(arr[m]));
        int in = 0;
        if(procurar(arrTD[m], palavra, j+1, a+1, &in)){
            printf("Direcao: Posicao horizontal, sentido anti-horario\t");
            printf("Linha: %i\tColuna: %i\n\n", in, (j-m-1));
        }
    }
}

void pSVH(Lista *prim, char *palavra, int i, int j){
    char words[j];
    strcpy(words, palavra);
    int a = 0, b = 0;
    while(words[a]!='\0'){
        a++;
    }
    a--;
    char word[a];
    strcpy(word, words);
    /*
    printf("word: %s", word);
    printf("i: %i\nj: %i\ta: %i\n",i,j, a);
    */
    Lista *aux = prim;

    char matriz[i][j+1];
    int k = 0, m = 0;

    for(k = 0; k < i; k++){
        for(m = 0; m < j; m++){
            matriz[k][m] = aux->info;
            if(m==j-1){
                matriz[k][m+1] = '\0';
            }
            aux = aux->prox;
        }
        //printf("matriz[%i]: %s\n", k, matriz[k]);
        int in = 0;
        if(procurar(matriz[k], palavra, j+1, a+1, &in)){
            printf("Direcao: Posicao vertical, sentido horario\t");
            printf("Linha: %i\tColuna: %i\n\n", k, in);
        }

    }
}

void pSDH(Lista *prim, char *palavra, int i, int j){
    char words[j];
    strcpy(words, palavra);
    int a = 0, b = 0;
    while(words[a]!='\0'){
        a++;
    }
    a--;
    char word[a];
    strcpy(word, words);
    Lista *aux = prim;
    char matriz[i][j+1];
    int k = 0, m = 0;
    for(k = 0; k < i; k++){
        for(m = 0; m < j; m++){
            matriz[k][m] = aux->info;
            if(m==j-1){
                matriz[k][m+1] = '\0';
            }
            aux = aux->prox;
        }
        int n = strlen(matriz[k]);
        if (n > 0 && matriz[k][n-1] == '\n')
            matriz[k][n-1] = 0;
    }

    for(k = 0; k < i; k++){
        for(m = k; m >= 0; m--){
            printf("k: %i\tm: %i\n", k, m);
        }
    }

}

int procurar(char *op, char *p, int tam, int a, int *in){
    char palavra[a];
    strcpy(palavra, p);
    int n = strlen(palavra);
    if (n > 0 && palavra[n-1] == '\n')
        palavra[n-1] = 0;
    char find[tam];
    strcpy(find, op);
    int m = strlen(find);
    if (m > 0 && find[m-1] == '\n')
        find[m-1] = 0;
    char *res;
    if ((res = strstr(find, palavra)) != NULL){
        printf("Palavra achada: %s", p);
        //  printf("matriz: %s\n", op);
        //  printf("Em: %s\n", res);
        //  printf("tam: %i", strlen(res));
        *in = (tam-strlen(res)-1);
        return 1;
        printf("Índice: %i", (tam-strlen(res)-1));
    }
    return 0;
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
