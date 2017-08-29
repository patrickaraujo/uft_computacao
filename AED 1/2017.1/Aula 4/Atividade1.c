#include <stdio.h>
#include <stdlib.h>

void teste(char letra){
    printf("Letra (funcao teste): %c\n", letra);
    printf("\nEnd. letra (funcao teste): %x\n\n", &letra);
    letra = '1';
    printf("Teste (funcao teste): %c\n\n", letra);
}

int main(){
    system("clear");
    char letra = 'a';
    printf("End. letra (main): %x\n", &letra);
    teste(letra);
    printf("Letra (main): %c\n\n", letra);

    return 0;
}
