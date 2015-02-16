#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "estructuras.h"

//PRIMITIVAS DE PILA ESTATICA

void crear_pila     (t_pila *);
int poner_en_pila   (t_pila *, const t_dato *);
int sacar_de_pila   (t_pila *, t_dato *);
int tope_de_pila    (const t_pila*, t_dato *);
int pila_llena      (const t_pila *);
int pila_vacia      (const t_pila *);
void vaciar_pila    (t_pila *);

//PRIMITIVAS DE PILA DINAMICA
/*
int crear_pila_din      (t_pila *);
int poner_en_pila_din   (t_pila *, const t_dato *);
int sacar_de_pila_din   (t_pila *, t_dato *);
int tope_de_pila_din    (const t_pila*, t_dato *);
int pila_llena_din      (const t_pila *);
int pila_vacia_din      (const t_pila *);
void vaciar_pila_din    (t_pila *);
*/

#endif // PILA_H_INCLUDED
