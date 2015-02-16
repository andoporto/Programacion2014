#include "cola_dinamica.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>

void crear_cola_din(t_cola_dinam * pcola){
    pcola->pfrente = pcola->pfondo = NULL;
}

int poner_en_cola_din(t_cola_dinam * pcola, const t_dato * pd){
    //ASIGNO MEMORIA Y LUEGO PREGUNTO SI SE HIZO BIEN
    t_nodo * pn = (t_nodo *)malloc(sizeof(t_nodo));
    if(pn == NULL)  //ó if(!pn)
        return 0; //SIN MEMORIA

    pn->info = *pd;
    pn->psig = NULL;
    //AHORA ME FIJO SI LA COLA TIENE ALGUN ELEMENTO, ASI HAGO QUE ESE ELEMENTO APUNTE A MI NUEVO NODO.
    if(pcola->pfondo)
        pcola->pfondo->psig = pn;
    else{
        pcola->pfrente = pn;
    }
    pcola->pfondo = pn;
    return 1;
}

int sacar_de_cola_din(t_cola_dinam * pcola, t_dato * pd){
    t_nodo * aux;

    if(!pcola->pfrente)
        return 0;
    aux = pcola->pfrente;
    *pd = aux->info;
    pcola->pfrente = aux->psig;

    //TENGO QUE FIJARME SI EL QUE ELIMINE ERA EL UNICO QUE QUEDABA, EN ESE CASO TENGO QUE PONER EN NULL PFONDO
    if(!pcola->pfrente)
        pcola->pfondo = NULL;

    free(aux);

    return 1;
}

int cola_vacia_din(const t_cola_dinam * pcola){
    if(pcola->pfrente == NULL)
        return 1; //COLA VACIA
    return 0;
}

int cola_llena_din(const t_cola_dinam * pcola){
    t_nodo * aux;

    aux = (t_nodo *)malloc(sizeof(t_nodo));
    //INTENTO TOMAR MEMORIA Y SI ES IGUAL A NULL QUIERE DECIR QUE NO HAY MAS MEMORIA
    if(aux == NULL)
        return 1; //SIN MEMORIA

    //SI NO FUE NULL QUIERE DECIR QUE HAY MEMORIA, ENTONCES LIBERO ESA MEMORIA Y DEVUELVO 0, OSEA HAY MEMORIA, NO ESTA LLENA.
    free(aux);

    return 0;
}

void vaciar_cola_din(t_cola_dinam * pcola){
    t_nodo * aux;

    while(pcola->pfrente){
        aux = pcola->pfrente;
        pcola->pfrente = pcola->pfrente->psig;
        free(aux);
    }
    pcola->pfondo = NULL;
}

int ver_frente_de_cola_din(const t_cola_dinam * pcola, t_dato * pd){
    if(!pcola->pfrente)
        return 0;

    *pd = pcola->pfrente->info;

    return 1;
}

void mostrar_cola(t_cola_dinam * pcola){
    t_nodo * pact = pcola->pfrente;

    puts("### COLA ###");
    printf("\nEste es el frente (por aca se saca)'");
    while(pact){
        printf("\nDato: %d", pact->info);
        pact = pact->psig;
    }
    printf("\nEste es el fondo (por aca se pone)");
}
