#include <stdio.h>

double soma(const double n, const double j) {
    return n + j;
}

int main() {
    double n, j;
    printf("== Soma ==\n\n");
    printf("Primeiro numero: ");
    scanf(" %lf", &n);
    printf("Segundo numero: ");
    scanf(" %lf", &j);
    printf("\nResultado: %.2lf\n", soma(n, j));
}
