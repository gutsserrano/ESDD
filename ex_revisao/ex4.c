#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insert_sort(int[], int);
void imprime_vetor(int colecao[], int tamanho);

int main(){
    int vetor[MAX] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};

    insert_sort(vetor, MAX);

    return 0;
}

void insert_sort(int colecao[], int tamanho){
	
	int i, j, elemento_auxiliar;
    int trocas;
    

	for(i=1; i<tamanho; i++){
		elemento_auxiliar = colecao[i];
		
		for(j = i-1; j >= 0 && colecao[j] > elemento_auxiliar; j--){
			colecao[j+1] = colecao[j];
            trocas++;
		}
		colecao[j+1] = elemento_auxiliar;
        trocas++;
	}

    imprime_vetor(colecao, MAX);
	printf("\nTrocas: %d\n\n", trocas);
}

void imprime_vetor(int colecao[], int tamanho){
	int i=0;

    printf("\n**VETOR ORDENADO**\n");
	for(i=0; i < tamanho; i++){
		printf("%d, ", colecao[i]);
	}
	printf("\n");
}