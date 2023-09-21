#include <stdio.h>
#include <stdlib.h>

void calcula(int *a, int *b);

int main(){
    int a, b;
    int *aptr, *bptr;

    scanf("%d%d", &a, &b);

    aptr = malloc(sizeof(int));
    bptr = malloc(sizeof(int));

    *aptr = a;
    *bptr = b;

    calcula(aptr, bptr);

    printf("\nA = %d\tB = %d\n\n", *aptr, *bptr);

    free(aptr);
    free(bptr);

    return 0;
}

void calcula(int *a, int *b){
    *a = *a + *b;
}
