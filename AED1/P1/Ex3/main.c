int Pilha_desempilha(Pilha *pilha, int *in) {
    printf("\nPilha->info: %c\n", pilha->info);
    printf("\nPrim->info: %c\n", prim->info);
    int j = 0, i;
    Pilha *aux = prim;
    *in = 0;
    if((pilha->info) == (prim->info)){
        *in = 1;
    }
	if(prim == NULL){    //  lista vazia
        printf("\nLista Vazia\n");
        return 0;
	}
	else
		while(aux != NULL){	//	enquanto não houver objetos nulos, da direita
			j++;
			aux = aux->prox;
		}
    aux = prim;
    if((j !=0 ) && (j != 1)){
        for(i = 0; i < j-1; i++){
            if(i == j-2)
                aux->prox = 0;
            aux = aux->prox;
        }
    }
    else{
        prim = NULL;
    }
    return 1;
}
