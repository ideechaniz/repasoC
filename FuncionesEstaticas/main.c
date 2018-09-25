#include <stdio.h>
#include "otro.h"

//int suma(int a, int b); // no vale robar el prototipo si tiene static

int main()
{

    imprime();
//    printf("%d\n", suma (1,3)); // si era static no puedes acceder desde aqui.
    return 0;
}
