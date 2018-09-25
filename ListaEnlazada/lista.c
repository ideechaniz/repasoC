#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


Lista *lista_nueva(void)
{
    Lista *L;
    L= (Lista *) malloc (sizeof(Lista));
    L->inicio = NULL;
    return L;
}

void lista_agrega(Lista *L, float val)
{
    Nodo *n, *m;
    if(L->inicio == NULL) {
        L->inicio = (Nodo *) malloc(sizeof(Nodo));
        L->inicio->val = val;
        L->inicio->siguiente = NULL;
        return;
    }

    n = L->inicio;
    while(n!=NULL)
    {
        m=n;
        n=n->siguiente;
    }
    m->siguiente = (Nodo *) malloc(sizeof(Nodo));
    m->siguiente->siguiente = NULL;
    m->siguiente->val= val;
}

void lista_muestra(const Lista *L)
{
    Nodo *i;
    for(i= L->inicio; i!= NULL; i=i->siguiente)
        printf("%f ", i->val);
    printf("\n");
}

void lista_libera(Lista *L)
{

    Nodo *n, *m;
    if (L->inicio == NULL)
        return;

    if(L->inicio->siguiente == NULL)
    {
        free(L->inicio);
        free(L);  // free libera pero no lo pone a null.
        L=NULL;
        return;
    }

    n= L->inicio;
    m= L->inicio->siguiente;

    while(m->siguiente!=NULL){
        n=n->siguiente;
        m=m->siguiente; // m solo recorre la lista hasta casi el final
    }

    n->siguiente = NULL; // n->siguiente aqui es m pero lo queremos quitar.
    free(m); // y lo limpiamos.
    m=NULL;
    lista_libera(L);
}
