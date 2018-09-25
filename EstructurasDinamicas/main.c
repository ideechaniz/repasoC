#include <stdio.h>
#include <stdlib.h>

typedef struct Persona Persona;

struct Persona
{
    char *nombre;
    int edad;
    float salario;
};

void imprime(const Persona *p);

int main(int argc, char *argv[])
{
    Persona luis; // estatico.
    luis.edad=5;

    Persona *juan, *pedro, *maria; // dinamico

    juan = (Persona *) malloc(sizeof(Persona));
    pedro= (Persona *) malloc(sizeof(Persona));
    maria= (Persona *) malloc(sizeof(Persona));

    juan-> nombre = "Juan";
    juan-> edad = 33;
    juan -> salario = 5000.0f;

    pedro->nombre= "Pedro";
    pedro-> edad=35;
    pedro-> salario= 5100.0f;

    maria-> nombre= "Maria";
    maria->edad=20;
    maria->salario=5700.0f;

    imprime(juan);
    imprime(pedro);
    imprime(maria);

    free(juan);
    free(pedro);
    free(maria);

    return 0;
}

void imprime(const Persona *p) // como no va a modificar lo paso constante.
{
    printf("nombre: %s\n", p->nombre);
    printf("Edad: %d\n", p->edad);
    printf("Salario: %f\n", p->salario);
    printf("\n");
}
