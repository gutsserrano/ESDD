#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(){

    int *array_ptr;

    array_ptr = malloc(sizeof(int) * 10);

    for(int i = 0; i < MAX; i++){
        *(array_ptr + i) = (i+1) * 10;
    }

    for(int i = 0; i < MAX; i++){
        printf("\nArray[%d]: %d\n", i, *(array_ptr + i));
    }
    
    return 0;
}
