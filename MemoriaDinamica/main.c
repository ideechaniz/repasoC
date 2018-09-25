#include <stdio.h>
#include <stdlib.h> // para memoria dinamica.

void funcion(int *q);
void funcion2(void);

int main(int argc, char *argv[])
{
    int y; // Almacenado en pila, stack en ram.
    y= 6;
    int *q;
    q=&y;
    funcion(q);
    // almacenado en el heap, en memoria dinamica en ram.

    int *x;
    x= (int *) malloc(sizeof(int)); //devuelve un puntero void
    *x= 5;
    printf("%d\n", *x);
    free(x);

    int *p= NULL; // NULL es zero. No apunta a ningun lugar de la memoria.
    free(p); // si se puede liberar un puntero no utilizado.

    // CUIDADO ESTO NO SE PUEDE HACER:
   int z;
   int *t;
   z=5;
   t=&z; // el puntero tiene info estatica, no info dinamica, esta en la pila no el heap.
   free(t); // esto no se puede hacer.
    return 0;
}

void funcion(int *q)
{
    printf("%d\n",*q);
}

void funcion2(void){
    int y;
    y=5;
}
