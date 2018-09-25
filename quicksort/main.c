#include <stdio.h>
#include <stdlib.h>


int compara_enteros(const void *p, const void *q);
int compara_flotantes(const void *p, const void *q);

int main(int argc, char *argv[])
{
        int i, ta,tb; // tamaño de a y b
        int a[] = { 10,6, -23, 48, 1,2,3,7,6,5 };
        float b[]= { 1.78f, -7.45f, 90.56f, 3.456 };

        int (*p1)(const void *, const void *); // variable puntero a funcion.
        p1=&compara_enteros; // el ampersand se puede quitar.

        ta = sizeof(a) / sizeof (int);
        tb= sizeof(b) /sizeof(float);
        qsort(a,ta,sizeof(int), p1);
        qsort(b,tb,sizeof(float), &compara_flotantes);

        for (i=0; i< ta; i++)
            printf("%d ", a[i] );
        printf("\n");

        for (i=0; i< tb; i++)
            printf("%d ", b[i] );
        printf("\n");

    return 0;
}


int compara_enteros(const void *p, const void *q)
{
    int x,y;
    x=* (int *) p;
    y= *(int *) q;
    if (x>y)
            return -1;
    if (x == y)
            return 0;
    return 1;
}

int compara_flotantes(const void *p, const void *q)
{
    float x,y;
    x= *(float *) p;
    y= *(float *) q;
    if (x>y)
            return -1;
    if (x == y)
            return 0;
    return 1;
}

