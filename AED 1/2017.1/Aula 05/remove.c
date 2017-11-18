#include <stdlib.h>
#include <stdio.h>

#define TAM 100

void imprimeVetor(char *vetor, int tam){
    int i;
    for(i = 0; i < tam; i++)
        printf("vetor[%d] = %c\n", i, vetor[i]);
}

void preencheVetor(char *vetor, int tam){
    srand(time(NULL));
    int i;
    for	(i = 0; i < tam; i++)
        vetor[i] = (rand() % (122 - 97)) + 97;
}

void removeDado(char *vetor, int tam, char dado){
    int i;
    for (i = 0; i < tam; i++) {
        if(vetor[i] == dado){
            int j;
            for(j = i; j < tam - 1; j++)
                vetor[j] = vetor[j + 1];
            vetor[tam - 1] = 0;
            i--;
        }
    }
}

int main(){
    system("clear");
    char *vetor = malloc(sizeof(char) * TAM);
    preencheVetor(vetor, TAM);
    imprimeVetor(vetor, TAM);
    char dado;
    printf("Digite dado a ser removido: ");
    scanf("%c", &dado);
    removeDado(vetor, TAM, dado);
    imprimeVetor(vetor, TAM);
    free(vetor);
    return 0;
}
