#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    int *aptr, *bptr;

    scanf("%d%d", &a, &b);

    aptr = malloc(sizeof(int));
    bptr = malloc(sizeof(int));

    *aptr = a;
    *bptr = b;

    if(aptr > bptr){
        printf("\nA maior\n");
        printf("\nEndereco de memoria: %p valor: %d\n", aptr, *aptr);

    }else{
        printf("\nB maior\n");
        printf("\nEndereco de memoria: %p valor: %d\n", bptr, *bptr);
    }

    free(aptr);
    free(bptr);
    
    return 0;
}
