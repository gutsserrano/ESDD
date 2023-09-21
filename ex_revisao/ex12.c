#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(){
    float vetor[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float *vp[MAX];
    
    for(int i = 0; i < MAX; i++){
        vp[i] = malloc(sizeof(float));
        *vp[i] = vetor[i];
        printf("\n %p", vp[i]);
    }

    for(int i = 0; i < MAX; i++){
        free(vp[i]);
    }

    return 0;
}
