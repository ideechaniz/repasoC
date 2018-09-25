#include <stdio.h>
#include <string.h>
#include <stdlib.h> // para NULL

int main()
{
    char contenido[] = "1,2,3,4,5.6.7.8.9.10";
    char *token;
    int sumaTotal;

    sumaTotal=0;
    token = strtok(contenido,",."); // El separador es la coma y/o el punto
    if (token == NULL)
    {
            puts("no hay separadores");
            return 1;
    }

    sumaTotal+=atoi(token);
    while(token!= NULL)
    {
        token= strtok(NULL, ",."); // fijate aqui para sacar el resto.
        if (token!=NULL)
            sumaTotal+= atoi(token);
    }

    printf("Suma total= %d\n",sumaTotal); // 55
    return 0;
}
