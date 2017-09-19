#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char conteudo;
    strict no *anterior;
}point;

int main(){
    
    return 0;
}

void push (int num) {
    ponto *pont = malloc(sizeof(ponto));
    if(pont == NULL)
        printf("Memoria insulficiente\n");
    else{
        pont->anterior = Point;
        pont->x = num;
    }
    Point = pont;
}
