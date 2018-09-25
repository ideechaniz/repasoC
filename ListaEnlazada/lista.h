#ifndef LISTA_H
#define LISTA_H

typedef struct Lista Lista;
typedef struct Nodo Nodo;

struct Nodo
{
    float val;
    Nodo *siguiente;
};

struct Lista
{
    Nodo *inicio;
};

Lista *lista_nueva(void);
void lista_agrega(Lista *L, float val);
void lista_muestra(const Lista *L);
void lista_libera(Lista *L);



#endif // LISTA_H
