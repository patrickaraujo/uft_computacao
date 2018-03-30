/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Árvore Binária de Busca
*/

#include <stdio.h>
#include <stdlib.h>
#include "TBT.h"
#include "TBT.c"

int main(){
    TBT *main = NULL;
    insereR(&main, 12);
    insereR(&main, 17);
    insereR(&main, 2);
    insereR(&main, 7);
    insereR(&main, 19);
    insereR(&main, 20);
    imprimir(main);
    int p = 0;
    printf("\nAltura: %i\n", alturaI(main));
    printf("\nContar folhas: %i\n", contarFolhas(main));
    if(busca(main, p))
        printf("%i esta na arvore", p);
    else
        printf("%i nao esta na arvore", p);

    printf("\n\nPercurso em pre-ordem\n");
    exibirPreOrdem(main);
    printf("\n\nPercurso em ordem simetrica\n");
    exibirEmOrdem(main);
    printf("\n\nPercurso em pos-ordem\n");
    exibirPosOrdem(main);
    printf("\n\nEsta cheia?:\t");
    if(cheia(main))
        printf("Sim!");
    else
        printf("Nao");
    int r = 19;

    printf("\n\nRemovendo: %i\t", r);
    removerI(&main, r);
    imprimir(main);

    printf("\n\nEspelho:\t");
    TBT *mirror = espelho(main);
    imprimir(mirror);

    return 0;
}
