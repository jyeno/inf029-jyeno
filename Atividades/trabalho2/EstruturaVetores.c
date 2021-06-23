#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

#define TAM 10

int ***vetorPrincipal;

void dobrar(int *x)
{
    *x *= 2;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    if (ehPosicaoValida(posicao) != SUCESSO) return POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao]) return JA_TEM_ESTRUTURA_AUXILIAR;
    else if (tamanho < 1) return TAMANHO_INVALIDO;

    vetorPrincipal[posicao] = calloc(tamanho + 1, sizeof(int**));
    if (!vetorPrincipal[posicao]) return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao][0] = malloc(sizeof(int));
    *(vetorPrincipal[posicao][0]) = tamanho;
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if (ehPosicaoValida(posicao) != SUCESSO) return POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao]) return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 1; i <= *(vetorPrincipal[posicao][0]); i += 1) {
        if (!vetorPrincipal[posicao][i]) {
            vetorPrincipal[posicao][i] = malloc(sizeof(int));
            *(vetorPrincipal[posicao][i]) = valor;
            return SUCESSO;
        }
    }

    return SEM_ESPACO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if (ehPosicaoValida(posicao) != SUCESSO) return POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao]) return SEM_ESTRUTURA_AUXILIAR;

    for (int i = *(vetorPrincipal[posicao][0]); i > 0; i -= 1) {
        if (vetorPrincipal[posicao][i]) {
            free(vetorPrincipal[posicao][i]);
            vetorPrincipal[posicao][i] = NULL;
            return SUCESSO;
        }
    }
    return ESTRUTURA_AUXILIAR_VAZIA;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores

ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if (ehPosicaoValida(posicao) != SUCESSO) return POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao]) return SEM_ESTRUTURA_AUXILIAR;

    int naoVazia = 0;
    for (int i = 1; i <= *(vetorPrincipal[posicao][0]); i += 1) {
        if (vetorPrincipal[posicao][i]) {
            naoVazia = 1;
            if (*(vetorPrincipal[posicao][i]) == valor) {
                free(vetorPrincipal[posicao][i]);
                shiftVetor((void**)vetorPrincipal[posicao], i);
                return SUCESSO;
            }
        }
    }
    return naoVazia ? NUMERO_INEXISTENTE : ESTRUTURA_AUXILIAR_VAZIA;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    return (posicao >= 1 && posicao <= TAM) ? SUCESSO : POSICAO_INVALIDA;
}

// funcao generica de shift de um vetor em C
void shiftVetor(void **vetor, int indexARemover)
{
    int i;
    for (i = indexARemover + 1; vetor[i]; i += 1) {
        if (vetor[i]) vetor[i - 1] = vetor[i];
    }
    vetor[i - 1] = NULL;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[], int tamVetor)
{
    if (ehPosicaoValida(posicao) != SUCESSO) return POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao]) return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 1, j = 0; j < tamVetor && i <= *(vetorPrincipal[posicao][0]) && vetorPrincipal[posicao][i]; i += 1) {
        vetorAux[j] = *(vetorPrincipal[posicao][i]);
        j += 1;
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[], int tamVetor)
{
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux, tamVetor);
    if (retorno == SUCESSO) {
        for (int i = 0; i < tamVetor; i += 1) {
            for (int j = i + 1; j < tamVetor; j += 1) {
                if (vetorAux[j] < vetorAux[i]) {
                    int temp = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = temp;
                }
            }
        }
    }
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[], int tamVetor)
{
    int j = 0;
    for (int i = 1; j < tamVetor && i <= TAM; i += 1) {
        if (vetorPrincipal[i]) {
            for (int k = 1; j < tamVetor && k <= *(vetorPrincipal[i][0]) && vetorPrincipal[i][k]; k += 1) {
                vetorAux[j] = *(vetorPrincipal[i][k]);
                j += 1;
            }
        }
    }
    return j > 0 ? SUCESSO : TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - Não tem estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[], int tamVetor)
{
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux, tamVetor);
    if (retorno == SUCESSO) {
        for (int i = 0; i < tamVetor; i += 1) {
            for (int j = i + 1; j < tamVetor; j += 1) {
                if (vetorAux[j] < vetorAux[i]) {
                    int temp = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = temp;
                }
            }
        }
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (ehPosicaoValida(posicao) != SUCESSO) return POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao]) return SEM_ESTRUTURA_AUXILIAR;

    int atualTam = *(vetorPrincipal[posicao][0]);
    int novoTam = atualTam + novoTamanho;
    if (novoTam < 1) return NOVO_TAMANHO_INVALIDO;
    else if (atualTam > novoTam) { // evitando possiveis memory leaks quando diminuir a estrutura auxiliar
        for (int i = atualTam; i > novoTam; i -= 1) {
            if (vetorPrincipal[posicao][i]) {
                free(vetorPrincipal[posicao][i]);
                vetorPrincipal[posicao][i] = NULL;
            }
        }
    }

    int **novaEstrutura = realloc(vetorPrincipal[posicao], sizeof(int*) * (novoTam + 1));
    if (!novaEstrutura) return SEM_ESPACO_DE_MEMORIA;

    if (novoTam > atualTam) {
        for (int i = atualTam + 1; i <= novoTam; i += 1) {
            novaEstrutura[i] = NULL; // garantindo que o novo espaço alocado eh nulo
        }
    }
    vetorPrincipal[posicao] = novaEstrutura;
    *(vetorPrincipal[posicao][0]) = novoTam;
    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if (ehPosicaoValida(posicao) != SUCESSO) return POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao]) return SEM_ESTRUTURA_AUXILIAR;

    int qtdItems = 0;
    for (int i = 1; i <= *(vetorPrincipal[posicao][0]); i += 1) {
        if (vetorPrincipal[posicao][i]) qtdItems += 1;
    }

    return qtdItems > 0 ? qtdItems : ESTRUTURA_AUXILIAR_VAZIA;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *inicio = calloc(1, sizeof(No));
    No *no = inicio;
    for (int i = 1; i <= TAM; i += 1) {
        if (vetorPrincipal[i]) {
            for (int k = 1; k <= *(vetorPrincipal[i][0]) && vetorPrincipal[i][k]; k += 1) {
                no->prox = calloc(1, sizeof(No));
                no->prox->conteudo = *(vetorPrincipal[i][k]);
                no = no->prox;
            }
        }
    }
    No *aDeletar = inicio;
    inicio = inicio->prox;
    free(aDeletar);
    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[], int tamVetor)
{
    int i = 0;
    for (No *no = inicio; no && i < tamVetor; no = no->prox, i += 1) {
        vetorAux[i] = no->conteudo;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *no = *inicio;
    while (no) {
        No *aDeletar = no;
        no = no->prox;
        free(aDeletar);
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    vetorPrincipal = calloc(TAM + 1, sizeof(int**));
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 1; i <= TAM; i += 1) {
        if (vetorPrincipal[i]) {
            for (int j = 1; j <= *(vetorPrincipal[i][0]); j += 1) {
                if (vetorPrincipal[i][j]) {
                    free(vetorPrincipal[i][j]);
                }
            }
            free(vetorPrincipal[i][0]);
            free(vetorPrincipal[i]);
        }
    }
    free(vetorPrincipal[0]);
    free(vetorPrincipal);
}
