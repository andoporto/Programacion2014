#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED
#include "estructuras.h"

void crear_cola_din(t_cola_dinam *);
int poner_en_cola_din(t_cola_dinam *, const t_dato *);
int sacar_de_cola_din(t_cola_dinam *, t_dato *);
int cola_vacia_din(const t_cola_dinam *);
int cola_llena_din(const t_cola_dinam *);
void vaciar_cola_din(t_cola_dinam *);
int ver_frente_de_cola_din(const t_cola_dinam *, t_dato *);
void mostrar_cola(t_cola_dinam *);

#endif // COLA_DINAMICA_H_INCLUDED
