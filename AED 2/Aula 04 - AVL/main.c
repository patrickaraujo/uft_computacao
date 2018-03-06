#include <stdio.h>
#include <stdlib.h>

#include "TAVL.h"

int main(){
    TAVL *avl = NULL;
    int res, i, N = 10, dados[10] = {1, 2, 3, 10, 4, 5, 9, 7, 8, 6};

    for(i = 0; i < N; i++)
        res = insere_ArvAVL(&avl, dados[i]);

    printf("Arvore AVL:\t");
    print(avl);
    printf("\nFator de balanceamento: %i\n", fatorBalanceamento_NO(avl));
    int r = 6;
    remove_ArvAVL(&avl, r);
    printf("Remocao do número %i\n", r);
    printf("Arvore AVL:\t");
    print(avl);
    return 0;
}
