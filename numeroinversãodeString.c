#include <stdio.h>
#include <string.h>

void printString(char* str) {
    printf("String: %s\n", str);
}

void printStringLength(char* str) {
    int length = strlen(str);
    printf("Número de caracteres: %d\n", length);
}

void printStringReversed(char* str) {
    printf("String invertida: ");
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[] = "boa noite, professor";

    // Imprimir a string
    printString(str);

    // Contar o número de caracteres
    printStringLength(str);

    // Inverter a string
    printStringReversed(str);

    return 0;
}

