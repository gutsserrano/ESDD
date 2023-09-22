#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define TRUE 1
#define FALSE 0


int main(){
    char *a;
    char *b;

    a = malloc(sizeof(char) * MAX);
    b = malloc(sizeof(char) * MAX);

    

    free(a);
    free(b);

    return 0;
}

