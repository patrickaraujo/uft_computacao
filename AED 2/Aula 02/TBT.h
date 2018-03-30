#ifndef TBT_H_INCLUDED
#define TBT_H_INCLUDED

typedef struct BT{
	int info;
	struct BT *esq, *dir;
}TBT;
//  typedef struct BT TBT;

void insereR(TBT **main, int num);
void insereI(TBT **main, int num);
int busca(TBT* main, int num);
int retornaMaior(int x, int y);
int alturaR(TBT *main);
int alturaI(TBT *main);
int contarFolhas(TBT *main);
void exibirPreOrdem(TBT *main);
void exibirEmOrdem(TBT *main);
void exibirPosOrdem(TBT *main);
int cheia(TBT *main);
TBT* espelho(TBT *main);
TBT* maiorD(TBT **main);
TBT* menorE(TBT **main);
TBT* remove_atual(TBT *main);
int removerI(TBT **main, int num);
void removerR(TBT **main, int num);
void imprimir(TBT* main);

#endif // TBT_H_INCLUDED
