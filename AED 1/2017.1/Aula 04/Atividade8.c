#include <stdio.h>
#include <string.h>

int main(){
    system("clear");

    int vet[3] = {4, 9, 12};
    int i, *ptr;
    ptr = vet;
    for(i = 0; i < 3; i++)
        printf("%d ", *(ptr++));
    printf("\n\n");
    return 0;
}
