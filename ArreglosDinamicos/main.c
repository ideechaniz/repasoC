#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *a; // la ventaja es que puede ser de cualquier tamaño.
    a=calloc(5, sizeof(int)); // calloc para arrays.

    a[0]= 6;
    a[1]= -512;
    a[2]= 2001;
    a[3]= -3;
    a[4]= 10;

    for (int i=0; i<5; i++)
        printf("%d\n", a[i]);

    free(a);
    return 0;
}
