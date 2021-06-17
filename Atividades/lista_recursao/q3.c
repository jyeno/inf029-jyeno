#include <stdio.h>

// 3) Faca uma funcao recursiva que pemita inverter um
// numero inteiro, ex: 123 - 321.
long inverteNum(long n) {
    if (n == 0) return 0;
    int tam = 1;
    for(; n > tam*10; tam *= 10);
    int resto = n % 10;
    return resto * tam + inverteNum(n / 10);
}

int main() {
    long num = 1234567890;
    printf("inverteNum(%ld) == %ld\n", num, inverteNum(num));
    num = 752;
    printf("inverteNum(%ld) == %ld\n", num, inverteNum(num));
    return 0;
}
