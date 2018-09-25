#include <stdio.h>

int main()
{
    int x;

    FILE *archivo;
    fprintf(stdout, "Hello World!\n");

    fprintf(stdout, "mete un numero: ");
    archivo=stdin;

    fscanf(archivo, "%d", &x);
    fprintf(stdout, "El valor metido ha sido este %d \n",x);

    return 0;
}
