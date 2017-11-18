#include <stdio.h>
#include <string.h>

typedef struct pessoa{
    char nome [20];
    char cpf [11];
    char sexo;
    char endereco [50];
} pessoa;

void teste(pessoa teste){
    printf("\nNome = %s\n", teste.nome);
    printf("Tamanho teste: %d\n\n", sizeof(teste));
}

int main(){
    system("clear");
    pessoa cliente;
    strcpy(cliente.nome, "Alexandre");
    strcpy(cliente.cpf, "99999999999");
    cliente.sexo = 'M';
    strcpy(cliente.endereco, "Palmas-TO");
    printf("Tamanho cliente: %d\n", sizeof(cliente));
    teste(cliente);
}
