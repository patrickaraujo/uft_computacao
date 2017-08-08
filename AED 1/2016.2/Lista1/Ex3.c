#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y, z;
} vetor;

void sum(const vetor *v1, const vetor *v2, vetor *r) {
    r->x = v1->x + v2->x, r->y = v1->y + v2->y, r->z = v1->z + v2->z;
}

float produto(const vetor *v1, const vetor *v2) {
    return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

int main(){
    vetor a = {1.2, 2.5, 3.7}, b = {3.3, 4.7, 5.1}, r;
    sum(&a, &b, &r);
    printf("Soma vetorial = <%f, %f, %f>\n", r.x, r.y, r.z);
    printf("Produto Escalar = %f\n", (produto(&a, &b)));
    return 0;
}
