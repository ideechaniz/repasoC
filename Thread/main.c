#include <stdio.h>
#include <pthread.h> // posix thread.
#include <stdlib.h>
#include <unistd.h> // sleep.

void *procesoSeparado(void *data)
{
    char *texto= (char *) data;
    // struct timespec tiempo ={ 1,0 } ;//segundo =1 nanosegundo=0
    while(1)
    {
        printf("%s\n", texto);
       // pthread_delay_np(&tiempo); // np es no portable, no va en linux.
        sleep(1);
    }
}
int main()
{
    pthread_t proceso1;
    pthread_t proceso2;

    pthread_create(&proceso1, NULL, &procesoSeparado, "hola");
    pthread_create(&proceso2, NULL, &procesoSeparado, "adios");
    pthread_join(proceso1, NULL);
    pthread_join(proceso2,NULL);

    return 0;
}
