#include <stdio.h>
#include <stdlib.h>

void funcao(int x, int vetor[10]){
    printf("Tamanho x = %d\n", sizeof(x));
    printf("Tamanho vetor = %d\n\n", sizeof(vetor));
}

int main(){
    int x = 5;
    int vetor [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("Tamanho x = %d\n", sizeof(x));
    printf("Tamanho vetor = %d\n\n", sizeof(vetor));
    funcao(x, vetor);
    return 0;
}
