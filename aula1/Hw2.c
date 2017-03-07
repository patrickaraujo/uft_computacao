#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
int verify(int *s, int x, int t){
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

void v(int s[], int t) {
	int n = (int) sqrt(2*t);
	bool triangular = n * (n + 1) / 2 == t;
	if(triangular){
		int aOK = verify(s, n);
		bool allOK;
		if(aOK == 0){
			aOK = false;
		}
		else{
			aOK = true;
		}
		if(allOK){
			printf("\nSequencia completa e correta, definindo resutado...\n");
			int x[] = arrayIncrease(s, generateNext(n));
			printArray(x);
		}
		else
			printf("\nSequencia completa mas incorreta, sem resultados a mostrar\n");
        }
	else
		printf("\nSequencia incompleta\n");
}

int[] arrayIncrease(int s[], int x[], int sT, int xT){
	int i, j;
	int newC[] = new int[sT+xT];
	for (i = 0; i < sT; i++) {
		newC[i] = s[i];
	}
	for (j = sT; j < (sT+xT); j++) {
		newC[j] = x[j - sT];
	}
	return newC;
}

int[] generateNext(int x){
	int v[] = new int[(((x+1) * ((x + 1) + 1) / 2) - (x * (x + 1) / 2))];
	int i;
	for (i = (x * (x + 1) / 2); i < ((x+1) * ((x + 1) + 1) / 2); i++) {
		int num;
		if((x + 1) % 2 == 0){
			do{
				num = (int) (rand() * 100);
				v[(i-(x * (x + 1) / 2))] = num;
			}while(num % 2 != 0);
		}
		else{
			do{
				num = (int) (rand() * 100);
				v[(i-(x * (x + 1) / 2))] = num;
			}while(num % 2 == 0);
		}
	}
	return v;
}
*/
void printArray(int t, int *v){
	int i;
	for(i = 0; i < t; i++){
		if(i == (t-2)){
			printf("Posicao %i", i, ": (%i", v[i], ") e \n");
		}
		else if (!(i == (t - 1))){
			printf("Posicao %i", i, ": (%i", v[i], "), \n");
		}
		else{
			printf("Posicao %i", i, ": (%i", v[i], ")\n");
		}
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	int t;
	printf("Entre com a quantidade de elementos\n");
	scanf("%i", &t);
	int n = sqrt (2*t);
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
	}
	else{
		printf("O numero não e triangular, :(\n");
	}
	return 0;
}
