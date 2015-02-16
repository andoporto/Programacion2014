#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "estructuras.h"


void crear_cola(t_cola *);
int poner_en_cola(t_cola *, const t_dato *);
int sacar_de_cola(t_cola *, t_dato *);
int cola_vacia(const t_cola *);
int cola_llena(const t_cola *);
void vaciar_cola(t_cola *);
int ver_frente_de_cola(const t_cola *, t_dato *);


#endif // COLA_H_INCLUDED
