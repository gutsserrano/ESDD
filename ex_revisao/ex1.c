#include <stdio.h>
#define MAX 5

void analisa(int vetor[]);

int main(){
    int vetor[MAX] = {1, 2, 2, 4, 5};

    analisa(vetor);

    return 0;
}

void analisa(int vetor[]){
    //int ordenado;
    int count = 0;

    for(int i = 0; i < MAX-1; i++){
        if(vetor[i] <= vetor[i+1]){
            count++;
        }
    }

    if(count == MAX-1){
        printf("\n**ORDENADO**\n");
    }else{
        printf("\n**NAO ORDENADO");
    }

}
