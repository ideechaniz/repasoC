#include <stdio.h>

int main()
{

    int x=3137;
    FILE  *archivo; // FILE es una estructura que ya existe

    archivo=fopen("/home/noise/prueba.txt","a");
    /*
     * r: read
     * w: write
     * a: append
     * b: binary
     */


    if( archivo == NULL) {
        printf("El archivo no se ha podido abrir\n");
        return 1;
    }
    fprintf(archivo,"Hello World! %d\n",x);

    fflush(archivo);
    fclose(archivo);

    return 0;
}
