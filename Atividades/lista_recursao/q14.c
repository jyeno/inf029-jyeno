#include <stdio.h>

// 14) Faca um funcao recursiva que receba um numero inteiro
// positivo par N e imprima todos os numeros pares de 0 a N,
// em ordem crescente.
void imprimeAteNumParCrescente(int n) {
    if (n % 2 != 0 || n < 0) return;
    imprimeAteNumParCrescente(n - 2);
    printf("%i ", n);
}

int main() {
    int num = 10;
    printf("imprimeAteNumParCrescente(%d)\n", num);
    imprimeAteNumParCrescente(num);
    printf("\n");
    num = 9;
    printf("imprimeAteNumParCrescente(%d)\n", num);
    imprimeAteNumParCrescente(num);
   return 0;
}
