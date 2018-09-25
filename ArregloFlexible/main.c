#include <stdio.h>
#include <stdlib.h>

typedef struct Test Test;

struct Test
{
    int len;
    int array[];
};

int main()
{
    // Al declarar una variable tipo Test se le dice cuanto ocupa su array.
    // Se pueden declarar tantas como se quiera, ej con diferente tamaño cada una.
    Test *T= (Test *) malloc(sizeof(Test)+10*sizeof(int)); // para array de 10
    T->len= 10;
    for( int i=0; i<T->len; i++)
        T->array[i]=i;

    for(int i=0; i<T->len; i++)
        printf("%d ", T->array[i]);

    free(T);
    T=NULL;
    return 0;
}
