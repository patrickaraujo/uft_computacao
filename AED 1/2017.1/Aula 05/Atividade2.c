#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char conteudo;
    struct no *vizinho;
}no;

int main(){
    system("clear");
    //  declaração dos nós
    no *no1;
    no *no2;
    no *no3;
    //  alocação de memória para os nós
    no1 = (no*)malloc(sizeof(no));
    no2 = (no*)malloc(sizeof(no));
    no3 = (no*)malloc(sizeof(no));
    /*
    printf("Tipo no = %d bytes\n\n", sizeof(no));

    printf("no1 = %x\n", no1);
    printf("no3 = %x\n", no2);
    printf("no2 = %x\n", no3);
    */
    //  armazenamento do elementos nos nós
    no1->conteudo = 'a';
    no2->conteudo = 'b';
    no3->conteudo = 'c';
    //  encadeamento dos nós
    no1->vizinho = no2;
    no2->vizinho = no3;
    no3->vizinho = NULL;
    //  imprime os conteúdos dos nós
    no *auxiliar = no1;
    while(auxiliar!=NULL){
        printf("auxiliar->conteudo = %c\n", auxiliar->conteudo);
        auxiliar = auxiliar->vizinho;
    }

    //  desaloca os nós da memória
    free(no1);
    free(no2);
    free(no3);

    return 0;
}
