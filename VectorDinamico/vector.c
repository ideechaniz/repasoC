#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

Vector *vector_nuevo(void)
{
    Vector *v;
    v= (Vector *) malloc(sizeof(Vector));
    v->arreglo = NULL;
    v->tamanyo=0;
    return v;
}
void vector_libera(Vector *v)
{
    free(v->arreglo);
    free(v);
}
void vector_agrega(Vector *v, float val)
{
    int i;
    float *a;
    a =(float *) calloc(v->tamanyo+1, sizeof(float) );
    for(i=0; i< v->tamanyo; i++)
        a[i]= v->arreglo[i];

    a[ v->tamanyo ]=val;
    free(v->arreglo);
    v->arreglo =a;
    v->tamanyo++;
}

void vector_muestra(const Vector *v)
{
    int i;
    printf("El vector es:\n");
    for(i=0; i<v->tamanyo; i++)
        printf("%f ", v->arreglo[i]);
    printf("\n");
}
