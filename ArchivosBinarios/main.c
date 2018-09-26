#include <stdio.h>
#include <stdlib.h>

typedef struct Persona Persona;
#define NOMBRE_ARCHIVO "/home/noise/empleados.bin"

struct Persona
{
     char nombre[256];
     int edad;
     double salario;
};

int escribeArchivo(Persona empleados[], int tam, const char *nombreArchivo);
int leeArchivo(Persona empleados[], int tam, const char *nombreArchivo);
void imprimeEmpleados(Persona empleados[], int tam);
void imprimePersona(Persona *persona);

int main()
{
    Persona empleados[]= { {"Juan", 25, 5000.0 },
                           {"Ana", 30, 6000.0 },
                           {"Luis", 40, 7000.0 },
                           {"Franchisco", 50, 8000.0 } };

    const int tam= sizeof(empleados) / sizeof(Persona);
    Persona empleadosEntrada[tam];

    if(!escribeArchivo(empleados, tam, NOMBRE_ARCHIVO))
    {
        printf("Error de escritura\n");
        return 1;
    }

    if (!leeArchivo(empleadosEntrada, tam, NOMBRE_ARCHIVO))
    {
        printf("Error de lectura\n");
        return 2;
    }

    imprimeEmpleados(empleadosEntrada, tam);

    return 0;
}

int escribeArchivo(Persona empleados[], int tam, const char *nombreArchivo)
{
    FILE *F;
    F= fopen(nombreArchivo, "wb");
    if (F==NULL)return 0;

    for(int i=0; i< tam; i++)
        fwrite(&empleados[i], sizeof(Persona), 1, F);

    fclose(F);
    return 1;
}
int leeArchivo(Persona empleados[], int tam, const char *nombreArchivo)
{
    FILE *F;
    F= fopen(nombreArchivo, "rb");
    if (F == NULL) return 0;

    for(int i=0; i< tam; i++)
    fread(&empleados[i], sizeof(Persona),1,F);
    fclose(F);
    return 1;
}

void imprimeEmpleados(Persona empleados[], int tam)
{
    for(int i=0; i<tam; i++)
        imprimePersona(&empleados[i]);
}

void imprimePersona(Persona *persona)
{
    printf("Nombre: %s\n", persona->nombre);
    printf("Edad: %d\n", persona->edad);
    printf("Salario: %lf\n\n", persona->salario);


}
