#include "pila.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>

//PRIMITIVAS DE PILA ESTATICA

void crear_pila(t_pila * p){
    p->tope = -1;
    p->tam = TAM;
}

void vaciar_pila(t_pila * p){
    p->tope = -1;
}

int poner_en_pila(t_pila * p, const t_dato * dato){

    if(pila_llena(p))
       return PILA_LLENA;

    p->tope++;
    p->v[p->tope] = *dato;

    return TODO_OK;
}

int sacar_de_pila(t_pila * p, t_dato * dato){
    if(pila_vacia(p))
        return PILA_VACIA;

    *dato = p->v[p->tope];
    p->tope--;
    return TODO_OK;
}

int tope_de_pila(const t_pila* p, t_dato * dato){
    if(pila_vacia(p))
        return PILA_VACIA;

    * dato = p->v[p->tope];
    return TODO_OK;
}

int pila_llena(const t_pila * p){
    if(p->tope == p->tam -1)
        return 1;
    return 0;
}

int pila_vacia(const t_pila * p){
    if(p->tope == -1)
        return 1;
    return 0;
}



//PRIMITIVAS DE PILA DINAMICA
/*
int crear_pila(t_pila * p){
    p->tope = -1;
    p->tam = TAM;
}

void vaciar_pila(t_pila * p){
    p->tope = -1;
}

int poner_en_pila(t_pila * p, const t_dato * dato){

    if(pila_llena(p))
       return PILA_LLENA;

    p->tope++;
    p->v[p->tope] = *dato;

    return TODO_OK;
}

int sacar_de_pila(t_pila * p, t_dato * dato){
    if(pila_vacia(p))
        return PILA_VACIA;

    *dato = p->v[p->tope];
    p->tope--;
    return TODO_OK;
}

int tope_de_pila(const t_pila* p, t_dato * dato){
    if(pila_vacia(p))
        return PILA_VACIA;

    * dato = p->v[p->tope];
    return TODO_OK;
}

int pila_llena(const t_pila * p){
    if(p->tope == p->tam -1)
        return 1;
    return 0;
}

int pila_vacia(const t_pila * p){
    if(p->tope == -1)
        return 1;
    return 0;
}
*/
