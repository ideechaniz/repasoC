#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int **matriz, nfilas, ncols;
    int i,j;

    nfilas=5;
    ncols=10;
    puts("hola");

    matriz= (int **) calloc(nfilas, sizeof(int *)); // fijate que es doble y el sizeof simple

    // reservar espacio para cada fila con n columnas.
    for (i=0; i<nfilas; i++)
        matriz[i] = (int *) calloc(ncols, sizeof(int)); // fijate que es simple y sizeof int
    // rellenarlos con valores
    for(i=0; i < nfilas; i++)
        for( j=0; j< ncols; j++)
            matriz[i][j] = i+j; // me da igual el valor, por poner algo.

    // sacar los valores (se podia haber hecho con un printf arriba es por separar)
    for(i=0; i<nfilas; i++)
    {
        for(j=0; j<ncols; j++)
            printf("%2d ", matriz[i][j] );

        printf("\n");
    }

    // Liberar memoria
    for (i=0; i<nfilas; i++)
        free(matriz[i]);

    free(matriz);


    return 0;
}
