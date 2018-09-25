#include <stdio.h>
#include <string.h>

int main()
{
    char *palabra ="Hola";
    char frase[20] ="Hola"; // recuerda que el ultimo es \0
    char nombre[50];

    strcpy(nombre, "Mortadelo y Filemon");

    printf("%s\n", nombre);

    if (strcmp(palabra,frase) == 0 ){
        printf("ambos son iguales\n");
    } // con -1 si son diferentes.

    strcat(frase,palabra);
    printf("doble hola=%s\n",frase);

    // memset para inicializar con un valor concreto.
    char x[50], y[50];
    memset(x, '@', 49); // el 50 es para el \0
    printf("%s\n", x);


    return 0;
}
