#include "cola.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>


//PONGO POR EL FONDO SACO POR EL FRENTE
//HAY QUE REVISAR TODO


void crear_cola(t_cola * pcola){
    pcola->frente = 0;
    pcola->fondo = -1;
}

int poner_en_cola(t_cola * pcola, const t_dato * pd){
    if( ( pcola->fondo + 1 ) % TAM == pcola->frente && pcola->fondo != -1){
       return 0; //COLA LLENA, NO PUEDO PONER
    }
    pcola->fondo++;
    pcola->vec[pcola->fondo] = (int) *pd;

    return 1;
}

int sacar_de_cola(t_cola * pcola, t_dato * pd){
    if(pcola->frente == 0 && pcola->fondo == -1)
        return 0; //COLA VACIA, NO PUEDO SACAR

    *pd = pcola->vec[pcola->frente];
    pcola->frente++;

    if( ( pcola->fondo + 1 ) %TAM == pcola->frente){ //PREGUNTO SI LA COLA QUEDO VACIA, SI QUEDO ASI ENTRO AL IF
        pcola->frente = 0;
        pcola->fondo = -1;
    }
    return 1;
}

int cola_vacia(const t_cola * pcola){
    if(pcola->frente == 0 && pcola->fondo == -1)
        return 1; //COLA VACIA
    return 0;
}

int cola_llena(const t_cola * pcola){
    if( ( pcola->fondo + 1 ) %TAM == pcola->frente && pcola->fondo != -1)
        return 1; //COLA LLENA
    return 0;
}

void vaciar_cola(t_cola * pcola){
    pcola->frente = 0;
    pcola->fondo = -1;
}

int ver_frente_de_cola(const t_cola * pcola, t_dato * pd){
    if(pcola->frente == 0 && pcola->fondo == -1)
        return 0; //COLA VACIA, NO PUEDO SACAR

    *pd = pcola->vec[pcola->frente];
    return 1;
}
