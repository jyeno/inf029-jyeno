#ifndef MENU_H
#define MENU_H

#include "disciplina.h"
#include "pessoa.h"

void menuPessoa(Pessoa **pessoas, Disciplina **disciplinas, Ocupacao profissao);

void menuListaPessoas(Pessoa **pessoas, Ocupacao ocupacao, char *membrosStr);

void menuDisciplina(Disciplina **disciplinas, Pessoa **pessoas);

void menuDetalhaDisciplina(Disciplina *disciplina, Pessoa **pessoas);

int menuMain();

#endif
