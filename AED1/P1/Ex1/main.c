/**
* @author Patrick Araújo
* Lista Duplamente Encadeada em C para a aula de Algorismo e Estrutura de Dados 1
*
* Assumindo que os códigos para as funções Pilha_empilha(Pilha* P, int dado); e
* Pilha_desempilha(Pilha* P, int &dado); estejam implementadas, faça um programa
* em C que receba uma expressão matemática usando operadores simples e as marcações
* de chaves, colchetes e parênteses e verifique se a equação está correta do ponto de
* vista da abertura de chaves, parênteses e colchetes
*/
/**
* @author Patrick Araújo
* Lista Duplamente Encadeada em C para a aula de Algorismo e Estrutura de Dados 1
*
* Assumindo que os códigos para as funções Pilha_empilha(Pilha* P, int dado); e
* Pilha_desempilha(Pilha* P, int &dado); estejam implementadas, faça um programa
* em C que receba uma expressão matemática usando operadores simples e as marcações
* de chaves, colchetes e parênteses e verifique se a equação está correta do ponto de
* vista da abertura de chaves, parênteses e colchetes
*/

#include <stdio.h>
#include <stdlib.h>
#define N 100

char pilha[N];
int t;

typedef struct{
	//  no* inicio, fim;
	unsigned int qtde;
}Lista;

void criapilha();
void empilha (char y);
char desempilha();
int pilhavazia();
int bemFormada(char s[]);

typedef Lista Pilha;

Lista* create(){
	Lista* nova = (Lista*)malloc(sizeof(Lista));
	if(nova){
		nova->qtde = 0;
//		nova->inicio = NULL;
//		nova->fim = NULL;
	}
	return nova;
}

//	retorna 0 para erro ou 1 para sucesso
//  Pilha_empilha(Pilha* P, int dado);

//	retorna 0 para erro ou 1 para sucesso
//  Pilha_desempilha(Pilha* P, int &dado);

int main(){
    char eq[N];
    printf("Entre com a equação\n");
    scanf("%s", eq);
    int i, k = 0;
    for (i = 0; eq[i] != '\0'; ++i) {
        if((eq[i] == '(') || (eq[i] == ')') || (eq[i] == '[') || (eq[i] == ']') || (eq[i] == '{') || (eq[i] == '}')){
            pilha[k] = eq[i];
            k++;
        }
    }
    if(bemFormada(pilha) == 0)
        printf("Equação Incorreta\n");
    else
        printf("Equação Correta\n");
    return 0;
}

int bemFormada (char s[]) {
    int i;
    criapilha ();

    for (i = 0; s[i] != '\0'; ++i) {
        char c;
        switch (s[i]) {
            case ')':
                if (pilhavazia ())
                    return 0;
                c = desempilha ();
                if (c != '(')
                    return 0;
                break;
            case ']':
                if (pilhavazia ())
                    return 0;
                c = desempilha ();
                if (c != '[')
                    return 0;
                break;
            case '}':
                if (pilhavazia ())
                    return 0;
                c = desempilha ();
                if (c != '{')
                    return 0;
                break;
             default:
                 empilha (s[i]);
        }
    }
    return pilhavazia ();
}

void criapilha() {
   t = 0;
}

void empilha (char y) {
   pilha[t++] = y;
}

char desempilha() {
   return pilha[--t];
}

int pilhavazia() {
   return t <= 0;
}
