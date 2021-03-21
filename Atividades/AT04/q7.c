#include <stdlib.h>
#include <stdio.h>

char** lerTresPalavras(char *const n, char *const j, char *const k) {
    char **frase = (char**) calloc(3, sizeof(char[34]));
    frase[0] = n;
    frase[1] = j;
    frase[2] = k;
    return frase;
}

int main() {
    char n[34], j[34], k[34];
    printf("== Tres palavras ==\n(max de 33 letras por palavra)\n");
    printf("Primeira palavra: ");
    scanf(" %33s", n);
    while(getchar() != '\n');  // limpa buffer de entrada para evitar overflows
    printf("Segunda palavra: ");
    scanf(" %33s", j);
    while(getchar() != '\n');  // limpa buffer de entrada para evitar overflows
    printf("Terceira palavra: ");
    scanf(" %33s", k);
    while(getchar() != '\n');  // limpa buffer de entrada para evitar overflows
    char **const frase = lerTresPalavras(n, j, k); 
    printf("\nTres letras: %s  %s  %s\n", frase[0], frase[1], frase[2]);
}
