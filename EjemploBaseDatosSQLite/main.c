#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sqlite3.h"

#define CREATE_TABLE_PERSONA\
    "CREATE TABLE IF NOT EXISTS persona" \
    "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL" \
    ", nombre TEXT NOT NULL" \
    ", edad INTEGER NOT NULL)"


typedef struct Persona Persona;
struct Persona
{
    char nombre[500];
    int edad;
    int id;
    Persona *siguiente;
};

void muestraLista(const Persona *lista);
int gestionaError(sqlite3 *db);
Persona *personaNueva(const Persona *persona);
void agregaPersona( Persona **lista, const Persona *persona);
void introduceDatos(const Persona *lista, sqlite3 *db);

int callback (void *ptr, int numeroDeColumnas, char **valoresCeldas, char **nombresDeColumnas)
{
    (void) ptr;
    for(int ix=0; ix< numeroDeColumnas; ++ix)
    {
        printf("%s: %s\n", nombresDeColumnas[ix], valoresCeldas[ix]);
    }
    printf("\n");
    return 0;
}

void leeBaseDatos(sqlite3 *db)
{
    // esto se ejecuta por cada registro.
    sqlite3_exec(db, "SELECT * FROM persona", callback, NULL, NULL);
}

int main()
{
    FILE *file=NULL;
    Persona persona;
    Persona *lista= NULL;
    sqlite3 *db = NULL;
    const char *filenameDatabase="/home/noise/ejemplo.db";
    const char *filenameLista="/home/noise/datos.txt";

    //abre la base de datos
    if (sqlite3_open(filenameDatabase, &db) != SQLITE_OK)
    {
        return gestionaError(db);
    }

    // configura base de datos
    if (sqlite3_exec(db, CREATE_TABLE_PERSONA, NULL, NULL, NULL) !=SQLITE_OK)
    {
        return gestionaError(db);
    }

    // lee lista
    file= fopen(filenameLista, "r");

    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file, "%s%d", persona.nombre, &persona.edad);
            agregaPersona(&lista, &persona);
        }
        fclose(file);
    }
    else
    {
        fprintf(stderr, "Error de apertura de archivo origen\n");
       // return ferror(file);
    }

    muestraLista(lista); // la que hemos cogido del fichero de datos.

    // introduce datos de la lista a la base de datos
    // SI VAS A EJECUTAR ESTO VARIAS VECES COMENTA LA LINEA DE ABAJO DESPUES DE LA PRIMERA
    introduceDatos(lista, db);

    // lectura de base de datos
    leeBaseDatos(db);

    // cerramos sqlite
    sqlite3_close(db);

    return 0;
}

void muestraLista(const Persona *lista)
{
    if (lista==NULL)
    {
        printf("lista vacia\n");
        return;
    }

    const Persona *ix = lista;
    while(ix!=NULL)
    {
        printf("ID: %d; Nombre: %s; Edad: %d\n", ix->id, ix->nombre, ix->edad);
        ix= ix->siguiente;
    }
}

int gestionaError(sqlite3 *db)
{
    fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
    return sqlite3_errcode(db);
}

Persona *personaNueva(const Persona *persona)
{
    Persona *p = (Persona *) malloc(sizeof(Persona));
    strcpy(p->nombre, persona->nombre);
    p->edad=persona->edad;
//  p->id = persona->id;
    p->id= -1;
    p->siguiente= NULL;

    return p;

}

void agregaPersona( Persona **lista, const Persona *persona)
{
    if (lista == NULL)
        return;

    if (*lista == NULL)
    {
        *lista= personaNueva(persona);
        return;
    }

    Persona *ix = *lista;
    while (ix->siguiente != NULL)
        ix= ix->siguiente;

    // agregar persona nueva al final de la lista
    ix->siguiente = personaNueva(persona);

}

void introduceDatos(const Persona *lista, sqlite3 *db)
{
    if (lista == NULL) return;

    const Persona *ix = lista;
    char sql[100];
    while(ix != NULL)
    {
        sprintf(sql, "INSERT INTO persona (nombre, edad) VALUES ('%s', %d)", // ID es autoincremental en el define.
                ix->nombre, ix->edad);

        if(sqlite3_exec(db,sql, NULL, NULL, NULL) != SQLITE_OK)
        {
            gestionaError(db);
            return;
        }
            ix=ix->siguiente;
    }
}
