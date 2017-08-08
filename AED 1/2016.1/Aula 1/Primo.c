#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Digite o numero\n");
    int num;
    scanf("%d", &num);
    int i, k = 0;
    for(i = 2; i <= num/2; ++i){
        // condition for nonprime number
        if(num % i == 0){
            k = 1;
            break;
        }
    }
    if (k == 0)
        printf("%d is a prime number.", num);
    else
        printf("%d is not a prime number.", num);
    return 0;
}
