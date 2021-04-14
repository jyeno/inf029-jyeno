#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "utils.h"

Pessoa *
criaPessoa(char sexo, Ocupacao ocupacao, char *nome, char *nascimento, char *cpf)
{
    static int indexAluno = 1;
    static int indexProfessor = 10000;
    Pessoa *pessoa = calloc(1, sizeof(Pessoa));
    pessoa->ocupacao = ocupacao;
    pessoa->sexo = sexo;
    strncpy(pessoa->nome, nome, TAMANHO_NOME_PESSOA);
    strncpy(pessoa->nascimento, nascimento, TAMANHO_NASC);
    strncpy(pessoa->cpf, cpf, TAMANHO_CPF);
    if (ocupacao == PROFESSOR) {
        pessoa->matricula = indexProfessor;
        indexProfessor += 1;
    } else {
        pessoa->matricula = indexAluno;
        indexAluno += 1;
    }

    return pessoa;
}

void
registraPessoa(Pessoa **pessoas, Pessoa *pessoa)
{
    int i = 0;
    for (; pessoas[i]; i += 1);
    pessoas[i] = pessoa;
}

int
removePessoa(Pessoa **pessoas, int matricula)
{
    for (int i = 0; pessoas[i]; i += 1) {
        if (pessoas[i]->matricula == matricula) {
            free(pessoas[i]);
            shiftVetor((void **) pessoas, i);
            return 1;
        }
    }
    return 0;
}

void
atualizaPessoa(Pessoa *pessoa, char sexo, char *nome, char *nascimento, char *cpf)
{
    pessoa->sexo = sexo;
    strncpy(pessoa->nome, nome, TAMANHO_NOME_PESSOA);
    strncpy(pessoa->nascimento, nascimento, TAMANHO_NASC);
    strncpy(pessoa->cpf, cpf, TAMANHO_CPF);
}
void
incrementaContagemDeDisciplinas(Pessoa *pessoa)
{
    pessoa->numDisciplinas += 1;
}

void
decrementaContagemDeDisciplinas(Pessoa *pessoa)
{
    pessoa->numDisciplinas -= 1;
}

void
mostraPessoa(Pessoa *pessoa)
{
    if (pessoa->ocupacao == PROFESSOR) {
        printf("Professor\n");
    } else {
        printf("Aluno\n");
    }
    printf(" Nome: %s\n", pessoa->nome);
    printf(" Matricula: %d\t", pessoa->matricula);
    printf("Sexo: %c\n", pessoa->sexo);
    printf(" CPF: %s\t", pessoa->cpf);
    printf("Nascimento: %s\n", pessoa->nascimento);
}

int
listaPessoas(Pessoa **pessoas, Ocupacao ocupacao)
{
    int c = 0;
    for(int i = 0; pessoas[i]; i += 1) {
        if (pessoas[i]->ocupacao == ocupacao) {
            mostraPessoa(pessoas[i]);
            c += 1;
        }
    }
    return c;
}

int
listaPorSexo(Pessoa **pessoas, Ocupacao ocupacao, char sexo)
{
    int c = 0;
    for (int i = 0; pessoas[i]; i += 1) {
        if (pessoas[i]->ocupacao == ocupacao && pessoas[i]->sexo == sexo) {
            mostraPessoa(pessoas[i]);
            c += 1;
        }
    }
    return c;
}

int
listaPorNome(Pessoa **pessoas, Ocupacao ocupacao, int ordem/*, Ordenamento ordem*/)
{
    Pessoa **lista = calloc(sizeof(pessoas), sizeof(Pessoa));
    for (int i = 0, j = 0; pessoas[i]; i += 1) {
        if (pessoas[i]->ocupacao == ocupacao) {
            lista[j] = pessoas[i];
            j += 1;
        }
    }
    for (int i = 0; lista[i]; i += 1) {
        for(int j = i + 1; lista[j]; j += 1) {
            if (ordem == 1) {
                if (strcmp(lista[i]->nome, lista[j]->nome) > 0) {
                    Pessoa *temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            } else {
                if (strcmp(lista[i]->nome, lista[j]->nome) < 0) {
                    Pessoa *temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            }
        }
    }

    int i = 0;
    for (; lista[i]; i += 1) {
        mostraPessoa(lista[i]);
    }
    free(lista);
    return i;
}

int
listaPorNascimento(Pessoa **pessoas, Ocupacao ocupacao, int ordem)
{
    Pessoa **lista = calloc(50, sizeof(Pessoa));
    for (int i = 0, j = 0; pessoas[i]; i += 1) {
        if (pessoas[i]->ocupacao == ocupacao) {
            lista[j] = pessoas[i];
            j += 1;
        }
    }

    for (int i = 0; lista[i]; i += 1) {
        for(int j = i + 1; lista[j]; j += 1) {
            int anoPessoaI, mesPessoaI, diaPessoaI, anoPessoaJ, mesPessoaJ, diaPessoaJ;
            sscanf(lista[i]->nascimento, "%d/%d/%d", &anoPessoaI, &mesPessoaI, &diaPessoaI);
            sscanf(lista[j]->nascimento, "%d/%d/%d", &anoPessoaJ, &mesPessoaJ, &diaPessoaJ);
            if (ordem == 1) {
                if (anoPessoaJ < anoPessoaI || mesPessoaJ < mesPessoaI || diaPessoaJ < diaPessoaI) {
                    Pessoa *temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            } else {
                if (anoPessoaJ > anoPessoaI || mesPessoaJ > mesPessoaI || diaPessoaJ > diaPessoaI) {
                    Pessoa *temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            }
        }
    }

    int i = 0;
    for (; lista[i]; i += 1) {
        mostraPessoa(lista[i]);
    }
    free(lista);
    return i;
}

int
listaAniversariantes(Pessoa **pessoas, Ocupacao ocupacao, int mes)
{
    int c = 0;
    for(int i = 0; pessoas[i]; i += 1) {
        if(pessoas[i]->ocupacao == ocupacao && fazAniversarioNoMes(pessoas[i], mes)) {
            mostraPessoa(pessoas[i]);
            c += 1;
        }
    }
    return c;
}

int
fazAniversarioNoMes(Pessoa *pessoa, int mes)
{
    char mesStr[2];
    mesStr[0] = pessoa->nascimento[3];
    mesStr[1] = pessoa->nascimento[4];
    int mesAniversario = atoi(mesStr);
    return mesAniversario == mes;
}

int
ehAluno(Pessoa *pessoa)
{
    return pessoa->ocupacao == ALUNO;
}

int
alunoEstaEmMenosDe(Pessoa *pessoa, int minDisciplinas)
{
    if (ehAluno(pessoa)) {
        return pessoa->numDisciplinas < minDisciplinas;
    }
    return 0;
}

int
listaAlunosEmMenosDeDisciplinas(Pessoa **alunos, int minDisciplinas)
{
    int c = 0;
    for (int i = 0; alunos[i]; i += 1) {
        if (alunoEstaEmMenosDe(alunos[i], minDisciplinas)) {
            mostraPessoa(alunos[i]);
            c += 1;
        }
    }
    return c;
}

Pessoa *
buscaPessoa(Pessoa **pessoas, int matricula, Ocupacao ocupacao)
{
    for(int i = 0; pessoas[i]; i += 1) {
        if (pessoas[i]->matricula == matricula) {
            if (pessoas[i]->ocupacao != ocupacao) break;
            return pessoas[i];
        }
    }
    return NULL;
}

int
mostraBuscaPessoa(Pessoa **pessoas, char *nome)
{
    int contagem = 0;
    for(int i = 0; pessoas[i]; i += 1) {
        if (!strncmp(nome, pessoas[i]->nome, strlen(nome))) {
            contagem += 1;
            mostraPessoa(pessoas[i]);
        }
    }
    return contagem;
}

int
contagemDePessoas(Pessoa **pessoas, Ocupacao ocupacao)
{
    int contagem = 0;
    for (int i = 0; pessoas[i]; i += 1) {
        if (pessoas[i]->ocupacao == ocupacao) contagem += 1;
    }
    return contagem;
}
