#include <stdlib.h>
#include <stdio.h>

typedef struct _no{
    void* info;
    struct _no *prox, *ant;
}TNo;

typedef struct{
    TNo *inicio;
}GDList;

typedef struct{
    TNo *inicio;
}Set;

Set* create(){
	Set* novo = (Set*)malloc(sizeof(Set));
	if(novo)
		novo->inicio = NULL;
	return novo;
}

TNo* create_n_fill(int d){
	TNo* novo = (TNo*)malloc(sizeof(TNo));
	if(novo){
		novo->info = d;
		novo->prox = NULL;
	}
	return novo;
}

void insert1(Set* s, int data){
	TNo* aux = s->inicio;
	char flag = 1;
	if(aux==NULL)
		s->inicio = create_n_fill(data);
	else{
		while(aux->prox != NULL){
			if(aux->info==data){
				flag = 0;
				break;
			}
			aux = aux->prox;
		}
		if(flag)
			aux->prox = create_n_fill(data);
	}
}

void insert2(Set* s, int data){
	TNo* aux = s->inicio;
	if(aux==NULL)
		s->inicio = create_n_fill(data);
	else{
		do{
			if(aux->info==data)
			return;
			aux = aux->prox;
		}while(aux);
		aux = create_n_fill(data);
		aux->prox = s->inicio;
		s->inicio = aux;
	}
}

void insert3(Set* s, int data){
	TNo* aux = s->inicio, *aux2;
	if(aux==NULL)
		s->inicio = create_n_fill(data);
	else{
		if(data<aux->info){
			aux = create_n_fill(data);
			aux->prox = s->inicio;
			s->inicio = aux;
		}
		else{
			do{
				aux2 = aux ;
				aux = aux->prox ;
				if(aux->info==data)
				return;
			}while(aux->prox && aux->info<data);
			aux2->prox = create_n_fill(data);
			aux2->prox->prox = aux;
		}
	}
}

void insert4(Set* s, int data){
	TNo* aux = s->inicio, *aux2;
	if(aux==NULL)
		s->inicio = create_n_fill(data);
	else{
		if(data<aux->info){
			aux = create_n_fill(data);
			aux->prox = s->inicio;
			s->inicio = aux;
		}
		else{
			do{
				aux2 = aux ;
				if(aux->info==data)
					return;
				aux = aux->prox;
			}while(aux->prox && aux->info<data);
			aux2->prox = create_n_fill(data);
			aux2->prox->prox = aux;
		}
	}
}

void insert5 (Set* s, int data){
	TNo* aux = s->inicio, *aux2;
	if(aux==NULL)
		s->inicio = create_n_fill(data);
	else{
		if(data < aux->info){
			aux = create_n_fill(data);
			aux->prox = s->inicio;
			s->inicio = aux;
		}
		else{
			do{
				aux2 = aux;
				if(aux->info==data)
					return;
				aux = aux->prox;
			}while(aux && aux->info < data);
			aux2->prox = create_n_fill(data);
			if(aux)
				aux2->prox->prox = aux;
		}
	}
}

void GDList_print(GDList* L, void(*print)(void*)){
    TNo* aux = L->inicio;
    while(aux){
        print(aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

int GDList_insere_o(GDList* L, void* info, unsigned int size, int (*cmp)(void*, void*)){
    TNo* novo = (TNo*)malloc(sizeof(TNo));
    TNo* aux;
    if(!novo)
        return(0);
    novo->info = malloc(size);
    if(!(novo->info))
        return(0);
    memcpy(novo->info, info, size);
    novo->prox = NULL;
    novo->ant = NULL;
    if(L->inicio == NULL)
        L->inicio = novo;
    else{
        aux = L->inicio;
        while(aux->prox && cmp(aux->info, info) < 0)
            aux = aux->prox;
        if(aux->prox == NULL){
            aux->prox = novo;
            novo->ant = aux;
        }
        else{
            novo->prox = aux;
            novo->ant = aux->ant;

            if(aux->ant)
                aux->ant->prox = novo;
            aux->ant = novo;
            if(aux == L->inicio)
                L->inicio = novo;
        }
    }
    return(1);
}

void print_int(void* t){
    int *p;
    p = (int *) t;
    printf("%d ", *p);
}

int comp_int(void* s1, void* s2) {
    int *p1 = (int *) s1, *p2 = (int *) s2;
    return(*p1 < *p2)? -1: (*p1 == *p2)? 0: 1;
}

int main(){
    int v[] = {3, 1, 5, 7, 2};
    int sizeV = 5, i;
    void (*fprint)(void*) = print_int;
//    GDList *L1 = GDList_create();
    for(i = 0; i < sizeV; i++)
//        GDList_insere_o(L1, &v[i], sizeof(v[i]), comp_int);
//    GDList_print(L1, fprint);    //  LINHA A
    return(0);
}
