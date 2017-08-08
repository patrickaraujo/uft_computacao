/**
* @author Patrick Araújo
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct way{
    int cima, baixo, direita, esquerda;
}Lista;

typedef struct info{
    char info;
    int linha, coluna;
    Lista direcoes;
    struct info *prox;
}Pilha;


Pilha *primeiro;


int busca(Pilha* aux, int dado);
void criar(Pilha **aux);
void popProcurar(Pilha *primeiro, Pilha *procurar);
void push (Pilha **aux, int num);
void imprimir();
void erase();
void pop(Pilha **prim, Pilha **aux, char elem, int linha, int coluna);
char** str_split(char* a_str, const char a_delim);
void imprimir(Pilha *auxa, int i, int j);
int inserir(Pilha **prim, int linhas, int colunas, int lL, int lC);
void iLista(Pilha **prim, int linhas, int colunas);

int main(){
    FILE *fp;
    char buff;
    char index[255];
    int i = 0, j;
    Pilha *prim;
    Pilha *p = NULL;
    fp = fopen("C:\\Users\\Patrick\\Documents\\C\\maze\\File\\maze.txt", "r");
    fscanf(fp, "%s", index);
    char **tokens = str_split(index, ',');
    int linhas = atoi((*(tokens + 0)));
    int colunas = atoi((*(tokens + 1)));
    char location[20];
    int l, c, m = 0;
    for(l = 0; l < linhas; l++)
        for(c = 0; c < colunas; c++){
            buff = fgetc(fp);
            while(buff == NULL) {
                buff = fgetc(fp);
            }
            if((int)buff == 10)
                buff = fgetc(fp);
            if(buff != EOF)
                pop(&prim, &p, buff, l, c);
            if((c == colunas -1) && (l == linhas-1)){
                while(buff != EOF){
                    if((int)buff != 10){
                        location[m] = buff;
                        buff = fgetc(fp);
                        m++;
                    }
                    else
                        buff = fgetc(fp);
                }
            }
        }

    int d;
    for(d = 0; location[d]!='\0'; d++){
        location[d] = location[d+1];
    }
    char **lIndex = str_split(location, ',');
    int lC = (atoi((*(lIndex + 0))) -1);
    int lL = (atoi((*(lIndex + 1))) -1);
    imprimir(prim, linhas, colunas);
    inserir(&prim, linhas, colunas, lC, lL);
    iLista(&prim, linhas, colunas);
    imprimir(prim, linhas, colunas);
    int iniciar = 0;

    do{
        printf("\nQual direcao deseja ir?\n");
        printf("1.\tPra cima\n2.\tPra baixo\n3.\tDireita\n4.\tEsquerda\n");
        int op;
        scanf("%d", &op);
        int lC1, lL1;
        int x;
        printf("\nLL: %i, CC: %i\n", lC, lL);
        switch(op) {
            case 1:
                lC1 = lC-1;
                x = inserir(&prim, linhas, colunas, lC1, lL);
                if(x==1){
                    lC = lC1;
                }
                imprimir(prim, linhas, colunas);
                break;
            case 2:
                lC1 = lC+1;
                x = inserir(&prim, linhas, colunas, lC1, lL);
                if(x==1){
                    lC = lC1;
                }
                imprimir(prim, linhas, colunas);
                break;
            case 3:
                lL1 = lL+1;
                x = inserir(&prim, linhas, colunas, lC, lL1);
                if(x==1){
                    lL = lL1;
                }
                imprimir(prim, linhas, colunas);
                break;
            case 4:
                lL1 = lL-1;
                x = inserir(&prim, linhas, colunas, lC, lL1);
                if(x==1){
                    lL = lL1;
                }
                imprimir(prim, linhas, colunas);
                break;
            default:
                printf("Opção inválida");
        }
        iLista(&prim, linhas, colunas);
        printf("\n1. Continuar\n0. Desistir\n");
        scanf("%d", &iniciar);
    }while(iniciar);




    return 0;
}

char** str_split(char* a_str, const char a_delim){
    char** result = 0;
    size_t count = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token){
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}

void pop(Pilha **prim, Pilha **aux, char elem, int linha, int coluna){
    Pilha *p;   //  auxiliar
    if((p = malloc(sizeof(Pilha))) == NULL)	//	erro
        printf("\nMemory Failure");
    else{
        p->info = elem; //recebendo valor
        p->linha = linha;
        p->coluna = coluna;
        p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
        if(*aux != NULL)    //  se a lista não for nula então a esquerda recebe o valor
            (*aux)->prox = p;
        else{
            (*prim) = p; //lista recebe valor da direita
        }
        (*aux) = p; //lista recebe valor da direita
    }
}

void iLista(Pilha **prim, int linhas, int colunas){
    printf("\n\n\n\n\n");
    Pilha *aux = (*prim);
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(i == 0){
                aux->direcoes.cima = 1;
                aux->direcoes.baixo = baixo(prim, linhas, colunas, i, j);
                aux->direcoes.esquerda = esquerda(prim, linhas, colunas, i, j);
                aux->direcoes.direita = direita(prim, linhas, colunas, i, j);
            }
            else if(i == linhas-1){
                aux->direcoes.cima = cima(prim, linhas, colunas, i, j);
                aux->direcoes.baixo = 1;
            }
            if(j == 0){
                aux->direcoes.cima = cima(prim, linhas, colunas, i, j);
                aux->direcoes.baixo = baixo(prim, linhas, colunas, i, j);
                aux->direcoes.direita = direita(prim, linhas, colunas, i, j);
                aux->direcoes.esquerda = 1;
                //aux->direcoes.direita = 0;
            }
            else if(j == colunas-1){
                aux->direcoes.cima = cima(prim, linhas, colunas, i, j);
                aux->direcoes.baixo = baixo(prim, linhas, colunas, i, j);
                aux->direcoes.esquerda = esquerda(prim, linhas, colunas, i, j);
                aux->direcoes.direita = 1;
            }
            else{
                aux->direcoes.cima = cima(prim, linhas, colunas, i, j);
                aux->direcoes.baixo = baixo(prim, linhas, colunas, i, j);
                aux->direcoes.esquerda = esquerda(prim, linhas, colunas, i, j);
                aux->direcoes.direita = direita(prim, linhas, colunas, i, j);
            }
            aux = aux->prox;
        }
    }

}

int baixo(Pilha **prim, int linhas, int colunas, int x, int y){
    Pilha *aux = (*prim);
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if((i == x+1) && (j == y)){
                if((int)aux->info == 32)
                    return 0;
                else
                    return 1;
            }
            aux = aux->prox;
        }
    }
    return 1;
}

int cima(Pilha **prim, int linhas, int colunas, int x, int y){
    Pilha *aux = (*prim);
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if((i == x-1) && (j == y)){
                if((int)aux->info == 32)
                    return 0;
                else
                    return 1;
            }
            aux = aux->prox;
        }
    }
    return 1;
}

int esquerda(Pilha **prim, int linhas, int colunas, int x, int y){
    Pilha *aux = (*prim);
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if((i == x) && (j == y-1)){
                if((int)aux->info == 32)
                    return 0;
                else
                    return 1;
            }
            aux = aux->prox;
        }
    }
    return 1;
}



int direita(Pilha **prim, int linhas, int colunas, int x, int y){
    Pilha *aux = (*prim);
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if((i == x) && (j == y+1)){
                if((int)aux->info == 32)
                    return 0;
                else
                    return 1;
            }
            aux = aux->prox;
        }
    }
    return 1;
}

void imprimir(Pilha *auxa, int i, int j){
    int k = 0, l = 0;
    Pilha *aux = auxa;
    if(aux == NULL) //  lista vazia
        printf("\nLista Vazia\n");
    else
        for(k = 0; k < i; k++){	//	enquanto não houver objetos nulos, da direita
            for(l = 0; l < j; l++){
                printf("%c", aux->info);
                aux = aux->prox; //o ponteiro volta imprimindo
            }
            printf("\n");
        }
}

int inserir(Pilha **prim, int linhas, int colunas, int lL, int lC){

    Pilha *aux = (*prim);
    int i, j;
    if(aux == NULL){ //  lista vazia
        printf("\nLista Vazia\n");
        return 0;
    }
    else
        for(i = 0; i < linhas; i++)
            for(j = 0; j < colunas; j++){
                if((j == lC) && (i == lL) && (aux->info != '#') && (aux->info != '*') ){
                    if(aux->direcoes.direita && aux->direcoes.cima && aux->direcoes.baixo && aux->direcoes.esquerda){
                        //  printf("Direita: %i\nEsquerda: %i\nCima: %i\nBaixo: %i", aux->direcoes.direita, aux->direcoes.cima, aux->direcoes.baixo, aux->direcoes.esquerda);
                        printf("Sem movimentos\n");
                        return 0;
                    }
                    else{
                        aux->info = '*';
                        return 1;
                    }
                }
            else if((j == lC) && (i == lL) && (aux->info == 97)) {
                printf("You won!");
                exit(EXIT_SUCCESS);
            }
                aux = aux->prox;
            }
}

void popProcurar(Pilha *primeiro, Pilha *procurar){
    Pilha *aux = primeiro;
    while(aux != NULL){
        if(aux->prox == procurar)
            aux->prox = procurar->prox;
        aux = aux->prox;
    }
}
