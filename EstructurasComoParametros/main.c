#include <stdio.h>

typedef struct Persona Persona;

struct Persona
{
    char *nombre;
    int edad;
    float salario;
};

void persona_muestra(const Persona *p); //const para no poder cambiarlo por error.

int main(int argc, char *argv[])
{
    Persona pedro = { "Pedro", 25, 1000.0f };
    Persona juan  = { "Juan", 30, 5000.0f };
    persona_muestra(&pedro);
    persona_muestra(&juan);
    return 0;
}

void persona_muestra(const Persona *p) //cuesta menos pasar por referencia.
{
    printf("Nombre: %s\n", p->nombre);
    printf("Edad: %d\n", p->edad);
    printf("Salario: %f\n", p->salario);
    printf("\n");
}
