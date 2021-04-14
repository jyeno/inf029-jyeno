#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

char
leSexo()
{
    char ch = 0;
    int valido = 0;
    while(!valido) {
        printf("sexo ( M F ): ");
        if (!scanf(" %c%*c", &ch)) {
            printf("Entrada invalida.\n");
        } else {
            valido = validaSexo(&ch);
        }
    }
    return ch;
}

int
leNumero(const char *mensagem)
{
    int num = 0;
    char strNum[8];
    while(0xBEE) {
        printf("%s", mensagem);
        fgets(strNum, 8, stdin);
        limpaStdin(strNum);
        num = atoi(strNum);
        if (num != 0) {
            break;
        }
    }
    return num;
}

char *
leString(const char *messagem, int tamanho, Validacao validacao)
{
    char *string = calloc(tamanho, sizeof(char));
    int valido = 0;
    while (!valido) {
        printf("%s", messagem);
        fgets(string, tamanho, stdin);
        limpaStdin(string);
        string[strcspn(string, "\n")] = '\0';
        if (validacao == CPF) {
            valido = validaCPF(string);
        } else if (validacao == OCUPACAO) {
            valido = validaOcupacao(string);
        } else if (validacao == DATA) {
            valido = validaData(string);
        } else if (validacao == CPF) {
            valido = validaCPF(string);
        } else if (validacao == SEMESTRE) {
            valido = validaSemestre(string);
        } else if (validacao == CODIGODISCIPLINA) {
            valido = validaCodigoDisciplina(string);
        } else {
            valido = 1;
        }
    }
    return string;
}

void
shiftVetor(void **vetor, int indexARemover)
{
    int i;
    for (i = indexARemover + 1; vetor[i]; i += 1) {
        if (vetor[i]) vetor[i - 1] = vetor[i];
    }
    vetor[i - 1] = NULL;
}

void
limpaStdin(char *ultimaStrLida)
{
    if (strchr(ultimaStrLida, '\n') == NULL) {
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
    }
}

int
validaOcupacao(char *ocupacao)
{
    return (!strncmp(ocupacao, "professor", 10) || !strncmp(ocupacao, "aluno", 6));
}

int
validaData(char *nascimento)
{
    if (strlen(nascimento) != 10) return 0;
    int dia = 0, mes = 0, ano = 0;
    sscanf(nascimento, "%d/%d/%d", &dia,&mes,&ano);

    int valido = 0;

    if (ano >= 1900 && ano <= 2015 && mes >= 1 && mes <= 12) {
        if (dia >= 1 && dia <= 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes== 10 || mes == 12)) {
            valido = 1;
        } else if ( dia >= 1 && dia <= 30 && (mes ==4 || mes ==6 || mes ==9 || mes ==11)) {
            valido = 1;
        } else if (dia > 0 && dia < 29 && (mes == 2)) {
            valido = 1;
        } else if (dia == 29 && mes ==2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))) {
            valido = 1;
        }
    }
    return valido;
}

int
validaSexo(char *sexo)
{
    if (*sexo >= 'a') *sexo -= 32;
    return *sexo == 'M' || *sexo == 'F';
}

int
validaCPF(char *cpf)
{
    if (strlen(cpf) != 14) return 0;
    int valido = 1;
    for (int i = 0; valido && cpf[i] != '\0'; i += 1) {
        if (!(cpf[i] >= '0' && cpf[i] <= '9')) {
            valido = 0;
        }
        if (i == 3 || i == 7 || i == 11) {
            if (cpf[i] == '.' || cpf[i] == '-') {
                valido = 1;
            } else {
                valido = 0;
            }
        }
    }
    return valido;
}

int
validaCodigoDisciplina(char *codigo)
{
    if (strlen(codigo) != 6) return 0;
    int valido = 1;
    int i = 0;
    for (; valido && i < 3; i += 1) {
        if (codigo[i] >= 'a') codigo[i] -= 32;
        if (codigo[i] < 'A' || codigo[i] > 'Z') valido = 0;
    }
    for (; valido && i < 6; i += 1) {
        if (codigo[i] < '0' || codigo[i] > '9') valido = 0;
    }
    return valido;
}

int
validaSemestre(char *semestre)
{
    if (strlen(semestre) != 7) return 0;

    int valido = 1;
    for (int i = 0; valido && i < 7; i += 1) {
        if (semestre[i] < '0' || semestre[i] > '9') valido = 0;
        if (i == 4 && semestre[i] == '.') valido = 1;
    }

    return valido;
}
