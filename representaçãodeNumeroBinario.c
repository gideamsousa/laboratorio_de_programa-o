
#include <stdio.h>
#include <stdint.h>
#include <math.h>


void printBinaryFloat8(float num) {
    int sign = (num < 0) ? 1 : 0;
    int exponent = 0;
    int mantissa = 0;

    if (num != 0.0) {
        float absNum = fabsf(num);
        while (absNum >= 2.0) {
            absNum /= 2.0;
            exponent++;
        }
        while (absNum < 1.0) {
            absNum *= 2.0;
            exponent--;
        }
        mantissa = (int)(absNum * 16); 
    }

   
    if (exponent > 7) {
        exponent = 7;
    } else if (exponent < 0) {
        exponent = 0;
    }

    
    uint8_t binaryFloat = (sign << 7) | (exponent << 4) | mantissa;
    
    for (int i = 7; i >= 0; i--) {
        int bit = (binaryFloat >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    float numero;
    printf("Digite um número real: ");
    scanf("%f", &numero);

    printf("Representação de (8 bits) em binário: ");
    printBinaryFloat8(numero);
    printf("\n");

    return 0;
}
