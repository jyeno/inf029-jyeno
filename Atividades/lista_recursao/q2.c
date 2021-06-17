#include <stdio.h>

// 2) Faca uma funcao recursiva que calcule e retorne
// o N-esimo termo da sequencia de Fibonacci.
long fibonacci(long n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    long num = 5;
    printf("fibonacci(%ld) == %ld\n", num, fibonacci(num));
    num = 7;
    printf("fibonacci(%ld) == %ld\n", num, fibonacci(num));
    return 0;
}
