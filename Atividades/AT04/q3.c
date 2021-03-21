#include <stdio.h>

long int fatorial(const int n) {
    if (n < 0) return -1;
    long int j = 1;
    for (int i = n; i > 0; j *= i, --i);
    return j;
}

int main() {
    int n;
    printf("== Fatorial ==\n\n");
    printf("Numero: ");
    if (!scanf(" %d", &n)) {
        printf("Entrada invalida!\n");
        return 1;
    }
    const long int result = fatorial(n);
    if (result == -1) printf("Fatorial nao eh possivel para esse numero.\n");
    else printf("\nResultado: %ld\n", result);
}
