#include <stdio.h>


void muestra( int p[], int t);

int main(int argc, char *argv[])
{

    int a[]={ 1,2,3,4,5,6,7,8,9,10 };
    int t= sizeof(a)/ sizeof(int);

    //printf("%d\n",t);
    muestra(a,t);
    return 0;
}

void muestra(int *p, int t){

    for (int i=0; i<t; ++i)
        printf("%d ", p[i]);
    printf("\n");

}
