#include <stdio.h>

// 11) Proponha um algoritmo recursivo que calcule a
// multiplicacao de dois inteiros.
long multiplica(int n, int m) {
    if (n == 0 || m == 0) return 0;
    return n + multiplica(n, m - 1);
}

int main() {
    int num = 10, num2 = 10;
    printf("multiplica(%d, %d) == %ld\n", num, num2, multiplica(num, num2));
    num = 9;
    num2 = 11;
    printf("multiplica(%d, %d) == %ld\n", num, num2, multiplica(num, num2));
    return 0;
}
