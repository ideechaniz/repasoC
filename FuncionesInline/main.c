#include <stdio.h>

int suma(int a, int b);

inline int suma(int a, int b)
{
    return a+b;
}

int main()
{
    int x;
    x=suma(3,4);
    printf("%d\n",x);
    return 0;
}
