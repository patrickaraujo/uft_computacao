#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* alphabet: [a-z0-9] */

const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
const int b = 8;
const int no = 2;

/**
 * not a cryptographically secure number
 * return interger [0, n).
 */

int intN(int n) {
    return rand() % n;
}

/**
 * Input: length of the random string [a-z0-9] to be generated
 */

char *randomString(int len) {
    char *rstr = malloc((len + 1) * sizeof(char));
    int i;
    for (i = 0; i < len; i++) {
        rstr[i] = alphabet[intN(strlen(alphabet))];
    }
    rstr[len] = '\0';
    return rstr;
}

int* bin(char a){
    int i = 0;
    int *output = calloc(8, sizeof(int));
    for (i = 0; i <8 ; ++i) {
        output[8-i-1] = (a >> i) & 1;
    }
    return output;
}

/*
typedef struct{
    TData* data;
} AoadBin;

AoadBin* AoadBin_add(int qty){
    AoadBin* nova = (TStaticList*) malloc(sizeof(TStaticList));
    int i;
    if (nova){
        nova->count = 0;
        nova->MAX = qty;
        nova->data = (TData*) calloc(qty, sizeof(TData));
        if (nova->data == NULL)
            return NULL;
    }return nova;
}
*/

int** strToBin(char *str, int linhas){
	int **array2d;
	int i, j;
    array2d = malloc(linhas * sizeof(int *));
    for ( i = 0; i < linhas; i++ ) {
        array2d[i] = malloc(b*sizeof(int));
        array2d[i] = bin(str[i]);
    }
    return array2d;
}

int* quantoFind(int *y){
	int i = 0;
	int j;
	int *occ = malloc(no * sizeof(int *));
	for(j = 0; j < b; j++)
        if(1 == y[j]){
            occ[i] = j;
            i++;
        }

	if(i == no){
        return occ;
	}
	exit(0);
    return NULL;
}

void imprime(int *m, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d", m[i]);
}

int* result(int *msg1, int *msg2, int *index, int x, int y){
    int j = 0;
    int i;
    printf("\n");
    imprime(msg1, 8);
    printf("\nmsg2: ");
    imprime(msg2, 8);
    printf("\n\nindex1: %d\n", index[0]);
    printf("\n\nindex2: %d\n", index[1]);

    for(i = b-x; i < b-y; i++){
        printf("\nidw: %i", i);
        printf("\nthis: %i", msg1[i]);
        msg2[index[j]] = msg1[i];
        j++;
        printf("\nfuckery: ");
    imprime(msg2, 8);
    }

}

int** convert(int **msg1, int **msg2, int *index, int tam){
	int k = 0, i, j;
    for(i = 0; i < tam; i++){
        for(j = 0; j < 4; j++){
            printf("\ni: %i", i);
            result(msg1[i], msg2[k], index, ((j+1)*2), (j*2));
            printf("\nk: %i", k);
            k++;
        }

    }
}

int main(){
    char msg1 [] =  {"hello"};
    int n = (4*strlen(msg1));
    char *msg2 = randomString(n);
    printf("%s", msg2);
    int mask = 12;
    int *msgBin = bin(mask);
    int *id = quantoFind(msgBin);
    printf("\n%i em binário: ", mask);
    imprime(msgBin, b);
    int** msg1Bin = strToBin(msg1, strlen(msg1));
    int** msg2Bin = strToBin(msg2, strlen(msg2));
    int** done = convert(msg1Bin, msg2Bin, id, strlen(msg1));
}
