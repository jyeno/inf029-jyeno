#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "utils.h"

#define MAXMEMBROS 100
#define MAXDISC 15
#define MAXVAGAS 5

int
menuMain()
{
    Pessoa **membros = calloc(MAXMEMBROS, sizeof(Pessoa));
    Disciplina **disciplinas = calloc(MAXDISC, sizeof(Disciplina));

    int opcao = 0;
    while (opcao != 5) {
        printf("== == Projeto Escola == ==\n");
        printf("Alunos: %d  Professores: %d  Disciplinas: %d\n\n", contagemDePessoas(membros, ALUNO), contagemDePessoas(membros, PROFESSOR), contagemDeDisc(disciplinas));
        opcao = leNumero("1) Disciplinas    2) Alunos   3) Professores   4) Busca pessoa  5) Sair\n");
        if (opcao == 1) {
            menuDisciplina(disciplinas, membros);
        } else if (opcao == 2) {
            menuPessoa(membros, disciplinas, ALUNO);
        } else if (opcao == 3) {
            menuPessoa(membros, disciplinas, PROFESSOR);
        } else if (opcao == 4) {
            char nome[35];
            printf("nome: ");
            scanf(" %35s%*c", nome);
            int qtdMatch = mostraBuscaPessoa(membros, nome);
            if (!qtdMatch) printf("Nao ha pessoas com esse nome.\n");
        } else if (opcao == 5) {
            printf("Saindo...\n");
        } else {
            printf("Entrada invalida.\n\n");
        }
    }
    return 0;
}

void
menuDisciplina(Disciplina **disciplinas, Pessoa **pessoas)
{
    int opcao;
    while(0xBEEF) {
        printf("\n -- Disciplinas --\n");
        opcao = leNumero("1) Listar    2) Cadastrar   3) detalhar   4) Lotadas   5) Remove disciplina   6) Alunos com baixa carga horaria   7) Voltar\n");
        if (opcao == 1) {
            int qtdDisc = listaDisciplinas(disciplinas);
            if (qtdDisc == 0) printf("Ainda nao ha disciplinas.\n");
        } else if (opcao == 2) {
            if (contagemDePessoas(pessoas, PROFESSOR) != 0) {
                char *nome = leString("nome: ", TAMANHO_NOME_DISC, SEMVALIDACAO);
                char *codigo = leString("codigo (LLLNNN): ", TAMANHO_CODIGO_DISC, CODIGODISCIPLINA);
                char *semestre = leString("semestre (NNNN.NN): ", TAMANHO_SEMESTRE_DISC, SEMESTRE);
                listaPessoas(pessoas, PROFESSOR);
                int matricula = leNumero("matricula do professor: ");
                Pessoa *professor = buscaPessoa(pessoas, matricula, PROFESSOR);
                if (professor) {
                    Disciplina *disciplina = criaDisciplina(nome, codigo, semestre, professor);
                    registraDisciplina(disciplinas, disciplina);
                } else {
                    printf("Matricula do professor nao encontrada.\n");
                }
                free(nome);
                free(codigo);
                free(semestre);
            } else {
                printf("Registre um professor primeiro.\n");
            }
        }
        else if (opcao == 3) {
            char *codigo = leString("codigo (LLLNNN): ", TAMANHO_CODIGO_DISC, CODIGODISCIPLINA);
            Disciplina *disciplina = buscaDisciplina(disciplinas, codigo);
            if (disciplina) {
                menuDetalhaDisciplina(disciplina, pessoas);
            } else {
                printf("Entrada invalida.\n");
            }
            free(codigo);
        } else if (opcao == 4) {
            int qtdDisc = listaDisciplinasLotadas(disciplinas, MAXVAGAS);
            if (qtdDisc == 0) printf("Nao ha disciplinas lotadas.\n");
        } else if (opcao == 5) {
            char *codigo = leString("codigo (LLLNNN): ", TAMANHO_CODIGO_DISC, CODIGODISCIPLINA);
            if (!removeDisciplina(disciplinas, codigo)) {
                printf("disciplina nao encontrada.\n");
            }
        } else if (opcao == 6) {
            int qtdAlunos = listaAlunosEmMenosDeDisciplinas(pessoas, 3);
            if (qtdAlunos == 0) printf("Sem alunos com pouca carga horaria.\n");
        } else if (opcao == 7) {
            break;
        } else {
            printf("Entrada invalida.\n");
        }
    }
}

void
menuPessoa(Pessoa **pessoas, Disciplina **disciplinas, Ocupacao profissao)
{
    int opcao;
    const int tamanhoMax = 12;
    char menuIntro[tamanhoMax];
    if (profissao == PROFESSOR) {
        snprintf(menuIntro, tamanhoMax, "professores");
    } else {
        snprintf(menuIntro, tamanhoMax, "alunos");
    }

     while (0xC0C0) {
        printf("\n -- Menu %s --\n", menuIntro);
        opcao = leNumero("1) Menu Listar    2) listar todos   3) Cadastrar   4) detalhar   5) Remover   6) Modificar   7) Voltar\n");
        if (opcao == 1) {
            menuListaPessoas(pessoas, profissao, menuIntro);
        } else if (opcao == 2) {
            int qtdPessoas = listaPessoas(pessoas, profissao);
            if (qtdPessoas == 0) printf("Ainda nao ha %s.\n", menuIntro);
        } else if (opcao == 3) {
            char *nome = leString("nome: ", TAMANHO_NOME_PESSOA, SEMVALIDACAO);
            char *nascimento = leString("data de nascimento (DD/MM/AAAA): ", TAMANHO_NASC, DATA);
            char *cpf = leString("CPF (NNN.NNN.NNN-NN): ", TAMANHO_CPF, CPF);
            char sexo = leSexo();
            Pessoa *pessoa = criaPessoa(sexo, profissao, nome, nascimento, cpf);
            registraPessoa(pessoas, pessoa);

            free(nome);
            free(nascimento);
            free(cpf);
        }
        else if (opcao == 4) {
            int matricula = leNumero("matricula: ");
            Pessoa *pessoa = buscaPessoa(pessoas, matricula, profissao);
            if (pessoa) {
                mostraPessoa(pessoa);
            } else {
                printf("Matricula nao encontrada.\n");
            }
        } else if (opcao == 5) {
            int matricula = leNumero("matricula: ");
            Pessoa *pessoa = buscaPessoa(pessoas, matricula, profissao);
   
            if (pessoa) {
                if (profissao == PROFESSOR) {
                    if (professorDahAula(disciplinas, pessoa)) {
                        printf("Primeiro substitua o professor em suas disciplinas.\n");
                    } else {
                        removePessoa(pessoas, matricula);
                    }
                } else {
                    for (int i = 0; disciplinas[i]; i += 1) {
                        removeAluno(disciplinas[i], pessoa);
                    }
                    removePessoa(pessoas, matricula);
                }
            } else {
                printf("Matricula nao encontrada.\n");
            }
        } else if (opcao == 6) {
            int matricula = leNumero("matricula: ");
            Pessoa *pessoa = buscaPessoa(pessoas, matricula, profissao);
            if (pessoa) {
                char *nome = leString("nome: ", TAMANHO_NOME_PESSOA, SEMVALIDACAO);
                char *nascimento = leString("data de nascimento (DD/MM/AAAA): ", TAMANHO_NASC, DATA);
                char *cpf = leString("CPF (NNN.NNN.NNN-NN): ", TAMANHO_CPF, CPF);
                char sexo = leSexo();
                atualizaPessoa(pessoa, sexo, nome, nascimento, cpf);

                free(nome);
                free(nascimento);
                free(cpf);
            } else {
                printf("Matricula nao encontrada.\n");
            }
        } else if (opcao == 7) {
            break;
        } else {
            printf("Entrada invalida.\n");
        }
    }
}

void
menuListaPessoas(Pessoa **pessoas, Ocupacao ocupacao, char *membrosStr)
{
    int opcao = 0;
    while (0x5E7E) {
        printf("\n -- Listagem de %s da Instituicao --\n", membrosStr);
        opcao = leNumero("1) Por sexo    2) Ordenado por nome   3) Ordenado por nascimento   4) Aniversariantes do mes   5) Voltar\n");
        if (opcao == 1) {
            char sexo = leSexo();
            int qtdPessoas = listaPorSexo(pessoas, ocupacao, sexo);
            if (qtdPessoas == 0) printf("Nao ha pessoas desse sexo.\n");
        } else if (opcao == 2) {
            char *ordem = leString("ordem ( C D ): ", 2, SEMVALIDACAO);
            if (ordem[0] == 'C' || ordem[0] == 'D') {
                int qtdPessoas = listaPorNome(pessoas, ocupacao, ordem[0] == 'C' ? 1 : -1);
                if (qtdPessoas == 0) printf("Lista de %s vazia.\n", membrosStr);
            } else {
                printf("Ordem Invalida.\n");
            }
            free(ordem);
        } else if (opcao == 3) {
            char *ordem = leString("ordem ( C D ): ", 2, SEMVALIDACAO);
            if (ordem[0] == 'C' || ordem[0] == 'D') {
                int qtdPessoas = listaPorNascimento(pessoas, ocupacao, ordem[0] == 'C' ? 1 : -1);
                if (qtdPessoas == 0) printf("Lista de %s vazia.\n", membrosStr);
            } else {
                printf("Ordem Invalida.\n");
            }
            free(ordem);
        } else if (opcao == 4) {
            int mes = leNumero("mes (1-12): ");
            if (mes >= 0 && mes <= 12) {
                int qtdPessoas = listaAniversariantes(pessoas, ocupacao, mes);
                if (qtdPessoas == 0) printf("Nao ha aniversariantes deste mes.\n");
            } else {
                printf("Mes invalido.\n");
            }
        } else if (opcao == 5) {
            break;
        } else {
            printf("Entrada invalida.\n");
        }
    }
}

void
menuDetalhaDisciplina(Disciplina *disciplina, Pessoa **pessoas)
{
    int opcao = 0;
    while (0xBABEC0DE) {
        printf("\n -- %s --\n", disciplina->nome);
        if (disciplinaExcedente(disciplina, MAXVAGAS)) printf("Disciplina esta lotada!\n");
        opcao = leNumero("1) Listar alunos    2) Adiciona aluno   3) Remover aluno   4) Detalha disciplina   5) Atualiza Disciplina  6) Voltar\n");
        if (opcao == 1) {
            int qtdPessoas = listaAlunos(disciplina);
            if (qtdPessoas == 0) printf("Disciplina sem alunos ainda.\n");
        } else if (opcao == 2) {
            int matricula = leNumero("matricula do aluno: ");
            Pessoa *aluno = buscaPessoa(pessoas, matricula, ALUNO);
            if (aluno) {
                insereAluno(disciplina, aluno);
            } else {
                printf("Matricula de aluno nao encontrada.\n");
            }
        } else if (opcao == 3) {
            int matricula = leNumero("matricula do aluno: ");
            Pessoa *aluno = buscaPessoa(pessoas, matricula, ALUNO);
            if (aluno) {
                removeAluno(disciplina, aluno);
            } else {
                printf("Entrada invalida.\n");
            }
        } else if (opcao == 4) {
            mostraDisciplina(disciplina);
        } else if (opcao == 5) {
            char *nome = leString("nome: ", TAMANHO_NOME_DISC, SEMVALIDACAO);
            char *codigo = leString("codigo (LLLNNN): ", TAMANHO_CODIGO_DISC, CODIGODISCIPLINA);
            char *semestre = leString("semestre (AAAA.SS): ", TAMANHO_SEMESTRE_DISC, SEMESTRE);
            int matricula = leNumero("matricula do professor: ");
            Pessoa *professor = buscaPessoa(pessoas, matricula, PROFESSOR);
            if (professor) {
                atualizaDisciplina(disciplina, nome, codigo, semestre, professor);
            } else {
                printf("Matricula do professor nao encontrada.\n");
            }
            free(nome);
            free(codigo);
            free(semestre);
        } else if (opcao == 6) {
            break;
        } else {
            printf("Entrada invalida.\n");
        }
    }
}
