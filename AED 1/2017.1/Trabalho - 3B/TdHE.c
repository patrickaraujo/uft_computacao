/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Trabalho Torre de Hanoi em C para a aula de Algoritmos e Estrutura de Dados 1 usando pilhas encadeadas
*   Assignment Tower of Hanoi in C language from the subject Algorithms and Data Structures 1 using Stacks
*   Finalizado em 22/09/2017 - Concluded in 09/22/2017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *anterior;
}ponto;

int push (ponto **Point, int num);
void jogar(int tam);
int compara(ponto *torreO, ponto *torreD);
void imprimir(ponto *Point);
int pointerLength(ponto *Point);
void printTorres(ponto *torre1, ponto *torre2, ponto *torre3);
void imprimeOP();
int pop(ponto **torre);

int main(){
    int nivel;
    do{
        printf("Jogo Torre de Hanoi\n\n");
        printf("0 - Instrucoes\n");
        printf("\nNIVEL\n\n");
        printf("1 - Facil\n");
        printf("2 - Medio\n");
        printf("3 - Dificil\n");
        printf("Para sair pressione 4\n");
        printf("\n\n");
        printf("Informe a Opcao: ");
        scanf("%d", &nivel);
        switch(nivel) {
            case 0:
                nivel = 5;
                printf("Todas as jogadas sao realizadas movendo os valores para outras torres,\nsendo que o valor na \ntorre de origem tem que ser menor que o valor na torre de destino.\nCaso a Torre 3 se encontre com todos os valores em ordem crescente e \nas outras torres se encontrem\nvazias voce concluiu o jogo!\n");
                system("pause");
                break;
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
    int op, i = 0;
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
                    if(!push(&torre2, pop(&torre1)))
                        printf("Não foi possivel mover da Torre 1 para Torre 2");
            break;
            case 2:
                if(compara(torre1, torre3))
                    if(!push(&torre3, pop(&torre1)))
                        printf("Não foi possivel mover da Torre 1 para Torre 3");
            break;
            case 3:
                if(compara(torre2, torre1))
                    if(!push(&torre1, pop(&torre2)))
                        printf("Não foi possivel mover da Torre 2 para Torre 1");
            break;
            case 4:
                if(compara(torre2, torre3))
                    if(!push(&torre3, pop(&torre2)))
                        printf("Não foi possivel mover da Torre 2 para Torre 3");
            break;
            case 5:
                if(compara(torre3, torre1))
                    if(!push(&torre1, pop(&torre3)))
                        printf("Não foi possivel mover da Torre 3 para Torre 1");
            break;
            case 6:
                if(compara(torre3, torre2))
                    if(!push(&torre2, pop(&torre3)))
                        printf("Não foi possivel mover da Torre 3 para Torre 2");
            break;
            default:
                printf("Invalido\n");
        }
        i++;
        system("cls");
        if(pointerLength(torre3) == tam){
            printf("\n%s\n", niv);
            printf("\nJogada: %i\n", i);
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
    return (torreD->num > torreO->num);
}

int pointerLength(ponto *Point){
    int i = 0, j = 0, k;
    ponto *aux;
    if(Point != NULL)
        for(aux = Point; aux != NULL; aux = aux->anterior)
            i++;
    return i;
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

void imprimir(ponto *Point){
    int j = 0, k;
    ponto *aux;
    if(Point != NULL){
        int auxiliar[pointerLength(Point)];
        for(aux = Point; aux != NULL; aux = aux->anterior)
            auxiliar[j++] = aux->num;
        j--;
        for(k = j; k >= 0; k--)
            printf("\t%i", auxiliar[k]);
    }
    else
        printf("\tPilha vazia");
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

int push (ponto **Point, int num){
    if(num){
        ponto *pont = malloc(sizeof(ponto));
        if(pont != NULL){
            pont->anterior = *Point;
            pont->num = num;
            *Point = pont;
            return 1;
        }
    }
    return 0;
}

int pop(ponto **torre) {
    if((*torre) != NULL){
        int auxiliar = (*torre)->num;
        ponto *aux = (*torre)->anterior;
        free(*torre);
        (*torre) = aux;
        return auxiliar;
    }
    return 0;
}
