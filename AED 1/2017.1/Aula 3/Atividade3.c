#include <stdio.h>
#include <stdlib.h>

#define MAX	10

int vetor[MAX] = {1, 2, 2, 3, 4, 5, 5, 6, 7, 7};


int verificaConsecutivos(int indice, int i){
    if(indice > MAX-1)
        return i;
    if(indice > 0 && vetor[indice-1] == vetor[indice])
        i++;
    return verificaConsecutivos(indice+1, i);
}

int main(){
    printf("%d ", verificaConsecutivos(0, 0));

    return 0;
}
