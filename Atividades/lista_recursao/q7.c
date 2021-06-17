#include <stdio.h>

// 7) Receba um vetor de numeros reais com 100 elementos
// inverta a posicao dos elementos presentes no vetor.
void inverteArray(double *array, int tam) {
    if (tam <= 0) return;

    double temp;
    temp = array[0];
    array[0] = array[tam - 1];
    array[tam - 1] = temp;

    inverteArray(array + 1, tam - 2);
}

int main() {
    double array[] = { 1.0, 1.1, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 9.99, };
    int tamanhoArray = sizeof(array)/sizeof(array[0]);
    printf("array [");
    for (int i = 0; i < tamanhoArray; i += 1) {
        printf(" %.2lf,", array[i]);
    }
    printf("]\n");
    printf("inverteArray(array, %d)\n", tamanhoArray);
    inverteArray(array, tamanhoArray);
    printf("array [");
    for (int i = 0; i < tamanhoArray; i += 1) {
        printf(" %.2lf,", array[i]);
    }
    printf("]\n");
    return 0;
}
