#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b);

int main(){
    int a, b;
    int *aptr, *bptr;

    scanf("%d%d", &a, &b);

    aptr = malloc(sizeof(int));
    bptr = malloc(sizeof(int));

    *aptr = a;
    *bptr = b;

    printf("\nA = %d\n", *aptr);
    printf("B = %d\n", *bptr);

    troca(aptr, bptr);

    printf("\n**VALORES TROCADOS**");
    printf("\nA = %d\n", *aptr);
    printf("B = %d\n\n", *bptr);

    free(aptr);
    free(bptr);

    return 0;
}

void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}
