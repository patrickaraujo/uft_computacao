#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int verify(int *s, int x){
	int i;
	for(i = 1; i <= x; i++) {
		int j, k = 0;
		if (i - 1 != 0)
			k = ((i - 1) * ((i - 1) + 1) / 2);
		for (j = k; j < (i * (i + 1) / 2); j++) {
			if((i % 2 == 0)){
				if(s[j] % 2 != 0){
					return 0;
				}
			}
			else{
				if(s[j] % 2 == 0){
					return 0;
				}
			}
		}
	}
	return 1;
}

void v(int *s, int n, int t) {
	int aOK = verify(s, n);
	int a = (((n+1) * ((n + 1) + 1) / 2) - (n * (n + 1) / 2));
	int v[a];
	if(aOK == 1){
		int i;
		for (i = (n * (n + 1) / 2); i < ((n+1) * ((n + 1) + 1) / 2); i++) {
			int num;
			if((n + 1) % 2 == 0){
				do{
					num = (int) (rand());
					v[(i-(n * (n + 1) / 2))] = num;
				}while(num % 2 != 0);
			}
			else{
				do{
					num = (int) (rand());
					v[(i-(n * (n + 1) / 2))] = num;
				}while(num % 2 == 0);
			}
		}
		int newC[t+a];
		int j, k;
		for (j = 0; j < t; j++) {
			newC[j] = s[j];
		}
		for (k = t; k < (t+a); k++) {
            newC[k] = v[k - t];
        }
		printf("\nSequencia completa e correta, definindo resutado...\n");

		printArray((t+a), newC);
	}
	else
		printf("\nSequencia completa mas incorreta, sem resultados a mostrar\n");
}

void printArray(int t, int *v){
    int i;
    for(i = 0; i < t; i++){
        if(i == (t-2)){
            printf("Posicao %d: (%i) e ", i, v[i]);
        }
        else if (!(i == (t - 1))){
            printf("Posicao %i: (%i), ", i, v[i]);
        }
        else{
            printf("Posicao %i: (%i)", i, v[i]);
        }
    }
    printf("\n");
}


int main(int argc, char *argv[]) {
    int t;
    printf("Entre com a quantidade de elementos\n");
    scanf("%i", &t);
    int n = (int)sqrt(2*t);
    bool triangular = n * (n + 1) / 2 == t;
    if(triangular){
        printf("Entre com a sequencia:\n");
        int i;
        int x[t];
        for(i = 0; i < t; i++){
            printf("Entre com o elemento %i\n", (i+1));
            scanf("%i", &x[i]);
        }
        printArray(t, x);
        v(x, n, t);
    }
    else{
        printf("O numero nao e triangular, :(\n");
    }
    return 0;
}
