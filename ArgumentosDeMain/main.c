#include <stdio.h>
#include <string.h> // strstr(*char completo, *char parte)


int main(int argc, char **argv, char **envp)
{

    printf("%d\n",argc);

    for(int i=0; i< argc; i++)
        printf("argumento[%d]: %s\n ",i, argv[i]);

    while(*envp)
    {
        char *s= *envp++;
        if (strstr(s,"USER"))
             printf("%s\n", s);
    }

    return 0;
}
