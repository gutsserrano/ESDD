#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000000
#define TRUE 1
#define FALSE 0

struct sequencial_index{
    int value;
    int pos;
};

void gera_vet(int vetor[]);
void gera_kindex(int vetor[], struct sequencial_index tab[], int tamanho, int intervalo);
int busca(int vetor[], struct sequencial_index tab[], int key, int intervalo);

int main(int argc, char const *argv[]){
    int vetor[MAX];
    int intervalo = 1000;
    int key = 178354;
    struct sequencial_index kindex[MAX / intervalo + 1];
    int achou;
    int posi;

    gera_vet(vetor);
    gera_kindex(vetor, kindex, MAX, intervalo);

    posi = busca(vetor, kindex, key, intervalo);

    if(posi >= 0){
        printf("\nA chave %d existe no vetor!", key);
        printf("\n[%d]: %d\n", posi, vetor[posi]);
    }else{
        printf("\nA chave %d nao existe no vetor!\n", key);
    }
    
    return 0;
}

void gera_vet(int vetor[]){
    srand( (unsigned) time(NULL) );
    vetor[0] = 10;
    
    for(int i = 1; i < MAX; i++){
        vetor[i] = vetor[i - 1] + (rand() % 10) + 1;
    }
}

void gera_kindex(int vetor[], struct sequencial_index tab[], int tamanho, int intervalo){
    int i = 0;

    for(i = 0; i < tamanho / intervalo; i++){
        tab[i].pos = i * intervalo;
        tab[i].value = vetor[i * intervalo];
    }
    
    tab[i].pos = tamanho - 1;
    tab[i].value = vetor[tamanho - 1];
}

int busca(int vetor[], struct sequencial_index tab[], int key, int intervalo){
    int ntem = TRUE;
    int achou = -1;
    int i;
    int j;

    for(i = 1; i <= MAX / intervalo && achou == -1 && ntem; i++){
        if(key <= tab[i].value){
            for(j = tab[i-1].pos; j <= tab[i].pos && achou == -1; j++){
                if(key == vetor[j]){
                    achou = j;
                }
            }
            if(achou == -1){
                ntem = FALSE;
            }
        }
    }

    return achou;
}
