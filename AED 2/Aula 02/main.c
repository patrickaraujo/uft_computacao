/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   https://gist.github.com/marcoscastro/3e4abc13dec4eddb7894
*/

#include <stdio.h>
#include <stdlib.h>
#include "TBT.h"

int main(){
    TBT *main = NULL;
    insereR(&main, 12);
    insereR(&main, 17);
    insereR(&main, 2);
    insereR(&main, 7);
    insereR(&main, 9);
    insereR(&main, 20);
    print(main);
    int p = 0;
    printf("\nAltura: %i\n", altura(main));
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
    printf("\n\nEspelho:\t");
    espelho(main);
    print(main);
    return 0;
}
