#include "pila_dinam.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>

void crear_pila_din(t_pila_dinam * ppila){   //OJO QUE LO QUE LE MANDO ES UN DOBLE PUNTERO PORQUE T_PILA_DINAM YA ES UN TIPO PUNTERO
    *ppila = NULL;
}

int poner_en_pila_din(t_pila_dinam * ppila, const t_dato * pd){
    t_nodo * pnuevo;
    pnuevo = (t_nodo*) malloc(sizeof(t_nodo));
    if(!pnuevo)
        return 0;

    pnuevo->info = *pd;
    pnuevo->psig = *ppila;
    *ppila = pnuevo;

    return 1;
}

int sacar_de_pila_din(t_pila_dinam * ppila, t_dato * pd){
    t_nodo * aux;

    if(!*ppila)
        return 0;

    aux = *ppila;
    *pd = (*ppila)->info;   //ESTOY HACIENDO UNA COPIA DE LA INFO, Y NO HACER QUE EL PUNTERO PD APUNTE A LA INFO
    *ppila = (*ppila)->psig;   //ó aux->psig;
    free(aux);

    return 1;
}

int tope_de_pila_din(const t_pila_dinam * ppila, t_dato * pd){
    if(!*ppila)
        return 0;

    *pd = (*ppila)->info;   //ESTOY HACIENDO UNA COPIA DE LA INFO, Y NO HACER QUE EL PUNTERO PD APUNTE A LA INFO

    return 1;
}

int pila_vacia_din(const t_pila_dinam * ppila){
    return *ppila == NULL;  //DEVUELVE VERDAD CUANDO ESTA VACIA
}

int pila_llena_din(const t_pila_dinam * ppila){
    void * p;
    p = malloc(sizeof(t_nodo));
    free(p);
    //NO IMPORTA QUE HAGA EL FREE, PORQUE AUNQUE ESA MEMORIA NO ESTÉ DISPONIBLE, EL CONTENIDO DE P SIGUE IGUAL.
    if(!p)  //if(p==NULL)
        return 1;   //P era null, entonces malloc devolvió null, entonces no hay mas memoria, entonces pila llena.
    return 0;
}

//ESTA FORMA ES FACIL Y RAPIDA, PERO NO SE DEBERIAN USAR PRIMITIVAS, ASIQUE SE COMENTA.
/*
void vaciar_pila_din(t_pila_dinam * ppila){
    t_dato dato;    //NO LO NECESITO PARA NADA, SOLO LO CREO PORQUE SACAR DE PILA NECESITA RECIBIR UN T_DATO
    while(!pila_vacia_din(ppila)){  // *ppila != NULL ó while(*ppila)
        sacar_de_pila_din(ppila, &dato);
    }
}
*/

void vaciar_pila_din(t_pila_dinam * ppila){
    t_nodo * aux;

    while(*ppila){
        aux = *ppila;
        *ppila = aux->psig;
        free(aux);
    }
}

//NO ES PRIMITIVA
void mostrar_pila(t_pila_dinam * pila){
    puts("##### PILA ######");
    while(*pila){
        printf("\nDato: %d",(*pila)->info);
        pila = &(*pila)->psig;
    }
}
