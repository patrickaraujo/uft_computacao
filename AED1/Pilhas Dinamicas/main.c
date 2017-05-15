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

ponto *Point;
//  typedef tpoint pilha;

void criar();
void push(int num);
void vazia();
void top();
void pop();
void imprimir();

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
                criar();
            break;
            case 2:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                push(x);
            break;
            case 3:
                vazia();
                system("pause");
            break;
            case 4:
                pop ();
            break;
            case 5:
                top ();
                system("pause");
            break;
            case 6:
                imprimir();
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
    Point = NULL;
}

void push (int num) {
    ponto *pont = malloc(sizeof(ponto));
    if(pont  == NULL)
        printf("Memoria insulficiente\n");
    else{
        pont->x = num;
        pont->prox = Point;
    }
    Point = pont;
}

void vazia() {
    if(Point == NULL)
        printf("Pilha vazia\n");
    else
        printf("Pilha nao vazia\n");
}

void top () {
    if(Point != NULL)
        printf("Topo da pilha %d", Point->x);
    else
        printf("Pilha vazia\n");
}

void pop() {
    ponto *aux;

    if(Point == NULL)
        printf("Nao ha elementos na pilha\n");
    else{
        aux = Point->prox;
        free(Point);
        // ver isso
        Point = aux;
    }
}

void imprimir() {
    ponto *aux;
    if(Point != NULL)
        for(aux = Point; aux != NULL; aux=aux->prox)
            printf("%d ",aux->x);
    else
        printf("Pilha vazia\n");
}
