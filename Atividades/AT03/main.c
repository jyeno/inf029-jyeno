#include <stdlib.h>
#include <stdio.h>
#include "util.h"

// FizzBuzz
//   printar numeros de 1 a n, sendo n um numero escolhido pelo usuario (por parametro)
//
//   caso o numero seja divisivel por 3 este numero deve ser substituido por "Fizz"
//   caso o numero seja divisivel por 5 este numero deve ser substituido por "Buzz"
//   caso o numero seja divisivel por 3 e 5 este numero deve ser substituido por "FizzBuzz"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        messagemHelp();
	exit(1);
    }
    int tamanho = atoi(argv[1]);
    
    if (!tamanho) {
	messagemHelp();
	exit(1);
    }
    
    printf(" == == Fizz Buzz == ==\n");

    for (int i = 1; i <= tamanho; i++) {
        fizzBuzz(i);
	if (i % 10 == 0) puts("");
    }
}
