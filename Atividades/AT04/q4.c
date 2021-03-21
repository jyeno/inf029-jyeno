#include <stdlib.h>
#include <stdio.h>

double* lerTresNumeros(const double n, const double j, const double k) {
    double *nums = (double*) calloc(3, sizeof(double));
    nums[0] = n;
    nums[1] = j;
    nums[2] = k;
    return nums;
}

int main() {
    double n, j, k;
    printf("== Tres numeros ==\n\n");
    printf("Primeiro numero: ");
    scanf(" %lf", &n);
    printf("Segundo numero: ");
    scanf(" %lf", &j);
    printf("Terceiro numero: ");
    scanf(" %lf", &k);
    const double * const nums = lerTresNumeros(n, j, k); 
    printf("\nTres numeros: %.4lf, %.4lf e %.4lf\n", nums[0], nums[1], nums[2]);
}
