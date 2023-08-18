#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10000
#define TRUE 1
#define FALSE 0

void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho);
void carrega_vetor_inverso(int colecao[], int valor_inicial, int tamanho);
void carrega_vetor_aleatorio(int colecao[], int tamanho, int qtd_digitos);
void copia_vetor(int colecao[], int copia[]);
void imprime_vetor(int colecao[], int tamanho);
void selection_sort(int[], int);
void bubble_sort(int[], int);
void insert_sort(int colecao[], int tamanho);
void chama_merge(int colecao[]);
void merge(int[], int, int, int *, int *);
void intercala(int[], int, int, int, int *, int *);
void quicksort(int x[], int lb, int ub);
void partition(int x[], int lb, int ub, int *j);
void chama_quick(int colecao[]);


int main(/*int argc, char const *argv[]*/){
    int vetor[MAX];

    //carrega_vetor_aleatorio(vetor, MAX, 3);
	carrega_vetor_ordenado(vetor, 0, MAX);
	//carrega_vetor_inverso(vetor, MAX, MAX);
	//imprime_vetor(vetor, MAX);

    bubble_sort(vetor, MAX);
    selection_sort(vetor, MAX);
	insert_sort(vetor, MAX);
	chama_merge(vetor);
	chama_quick(vetor);


    return 0;
}

void carrega_vetor_aleatorio(int colecao[], int tamanho, int qtd_digitos){
	int i, digitos;
	
	for(i=1, digitos = 10; i < qtd_digitos; i++){
		digitos *= 10;
	}
	
	srand( (unsigned) time(NULL) );
	for(i=0; i < tamanho; i++){
		colecao[i] = rand() % digitos;
	}
	
}

void imprime_vetor(int colecao[], int tamanho){
	int i=0;
	for(i=0; i < tamanho; i++){
		printf("%d, ", colecao[i]);
	}
	printf("\n");
}

void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho){
	int i;

	srand( (unsigned) time(NULL) );
	for(colecao[0] = valor_inicial, i=1; i<tamanho; i++){
		colecao[i] = colecao[i-1] + (rand() % 10);
	}
}

void carrega_vetor_inverso(int colecao[], int valor_inicial, int tamanho){
	int i;

	srand( (unsigned) time(NULL) );
	for(colecao[0] = valor_inicial, i=1; i<tamanho; i++){
		colecao[i] = colecao[i-1] - (rand() % 10);
	}
}

void copia_vetor(int colecao[], int copia[]){
    for(int i = 0; i < MAX; i++){
        copia[i] = colecao[i];
    }
}

void bubble_sort(int colecao[], int tamanho){
    //imprime_vetor(colecao, MAX);
    int copia[MAX];
    copia_vetor(colecao, copia);
	int i, j, elemento_auxiliar;
    long int troca = 0, compara = 0;
	int trocou = TRUE;

    /* troca = 0;
    compara = 0; */

    double time_spent = 0.0;

    clock_t begin = clock();   
	
	for(i=0; i<tamanho && trocou; i++){
		trocou = FALSE;
		for(j=0; j < tamanho-(1+i); j++){
			if(copia[j] > copia[j+1]){
				elemento_auxiliar = copia[j];
				copia[j] = copia[j+1];
				copia[j+1] = elemento_auxiliar;
				trocou = TRUE;
                troca++;
			}
            compara++;
		}
    }	

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    //imprime_vetor(copia, MAX);

    printf("\n**Bubble Sort**\n");

    printf("\nComparacoes: %ld", compara);
    printf("\nTrocas: %ld", troca);
    printf("\nTempo: %f segundos\n", time_spent);
}

void selection_sort(int colecao[], int tamanho){
    int copia[MAX];
    copia_vetor(colecao, copia);
    long int compara = 0, troca = 0;
	int i, j, pos_menor, elemento_auxiliar;
	
    double time_spent = 0.0;

    clock_t begin = clock();
	for(i=0; i<tamanho; i++){
		pos_menor = i;
		for(j=i+1; j<tamanho; j++){
			if(copia[j] < copia[pos_menor]){
				pos_menor = j;
			}
            compara++;
		}
		elemento_auxiliar = copia[i];
		copia[i] = copia[pos_menor];
		copia[pos_menor] = elemento_auxiliar;
        troca++;
	}
    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n**Selection Sort**\n");
    printf("\nComparacoes: %ld", compara);
    printf("\nTrocas: %ld", troca);
    printf("\nTempo: %f segundos\n", time_spent);

}

void insert_sort(int colecao[], int tamanho){
	int copia[MAX];
	copia_vetor(colecao, copia);
	
	int i, j, elemento_auxiliar;
	long int compara = 0, troca = 0;
	double time_spent = 0.0;

    clock_t begin = clock();
	for(i=1; i<tamanho; i++){
		elemento_auxiliar = copia[i];
		
		for(j = i-1; j >= 0 && copia[j] > elemento_auxiliar; j--){
			compara++;
			copia[j+1] = copia[j];
		}
		copia[j+1] = elemento_auxiliar;
		troca++;
	}
	clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n**Insert Sort**\n");
    printf("\nComparacoes: %ld", compara);
    printf("\nTrocas: %ld", troca);
    printf("\nTempo: %f segundos\n", time_spent);
}

void chama_merge(int colecao[]){
	int copia[MAX];
	copia_vetor(colecao, copia);
	int compara = 0, troca = 0;

	double time_spent = 0.0;
    clock_t begin = clock();
	merge(copia, 0, MAX-1, &compara, &troca);
	clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n**Merge Sort**\n");
    printf("\nComparacoes: %d", compara);
    printf("\nTrocas: %d", troca);
    printf("\nTempo: %f segundos\n", time_spent);
	
}

void merge(int colecao[], int inicio, int fim, int * compara, int * troca){
	int meio;
	if(inicio < fim){
		meio = (inicio + fim) / 2;
		merge(colecao, inicio, meio, compara, troca);
		merge(colecao, meio+1, fim, compara, troca);
		intercala(colecao, inicio, fim, meio, compara, troca);
	}
}

void intercala(int colecao[], int inicio, int fim, int meio, int * compara, int * troca){
	int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
	int arquivo_aux[MAX];
	inicio_arquivo1 = inicio;
	inicio_arquivo2 = meio + 1;
	pos_livre = inicio;
	while(inicio_arquivo1 <= meio && inicio_arquivo2 <= fim){
		if(colecao[inicio_arquivo1] <= colecao[inicio_arquivo2]){
			arquivo_aux[pos_livre] = colecao[inicio_arquivo1];
			inicio_arquivo1 += 1;
		} 
		else
		{
			arquivo_aux[pos_livre] = colecao[inicio_arquivo2];
			inicio_arquivo2 += 1;
		}
		compara++;
		pos_livre += 1;
	}
	for(i=inicio_arquivo1; i<= meio; i++, pos_livre++){
		arquivo_aux[pos_livre] = colecao[i];
		troca++;
	}
	for(i=inicio_arquivo2; i<= fim; i++, pos_livre++){
		arquivo_aux[pos_livre] = colecao[i];
		troca++;
	}
	for(i=inicio; i <= fim; i++){
		colecao[i] = arquivo_aux[i];
		troca++;
	}
}

void quicksort(int x[], int lb, int ub){

    int j = -1;

    if(lb >= ub)
        return;

    partition(x, lb, ub, &j);
    quicksort(x, lb, j-1);
    quicksort(x, j+1, ub);

}

void partition(int x[], int lb, int ub, int *j){

    int a, down, up, temp;

    a = x[lb];

    up = ub;
    down = lb;

    while(down < up){
        while(x[down] <= a && down < ub){
            down++;
        }
        while(x[up] > a){
            up--;
        }
        if(down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *j = up;
}

void chama_quick(int colecao[]){
	int copia[MAX];
	copia_vetor(colecao, copia);

	double time_spent = 0.0;
    clock_t begin = clock();
	quicksort(colecao, 0, MAX-1);
	clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n**Quick Sort**\n");
    //printf("\nComparacoes: %d", compara);
    //printf("\nTrocas: %d", troca);
    printf("\nTempo: %f segundos\n", time_spent);


}