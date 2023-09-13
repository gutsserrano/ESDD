#include <stdio.h>
#include <stdlib.h>


typedef struct cadastro_aluno *Aluno;

Aluno criarAluno(/*char nome*/int num, int prontuario);
void destruir(Aluno dado);
void printAluno(Aluno);