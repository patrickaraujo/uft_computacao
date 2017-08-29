#include <stdio.h>
#include <string.h>

void potencia(int *x){
    int valor = *x;
    int resultado = valor*valor*valor;
    printf("%i elevado ao cubo", valor);
    printf("\nResultado: %i", resultado);
}

int main(){
    system("clear");
    int x = 3;
    potencia(&x);
    return 0;
}
