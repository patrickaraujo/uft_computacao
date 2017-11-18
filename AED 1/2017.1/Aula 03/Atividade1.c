#include <stdio.h>
#include <stdlib.h>

#define MAX	5

int vetor[MAX] = {0, 1, 2, 3, 4};

int verificaOrdenado(int indice){
    if(indice == MAX-1)
        return 1;
    if(indice <= 0 || vetor[indice-1] <= vetor[indice])
        return verificaOrdenado(indice+1);
    return 0;
}

int main(){
    if((verificaOrdenado(0)))
        printf("Esta ordenado");
    else
        printf("Nao esta ordenado");
    return 0;
}
