#include <stdio.h>

double subtrai(const double n, const double j, const double k) {
    return n - j - k;
}

int main() {
    double n, j, k;
    printf("== Subtrai ==\n\n");
    printf("Primeiro numero: ");
    scanf(" %lf", &n);
    printf("Segundo numero: ");
    scanf(" %lf", &j);
    printf("Terceiro numero: ");
    scanf(" %lf", &k);
    printf("\nResultado: %.2lf\n", subtrai(n, j, k));
}

