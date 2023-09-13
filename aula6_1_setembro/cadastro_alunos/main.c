#include "aluno.h"
#include "aluno.c"

int main()
{
    Aluno aluno;

    aluno = criarAluno(123, 3022404);

    printAluno(aluno);

    destruir(aluno);

    return 0;
}
