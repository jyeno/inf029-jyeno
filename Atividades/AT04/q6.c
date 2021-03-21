#include <stdlib.h>
#include <stdio.h>

char* lerTresLetras(const char n, const char j, const char k) {
    char *chars = (char*) calloc(3, sizeof(char));
    chars[0] = n;
    chars[1] = j;
    chars[2] = k;
    return chars;
}

int main() {
    char n, j, k;
    printf("== Tres letras ==\n\n");
    printf("Primeira letra: ");
    scanf(" %c", &n);
    printf("Segunda letra: ");
    scanf(" %c", &j);
    printf("Terceira letra: ");
    scanf(" %c", &k);
    const char *const chars = lerTresLetras(n, j, k); 
    printf("\nTres letras: %c  %c  %c\n", chars[0], chars[1], chars[2]);
}
