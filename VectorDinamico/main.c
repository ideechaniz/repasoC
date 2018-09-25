#include <stdio.h>
#include "vector.h"

// Un vector es un arreglo dinamico

int main()
{

    Vector *v;
    v=vector_nuevo();
    vector_agrega(v, 2.3); //son valores float, estan bien.
    vector_agrega(v, 0.5);
    vector_agrega(v, 100.0);
    vector_agrega(v, -200);
    vector_agrega(v, -3.5);

    vector_muestra(v);
    vector_libera(v);

    return 0;
}
