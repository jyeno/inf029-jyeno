#ifndef PESSOA_H
#define PESSOA_H

#define TAMANHO_NOME_PESSOA 35
#define TAMANHO_NASC 11
#define TAMANHO_CPF 15

typedef enum { PROFESSOR, ALUNO, INVALIDO } Ocupacao;

typedef struct {
    int matricula;
    char sexo;
    Ocupacao ocupacao;
    char nome[TAMANHO_NOME_PESSOA];
    char nascimento[TAMANHO_NASC];
    char cpf[TAMANHO_CPF];
    int numDisciplinas;
} Pessoa;

Pessoa *criaPessoa(char sexo, Ocupacao ocupacao, char *nome, char *nascimento, char *cpf);

void registraPessoa(Pessoa **pessoas, Pessoa *pessoa);

int removePessoa(Pessoa **pessoas, int matricula);

void atualizaPessoa(Pessoa *pessoa, char sexo, char *nome, char *nascimento, char *cpf);

void mostraPessoa(Pessoa *pessoa);

int listaPessoas(Pessoa **pessoas, Ocupacao ocupacao);

int listaPorSexo(Pessoa **pessoas, Ocupacao ocupacao, char sexo);

int listaPorNome(Pessoa **pessoas, Ocupacao ocupacao, int ordem);

int listaPorNascimento(Pessoa **pessoas, Ocupacao ocupacao, int ordem);

int listaAniversariantes(Pessoa **pessoas, Ocupacao ocupacao, int mes);

int fazAniversarioNoMes(Pessoa *pessoa, int mes);

int ehAluno(Pessoa *pessoa);

int alunoEstaEmMenosDe(Pessoa *pessoa, int minDisciplinas);

void incrementaContagemDeDisciplinas(Pessoa *pessoa);

void decrementaContagemDeDisciplinas(Pessoa *pessoa);

int listaAlunosEmMenosDeDisciplinas(Pessoa **alunos, int minDisciplinas);

Pessoa *buscaPessoa(Pessoa **pessoas, int matricula, Ocupacao ocupacao);

int mostraBuscaPessoa(Pessoa **pessoas, char *nome);

int contagemDePessoas(Pessoa **pessoas, Ocupacao ocupacao);

#endif
