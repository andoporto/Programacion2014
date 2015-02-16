#ifndef LISTA_DINAM_H_INCLUDED
#define LISTA_DINAM_H_INCLUDED
#include "estructuras.h"

void crear_lista(t_lista *);
int insertar_en_lista_ord(t_lista *, t_dato *, t_cmp);
void mostrar_lista(t_lista *);
int sacar_de_lista(t_lista *, t_dato *, t_cmp);
int buscar_en_lista(t_lista *, t_dato *, t_cmp);
int actualizar_lista(t_lista *, t_dato *, t_cmp, t_actualizar);
int actualizar_insertar_lista(t_lista *, t_dato *, t_cmp, t_actualizar);
void intercambiar_nodos(t_nodo **, t_nodo **);
void ordenar_lista(t_lista *, t_cmp);
t_nodo ** buscar_menor(t_lista *, t_cmp);
int insertar_en_lista_al_final(t_lista * plista, t_dato * pd);

#endif // LISTA_DINAM_H_INCLUDED
