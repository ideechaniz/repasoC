#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector Vector;

struct Vector
{
       float *arreglo;
       int tamanyo;
};

Vector *vector_nuevo(void);
void vector_libera(Vector *v);
void vector_agrega(Vector *v, float val);

void vector_muestra(const Vector *v);



#endif // VECTOR_H
