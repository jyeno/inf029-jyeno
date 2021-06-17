#include <stdio.h>

// 8) Escreva uma funcao recursiva mdc que retorna o maximo
// divisor comum de x e y.
long maximoDivisorComum(long x, long y) {
    if (y == 0) return x;
    return maximoDivisorComum(y, x % y);
}

int main() {
    long num = 50, num2 = 15;
    printf("maximoDivisorComum(%ld, %ld) == %ld\n", num, num2, maximoDivisorComum(num, num2));
    num = 30;
    num2 = 150;
    printf("maximoDivisorComum(%ld, %ld) == %ld\n", num, num2, maximoDivisorComum(num, num2));
    return 0;
}
