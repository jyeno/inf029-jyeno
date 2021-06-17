#include <stdio.h>

// 1) Faca uma funcao recursiva que calcule e retorne
// o fatorial de um numero n.
long fatorial(long n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    return n * fatorial(n -1);
}

int main() {
    long num = 5;
    printf("fatorial(%ld) == %ld\n", num, fatorial(num));
    num = 7;
    printf("fatorial(%ld) == %ld\n", num, fatorial(num));
    return 0;
}
