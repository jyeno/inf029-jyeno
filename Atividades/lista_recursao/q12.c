#include <stdio.h>

// 12) Faca um funcao recursiva que receba um numero inteiro
// positivo N e imprima todos os numeros naturais de 0 a N,
// em ordem crescente.
void imprimeAteNumCrescente(int n) {
    if (n < 0) return;
    imprimeAteNumCrescente(n - 1);
    printf("%i ", n);
}

int main() {
    int num = 10;
    printf("imprimeAteNumCrescente(%d)\n", num);
    imprimeAteNumCrescente(num);
    printf("\n");
    num = 9;
    printf("imprimeAteNumCrescente(%d)\n", num);
    imprimeAteNumCrescente(num);
    printf("\n");
    return 0;
}
