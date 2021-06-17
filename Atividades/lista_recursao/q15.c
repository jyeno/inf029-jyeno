#include <stdio.h>

// 15) Faca um funcao recursiva que receba um numero inteiro
// positivo par N e imprima todos os numeros pares de 0 a N,
// em ordem descrescente.
void imprimeAteNumParDecrescente(int n) {
    if (n % 2 != 0 || n < 0) return;
    printf("%i ", n);
    imprimeAteNumParDecrescente(n - 2);
}

int main() {
    int num = 10;
    printf("imprimeAteNumParDecrescente(%d)\n", num);
    imprimeAteNumParDecrescente(num);
    printf("\n");
    num = 9;
    printf("imprimeAteNumParDecrescente(%d)\n", num);
    imprimeAteNumParDecrescente(num);
    return 0;
}
