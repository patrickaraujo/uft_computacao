#include <stdio.h>
#include <stdlib.h>

#define MAX	5

int vetor[MAX] = {1, 2, 3, 4, 5};

int impares(int indice){
    if(indice == MAX-1)
        return 0;
    if(indice > 0 && vetor[indice-1]%2==1 && vetor[indice]%2==1)
        return 1;
    return impares(indice+1);
}

/*
int avancarVetor(int indice){
	if(indice == MAX)
		return 0;
	else
		return vetor[indice]+avancarVetor(indice+1);
}
*/

int main(){
    printf("%d\n", impares(0));
    return 0;
}
