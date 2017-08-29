#include <stdio.h>
#include <string.h>

typedef struct pessoa{
    char nome [20];
    char cpf [11];
    char sexo;
    char endereco [50];
} pessoa;

void teste(pessoa teste [5]){
    printf("\nNome = %s\n", teste[0].nome);
    printf("Tamanho teste: %d\n", sizeof(teste));
}

int main(){
    system("clear");
    pessoa cliente[5];
    strcpy(cliente[0].nome, "Alexandre");
    strcpy(cliente[0].cpf, "99999999999");
    cliente[0].sexo = 'M';
    strcpy(cliente[0].endereco, "Palmas-TO");
    printf("Tamanho cliente: %d\n", sizeof(cliente[0]));
    printf("Tamanho clientes: %d\n", sizeof(cliente));
    teste(cliente);
}
