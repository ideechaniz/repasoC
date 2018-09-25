#include <stdio.h>
#include <stdlib.h>

int * funcion(void)
{
    int *x; // almacenado en la pila o sea desaparece cuando la funcion termina.
    x= (int *) malloc (sizeof(int));
    return x;
}
int main(int argc, char *argv[])
{

    int *p;
    p=funcion();
    *p=5;
    printf("%d\n", *p);

    free(p);
    return 0;
}
