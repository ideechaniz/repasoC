#include <stdio.h>

int main()
{
    int a=0;

    asm("movl %1,%0\n"
    : "=g" (a) //salida"
    :  "g" (5) //entrada
    : //clobbers
    );

    printf("a: %d\n", a);

    asm("movl %[valor_de_a],%[variable_a]\n"
    : [variable_a] "=g" (a)
    : [valor_de_a] "g" (7)
    : //clobbers
    );

    printf("a: %d\n", a);

    asm("movl %1, %%eax\n" // dos %
        "movl %%eax,%0\n"
        :"=g" (a)
        :"g" (8)
        : "%eax" // un %
        );

    printf("a: %d\n", a);

    a=0;
    int b=0,c=0,d=0,e=0;

    asm("movl %[val_a],%[a]\n"
        "movl %[val_b],%[b]\n"
        "movl %[val_c],%[c]\n"
        "movl %[val_d],%[d]\n"
        "movl %[val_e],%[e]\n"
        :[a] "=g" (a), [b] "=g" (b), [c] "=g" (c), [d] "=g" (d), [e] "=g" (e)
        :[val_a] "g" (1), [val_b] "g" (2), [val_c] "g" (3), [val_d] "g" (4), [val_e] "g" (5)
        : // no hay clobbers
    );


    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("e: %d\n", e);

    printf("\n");

    asm("movl %5,%0\n"
        "movl %6,%1\n"
        "movl %7,%2\n"
        "movl %8,%3\n"
        "movl %9,%4\n"
        :"=g" (a), "=g" (b), "=g" (c), "=g" (d), "=g" (e)
        :"g" (1),  "g" (2),  "g" (3),  "g" (4),  "g" (5)
        : // no hay clobbers
    );

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("e: %d\n", e);

    printf("\n");

    a=0;
    b=0;
    c=0;

    asm("movl %1,%0\n"
    : "=g" (a) //salida"
    :  "g" (1) //entrada
    : //clobbers
    );

    goto etiqueta;

/* en ensamblador no estan soportadas aun en Linux y mac
    asm goto("jmp %l0\n"
    : // no hay salidas
    : // no hay entradas
    : // no hay clobbers
    : etiqueta
    );
*/

    asm("movl %1,%0\n"
    : "=g" (b) //salida"
    :  "g" (2) //entrada
    : //clobbers
    );

    etiqueta:

    asm("movl %1,%0\n"
    : "=g" (c) //salida"
    :  "g" (3) //entrada
    : //clobbers
    );

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("\n");

    // multiplicacion:
    a=5;
    b=7;
    c=0;
    d=0;

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);


    asm("movl %2,%%eax\n"
        "movl %3, %%ebx\n"
        "mul %%ebx\n"
        "movl %%eax, %0\n"
        "movl %%ebx, %1\n"
    : "=g" (c), "=g" (d)// salidas
    : "g" (a), "g" (b)// entradas
    : // no hay clobbers
    );

    printf("\n");

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c); // resultado
    printf("d: %d\n", d);

    return 0;
}
