#include "aluno.h"

int main()
{
    Aluno aluno;

    aluno = criarAluno(123, 3022404);

    printAluno(aluno);

    destruir(aluno);

    return 0;
}
