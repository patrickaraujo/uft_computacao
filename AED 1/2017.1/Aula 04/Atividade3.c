#include <stdio.h>

void teste(int teste [10]){
    printf("\nEnd. teste: %d\n", &teste);
    printf("Tam. teste:	%d\n\n", sizeof(teste));
    teste[0] = -1;
}

int main(){
    system("clear");
    int i, vetor [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("End. vetor: %d\n", &vetor);
    printf("Tam. vetor: %d\n\n", sizeof(vetor));
    teste(vetor);
    for (i = 0; i < 10; i++)
        printf("%d ", vetor[i]);
    printf("\n\n");
}
