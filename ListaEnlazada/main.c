#include <stdio.h>
#include "lista.h"

int main()
{
    Lista *L;
    L= lista_nueva();
    lista_agrega(L, 1.2);
    lista_agrega(L, 3.9);
    lista_agrega(L, 10.5);
    lista_agrega(L, -1.7);

    lista_muestra(L);
    lista_libera(L);

    return 0;
}
