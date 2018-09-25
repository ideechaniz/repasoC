#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *a, *b;
    a=(int *) calloc (5, sizeof(int));
    a[0]=5;
    a[1]=7;
    a[2]=9;
    a[3]=11;
    a[4]=13;

    for(int i=0; i<5; i++)
        printf("%d\n",a[i]);

    printf("\n ==============\n");
    b=(int *) calloc (5, sizeof(int));
    for(int i=0; i<5; i++)
        b[i]=a[i];

    free(a);
    a=(int *) calloc (10, sizeof(int));
    for(int i=0; i<5; i++)
        a[i]=b[i];

    free(b);
    a[5]=15;
    a[6]=17;
    a[7]=19;
    a[8]=21;
    a[9]=23;

    for(int i=0; i<10; i++)
         printf("%d ",a[i]);

    free(a);
    return 0;
}
