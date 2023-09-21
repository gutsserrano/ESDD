#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define MAX 5

int busca_sequencial(int file[], int size, int key);

int main(){
    int vetor[MAX] = {1, 2, 3, 4, 5};
    int achou = busca_sequencial(vetor, MAX, 1);

    if(achou){
        printf("\nA chave existe no arquivo\n\n");
    }else{
        printf("\nA chave nao existe no arquivo\n\n");
    }

    return 0;
}

int busca_sequencial(int file[], int size, int key){
    int founded = FALSE;
    for(int i = 0; i < size && file[i] <= key; i++){
        if(file[i] == key){
            founded = TRUE;
        }
    }
    return founded;
}