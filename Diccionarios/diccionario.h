#ifndef DICCIONARIO_H
#define DICCIONARIO_H

typedef struct Pareja Pareja;
typedef struct Diccionario Diccionario;

struct Pareja {
    const char *llave;
    const char *valor;
};

struct Diccionario {
    Pareja **parejas;
    int tamanyo;
};


Diccionario *diccionario_nuevo(void);
void diccionario_agrega(Diccionario *D, const char *llave, const char *valor);

void diccionario_muestra(const Diccionario *D);
void diccionario_aumenta(Diccionario **D, int unidades);
void diccionario_copia(const Diccionario *Do, Diccionario *Dd, int unidades); // origen y destino
void diccionario_libera(Diccionario *D);
void diccionario_inicializa_contenido(Diccionario *D);


#endif // DICCIONARIO_H
