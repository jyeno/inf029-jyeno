#include <stdio.h>

// 10) Escreva uma funcao recursiva que determine quantas vezes
// um digito K ocorre em um numero natural N.
int contaOcorrencia(long n, int k) {
    if (n <= 0) return 0;
    long tam = 1;
    for(; n > tam*10; tam *= 10);
    int digitoAtual = n / tam;
    return (digitoAtual == k ? 1 : 0) + contaOcorrencia(n%tam, k);
}

int main() {
    long n = 22030232;
    int k = 2;
    printf("contaOcorrencia(%ld, %d) == %d\n", n, k, contaOcorrencia(n, k));
    n = 9023921121;
    k = 11;
    printf("contaOcorrencia(%ld, %d) == %d\n", n, k, contaOcorrencia(n, k));
    return 0;
}
