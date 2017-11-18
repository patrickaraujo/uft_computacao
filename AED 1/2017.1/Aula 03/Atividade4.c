#include <stdio.h>
#include <stdlib.h>

#define MAX	11

int vetor[MAX] = {1, 2, 3, 4, 5, 7, 10, 12, 56, 144, 921};

int busca(int chave) {
	return buscaBinariaRecursiva(0, MAX - 1, chave);
}

int buscaBinariaRecursiva(int menor, int maior, int chave){
    int media = (maior + menor) / 2;
    int valorMeio = vetor[media];
    if (menor > maior)
        return -1;
    else if(valorMeio == chave)
        return media;
    else if (valorMeio < chave)
        return buscaBinariaRecursiva(media+1, maior, chave);
    else
        return buscaBinariaRecursiva(menor, media-1, chave);
}

int main(){
    printf("Numero pesquisado: %d\nIndice: %d", 144, (busca(144)));
    return 0;
}
