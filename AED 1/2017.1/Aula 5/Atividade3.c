#include<stdio.h>
#include<stdlib.h>

typedef struct no {
	char conteudo;
	struct no *vizinho;
}no;

no *inicio=NULL;
no *fim=NULL;

void inserir(char conteudo) {
	no *tmp=(no*)malloc(sizeof(no));
	tmp->conteudo=conteudo;
	tmp->vizinho=NULL;
	if(inicio==NULL)
		inicio=tmp;
	else
		fim->vizinho=tmp;
	fim=tmp;
}

void imprimir() {
	no *auxiliar=inicio;
	while (auxiliar!=NULL) {
		printf("auxiliar->conteudo = %c\n",auxiliar->conteudo);
		auxiliar=auxiliar->vizinho;
	}	
}

void desalocarMemoria() {
	no *auxiliar=inicio;
	no *tmp;
	while (auxiliar!=NULL) {
		tmp=auxiliar;
		auxiliar=auxiliar->vizinho;
		free(tmp);
	}		
}

int main() {
	system("clear");

	inserir('a');
	inserir('f');
	inserir('c');
	inserir('d');
	inserir('e');		

	imprimir();

	desalocarMemoria();
}
