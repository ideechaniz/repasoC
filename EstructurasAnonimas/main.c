#include <stdio.h>
// estructuras anonimas

struct // aqui no le pongo nombre;
{
    int a;
    float b;
    double d;
    char c;
    int *x[10];
} m,n; // variables globales.

// esto no se puede hacer. typedef m MiEstructuraNueva;

int main(int argc, char *argv[])
{

   // esto no lo veria. MiEstructuraNueva a,b,c;

    m.a=7;

    printf("Hello World!\n");
    return 0;
}
