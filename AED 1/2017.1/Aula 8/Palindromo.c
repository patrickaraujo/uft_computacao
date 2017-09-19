#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char letra;
    struct no *anterior;
}ponto;

void push (ponto **Point, char letra);
void imprimir(ponto *Point);

void inserir(ponto **main, char *word, int tam){
    int i;
    for(i = 0; i < tam; i++)
        push(main, word[i]);
}

int main(){
    ponto *palavra = NULL;
    printf("IDENTIFICACAO DE PALINDROMOS\n\n");
    printf("Entre com a palavra: ");
    char word[64];
    fgets(word, sizeof(word), stdin);
    int tam = strlen(&word)-1;
    inserir(&palavra, &word, tam);
    imprimir(palavra);

    return 0;
}

void push (ponto **Point, char letra) {
    ponto *pont = malloc(sizeof(ponto));
    if(pont == NULL)
        printf("Memoria insulficiente\n");
    else{
       pont->anterior = *Point;
       pont->letra = letra;
    }
    *Point = pont;
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

void imprimir(ponto *Point){
    ponto *aux;
    if(Point != NULL)
        for(aux = Point; aux != NULL; aux = aux->anterior){
            printf("%c", aux->letra);
        }
    else
        printf("Pilha vazia\n");
}
