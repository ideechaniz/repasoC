#include <stdio.h>

typedef union Persona Persona;

// los miembros de la union comparten el mismo espacio de memoria.
union Persona
{
    char nombre[20];
    char inicial;
};


int main()
{
    Persona iker = { "Iker"};
    printf("Nombre: %s \n", iker.nombre);
    printf("Inicial: %c\n", iker.inicial);
    return 0;
}
