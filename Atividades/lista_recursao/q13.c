#include <stdio.h>

// 13) Faca um funcao recursiva que receba um numero inteiro
// positivo N e imprima todos os numeros naturais de 0 a N,
// em ordem descrescente.
void imprimeAteNumDecrescente(int n) {
    if (n < 0) return;
    printf("%i ", n);
    imprimeAteNumDecrescente(n - 1);
}

int main() {
    int num = 10;
    printf("imprimeAteNumDecrescente(%d)\n", num);
    imprimeAteNumDecrescente(num);
    printf("\n");
    num = 9;
    printf("imprimeAteNumDecrescente(%d)\n", num);
    imprimeAteNumDecrescente(num);
    printf("\n");
    return 0;
}
