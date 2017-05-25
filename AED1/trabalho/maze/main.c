/**
* @author Patrick Araújo
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct info{
    char info;
    int linha, coluna;
    struct info *prox;
}Pilha;

Pilha *primeiro;

int busca(Pilha* aux, int dado);
void criar(Pilha **aux);

void push (Pilha **aux, int num);
void imprimir();
void erase();
void pop(Pilha **prim, Pilha **aux, char elem, int linha, int coluna);
char** str_split(char* a_str, const char a_delim);
void imprimir(Pilha *auxa);

int main(){
    FILE *fp;
    char buff;
    char index[255];
    int i = 0, j;
    Pilha *prim;
    Pilha *p = NULL;
    fp = fopen("C:\\Users\\Patrick\\Desktop\\File\\maze.txt", "r");
    fscanf(fp, "%s", index);
    char **tokens = str_split(index, ',');
    int linhas = atoi((*(tokens + 0)));
    int colunas = atoi((*(tokens + 1)));
    int l, c;
    for(l = 0; l <= linhas; l++)
        for(c = 0; c <= colunas; c++)
            if(buff!= EOF){
                buff = fgetc(fp);
                pop(&prim, &p,buff, l, c);
            }

    imprimir(prim);
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

void imprimir(Pilha *auxa){
    int i = 0;
    Pilha *aux = auxa;
	if(aux == NULL) //  lista vazia
		printf("\nLista Vazia\n");
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("%c", aux->info);
			aux = aux->prox; //o ponteiro volta imprimindo
		}
}
