#include <stdio.h>
#include <stdlib.h>

/*
typedef struct reg_pilha{
      int info;
      struct reg_pilha *lig ;
};
typedef struct reg_pilha *tpont;
typedef tpont pilha;
*/

typedef struct reg{
    int x;
    struct reg *prox ;
}ponto;

typedef ponto *tpoint;
typedef tpoint pilha;
pilha p;

void criar();
void push(int num);
void vazia(pilha p);
void top(pilha p);
void pop();
void imprimir(pilha p);

int main(){
    int choice, x;
    for(;;){
        printf("\n--------------------MENU---------------------------\n\n");
        printf("1 - Para Criar pilha vazia\n");
        printf("2 - Para Empilhar(PUSH)\n");
        printf("3 - Para Verificar se a pilha esta vazia\n");
        printf("4 - Para Desempilhar(POP)\n");
        printf("5 - Para Acessar o topo da pilha\n");
        printf("6 - Mostrar elementos da pilha\n");
        printf("7 - Para Sair\n");
        printf("\n----------------------------------------------------\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                criar;
            break;
            case 2:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                push(x);
            break;
            case 3:
                vazia (p);
                system("pause");
            break;
            case 4:
                pop (p);
            break;
            case 5:
                top (p);
                system("pause");
            break;
            case 6:
                imprimir(p);
                system("pause");
            break;
            case 7:
                exit (1);
        }
        system("cls");
    }

    system("pause");
    return 0;
}

void criar() {
    p = NULL;
}

void push (int num) {
    pilha pont;
    if((pont = malloc(sizeof(ponto))) == NULL)
        printf("Memoria insulficiente\n");
    else{
        pont->x = num;
        pont->prox = p;
    }
    p = pont;
}

void vazia (pilha p) {
    if(p == NULL)
        printf("Pilha vazia\n");
    else
        printf("Pilha nao vazia\n");
}

void top (pilha p) {
    if(p != NULL)
        printf("Topo da pilha %d",p->x);
    else
        printf("Pilha vazia\n");
}

void pop() {
    tpoint aux;

    if(p == NULL){
        printf("Nao ha elementos na pilha\n");
        return;
    }
    aux = p->prox;
    free(p);

    p = aux;
}

void imprimir(pilha p) {
    tpoint aux;

    if(p!= NULL)
        for(aux = p;aux!=NULL;aux=aux->prox)
            printf("%d ",aux->x);
    else
        printf("Pilha vazia\n");
}
