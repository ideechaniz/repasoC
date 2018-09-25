#include <stdio.h>

#define IMPRIME(formato, ...) \
    printf("%s(%d): " formato "\n", __FILE__,__LINE__,##__VA_ARGS__)

int main()
{
    IMPRIME("Algo %d", 1);
    IMPRIME("Numeros %d %d %d", 1,2,3);
    IMPRIME("Nada");

    return 0;
}
