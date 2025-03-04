#include <stdio.h>
#include <string.h>

// Função para converter um caractere romano em seu valor decimal
int romanToDecimal(char r) {
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1; // Caractere inválido
    }
}

// Função para converter uma string de números romanos para decimal
int convertRomanToDecimal(const char *roman) {
    int total = 0; // Total acumulado do valor decimal
    int prevValue = 0; // Valor do caractere romano anterior
    int currentValue; // Valor do caractere romano atual

    // Iterar sobre cada caractere da string romana
    for (int i = 0; i < strlen(roman); i++) {
        currentValue = romanToDecimal(roman[i]); // Converter caractere romano para decimal
        if (currentValue == -1) {
            // Se o caractere for inválido, imprimir mensagem de erro e retornar -1
            printf("Erro: Input invalido '%c' na posicao %d\n", roman[i], i + 1);
            return -1;
        }

        // Se o valor atual for maior que o valor anterior, ajustar o total
        if (currentValue > prevValue) {
            total += currentValue - 2 * prevValue;
        } else {
            total += currentValue;
        }
        prevValue = currentValue; // Atualizar o valor anterior
    }

    return total; // Retornar o valor decimal total
}

int main() {
    char roman[100]; // Buffer para armazenar a entrada do usuário
    int result; // Resultado da conversão

    // Loop infinito para continuar pedindo entrada do usuário
    while (1) {
        printf("Digite um numero em numeracao romana: ");
        scanf("%s", roman); // Ler a entrada do usuário

        result = convertRomanToDecimal(roman); // Converter a entrada para decimal
        if (result != -1) {
            // Se a conversão for bem-sucedida, imprimir o resultado
            printf("O valor decimal de %s e %d\n", roman, result);
        } else {
            // Se houver um erro na conversão, imprimir mensagem de erro
            printf("Erro na conversao do numero romano. Tente novamente.\n");
        }
    }

    return 0; // Retornar 0 para indicar que o programa terminou com sucesso
}