#include <stdio.h>
#include "persona.h"

int main()
{

    Persona *p = personaNueva("Juan", 34, 5000.0);
    personaImprime(p);
    personaLibera(p);
    return 0;
}
