#include <stdio.h>

#define MAX 14

void ordena(int vetor[], int size);

int main(){

    int vetor[MAX] = {5,5,3,3,3,2,1,4,4,4,4,6,5,6};

    ordena(vetor, MAX);

    return 0;
}

void ordena(int vetor[], int size){

    int flag = 0;
    int count[size];
    int saida[size];

    for(int i = 0; i < size; i++){
        flag = 0;
        for(int j = 0; j < size; j++){
            if(vetor[j] < vetor[i]){
                flag++;
            }
        }
        count[i] = flag;
    }

    for(int i = 0; i < size; i++){
        printf("Count[%d]: %d\n", i, count[i]);
    }

    for(int i = 0; i < size; i++){
        saida[i] = 0;
    }

    for(int i = 0; i < size; i++){
        int find = 0;
        for(int j = 0; j < size; j++){
            if(saida[j] == vetor[i]){
                find++;
            }
        }

        if(find != 0){
            saida[count[i]+find] = vetor[i];
        }else{
            saida[count[i]] = vetor[i];
        }
    }

    printf("**** Ordenado ****\n");

    for(int i = 0; i < size; i++){
        printf("Saída[%d]: %d\n", i, saida[i]);
    }

}
