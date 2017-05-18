/**
* @author Patrick Araújo
*Lista Duplamente Encadeada em C para a aula de Algorismo e Estrutura de Dados 1
* baseado no código do site: http://www.ebah.com.br/content/ABAAAgKOQAJ/lista-duplamente-encadeada-c
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct reg {
    int x;
    struct reg *prox, *ant;
}ponto;

ponto *lista;

void criar();
void push(int valor);
void print();
void printInvert();
void top ();
ponto* find(int valor);
//void erase(int valor);

int main() {
    int op, x;
	criar();

	while(op != 8){
        printf("\n\tMENU\t\n\n");
        printf("1 - Para Empilhar(PUSH)\n");
        printf("2 - Para Verificar se a pilha esta vazia\n");
        printf("3 - Para Desempilhar(POP)\n");
        printf("4 - Para Acessar o topo da pilha\n");
        printf("5 - Mostrar elementos da pilha\n");
        printf("6 - Buscar um Elemento e Exibir Ponteiro\n");
        //  printf("7 - Remover Elemento\n");
        printf("8 - Para Sair\n");
        printf("\n\n");
        printf("Informe A Opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Digite o numero a inserir\n");
                scanf("%d", &x);
                push(x);
            break;
            case 2:
                vazia();
                system("pause");
            break;
            case 3:
                pop ();
            break;
            case 4:
                top ();
                system("pause");
            break;
            case 5:
                print();
                system("pause");
            break;
            case 6:
                printf("Digite o numero a procurar\n");
                scanf("%d", &x);
                printf("\nPonteiro: %i\n", find(x));
                system("pause");
            break;
            /*
            case 7:
                printf("Entre com o valor\n");
                scanf("%d", &x);
                erase(x);
                system("pause");
            break;
            */
            default:
                printf("\nOpção inválida");
        }
        //  limpa a tela
        system("cls");
    }

    system("pause");
    return 0;
}

void criar() {
    lista = NULL; //lista nula
}

void vazia() {
    if(lista == NULL)
        printf("Pilha vazia\n");
    else
        printf("Pilha nao vazia\n");
}

void push(int valor){//adicionar no inicio da lista
	ponto *p; //auxiliar

	if((p = malloc(sizeof(ponto))) == NULL)	//	erro
		printf("\nMemory Failure");
	else{
		p->x = valor; //recebendo valor
		p->prox = NULL;	//	esquerda é nulo pois a inseção é no inicio
		p->ant = lista;	//	direita recebe a lista
		if(lista != NULL){	//	se a lista não for nula então a esquerda recebe o valor
			(lista)->prox = p;
		} //não pode ter um else, pois se não for nulo, ou insere na esquerda, ou a lista recebe o valor
		lista = p; //lista recebe valor da direita
	}
}

void pushInvert(int valor){ //  inserir no fim da lista

	ponto *pNow, *pNavegar; //  ponteiro de navegação
	pNavegar = lista;  //  navegação recebe a lista

	if((pNow = malloc(sizeof(ponto))) == NULL)  //  erro
		printf("\nMemory Failure\n");
	else{
		//para conter algum valor
		pNow->x = valor; //recebe valor
		pNow->ant = NULL; //direita e esquerda são nulos
		pNow->prox = NULL;
		if(lista == NULL) //  lista vazia
			lista = pNow;
		else{
			while(pNavegar->ant != NULL){   //  navegar paraa o último elemento para inserir no fim
				pNavegar = pNavegar->ant;
			}
			pNavegar->ant = pNow; //o ultimo elemento recebe o valor (direita e esquerda do pNow continuam nulos)
			pNow->prox = pNavegar; //valor da esquerda recebe o valor contido acima e insere no fim
		}
	}
}

void top () {
    if(lista != NULL)
        printf("Topo da pilha: %d\n", lista->x);
    else
        printf("Pilha vazia\n");
}

void pop() {
    ponto *aux;

    if(lista == NULL)
        printf("Nao ha elementos na pilha\n");
    else if(lista->prox == lista->ant)
        lista = NULL;
    else{
        aux = lista->ant;
        free(lista);
        // ver isso
        lista = aux;
        lista->prox = NULL;
    }
}

void print(){	//	imprime em ordem crescente
	ponto *p;
	p = lista;
	if(lista == NULL)//lista vazia
		printf("\nLista Vazia\n");
	else{
		while(p->ant != NULL){	//	enquanto o elemento da direita não for nulo
			p = p->ant; //p passa para o próximo elemento
		}
		while(p != NULL){	//	enquanto não houver objetos nulos, da direita
			printf("\nElemento: %d\n",p->x);
			p = p->prox; //o ponteiro volta imprimindo
		}
	}
}

void printInvert(){ //  imprime em ordem decrescente

	ponto *p;
	p = lista;
	if(p == NULL)   //  lista nula, lista vazia
		printf("\nLista Vazia");
	else{
		while(p!=NULL){ //  enquanto a lista não for nula
			printf("\nElemento: %d\n",p->x);    // imprime o elemento
			p = p->ant; //  passa para o próximo regitro
		}
	}
}

ponto* find(int valor){ //função passada para buscar, e retornar ponteiro
	ponto *retorno; //ponteiro de retorno
	int encontrou = 0;
	retorno = NULL; //  se não encontrar então retorno é nulo
	while(lista != NULL){   //  enquanto a lista não for nula
		if((lista->x) == valor){ //  se valor digitado for encotnrado
			retorno = lista;  //retorno recebe a lista, para retornar ponteiro
			encontrou = 1;
			break;
		}
		lista = lista->ant; //próximo elemento
	}
	if(encontrou == 1)  //  encontrou
		printf("\nElemento Encontrado com Sucesso!\n");
	else    //  nao encontrou
		printf("\nElemento digitado %c inv%clido!\n", 130, 160);
	return retorno;//retorno do ponteiro
}

/*
void erase(int valor){ //  remover elemento desejado
	ponto *aux; //  auxiliar
	int encontrou = 0;
	aux = find(valor);  //  chamando função de busca
	if(lista == NULL)   // lista vazia
		printf("\nLista Vazia\n");
	else{
		if(aux != NULL){    //  se a lista não for nula
			if(aux->ant != NULL)    //  se no valor digitado a direita não for nula
				aux->ant->prox = aux->prox; //  aux direita e esquerdqa recebe o valor da esquerda
			if(aux->prox != NULL)   //  e se a esquerda não for nula
				aux->prox->ant = aux->ant;  //  aux esquerda e direita recebe o valor da direita
			else    //  se os 2 forem nulos
				lista = aux->ant;
			free(aux);
			encontrou = 1;
		}

		if(encontrou == 1)  //  mensagem
			printf("\nElemento removido com Sucesso!\n");
		else
			printf("\nElemento nao Encontrado\n");
	}
}
*/
