#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define TRUE 1
#define FALSE 0

void analisa(char *a, char *b);

int main(){
    char a[MAX] = "imoveis";
    char b[MAX] = "moveis";
    
    analisa("imoveis", "moveis");

    return 0;
}

void analisa(char *a, char *b){
    int existe = FALSE;

    for (int i = 0; i < MAX && !existe; i++){
        
        int j = 0;
        while(j < MAX && *b[j] != '\0'){
            if(*b[j] == *a[i]){
                j++;
            }
        }

    }
    
}


