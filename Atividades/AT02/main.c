#include <stdlib.h>
#include <stdio.h>

float soma(float num1, float num2) {
    return num1 + num2;
}

float subtrai(float num1, float num2) {
    return num1 - num2;
}

float multiplica(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    return num1 / num2;
}

void limpaBufferDeEntrada() {
    while(getchar() != '\n'); // limpa buffer de entrada, util caso o usuario coloque algo invalido como letra
}
int main() {
    int opcao = -1;
    printf("======= Bem vindo a mini calculadora =======\n\n");
    while (opcao) {
        printf("Escolha uma das opcoes:\n");
        printf(" 0 - Sair\n 1 - Somar\n 2 - Subtrair\n 3 - Multiplicar\n 4 - Dividir.\n\n");
        if (scanf(" %i", &opcao) && opcao >= 0 && opcao < 5)  {
            if (opcao) {
                float num1, num2;
                do { // leitura do primeiro numero
                    limpaBufferDeEntrada();
                    printf("Primeiro numero (float): ");
                } while(!scanf(" %f", &num1));

                do { // leitura do segundo numero
                    limpaBufferDeEntrada();
                    printf("Segundo numero (float): ");
                } while (!scanf(" %f", &num2));

                switch (opcao) { // nao precisa do default pois caso seja 0 ele nem entraria aki
                    case 1:
                        printf("\n %.2f + %.2f == %.2f\n", num1, num2, soma(num1, num2));
                        break;
                    case 2:
                        printf("\n %.2f - %.2f == %.2f\n", num1, num2, subtrai(num1, num2));
                        break;
                    case 3:
                        printf("\n %.2f * %.2f == %.2f\n", num1, num2, multiplica(num1, num2));
                        break;
                    case 4:
                        printf("\n %.2f / %.2f == %.2f\n", num1, num2, divide(num1, num2));
                        break;
                }
            }
            exit(0);
        }
        else {
            limpaBufferDeEntrada();
            printf("Entrada Invalida.\n\n");
        }
    }
}
