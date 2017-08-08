#include <stdio.h>
#include <stdlib.h>

#define MAX	5

int vetor[MAX] = {0, 1, 2, 3, 4};

void avancarVetor(int x){
    printf("%d ", vetor[x]);
    int z = x+1;
    if(z < MAX)
        avancarVetor(z);
}

int main(){
    avancarVetor(0);
    return 0;
}
