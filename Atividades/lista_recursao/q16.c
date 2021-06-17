#include <stdio.h>

// 16) Faca uma funcao recursiva que receba um numero inteiro positivo
// impar N e retorne o fatorial duplo desse numero.
long fatorialDuplo(long n) {
    if (n < 1 || n % 2 != 1) return 0;
    if (n == 1) return 1;

    return n * fatorialDuplo(n - 2);
}

int main() {
    long num = 5;
    printf("fatorialDuplo(%ld) == %ld\n", num, fatorialDuplo(num));
    num = 7;
    printf("fatorialDuplo(%ld) == %ld\n", num, fatorialDuplo(num));
    return 0;
}
