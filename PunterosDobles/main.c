#include <stdio.h>

int main(int argc, char *argv[])
{
    int x,y;
    int *p, *q, **t;

    x=5;
    p=&x;

    y=6;
    q=&y;

    printf("%d\n",*p);
    printf("%d\n",*q);

    t=&p; // ahora t apunta a p
    printf("%d\n", **t);

    *t=&y;
    printf("%d\n", **t);


    return 0;
}
