#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int push(int *torre, int x, int *fim, int max){
    if ( !pilhaCheia(fim, &max) ){
        torre[(*fim)++] = x;
        return 1;
    }
    return 0;
}


int pilhaVazia(int *inicio, int *fim){
    return ((*inicio) == (*fim));
}

int pilhaCheia(int *fim, int *max){
    return ((*fim) == (*max));
}

int pop(int *torre, int *inicio, int *fim){
    if( !pilhaVazia(inicio, fim) ){
        torre[((*fim) - 1)] = NULL;
        (*fim)--;
        return 1;
    }
    return -1;
}

void printTorres(int *torre1, int *torre2, int *torre3, int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(i == 0)
            printf("Torre 1:\t%i\t", torre1[i]);
        else
            printf("%i\t", torre1[i]);
    }
    printf("\n");
    for(i = 0; i < tam; i++){
        if(i == 0)
            printf("Torre 2:\t%i\t", torre2[i]);
        else
            printf("%i\t", torre2[i]);
    }
    printf("\n");
    for(i = 0; i < tam; i++){
        if(i == 0)
            printf("Torre 3:\t%i\t", torre3[i]);
        else
            printf("%i\t", torre3[i]);
    }
    printf("\n");
}

void change(int *torre1, int *torre2, int tam, int *inicioT1, int *fimT1, int *inicioT2, int *fimT2){

    if(!(*fimT1))
        printf("\nTorre de origem vazia!\n");
    else{
        int x = 0;
        if((!(torre2[(*fimT2-1)])) || ((torre1[(*fimT1)-1]) <= (torre2[(*fimT2-1)]))){
            int aux = torre1[(*fimT1)-1];
            if(pop(torre1, inicioT1, fimT1))
                push(torre2, aux, fimT2, 3);
        }
        else
            printf("\nNao e possivel");
    }
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

void facil(){
    int op, inicioT1 = 0, fimT1 = 3, inicioT2 = 0, fimT2 = 0, inicioT3 = 0, fimT3 = 0, i = 0;
    int torre1[3] = {5, 3, 1};
    int torre2[3] = {NULL, NULL, NULL};
    int torre3[3] = {NULL, NULL, NULL};

    do{
        printf("\nJogada: %i\n", i);
        printTorres(&torre1, &torre2, torre3, 3);
        imprimeOP();
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                change(&torre1, &torre2, 3, &inicioT1, &fimT1, &inicioT2, &fimT2);
            break;
            case 2:
                change(&torre1, &torre3, 3, &inicioT1, &fimT1, &inicioT3, &fimT3);
            break;
            case 3:
                change(&torre2, &torre1, 3, &inicioT2, &fimT2, &inicioT1, &fimT1);
            break;
            case 4:
                change(&torre2, &torre3, 3, &inicioT2, &fimT2, &inicioT3, &fimT3);
            break;
            case 5:
                change(&torre3, &torre1, 3, &inicioT3, &fimT3, &inicioT1, &fimT1);
            break;
            case 6:
                change(&torre3, &torre2, 3, &inicioT3, &fimT3, &inicioT2, &fimT2);
            break;
            default:
                printf("Invalido\n");
        }
        i++;
        if(fimT3 == 3)
            if(decrescente(&torre3, 3)){
                op = 7;
                printf("\nFim de jogo\n");
            }
    }while(op != 7);

    exit(EXIT_SUCCESS);
}

int decrescente(int *torre3, int tam){
    int i;
    for(i = 0; i < tam-1; i++)
        if (torre3[i] < torre3[i+1])
            return 0;
    return 1;
}

int main(){
    int nivel, x;
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
                facil();
                system("pause");
                break;
            case 2:

                system("pause");
                break;
            case 3:

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
