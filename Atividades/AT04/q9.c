#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char nome[21];
    char nascimento[11]; // mais um para validacao
    char cpf[15];  // colocar um caractere a mais para validacao
    char sexo;
} Cliente;

void limpaStdin() {
    int c;
    do {
        c = getchar();
    } while(c != '\n' && c != EOF);
}

void validaNome(const char* const nome) {
    int i;
    for (i = 0; nome[i] != '\0'; i += 1);
    if (i > 20) {
        printf("Nome invalido, deve ser menor ou igual a 20 caracteres.\n");
        exit(1);
    }
}

void validaNascimento(const char* const nascimento) {
    char mesChar[2];
    int posMes = nascimento[2] == ' ' || nascimento[2] == '-' || nascimento[2] == '/' ? 3 : 2;
    mesChar[0] = nascimento[posMes];
    mesChar[1] = nascimento[posMes + 1];
    int mes = atoi(mesChar);

    char diaChar[2];
    diaChar[0] = nascimento[0];
    diaChar[1] = nascimento[1];
    int dia = atoi(diaChar);

    int valido = 0;
    if (mes > 0 && mes < 13 && dia > 0) {
        if (mes == 2) valido = dia < 29;
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) valido = dia < 31;
        else valido = dia < 32;
    }

    int i;
    for (i = 0; valido && nascimento[i] != '\0'; i += 1) {
        if (!(nascimento[i] >= '0' && nascimento[i] <= '9')) valido = 0;
        if ((i == 2 || i == 5) && (nascimento[i] == '/' || nascimento[i] == '-' || nascimento[i] == ' ')) valido = 1;
    }
    if (!valido || i < 6 || i % 2 != 0 || i > 11) {
        printf("Data invalida, verifique se digitou dias/meses existente.\nFormatos aceitos: DD/MM/AAAA, DD-MM-AAAA, DD MM AAAA, DDMMAAAA, DD/MM/AA, DD-MM-AAAA, DD MM AA, DDMMAA\n");
        exit(1);
    }
}

void validaCPF(const char* const cpf) {
    int valido = 1;
    int i;
    for (i = 0; valido && cpf[i] != '\0'; i += 1) {
        if (!(cpf[i] >= '0' && cpf[i] <= '9')) valido = 0;
        if (((i == 3 || i == 7) && (cpf[i] == '.' || cpf[i] == ' ')) || (i == 11 && (cpf[i] == '-' || cpf[i] == ' '))) valido = 1;
    }
    if (!valido || i < 11 || i > 14) {
        printf("CPF invalido, formatos aceitos: NNN.NNN.NNN-NN, NNN NNN NNN NN, NNNNNNNNNNN\n");
        exit(1);
    }
}

void validaSexo(const char sexo) {
    char s = sexo;
    if (s <= 'Z') s += 32;
    if (s != 'm' && s != 'f' && s != 'o') {
        printf("Sexo invalido, use:\n 'm', 'M' para masculino\n 'f' ou 'F' para feminino\n 'o' ou 'O' para outro\n");
        exit(1);
    }
}

Cliente *cadastraCliente(const char * const nome, const char * const nascimento, const char * const cpf, const char sexo) {
    validaNome(nome);
    validaNascimento(nascimento);
    validaCPF(cpf);
    validaSexo(sexo);

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
    char nome[22], nascimento[12], cpf[16], sexo;
    printf("== Registra Cliente ==\n\n");
    printf("Nome: ");
    scanf(" %21[^\n]", nome);
    limpaStdin();
    printf("Data de nascimento: ");
    scanf(" %11[^\n]", nascimento);
    limpaStdin();
    printf("CPF: ");
    scanf(" %15[^\n]", cpf);
    limpaStdin();
    printf("Sexo: ");
    scanf(" %c", &sexo);
    limpaStdin();
    const Cliente* const cliente = cadastraCliente(nome, nascimento, cpf, sexo);
    printf("Cliente:\n nome: %s\n nascimento: %s\n CPF: %s\n sexo: %c\n", cliente->nome, cliente->nascimento, cliente->cpf, cliente->sexo);
}
