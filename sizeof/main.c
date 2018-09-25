#include <stdio.h>

int main(int argc, char *argv[])
{


    int x;

    x=sizeof(char); // sizeof en bytes
    printf("char %d\n",x);

    x=sizeof(short);
    printf("short %d\n",x);

    x=sizeof(long); // equivalente a int
    printf("long %d\n",x);

    x=sizeof(unsigned int); // el tamaño no cambia si es signed o unsigned.
    printf("uint %d\n",x);

    x=sizeof(long long int);
    printf("long long int %d\n",x);


    x=sizeof(int);
    printf("int %d\n",x);

    x=sizeof(float);
    printf("float %d\n",x);

    x=sizeof(double);
    printf("double %d\n",x);


    x=sizeof(main);
    printf("main %d\n",x);

    x=sizeof(void); // ocupa un byte
    printf("void %d\n",x);

    int *p;
    x=sizeof(p);
    printf("puntero %d\n",x); // estoy en 64 bits ocupan 8, en 32 bits ocupan 4.


    int a[10];
    x=sizeof(a);
    printf("array de 10 int %d \n",x); // pero un puntero apuntando a un array ocupa
    return 0;                           // 4 y 8 bytes solo.


}
