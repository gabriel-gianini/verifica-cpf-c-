#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool verificarCPF(const char* cpf) {
    // Verificar se todos os caracteres são iguais (caso inválido)
    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            break;
        }
        if (i == 10) {
            return false;
        }
    }
    
    // Verificar o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    
    int digitoVerificador1 = (soma * 10) % 11;
    if (digitoVerificador1 == 10) {
        digitoVerificador1 = 0;
    }
    
    if (cpf[9] - '0' != digitoVerificador1) {
        return false;
    }
    
    // Verificar o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    
    int digitoVerificador2 = (soma * 10) % 11;
    if (digitoVerificador2 == 10) {
        digitoVerificador2 = 0;
    }
    
    if (cpf[10] - '0' != digitoVerificador2) {
        return false;
    }
    
    return true;
}

bool validarEntrada(const char* cpf) {
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char cpf[12];
    
    printf("Digite um CPF (apenas numeros): ");
    scanf("%s", cpf);
    
    while (!validarEntrada(cpf)) {
        printf("Entrada invalida. Digite apenas numeros: ");
        scanf("%s", cpf);
    }
    
    bool valido = verificarCPF(cpf);
    
    if (valido) {
        printf("CPF valido.\n");
    } else {
        printf("CPF invalido.\n");
    }
    
    return 0;
}

