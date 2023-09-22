#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet;
    int n;
    int i = 0;

    vet = malloc(sizeof(int) * 10);

    do
    {

        printf("\nDigite o valor %d: ", i);
        scanf("%d", &n);
        if((vet + i) == NULL){
            vet = malloc(sizeof(int) * 10);
        }
        *(vet + i) = n;
        i++;

    } while (n != 0);
    
    
    for(int i = 0; *(vet + i) != NULL; i++){
        printf("\nVetor[%d]: %d", i, *(vet + i));
    }

    free(vet);

    return 0;
}
