/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Lista Encadeada Ordenada em C para a aula de Algoritmos e Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    int oc;
    struct reg *prox;
}Quartos;

typedef struct reg {
    char *name;
    char *endereco;
    char *observacoes;
    struct reg *prox;
}Hospede;

int verifica(int quarto, int pavimentos){
    if((quarto/100) <= pavimentos && (quarto/100) >= 1)
        if((quarto%100) <= 10 && (quarto%100) >= 1)
            return 1;
    return NULL;
}

char* EntraString(){
    char tecla;
    char *retorno = NULL;
    int tam = 0;
    do {
        tecla = getchar();
        if(retorno == NULL)
            retorno = (char*)malloc(sizeof(char));
        else
            retorno = (char*)realloc(retorno,tam+1);
        retorno[tam] = tecla;
        tam++;
    } while(tecla != '\n');
    retorno[tam-1] = '\0';
    return retorno;
}

int main(){
    int op, quarto, telefone, pavimentos = 6, obs;
    char *nome, *endereco, *observacoes;
    do{
        printf("Qual a opcao?\n\n1\tAdicionar hospede\n2\tRemover hospede\n3\tConsulta de quarto\n\n0\tSair\n\nOpcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                do{
                    printf("\nQual o quarto?:\t");
                    scanf("%d", &quarto);
                    free(getchar());
                }while(!verifica(quarto, pavimentos));
                printf("\nInformacoes do Hospede\n\nNome: \t");
                nome = EntraString();
                printf("\nEndereco: \t");
                endereco = EntraString();
                printf("\nTelefone: \t");
                scanf("%d", &telefone); free(getchar());
                printf("\nObservacoes?\n1\tSIM\n0\tNAO");
                scanf("%d", &obs); free(getchar());
                if(obs)
                    observacoes = EntraString();
                system("pause");

                //  inserir();
            break;
            case 2:
                //  remover();
            break;
            case 3:
                //  imprimir();
                system("pause");
            break;
        }
        system("cls");
    }while(op);

    return 0;
}
