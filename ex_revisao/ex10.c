#include <stdio.h>
#include <stdlib.h>

int calcula(int *a, int *b);

int main(){
    int a, b;
    int *aptr, *bptr;
    int res;

    scanf("%d%d", &a, &b);

    aptr = malloc(sizeof(int));
    bptr = malloc(sizeof(int));

    *aptr = a;
    *bptr = b;

    res = calcula(aptr, bptr);

    printf("\nA = %d\tB = %d\n", *aptr, *bptr);
    printf("Resultado: %d\n\n", res);

    free(aptr);
    free(bptr);

    return 0;
}

int calcula(int *a, int *b){
  
    *a *= 2;
    *b *= 2;

    return *a + *b;
}