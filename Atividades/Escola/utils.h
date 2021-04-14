#ifndef UTILS_H
#define UTILS_H

typedef enum { DATA, CPF, OCUPACAO, SEMESTRE, CODIGODISCIPLINA, SEMVALIDACAO } Validacao;

int leNumero(const char *mensagem);

char leSexo();

char *leString(const char *messagem, int tamanho, Validacao validacao);

void shiftVetor(void **vetor, int indexARemover);

int validaCPF(char *cpf);

int validaData(char *data);

int validaOcupacao(char *ocupacao);

int validaCodigoDisciplina(char *codigo);

int validaSemestre(char *semestre);

int validaSexo(char *sexo);

void limpaStdin(char *ultimaStrLida);

#endif
