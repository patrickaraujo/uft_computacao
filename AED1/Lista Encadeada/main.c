#include <stdio.h>
#include <stdlib.h>


typedef struct reg {
    int x, y, z;
    struct reg *prox;
}ponto;

int main() {
    ponto * primeiro;
    ponto * seguinte;
    int op;

    primeiro = (ponto *)malloc(sizeof(ponto));

    seguinte = primeiro;

    while(1){
        printf("\nDigite o x: ");
        scanf("%d", &seguinte->x);
        printf("Digite o y: ");
        scanf("%d", &seguinte->y);
        printf("Digite o z: ");
        scanf("%d", &seguinte->z);
        printf("Deseja continua? \n<1>: SIM \n<outro valor>?: NAO\nComando: ");
        scanf("%d", &op);
        if(op == 1){
            seguinte->prox = (ponto *)malloc(sizeof(ponto));
            seguinte = seguinte->prox;
        }
        else
            break;
    }
    seguinte->prox = NULL;
    //  volta para o começo
    seguinte = primeiro;
    printf("\n");
    while(seguinte != NULL){
        printf("x: %i \ty: %i \tz: %i \n", seguinte->x, seguinte->y, seguinte->z);
        seguinte = seguinte->prox;
    }
    return 0;
}
