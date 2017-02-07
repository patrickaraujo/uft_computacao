#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int **alocar(int linhas, int colunas){
	int **array2d;
	int i, j;
    int *gridstart;
    array2d = malloc((linhas * sizeof(int *)) + (linhas * colunas * sizeof(int)));
	/* Demote to char for safe pointer arithmetic */
    gridstart = (int *)((char *)array2d + (linhas * sizeof(int *)));
    // (int *), (char *): São tipos de cast
    
    for ( i = 0; i < linhas; i++ ) {
        array2d[i] = gridstart + i * colunas;
        for ( j = 0; j < colunas; j++ ) 
            array2d[i][j] = rand() % 100;
    }

    return array2d;
    
}
	
void printtdArray(int **x, int linhas, int colunas){
	int i, j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++)
			printf("%d\t", x[i][j]);
		printf("\n");
	}
}

int main(int argc, char *argv[]) {	
	int linhas, colunas;
	printf("Entre com a quantidade de linhas...\n");
	scanf("%i", &linhas);
	printf("Entre com a quantidade de colunas...\n");
	scanf("%i", &colunas);
	int tdArray[linhas][colunas];
	//	int (*pointer)[linhas][colunas];
	int **x = alocar(((sizeof(tdArray))/(sizeof(tdArray[0]))), ((sizeof(tdArray[0]))/(sizeof(tdArray[0][0]))));	// Guardar pra vida
	printtdArray(x, ((sizeof(tdArray))/(sizeof(tdArray[0]))), ((sizeof(tdArray[0]))/(sizeof(tdArray[0][0]))));
	
	return 0;
}
