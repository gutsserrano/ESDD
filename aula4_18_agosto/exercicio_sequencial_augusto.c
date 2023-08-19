#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 25
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
    int intervalo = 5;
    int key = 124;
    struct sequencial_index kindex[MAX];
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
    //srand( (unsigned) time(NULL) );
    vetor[0] = 10;
    
    for(int i = 1; i < MAX; i++){
        vetor[i] = vetor[i - 1] + (rand() % 10) + 1;
    }

    for(int i = 0; i<MAX; i++){
        printf("[%d] = %d\n", i, vetor[i]);
    }
}

void gera_kindex(int vetor[], struct sequencial_index tab[], int tamanho, int intervalo){

    for(int i = 0; i<=intervalo; i++){
        tab[i].pos = i*intervalo;
        tab[i].value = vetor[i*intervalo];
    }
    
}

int busca(int vetor[], struct sequencial_index tab[], int key, int intervalo){
    int ntem = TRUE;
    int achou = -1;
    int i;
    int j;

    for(i = 1; i < MAX/intervalo && achou == -1 && ntem; i++){
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
    for(int k = 0; k<MAX/intervalo;k++){
    printf("pos %d ", tab[k].pos);
    printf("value %d\n", tab[k].value);
        
    }

    return achou;
}


