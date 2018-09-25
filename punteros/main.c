#include <stdio.h>

int main(int argc, char *argv[])
{

// Punteros basico
    int x=5;
    int *pt= &x; // esto es igual que int *pt; pt=&x;

    printf("0x%X  %p\n",&x,&x); // cuidado no uses x para p porque no cabe.
    printf("%p\n",pt);

    printf("%d\n",*pt); // dame el valor contenido en la variable original

// Aritmetica de punteros
puts("==========================================");
    int a[10] = { 1,2,33,4,5,6,7,8,9,10 };
    for(int i=0; i!=10; i++)
    {
        printf("%p ",&a[i]);  printf("%d\n",*(a+i)); // los enteros ocupan 4 bytes.
    }

    x=5;
    int *p;
    int *q;

    q=&x;
    p=q;
    // ahora dos punteros apuntan a la misma variable
    printf("%p\n",p);
    printf("%p\n",q);
    printf("%p\n",&x);

    *p=6; // como poner x=6;
    *q=7; // como poner x=7;

    printf("%d\n", *p); // saldra 7;

    return 0;
}
