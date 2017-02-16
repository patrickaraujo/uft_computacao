#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char * convertNumberIntoArray(unsigned int number) {
    unsigned int length = (int)(log10((float)number)) + 1;
    char * arr = (char *) malloc(length * sizeof(char)), * curr = arr;
    do {
        *curr++ = number % 10;
        number /= 10;
    } while (number != 0);
    return arr;
}

void quantoFind(int x, int y){
	char *a = convertNumberIntoArray(y);
	int i = 0;
	int j;
	for(j = 0; j < strlen(a); j++)
	if(x == a[j])
		i++;
	printf("\nQuantidade: %d", i);
}

void permutacao(int x1, int y1){
	char *x = convertNumberIntoArray(x1);
	char *y = convertNumberIntoArray(y1);
	int a = 0, b = 0, c = 0, d = 0;
	int i;
	for(i = 0; i < strlen(x); i++){
		a+=x[i];
		b+=y[i];
		c*=x[i];
		d*=y[i];
	}
	if((a == b) && (c == d))
		printf("\nÉ permutação");
	else
		printf("\nNão é permutação");
}

void exercicioC(int x1, int y1){
	char *x = convertNumberIntoArray(x1);
	char *y = convertNumberIntoArray(y1);
	int i, count, findIndex = 0;
	bool ok[strlen(y)];
	for (i = 0; i < strlen(x); i++){
		if(x[i] == y[0]){
			findIndex = i;
			ok[0] = true;
		}
	}
	if((findIndex + (strlen(y) - 1)) < strlen(x)){
		int j;
		for (j = findIndex; j < (findIndex + strlen(y) - 1); j++){
			if(x[j+1] == y[1+j-findIndex]){
				ok[1+j-findIndex] = true;
			}
		}
		int i;
		for (i = 0; i < strlen(y); i++){
			if(ok[i]){
				count++;
			}
		}
		if(count == strlen(y))
			printf("\nÉ parte");
		else
			printf("\nNão é parte");
    }
	else{
		printf("\nNão é parte");
	}
}

int main(int argc, char *argv[]) {
	int num, operacao, d;
	printf("Entre com o número\n");
	scanf("%i", &num);
	printf("\nEscolha a operação: \n");
	printf("\n1. Achar quantidade de dígitos");
	printf("\n2. Verificar se o número é permutação de outro número");
	printf("\n3. Procurar por ocorrencia\n");
	scanf("%i", &operacao);
	switch(operacao){
		case 1:
			printf("\nEntre com o elemento\n");
			scanf("%i", &d);
			char *a = convertNumberIntoArray(num);
			quantoFind(d, num);
		break;
		case 2:
			printf("\nEntre com o elemento\n");
			scanf("%i", &d);
			permutacao(num, d);
		break;
		case 3:
			printf("\nEntre com o elemento\n");
			scanf("%i", &d);
			exercicioC(num, d);
		break;
		default:
			printf("\nFim da execução\n");
	}
	return 0;
}
