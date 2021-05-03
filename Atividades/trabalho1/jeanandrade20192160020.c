// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Jean Lima Andrade
//  email: jyeno@protonmail.com
//  Matrícula: 20192160020
//  Semestre: segundo 

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>

#include "jeanandrade20192160020.h"

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = x;
    return fat;
}

/*typedef struct DQ
{
    char sDia [3];
    char sMes [3];
    char sAno [3];
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

DataQuebrada quebraData(char *data){
    //[ e , r  ,  /  ,    ,   ,  /  ,    ,     ,    ,      ,]

}*/
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data)
{
    int dia = 0, mes = 0, ano = 0, ehValido = 0;
    coletaDatan(data, &dia, &mes, &ano);

    if (dia && mes && ano) {
        if (mes <= 12) {
            if (dia >= 1 && dia <= 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) {
                ehValido = 1;
            } else if ( dia >= 1 && dia <= 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
                ehValido = 1;
            } else if (dia > 0 && dia < 29 && (mes == 2)) {
                ehValido = 1;
            } else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))) {
                ehValido = 1;
            }
        }
    }
    return ehValido;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
    if (q1(datainicial) == 0) {
        return 2;
    } else if (q1(datafinal) == 0) {
        return 3;
    }
    int iDia = 0, iMes = 0, iAno = 0, fDia = 0, fMes = 0, fAno = 0;
    coletaDatan(datainicial, &iDia, &iMes, &iAno);
    coletaDatan(datafinal, &fDia, &fMes, &fAno);

    if (iAno > fAno || (iAno == fAno && (iMes > fMes || (iMes == fMes && iDia > fDia))))  {
        return 4;
    }

    *qtdDias = fDia - iDia;
    if (*qtdDias < 0) {
        fMes -= 1;
        if (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes== 10 || iMes == 12) {
            *qtdDias += 31;
        } else if (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11) {
            *qtdDias += 30;
        } else {
            *qtdDias += (iAno % 400 == 0 || (iAno % 4 == 0 && iAno % 100 != 0)) ? 29 : 28;
        }
    }
    *qtdAnos = fAno - iAno;
    *qtdMeses = fMes - iMes;

    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(wchar_t *texto, wchar_t c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    retiraAcentos(texto);
    retiraAcentos(&c);

    if(isCaseSensitive != 1 && c >= 'A' && c <= 'Z') c += 32;

    for (int i = 0; texto[i] != '\0'; i += 1) {
        if (texto[i] == c) qtdOcorrencias += 1;
        else if (isCaseSensitive != 1) {
            char a = (texto[i] >= 'A' && texto[i] <= 'Z') ? texto[i] + 32 : texto[i];
            if (a == c) qtdOcorrencias += 1;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(wchar_t *strTexto, wchar_t *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    retiraAcentos(strTexto);
    retiraAcentos(strBusca);

    for (int i = 0, j = 0, k = 0, primeiraPosAtual; strTexto[i] != '\0'; i += 1) {
        if (strTexto[i] == strBusca[j]) {
            if (j == 0) primeiraPosAtual = i;
            j += 1;
        } else j = 0;
        if (strBusca[j] == '\0') {
            qtdOcorrencias += 1;
            if (k < 30) {
                posicoes[k] = primeiraPosAtual + 1;
                posicoes[k+1] = i + 1;
                j = 0; k += 2;
            } else break;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int div = 1, inverso = 0, mul = 1;
    while (div <= num) { div *= 10; }

    while (div > 1) {
        div /= 10;
        inverso += num / div * mul;
        num %= div; mul *= 10;
    }
    return inverso;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0, divBase = 1, baseTamanho = 1, divBusca = 1, buscaTamanho = 1;
    while (divBase <= numerobase) { divBase *= 10; baseTamanho += 1; }
    while (divBusca <= numerobusca) { divBusca *= 10; buscaTamanho += 1; }

    char strBase[baseTamanho], strBusca[buscaTamanho];
    int baseIndex = 0, buscaIndex = 0;
    while (0xBABEC0DE) {
        if (divBase > 1) {
            divBase /= 10;
            strBase[baseIndex] = (numerobase / divBase) - '0';
            baseIndex++; numerobase %= divBase;
        } else if (divBusca > 1) {
            divBusca /= 10;
            strBusca[buscaIndex] = (numerobusca / divBusca) - '0';
            buscaIndex++; numerobusca %= divBusca;
        } else {
            strBase[baseTamanho - 1] = '\0';
            strBusca[buscaTamanho - 1] = '\0';
            break;
        }
    }

    for (int i = 0, j = 0; strBase[i] != '\0'; i += 1) {
        if (strBase[i] == strBusca[j]) j += 1;
        else j = 0;
        if (j == buscaIndex) {
            qtdOcorrencias += 1; j = 0;
        }
    }

    return qtdOcorrencias;
}

// funcoes internas
void coletaDatan(char *data, int *dia, int *mes, int *ano)
{
    char d[3][5] = { {0}, {0}, {0} };
    for (int i = 0, j = 0, k = 0; data[i] != '\0'; i += 1 ) {
        if (data[i] != '/') {
            d[k][j] = data[i];
            j += 1;
        } else {
            k += 1; j = 0;
        }
    }

    *dia = atoi(d[0]);
    *mes = atoi(d[1]);
    int tempAno = atoi(d[2]);
    *ano = tempAno < 1000 ? tempAno + 2000 : tempAno;
}

void retiraAcentos(wchar_t *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] > L'À' && str[i] < L'Ü') {
            if (str[i] <= L'Å') str[i] = 'A';
            else if (str[i] >= L'È' && str[i] <= L'Ë') str[i] = 'E';
            else if (str[i] == L'Ç') str[i] = 'C';
            else if (str[i] <= L'Ï') str[i] = 'I';
            else if (str[i] >= L'Ò' && str[i] <= L'Ö') str[i] = 'O';
            else if (str[i] >= L'Ù') str[i] = 'U';
        } else if (str[i] >= L'à' && str[i] <= L'ü') {
            if (str[i] <= L'å') str[i] = 'a';
            else if (str[i] >= L'è' && str[i] <= L'ë') str[i] = 'e';
            else if (str[i] == L'ç') str[i] = 'c';
            else if (str[i] <= L'ï') str[i] = 'i';
            else if (str[i] >= L'ò' && str[i] <= L'ö') str[i] = 'o';
            else if (str[i] >= L'ù') str[i] = 'u';
        }
    }
}
