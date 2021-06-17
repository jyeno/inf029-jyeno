#include <stdio.h>

// 6) Receba dois inteiros positivo k e n e calcule k
// elevado a n. utilize apenas multiplicacoes.
long kElevadoNum(int k, int n) {
    if(n <= 0) return 1;
    return k * kElevadoNum(k, n - 1);
}

int main() {
    int k = 2;
    int n = 4;
    printf("kElevadoNum(%d, %d) == %ld\n", k, n, kElevadoNum(k, n));
    n = 2;
    k = 11;
    printf("kElevadoNum(%d, %d) == %ld\n", k, n, kElevadoNum(k, n));
    return 0;
}
