#include <stdio.h>

void inicia(void) __attribute__ ((constructor));
void finaliza(void) __attribute ((destructor));

int main()
{
    printf("Hello World!\n");
    return 0;
}

void inicia(void){
    printf("iniciando la aplicacion\n");
}

void finaliza(void)
{
    printf("finalizando la aplicacion\n");
}
