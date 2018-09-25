#include <stdio.h>

// Fijate donde termina el parantesis de _Generic abajo!
#define IMPRIME(x) _Generic((x),    int: imprimeInt,\
                                   char: imprimeChar,\
                                  float: imprimeFloat,\
                                 double: imprimeDouble,\
                            const char*: imprimeCharPtr,\
                                default: imprimeError)(x) //aqui termina

void imprimeInt(int i);
void imprimeChar(char c);
void imprimeFloat(float f);
void imprimeDouble(double d);
void imprimeError(void *p);
void imprimeCharPtr(const char *str);

int main()
{
    IMPRIME(1);
    IMPRIME((char) '@'); // hay que hacer cast para que no lo coja como entero.
    IMPRIME(3.4f);
    IMPRIME(5.6);
    IMPRIME((const char *) "cadena");
    IMPRIME("algo");

    return 0;
}

void imprimeInt(int i)
{
    printf("Entero %d\n",i);
}
void imprimeChar(char c)
{
    printf("char %c\n",c);
}
void imprimeFloat(float f)
{
    printf("Float %f\n",f);
}
void imprimeDouble(double d)
{
    printf("Double %lf\n",d);
}
void imprimeError(void *p)
{
    (void *) p; // no lo uso.
    printf("Va a ser que no\n");
}

void imprimeCharPtr(const char *str)
{
    printf("%s\n",str);
}
