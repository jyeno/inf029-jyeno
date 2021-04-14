#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define TAMANHO_NOME_DISC 40
#define TAMANHO_CODIGO_DISC 10
#define TAMANHO_SEMESTRE_DISC 8

#include "pessoa.h"

typedef struct {
    char nome[TAMANHO_NOME_DISC];
    char codigo[TAMANHO_CODIGO_DISC ];
    char semestre[TAMANHO_SEMESTRE_DISC];
    int vagasOcupadas;
    Pessoa *professor;
    Pessoa **alunos;
} Disciplina;

Disciplina *criaDisciplina(char *nome, char *codigo, char *semestre, Pessoa *professor);

void registraDisciplina(Disciplina **disciplinas, Disciplina *disciplina);

int removeDisciplina(Disciplina **disciplinas, char *codigo);

int atualizaDisciplina(Disciplina *disciplina, char *nome, char *codigo, char *semestre, Pessoa *professor);

void insereAluno(Disciplina *disciplina, Pessoa *aluno);

int removeAluno(Disciplina *disciplina, Pessoa *aluno);

int professorDahAula(Disciplina **disciplinas, Pessoa *professor);

int disciplinaExcedente(Disciplina *disciplina, int maxVagas);

int listaDisciplinasLotadas(Disciplina **disciplinas, int maxVagas);

void mostraDisciplina(Disciplina *disciplina);

int listaDisciplinas(Disciplina **disciplinas);

int listaAlunos(Disciplina *disciplina);

Disciplina *buscaDisciplina(Disciplina **disciplinas, char *codigo);

int contagemDeDisc(Disciplina **disciplinas);

#endif
