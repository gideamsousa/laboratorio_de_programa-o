#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a = 25;
    int b = 2;
    
    printf("raiz quadrada de %d = %.2f\n", a, sqrt(a));
    printf("potencia de %d elevado a %d = %.2f\n", a, b, pow(a, b));
    printf("valor absoluto da -10 = %d\n", abs(-10));
    
    return 0;
}
