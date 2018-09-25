#include <stdio.h>

typedef struct Punto Punto;
typedef struct Persona Persona;


struct Persona
{
    char *nombre;
    int edad;
    struct Punto
    {
           float x,y;
    } p;
};


int main(int argc, char *argv[])
{
    Persona juan={ "Juan", 20, { -4.5f, 10.0f} };
    /*
    juan.nombre= "Juan";
    juan.edad= 20;
    juan.p.x= -5.4f;
    juan.p.y=10.0f;
    */
    printf("Nombre: %s\n", juan.nombre);
    printf("Edad: %d\n", juan.edad);
    printf("P(%f,%f)\n", juan.p.x, juan.p.y);
    return 0;
}
