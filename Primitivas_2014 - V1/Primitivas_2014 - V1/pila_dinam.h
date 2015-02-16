#ifndef PILA_DINAM_H_INCLUDED
#define PILA_DINAM_H_INCLUDED
#include "estructuras.h"

//PRIMITIVAS
void crear_pila_din     (t_pila_dinam * );   //OJO QUE LO QUE LE MANDO ES UN DOBLE PUNTERO PORQUE T_PILA_DINAM YA ES UN TIPO PUNTERO
int poner_en_pila_din   (t_pila_dinam *, const t_dato *);
int sacar_de_pila_din   (t_pila_dinam *, t_dato *);
int tope_de_pila_din    (const t_pila_dinam *, t_dato *);
int pila_vacia_din      (const t_pila_dinam *);
int pila_llena_din      (const t_pila_dinam *);
void vaciar_pila_din    (t_pila_dinam *);

//NO ES PRIMITIVA
void mostrar_pila(t_pila_dinam *);

#endif // PILA_DINAM_H_INCLUDED
