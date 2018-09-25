#include "diccionario.h"
//#include <stdlib.h>
#include <stdio.h>

void diccionario_muestra(const Diccionario *D)
{
    int i;
    for(i=0; i< D->tamanyo; i++){
        printf("%s: %s\n", D->parejas[i]->llave,
                           D->parejas[i]->valor);
    }
}

void diccionario_aumenta(Diccionario **D, int unidades)
{
    Diccionario *E = diccionario_nuevo();
    E->tamanyo = (**D).tamanyo;
    E->parejas= (Pareja **) calloc(E->tamanyo, sizeof(Pareja));
    diccionario_inicializa_contenido(E);
    diccionario_copia(*D, E, E->tamanyo);
    diccionario_libera(*D);
    *D = diccionario_nuevo();
    (**D).tamanyo = E->tamanyo + unidades;
    (**D).parejas = (Pareja **) calloc((**D).tamanyo, sizeof(Pareja) );
    diccionario_inicializa_contenido(*D);
    diccionario_copia(E, *D, E->tamanyo);
    diccionario_libera(E);
}

void diccionario_copia(const Diccionario *Do, Diccionario *Dd, int unidades)
{
    //Do origen y Dd destino
    for(int i=0; i< unidades; i++)
    {
        Dd->parejas[i]->llave = Do->parejas[i]->llave;
        Dd->parejas[i]->valor = Do->parejas[i]->valor;
    }
}

void diccionario_libera(Diccionario *D)
{
    for(int i=0; i< D->tamanyo ; i++)
        free(D->parejas[i]);

    free(D->parejas);
    free(D);
    D=NULL;
}

void diccionario_inicializa_contenido(Diccionario *D)
{
    for(int i=0; i< D->tamanyo; i++)
    {
        D->parejas[i] = (Pareja *) malloc(sizeof(Pareja));
        D->parejas[i] ->llave = NULL;
        D->parejas[i] ->valor = NULL;
    }
}

void diccionario_agrega(Diccionario *D, const char *llave, const char *valor)
{
    diccionario_aumenta(&D, 1);
    D->parejas[D->tamanyo -1] -> llave = llave;
    D->parejas[D->tamanyo -1] -> valor = valor;
}

Diccionario *diccionario_nuevo(void)
{
    Diccionario *D=(Diccionario *) malloc(sizeof(Diccionario));
    D->parejas=NULL;
    D->tamanyo=0;
    return D;
}
