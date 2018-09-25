
static int suma(int a, int b) // no se puede usar fuera de otro.c
{
  return a+b;
}

void imprime(void)
{
    int x;
    x=suma(1,2);
    printf("%d\n",x);
}
