#include <stdio.h>
#include <string.h>

void funcao(int *m){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++)
            printf("%d\t", *m++);
        printf("\n");
    }
}

int main(){

    system("clear");

    int matriz[3][5];
    int i, j;
    for (i = 0; i < 3; i++)
        for(j = 0; j < 5; j++)
            matriz[i][j] = rand()%100;
    funcao(&matriz);
    return 0;
}
