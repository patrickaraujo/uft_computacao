#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char conteudo;
    struct no *anterior;
}ponto;

void inserir(char *word, int tam){
    int i;
    for(i = 0; i < tam; i++)
        push()
}

int main(){
    ponto * palavras = NULL;
    printf("IDENTIFICACAO DE PALINDROMOS\n");
    printf("Entre com a palavra\n");
    char word[64];
    fgets(word, sizeof(word), stdin);
    int tam = strlen(&word)-1;
    printf("%i", tam);
    inserir(&word, tam);

    return 0;
}

void push (ponto **Point, int num) {
    ponto *pont = malloc(sizeof(ponto));
    if(pont == NULL)
        printf("Memoria insulficiente\n");
    else{
//       pont->x = num;
//       pont->anterior = *Point;
    }
//    *Point = pont;
}

void pop() {
    ponto *aux;

/*    if(Point == NULL)
        printf("Nao ha elementos na pilha\n");
    else{
        aux = Point->prox;
        free(Point);
        // ver isso
        Point = aux;
    }

}

char top(no_char *p){
    if(p!=NULL)
        return p->conteudo;
    return '\0';
    */
}
