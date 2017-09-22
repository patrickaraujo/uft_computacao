#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *anterior;
}ponto;

void push (ponto **Point, int num);
int pop(ponto **torre);
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
    if(num != -1){
        ponto *pont = malloc(sizeof(ponto));
        if(pont == NULL)
            printf("Memoria insulficiente\n");
        else{
            pont->anterior = *Point;
            pont->num = num;
        }
        *Point = pont;
    }
    else
        printf("Nao ha elementos na pilha\n");
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
                if(compara(torre1, torre2))
                    push(&torre2, pop(&torre1));
            break;
            case 2:
                if(compara(torre1, torre3))
                    push(&torre3, pop(&torre1));
            break;
            case 3:
                if(compara(torre2, torre1))
                    push(&torre1, pop(&torre2));
            break;
            case 4:
                if(compara(torre2, torre3))
                    push(&torre3, pop(&torre2));
            break;
            case 5:
                if(compara(torre3, torre1))
                    push(&torre1, pop(&torre3));
            break;
            case 6:
                if(compara(torre3, torre1))
                    push(&torre2, pop(&torre3));
            break;
            default:
                printf("Invalido\n");
        }
        i++;
        //system("cls");
            if(decrescente(torre3, tam)){
                printTorres(torre1, torre2, torre3);
                op = 7;
                printf("\nFim de jogo\n");
            }
    }while(op != 7);
    exit(EXIT_SUCCESS);
}

int compara(ponto *torreO, ponto *torreD){
    if(torreD == NULL)
        return 1;
    return (torreD->num>torreO->num);
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
        int def[--j];
        for(k = j; k >= 0; k--)
            printf("\t%i", auxiliar[k]);
    }
    else
        printf("\tPilha vazia");
}

int decrescente(ponto *Point, int tam){
    int i = 0, j = 0, k;
    ponto *aux;
    if(Point != NULL){
        for(aux = Point; aux != NULL; aux = aux->anterior)
            i++;
        if(i == tam){
            int auxiliar[i];
            for(aux = Point; aux != NULL; aux = aux->anterior)
                if(aux->num < aux->anterior->num)
                    return 1;
        }
    }
    return 0;
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

int pop(ponto **torre) {
    if((*torre) == NULL)
        return -1;
    else{
        int auxiliar = (*torre)->num;
        ponto *aux = (*torre)->anterior;
        free(*torre);
        (*torre) = aux;
        return auxiliar;
    }
}
