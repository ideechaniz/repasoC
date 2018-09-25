#include <stdio.h>
#include "diccionario.h"

int main()
{
    Diccionario *D = diccionario_nuevo();
    diccionario_agrega(D, "Linux", "Derivado de GNU");
    diccionario_agrega(D, "FreeBSD", "Derivado de Unix");
    diccionario_agrega(D, "MacOS", "Derivado de FreeBSD");
    diccionario_agrega(D, "Windows", "Derivado de MSDOS");
    diccionario_muestra(D);
    diccionario_libera(D);

    return 0;
}
