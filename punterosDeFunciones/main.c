#include <stdio.h>

int f1(int x, ...);
int f2(int x, ...); // los 3 puntos son para parametros ocultos.
int f3(void); // si no se pone nada es como los 3 puntos. void es para sin parametros.

void funcion(int (*p)(int, int), int a, int b);
int suma(int a, int b);
int resta(int a, int b);

int main(int argc, char *argv[])
{
    int (*p)(void); // recibe void y retorna int.

    p=f1;
    printf("%d\n", p() );

    p=f2;
    printf("%d\n", p() );

    p=f3;
    printf("%d\n", p() );

    funcion(suma, 3, 2);
    funcion(resta, 3, 2);


    return 0;
}

int suma(int a, int b)
{
   return a + b;
}

int resta(int a, int b)
{
   return a - b;
}

void funcion (int (*p)(int, int), int a, int b)
{
    int x;
    x=p(a,b);
    printf("%d\n", x);
}

int f1(int x,...)
{
    return 1;
}

int f2(int x,...)
{
    return 2;
}

int f3(void)
{
    return 3;
}
