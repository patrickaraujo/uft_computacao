#include <stdio.h>
#include <stdlib.h>
#include "TBT.h"

void insereR(TBT **main, int num){   //  Inserção Recursiva
    if(!(*main)){
        TBT *aux = (TBT*) malloc(sizeof(TBT));
        aux->info = num; aux->esq = aux->dir = NULL;
        *main = aux;
    }
    else{
        if( num < (*main)->info )
            insereR(&((*main)->esq), num);
        else
            insereR(&((*main)->dir), num);
    }
}

void insereI(TBT **main, int num){  //  Inserção Iterativa
    TBT *aux = (TBT*) malloc(sizeof(TBT));
    aux->info = num; aux->esq = aux->dir = NULL;
    if(!(*main))
        *main = aux;
    else{
        TBT *temp = *main;
        while( (temp->esq && (num < temp->info)) || (temp->dir && (num >= temp->info)) ){
            if( num < temp->info )
                temp = temp->esq;
            else
                temp = temp->dir;
        }
        if( num < temp->esq )
            temp->esq = aux;
        else
            temp->dir = aux;
    }
}

int busca(TBT* main, int num){
    if(!main)   //  Se a árvore estiver vazia, então retorna 0
        return NULL;
    //  O operador lógico || interrompe a busca quando o elemento for encontrado
    return ( ( main->info == num ) || ( busca(main->esq, num) || busca(main->dir, num ) ) );
}

int retornaMaior(int x, int y){
    return ( ( x > y ) ? x : y );
}

int alturaR(TBT *main){ //  Altura Recursiva
    if( !main || (!(main->esq) && (!(main->dir))))
        return NULL;
    else
        return ( retornaMaior( alturaR(main->esq), alturaR(main->dir) ) + 1 );
}

int alturaI(TBT *main){  // Altura Iterativa
    int altura1 = 0, altura2 = 0;
    TBT *aux = main;
    while((aux->esq) || (aux->dir)){
        altura1++;
        if(!(aux->esq))
            aux = aux->dir;
        else
            aux = aux->esq;
    }
    aux = main;
    while((aux->esq) || (aux->dir)){
        altura2++;
        if(!(aux->dir))
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    return ( retornaMaior(altura1, altura2) );
}

int contarFolhas(TBT *main){
   if(!main)
        return NULL;
   if((!(main->esq)) && (!(main->dir)))
        return 1;
   return contarFolhas(main->esq) + contarFolhas(main->dir);
}

void exibirPreOrdem(TBT *main){ //  c, e, d
    if(main){
        printf("\n%i", main->info);
        exibirPreOrdem(main->esq);
        exibirPreOrdem(main->dir);
    }
}

void exibirEmOrdem(TBT *main){  //  e, c, d
    if(main){
        exibirEmOrdem(main->esq);
        printf("\n%i", main->info);
        exibirEmOrdem(main->dir);
    }
}

void exibirPosOrdem(TBT *main){ //  e, d, c
    if(main){
        exibirPosOrdem(main->esq);
        exibirPosOrdem(main->dir);
        printf("\n%i", main->info);
    }
}

int cheia(TBT *main){
    // If empty tree
    if (!(main))
        return 1;

    // If leaf node
    if ( (!(main->esq)) && (!(main->dir)) )
        return 1;

    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ( (main->esq) && (main->dir) )
        return ( cheia(main->esq) && cheia(main->dir) );

    // We reach here when none of the above if conditions work
    return NULL;
}

TBT* espelho(TBT *main){
    if(main){
        TBT *retorno = (TBT*) malloc(sizeof(TBT));
        retorno->info = main->info;
        retorno->esq = espelho(main->dir);
        retorno->dir = espelho (main->esq);
        return retorno;
    }
    return NULL;
}

TBT* maiorD(TBT **main){    //  Maior Direita
    if( (*main)->dir )
        return maiorD(&((*main)->dir));
    else{
        TBT *pAux = *main;
        if( (*main)->esq )
            *main = (*main)->esq;
        else
            *main = NULL;
        return (pAux);
    }
}

TBT* menorE(TBT **main){    //  menorEsquerda
    if( (*main)->esq )
       return menorE(&(*main)->esq);
    else{
       TBT *aux = *main;
       if( (*main)->dir ) //  se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *main = (*main)->dir;
       else
          *main = NULL;
       return aux;
    }
}

TBT* remove_atual(TBT *main){
    TBT *aux, *temp;
    if(!(main->esq)){
        temp = main->dir;
        free(main);
        return temp;
    }
    aux = main;
    temp = main->esq;
    while(temp->dir){
        aux = temp;
        temp = temp->dir;
    }
    if(aux != main){
        aux->dir = temp->esq;
        temp->esq = main->esq;
    }
    temp->dir = main->dir;
    free(main);
    return temp;
}

int removerI(TBT **main, int num){    //  Remoção Iterativa
    if(*main){
        TBT *temp = NULL;
        TBT *atual = *main;
        while(atual){
            if(num == atual->info){
                if(atual == *main)
                    *main = remove_atual(atual);
                else{
                    if(temp->dir == atual)
                        temp->dir = remove_atual(atual);
                    else
                        temp->esq = remove_atual(atual);
                }
                return 1;
            }
            temp = atual;
            if(num > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
    }
    return NULL;
}

void removerR(TBT **main, int num){
    if(*main)
        if(num < (*main)->info)
            removerR(&((*main)->esq), num);
        else if(num > (*main)->info)
            removerR(&((*main)->dir), num);
        else{
            TBT *temp = (*main);
            if( (!(temp->esq)) && (!(temp->dir)) )  //  se nao houver filhos...
                temp = NULL;    //  free(temp);
            else
                if(!(temp->esq)){
                    (*main) = temp->dir;    //  so tem filho da esquerda
                    temp = NULL;    //  free(temp);
                }
                else if(!(temp->dir)){  //  so tem o filho da direita
                    (*main) = temp->esq;
                    temp = NULL;    //  free(temp);
                }
                else{   //  Escolhi fazer o maior filho direito da subarvore esquerda.
                    temp = maiorD(&((*main)->esq)); //  temp = menorE(&(*main)->dir);
                    temp->esq = (*main)->esq;
                    temp->dir = (*main)->dir;
                    (*main)->dir = (*main)->esq = NULL;
                    (*main) = NULL; //  free(*main);
                    (*main) = temp;
                    temp = NULL;
                }
        }
}

void imprimir(TBT* main){
    //  Essa função imprime os elementos de forma recursiva

    printf("(");    //  notação para organizar na hora de mostrar os elementos
    if(main) {  //  se a árvore não for vazia...
        //  Mostra os elementos em pré-ordem
        printf("%d ", main->info);  //  mostra a raiz
        imprimir(main->esq);   //  mostra a sae (subárvore à esquerda)
        imprimir(main->dir);   //  mostra a sad (subárvore à direita)
    }
    printf(")");    //  notação para organizar na hora de mostrar os elementos
}
