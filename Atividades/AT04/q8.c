#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char nome[22];
    char nascimento[11];
    char cpf[15];
    char sexo;
} Cliente;

void limpaStdin() {
    int c;
    do {
        c = getchar();
    } while(c != '\n' && c != EOF);
}

Cliente *cadastraCliente(const char * const nome, const char * const nascimento, const char * const cpf, const char sexo) {
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    int i = 0;
    for (i = 0; nome[i] != '\0'; i += 1) {
        cliente->nome[i] = nome[i];
    }
    cliente->nome[i] = '\0';
    for (i = 0; nascimento[i] != '\0'; i += 1) {
        cliente->nascimento[i] = nascimento[i];
    }
    cliente->nascimento[i] = '\0';
    for (i = 0; cpf[i] != '\0'; i += 1) {
        cliente->cpf[i] = cpf[i];
    }
    cliente->cpf[i] = '\0';
    cliente->sexo = sexo;
    return cliente;
}

int main() {
    char nome[22], nascimento[11], cpf[15], sexo;
    printf("== Registra Cliente ==\n\n");
    printf("Nome: ");
    scanf(" %21[^\n]", nome);
    limpaStdin();
    printf("Data de nascimento: ");
    scanf(" %10s", nascimento);
    limpaStdin();
    printf("CPF: ");
    scanf(" %14s", cpf);
    limpaStdin();
    printf("Sexo: ");
    scanf(" %c", &sexo);
    limpaStdin();
    const Cliente* const cliente = cadastraCliente(nome, nascimento, cpf, sexo);
    printf("Cliente:\n nome: %s\n nascimento: %s\n CPF: %s\n sexo: %c\n", cliente->nome, cliente->nascimento, cliente->cpf, cliente->sexo);
}
