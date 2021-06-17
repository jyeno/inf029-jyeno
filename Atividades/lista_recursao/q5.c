#include <stdio.h>

// 5) Crie uma funcao recursiva que receba um numero
// inteiro positivo N e calcule o somatorio de 1 a N.
long somatorioAteNum(int n) {
    if (n <= 0) return 0;
    return n + somatorioAteNum(n - 1);
}

int main() {
    int n = 3;
    printf("somatorioAteNum(%d) == %ld\n", n, somatorioAteNum(n));
    n = 4;
    printf("somatorioAteNum(%d) == %ld\n", n, somatorioAteNum(n));
    return 0;
}
