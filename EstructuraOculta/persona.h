#ifndef PERSONA_H
#define PERSONA_H

typedef struct Persona Persona;

Persona *personaNueva(const char *nombre, int edad, float salario);
void personaImprime(const Persona *p);
void personaLibera(Persona *p);

#endif // PERSONA_H
