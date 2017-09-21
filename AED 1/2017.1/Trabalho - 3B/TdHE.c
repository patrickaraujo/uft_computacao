#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *anterior;
}ponto;

void push (ponto **Point, int letra);
void imprimir(ponto *Point);

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

void inserir (ponto **Point, int num){
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
    else if(tam == 7){
        strcpy(niv, "Nivel Medio");
        push(&torre1, 9);   push(&torre1, 7);   push(&torre1, 5);   push(&torre1, 3);   push(&torre1, 1);
    }
    else if(tam == 9){
        strcpy(niv, "Nivel Dificil");
        push(&torre1, 13);  push(&torre1, 11);  push(&torre1, 9);   push(&torre1, 7);   push(&torre1, 5);   push(&torre1, 3);   push(&torre1, 1);
    }

    int op, inicioT1 = 0, fimT1 = tam, inicioT2 = 0, fimT2 = 0, inicioT3 = 0, fimT3 = 0, i = 0;

    do{
        printf("\n%s\n", niv);
        printf("\nJogada: %i\n", i);
        printTorres(torre1, torre2, torre3, tam);
        imprimeOP();
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                change(torre1, torre2, &inicioT1, &fimT1, &inicioT2, &fimT2);
            break;
            case 2:
                change(torre1, torre3, &inicioT1, &fimT1, &inicioT3, &fimT3);
            break;
            case 3:
                change(torre2, torre1, &inicioT2, &fimT2, &inicioT1, &fimT1);
            break;
            case 4:
                change(torre2, torre3, &inicioT2, &fimT2, &inicioT3, &fimT3);
            break;
            case 5:
                change(torre3, torre1, &inicioT3, &fimT3, &inicioT1, &fimT1);
            break;
            case 6:
                change(torre3, torre2, &inicioT3, &fimT3, &inicioT2, &fimT2);
            break;
            default:
                printf("Invalido\n");
        }
        i++;
        system("cls");
        if(fimT3 == tam)
            if(decrescente(torre3, tam)){
                op = 7;
                printf("\nFim de jogo\n");
            }
    }while(op != 7);

    exit(EXIT_SUCCESS);
}
