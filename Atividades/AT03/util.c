#include "util.h"

#include <stdio.h>

void messagemHelp() {
    printf("\nFizzBuzz n\n\n\
   Printa numeros de 1 a n, sendo n um *numero* escolhido pelo usuario (por parametro)\n\
\
   Caso o numero seja divisivel por 3 este numero deve ser substituido por \"Fizz\"\n\
   Caso o numero seja divisivel por 5 este numero deve ser substituido por \"Buzz\"\n\
   Caso o numero seja divisivel por 3 e 5 este numero deve ser substituido por \"FizzBuzz\"\n");
}

int ehDivisivelPorTres(int num) {
    return num % 3 == 0;
}

int ehDivisivelPorCinco(int num) {
    return num % 5 == 0;
}

void fizzBuzz(int num) {
    char string[9];
    if (ehDivisivelPorTres(num) && ehDivisivelPorCinco(num)) {
	sprintf(string, "%s", "FizzBuzz");
    }
    else if (ehDivisivelPorTres(num)) {
	sprintf(string, "%s", "Fizz");
    }
    else if (ehDivisivelPorCinco(num)) {
	sprintf(string, "%s", "Buzz");
    }
    else {
	sprintf(string, "%d", num);
    }
    printf("%s ", string);
}
