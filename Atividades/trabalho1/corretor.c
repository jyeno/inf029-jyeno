// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <wctype.h>
#include <string.h>
#include <locale.h>

//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.c
#include "jeanandrade20192160020.h"

void testSomar();    //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{
    char *locale = NULL;
    char const *locales[] = { "pt_BR.UTF-8", "en_US.UTF-8", "pt_BR.ISO-8859-1", "en_US.ISO-8859-1", NULL };
    for (int i = 0; !locale && locales[i]; i += 1) {
        locale = setlocale(LC_ALL, locales[i]);
    }
    if (locale) {
        wprintf(L"Locale atual é: %s.\n", locale);
    } else {
        wprintf(L"nenhum dos locales especificados estao configurados na maquina, favor ter ao menos um destes configurados na maquina: ");
        for (int i = 0; locales[i]; i += 1) wprintf(L"%s ", locales[i]);
        wprintf(L"\n");
        return 1;
    }
    //wprintf(L"--- teste somar ---\n");
    //testSomar();
    //wprintf(L"--- teste fatorial ---\n");
    //testFatorial();
    wprintf(L"--- teste 1 ---\n");
    testQ1();
    wprintf(L"--- teste 2 ---\n");
    testQ2();
    wprintf(L"--- teste 3 ---\n");
    testQ3();
    wprintf(L"--- teste 4 ---\n");
    testQ4();
    wprintf(L"--- teste 5 ---\n");
    testQ5();
    wprintf(L"--- teste 6 ---\n");
    testQ6();
}

void testSomar()
{
    wprintf(L"%d\n", somar(3, 4) == 7);
    wprintf(L"%d\n", somar(-1, -3) == 2);
    wprintf(L"%d\n", somar(-6, 6) == 0);
    wprintf(L"%d\n", somar(74, 9) == 83);
    wprintf(L"%d\n", somar(30, -9) == 21);
}

void testFatorial()
{
    wprintf(L"%d\n", fatorial(3) == 6);
    wprintf(L"%d\n", fatorial(1) == 1);
    wprintf(L"%d\n", fatorial(5) == 120);
}

void testQ1()
{
    char str[11];
    strcpy(str, "29/02/2015");
    wprintf(L"%d\n", q1(str) == 0);
    strcpy(str, "29/02/2012");
    wprintf(L"%d\n", q1(str) == 1);
    strcpy(str, "9/13/2014");
    wprintf(L"%d\n", q1(str) == 0);
    strcpy(str, "45/4/2014");
    wprintf(L"%d\n", q1(str) == 0);
    strcpy(str, "/9/2014");
    wprintf(L"%d\n", q1(str) == 0);
}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    wprintf(L"%d\n", retorno == 1);
    wprintf(L"%d\n", qtdDias == 0);
    wprintf(L"%d\n", qtdMeses == 0);
    wprintf(L"%d\n", qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    wprintf(L"%d\n", retorno == 2);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    wprintf(L"%d\n", retorno == 3);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    wprintf(L"%d\n", retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    wprintf(L"%d\n", retorno == 1);
    wprintf(L"%d\n", qtdDias == 1);
    wprintf(L"%d\n", qtdMeses == 1);
    wprintf(L"%d\n", qtdAnos == 0);
}

void testQ3()
{
    wchar_t str[250];
    wcscpy(str, L"Renato Lima Novais");
    wprintf(L"%d\n", q3(str, 'a', 0) == 3);
    wprintf(L"%d\n", q3(str, 'b', 0) == 0);
    wprintf(L"%d\n", q3(str, 'l', 1) == 0);
    wprintf(L"%d\n", q3(str, 'l', 0) == 1);
    wprintf(L"%d\n", q3(str, 'L', 0) == 1);
}

void testQ4()
{
    wchar_t strTexto[250];
    wchar_t strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    wcscpy(strTexto, L"Laboratorio de programacao: para ratos de programação");
    wcscpy(strBusca, L"rato");
    wprintf(L"%d\n", q4(strTexto, strBusca, posicoes) == 2);
    wprintf(L"%d\n", posicoes[0] == 5);
    wprintf(L"%d\n", posicoes[1] == 8);
    wprintf(L"%d\n", posicoes[2] == 34);
    wprintf(L"%d\n", posicoes[3] == 37);

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    wcscpy(strTexto, L"Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    wcscpy(strBusca, L"mui");
    wprintf(L"%d\n", q4(strTexto, strBusca, posicoes) == 3);
    wprintf(L"%d\n", posicoes[0] == 16);
    wprintf(L"%d\n", posicoes[1] == 18);
    wprintf(L"%d\n", posicoes[2] == 34);
    wprintf(L"%d\n", posicoes[3] == 36);
    wprintf(L"%d\n", posicoes[4] == 52);
    wprintf(L"%d\n", posicoes[5] == 54);
}

void testQ5()
{
    wprintf(L"%d\n", q5(345) == 543);
    wprintf(L"%d\n", q5(78) == 87);
    wprintf(L"%d\n", q5(3) == 3);
    wprintf(L"%d\n", q5(5430) == 345);
}

void testQ6()
{
    wprintf(L"%d\n", q6(34567368, 3) == 2);
    wprintf(L"%d\n", q6(34567368, 4576) == 0);
    wprintf(L"%d\n", q6(3539343, 3) == 4);
    wprintf(L"%d\n", q6(3539343, 39) == 1);
}
