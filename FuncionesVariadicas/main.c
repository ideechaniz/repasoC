#include <stdio.h>
#include <stdarg.h>

double suma(int n, ...); // en la n hay que meterle cuantos parametros le paso.

int main()
{

    double x;
    x=suma(5, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f); // suma 15
    printf("%lf\n",x);

    x=suma(10, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 ,1.0 ,1.0, 1.0, 1.0); // suma 10
    printf("%lf\n",x);

    x=suma(2, 4.0, 5.0 ); // suma 9
    printf("%lf\n",x);

    return 0;
}

double suma(int n, ...)
{
    double valor,s;
    va_list parametros;      // es una estructura donde se van a guardar los parametros
    va_start(parametros, n); // es una macro que recible paramatros y la cantidad de parametros
    s=0.0f;
    for(int i=0; i<n; i++)
    {
        valor = va_arg(parametros, double); // sacamos los parametros.
        s+=valor;
    }
    va_end(parametros); // es una macro.
    return s;
}
