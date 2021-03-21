#include <stdlib.h>
#include <stdio.h>

typedef struct {
    double num1;
    double num2;
    double num3;
    double num4;
} Nums;

Nums* lerQuatroNumeros(const double n, const double j, const double k, const double m) {
    Nums *nums = (Nums*) malloc(sizeof(Nums));
    nums->num1 = n;
    nums->num2 = j;
    nums->num3 = k;
    nums->num4 = m;
    return nums;
}

int main() {
    double n, j, k, m;
    printf("== Quatro numeros ==\n\n");
    printf("Primeiro numero: ");
    scanf(" %lf", &n);
    printf("Segundo numero: ");
    scanf(" %lf", &j);
    printf("Terceiro numero: ");
    scanf(" %lf", &k);
    printf("Quarto numero: ");
    scanf(" %lf", &m);
    const Nums *const nums = lerQuatroNumeros(n, j, k, m); 
    printf("\nQuatro numeros: %.4lf, %.4lf, %.4lf e %.4lf\n", nums->num1, nums->num2, nums->num3, nums->num4);
}
