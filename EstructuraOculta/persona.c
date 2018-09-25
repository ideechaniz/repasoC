#include <stdio.h>
#include <stdlib.h>
#include "persona.h"


struct Persona
{
    const char* nombre;
    int edad;
    float salario;
};


Persona *personaNueva(const char *nombre, int edad, float salario)
{
    Persona *p= (Persona *) malloc(sizeof(Persona));
    p->nombre = nombre;
    p->edad= edad;
    p->salario= salario;
    return p;
}
void personaImprime(const Persona *p)
{
    printf("%s, %d, %f\n", p->nombre, p->edad, p->salario);
}
void personaLibera(Persona *p)
{
    free(p);
}
