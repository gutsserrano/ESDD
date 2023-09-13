#include "aluno.h"

struct cadastro_aluno {
    //char nome[50];
    int num;
    int prontuario;
};

Aluno criarAluno(int num, int p){
    Aluno aluno;

    aluno = malloc(sizeof(struct cadastro_aluno));

    //aluno->nome = n;
    aluno->num = num;
    aluno->prontuario = p;

    return aluno;
}

void destruir(Aluno dado){
    free(dado);
}

void printAluno(Aluno aluno){
    /*printf("Nome: ");
    for(int i = 0; i < (sizeof(aluno->nome)); i++){
        printf("%c", aluno->nome[i]);
    }*/
    printf("num: %d", aluno->num);
    printf("\n");
    printf("Prontuario: %d\n", aluno->prontuario);
}
