#include <stdio.h>
#include <stdlib.h>

struct cadastro{
    char nome[70+1];  // based on UK Government Data Standards Catalogue suggestion, for a Given Name is 35.
    int idade;
    char end[175+1];    // based on UK Government Data Standards Catalogue suggestion, http://webarchive.nationalarchives.gov.uk/+/http://www.cabinetoffice.gov.uk/media/254290/GDS%20Catalogue%20Vol%202.pdf
    int numero;
};

void imprime_matriz(int *m, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("\n %d", m[i]);
}

int main(){
    struct cadastro c;
    strcpy(c.nome, "Edu");
    c.idade = 20;
    strcpy(c.end, "Av. Paulista");
    c.numero = 1660;
    printf("Nome: %s\nIdade: %i\nEndereço: %s, %i", (c.nome), (c.idade), (c.end), (c.numero));
    int mat[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    imprime_matriz(&mat[0][0], 6);
    return 0;
}
