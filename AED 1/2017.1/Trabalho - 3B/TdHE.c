#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *anterior;
}ponto;

void push (ponto **Point, int num);
void imprimir(ponto *Point);
void printTorres(ponto *torre1, ponto *torre2, ponto *torre3);
void imprimeOP();
void jogar(int tam);
void change (ponto *torreO, ponto *torreD);

int main(){
    int nivel;
    do{
        printf("\nNIVEL\n\n");
        printf("1 - Facil\n");
        printf("2 - Medio\n");
        printf("3 - Dificil\n");
        printf("Para sair pressione 4\n");
        printf("\n\n");
        printf("Informe a Opcao: ");
        scanf("%d", &nivel);
        switch(nivel) {
            case 1:
                jogar(3);
                system("pause");
                break;
            case 2:
                jogar(5);
                system("pause");
                break;
            case 3:
                jogar(7);
                system("pause");
            break;
            default:
                printf("\nOpcao invalida\n");
                system("pause");
        }
        system("cls");
    }while(nivel > 4);
    return 0;
}

void push (ponto **Point, int num){
    ponto *pont = malloc(sizeof(ponto));
    if(pont == NULL)
        printf("Memoria insulficiente\n");
    else{
       pont->anterior = *Point;
       pont->num = num;
    }
    *Point = pont;
}

void jogar(int tam){
    ponto *torre1 = NULL;
    ponto *torre2 = NULL;
    ponto *torre3 = NULL;
    char niv[15] = "Nivel";
    if(tam == 3){
        strcpy(niv, "Nivel Facil");
        push(&torre1, 5);   push(&torre1, 3);   push(&torre1, 1);
    }
    else if(tam == 5){
        strcpy(niv, "Nivel Medio");
        push(&torre1, 9);   push(&torre1, 7);   push(&torre1, 5);   push(&torre1, 3);   push(&torre1, 1);
    }
    else if(tam == 7){
        strcpy(niv, "Nivel Dificil");
        push(&torre1, 13);  push(&torre1, 11);  push(&torre1, 9);   push(&torre1, 7);   push(&torre1, 5);   push(&torre1, 3);   push(&torre1, 1);
    }
    int op, inicioT1 = 0, fimT1 = tam, inicioT2 = 0, fimT2 = 0, inicioT3 = 0, fimT3 = 0, i = 0;
    do{
        printf("\n%s\n", niv);
        printf("\nJogada: %i\n", i);
        printTorres(torre1, torre2, torre3);
        imprimeOP();
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                push(&torre2, torre1->num);
                pop(&torre1);
            break;
            case 2:
                push(&torre3, torre1->num);
                pop(&torre1);
            break;
            case 3:
                push(&torre1, torre2->num);
                pop(&torre2);
            break;
            case 4:
                push(&torre3, torre2->num);
                pop(&torre2);
            break;
            case 5:
                push(&torre1, torre3->num);
                pop(&torre3);
            break;
            case 6:
                push(&torre2, torre3->num);
                pop(&torre3);
            break;
            default:
                printf("Invalido\n");
        }
        i++;
        //system("cls");
        /*
        if(fimT3 == tam)
            if(decrescente(torre3, tam)){
                op = 7;
                printf("\nFim de jogo\n");
            }
        */
    }while(op != 7);
    exit(EXIT_SUCCESS);
}

void imprimir(ponto *Point){
    int i = 0, j = 0, k;
    ponto *aux;
    if(Point != NULL){
        for(aux = Point; aux != NULL; aux = aux->anterior)
            i++;
        int auxiliar[i];
        for(aux = Point; aux != NULL; aux = aux->anterior)
            auxiliar[j++] = aux->num;
        j--;
        int def[j];
        for(k = 0; k <= j; k++){
            def[k] = auxiliar[j-k];
            printf("\t%i", def[k]);
        }
    }
    else{
        printf("\tPilha vazia\n");
    }
}

void printTorres(ponto *torre1, ponto *torre2, ponto *torre3){
    printf("\nTorre 1:");
    imprimir(torre1);
    printf("\nTorre 2:");
    imprimir(torre2);
    printf("\nTorre 3:");
    imprimir(torre3);
    printf("\n");
}

void imprimeOP(){
    printf("\nTrocar:\n\n");
    printf("1 - Torre 1 para Torre 2\n");
    printf("2 - Torre 1 para Torre 3\n");
    printf("3 - Torre 2 para Torre 1\n");
    printf("4 - Torre 2 para Torre 3\n");
    printf("5 - Torre 3 para Torre 1\n");
    printf("6 - Torre 3 para Torre 2\n");
    printf("7 - Para desistir\n");
}

void pop(ponto **torre) {
    ponto *aux;

    if(torre == NULL)
        printf("Nao ha elementos na pilha\n");
    else{
        aux = (*torre)->anterior;
        free(*torre);
        (*torre) = aux;
    }
}
