#include <stdio.h>

// 4) Faça uma funcao recursiva que permita somar os
// elementos de um vetor de inteiros.
long somaArray(int *arrayptr, int tam) {
    if (tam == 0) return 0;
    return *arrayptr + somaArray(arrayptr + 1, tam - 1);
}

int main() {
    int array[] = { 1, 2, 3, 4, 5,};
    int tamanhoArray = sizeof(array)/sizeof(array[0]);
    printf("array [");
    for (int i = 0; i < tamanhoArray; i += 1) {
        printf(" %d,", array[i]);
    }
    printf("]\n");
    printf("inverteArray(array, %d) == %ld\n", tamanhoArray, somaArray(array, tamanhoArray));

    int array2[] = { 6, 7, 8, 9, 10, 11,};
    int tamanhoArray2 = sizeof(array2)/sizeof(array2[0]);
    printf("array2 [");
    for (int i = 0; i < tamanhoArray2; i += 1) {
        printf(" %d,", array2[i]);
    }
    printf("]\n");
    printf("inverteArray(array2, %d) == %ld\n", tamanhoArray2, somaArray(array2, tamanhoArray2));
    return 0;
}
