#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disciplina.h"
#include "utils.h"

#define QTD_DISCIPLINA 50

Disciplina *
criaDisciplina(char *nome, char *codigo, char *semestre, Pessoa *professor)
{
    Disciplina * disciplina = calloc(1, sizeof(Disciplina));
    strncpy(disciplina->nome, nome, TAMANHO_NOME_DISC);
    strncpy(disciplina->codigo, codigo, TAMANHO_CODIGO_DISC);
    strncpy(disciplina->semestre, semestre, TAMANHO_SEMESTRE_DISC);
    disciplina->professor = professor;
    disciplina->alunos = calloc(QTD_DISCIPLINA, sizeof(Pessoa*));

    return disciplina;
}

void
registraDisciplina(Disciplina **disciplinas, Disciplina *disciplina)
{
    int i = 0;
    for (; disciplinas[i]; i += 1);
    disciplinas[i] = disciplina;
    // verificar tamanho
}

int
removeDisciplina(Disciplina **disciplinas, char *codigo)
{
    for (int i = 0; disciplinas[i]; i += 1) {
        if (!strncmp(disciplinas[i]->codigo, codigo, 7)) {
            free(disciplinas[i]->alunos);
            free(disciplinas[i]);
            shiftVetor((void**) disciplinas, i);
            return 1;
        }
    }
    return 0;
}

int
atualizaDisciplina(Disciplina *disciplina, char *nome, char *codigo, char *semestre, Pessoa *professor)
{
    strncpy(disciplina->nome, nome, TAMANHO_NOME_DISC);
    strncpy(disciplina->codigo, codigo, TAMANHO_CODIGO_DISC);
    strncpy(disciplina->semestre, semestre, TAMANHO_SEMESTRE_DISC);
    disciplina->professor = professor;
    return 0;
}

void
mostraDisciplina(Disciplina *disciplina)
{
    printf("Disclipina %s\n", disciplina->nome);
    printf(" codigo:  %s\n", disciplina->codigo);
    printf(" semestre: %s\n", disciplina->semestre);
    printf(" professor:  %s\n", disciplina->professor->nome);
    printf(" Vagas ocupadas:  %d\n", disciplina->vagasOcupadas);
}

int
disciplinaExcedente(Disciplina *disciplina, int maxVagas)
{
    return disciplina->vagasOcupadas > maxVagas;
}

int
listaDisciplinasLotadas(Disciplina **disciplinas, int maxVagas)
{
    int c = 0;
    for (int i = 0; disciplinas[i]; i += 1) {
        if (disciplinaExcedente(disciplinas[i], maxVagas)) {
            mostraDisciplina(disciplinas[i]);
            c += 1;
        }
    }
    return c;
}

int
listaDisciplinas(Disciplina **disciplinas)
{
    int i = 0;
    for (; disciplinas[i]; i += 1) {
        mostraDisciplina(disciplinas[i]);
    }
    return i;
}

void
insereAluno(Disciplina *disciplina, Pessoa *aluno)
{
    int i = 0;
    for (; disciplina->alunos[i]; i += 1);
    disciplina->alunos[i] = aluno;
    disciplina->vagasOcupadas += 1;
    incrementaContagemDeDisciplinas(aluno);
}

int
removeAluno(Disciplina *disciplina, Pessoa *pessoa)
{
    for (int i = 0; disciplina->alunos[i]; i += 1) {
        if (disciplina->alunos[i] == pessoa) {
            decrementaContagemDeDisciplinas(disciplina->alunos[i]);
            shiftVetor((void **) disciplina->alunos, i);
            return 1;
        }
    }
    return 0;
}

int
professorDahAula(Disciplina **disciplinas, Pessoa *professor)
{
    for (int i = 0; disciplinas[i]; i += 1) {
        if (disciplinas[i]->professor == professor) {
            return 1;
        }
    }
    return 0;
}

Disciplina *
buscaDisciplina(Disciplina **disciplinas, char *codigo)
{
    for (int i = 0; disciplinas[i]; i += 1) {
        if (!strcmp(disciplinas[i]->codigo, codigo)) return disciplinas[i];
    }
    return NULL;
}

int
contagemDeDisc(Disciplina **disciplinas)
{
    int contagem = 0;
    for (; disciplinas[contagem]; contagem += 1);
    return contagem;
}

int
listaAlunos(Disciplina *disciplina)
{
    int i = 0;
    for (; disciplina->alunos[i]; i += 1) {
        mostraPessoa(disciplina->alunos[i]);
    }
    return i;
}
