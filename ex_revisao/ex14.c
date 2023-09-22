#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    int *vet;
    int par = 0, impar = 0;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &size);

    vet = malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++){
        int n = 0;
        printf("\nDigite o valor [%d] do vetor: ", i);
        scanf("%d", &n);
        *(vet + i) = n;
        if(n % 2 == 0){
            par++;
        }else{
            impar++;
        }
    }

    for(int i = 0; i < size; i++){
        printf("\nVetor[%d]: %d", i, *(vet + i));
    }

    printf("\n\nPares: %d", par);
    printf("\nImpares: %d\n\n", impar);

    return 0;
}
