#include <stdio.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

void insere(int vetor[]);

int main(){
    int vetor[MAX + 1] = {1, 2, 3, 4, 5};

    insere(vetor);

    return 0;
}

void insere(int vetor[]){
    int key;
    int achou = FALSE;
    int save;

    printf("\nDigite o valor a ser buscado: ");
    scanf("%d", &key);

    printf("\n**ANTES**\n");
    for(int i = 0; i < MAX; i++){
        printf("vetor[%d]: %d\n", i, vetor[i]);
    }

    for(int i = 0; i < MAX && achou == FALSE; i++){
        if(key <= vetor[i]){
            save = i;
            achou = TRUE;
        }

    }
    
    for(int i = MAX+1; i > save && achou; i--){
        vetor[i] = vetor[i-1];
    } 
    
    if(!achou){
        save = MAX+1;
        vetor[save] = key;
    }else{
       vetor[save] = key; 
    }
    

    printf("\n**DEPOIS**\n");
    for(int i = 0; i < MAX+1; i++){
        printf("vetor[%d]: %d\n", i, vetor[i]);
    }
}
