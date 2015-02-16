#include "lista_dinam.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>

void crear_lista(t_lista * plista){
    *plista = NULL;
}

int insertar_en_lista_ord(t_lista * plista, t_dato * pd, t_cmp cmp){
    t_nodo * pnuevo;

    while(*plista && cmp(pd, &(*plista)->info) > 0){//REPITO MIENTRAS EL PD SEA MAYOR
        plista = &(*plista)->psig;
    }
    if(*plista && (cmp(pd, &(*plista)->info) ) == 0){
        return -1; //CODIGO DUPLICADO
    }

    pnuevo = (t_nodo*)malloc(sizeof(t_nodo));

    if(!pnuevo)
        return 0; //SIN MEMORIA

    pnuevo->info = *pd;
    pnuevo->psig = *plista;
    *plista = pnuevo;

    return 1;
}

void mostrar_lista(t_lista * plista){
    puts("#### LISTA ####");
    while(*plista){
        printf("\nDato: %d",(*plista)->info);
        plista = &(*plista)->psig;
    }
}

//BUSCA EN LA LISTA UN DATO POR MEDIO DE UNA REFERENCIA QUE RECIBE POR PARAMETRO Y
//LO ELIMINA, ADEMAS DEVUELVE LA INFO ENCONTRADA EN LA VARIABLE RECIBIDA
int sacar_de_lista(t_lista * plista, t_dato * pdato, t_cmp cmp){
    int resul = 1;
    t_nodo * nodo_elim;

    while(*plista && (resul = cmp(&(*plista)->info, pdato) ) < 0){
        plista = &(*plista)->psig;
    }
    if(*plista == NULL || resul > 0)
        return 0; //NO ENCONTRADO

    nodo_elim = (*plista);
    *pdato = (*plista)->info;
    *plista = (*plista)->psig;
    free(nodo_elim);

    return 1;
}

int buscar_en_lista(t_lista * plista, t_dato * pdato, t_cmp cmp){
    int resul;

    while(*plista && (resul = cmp(&(*plista)->info, pdato) ) < 0){
        plista = &(*plista)->psig;
    }
    if(*plista == NULL || resul > 0)
        return 0; //NO ENCONTRADO

    *pdato = (*plista)->info;
    return 1;
}

int actualizar_lista(t_lista * plista, t_dato * pdato, t_cmp cmp, t_actualizar actualizar){
    int resul;

    while(*plista && (resul = cmp(&(*plista)->info, pdato) ) < 0){
        plista = &(*plista)->psig;
    }
    if(*plista == NULL || resul > 0)
        return 0; //NO ENCONTRADO

    actualizar(&(*plista)->info, pdato);
    return 1;
}

//ACTUALIZA Y SI NO EXISTE INSERTA
int actualizar_insertar_lista(t_lista * plista, t_dato * pdato, t_cmp cmp, t_actualizar actualizar){
    int resul;
    t_nodo * pn;

    while(*plista && (resul = cmp(&(*plista)->info, pdato) ) < 0){
        plista = &(*plista)->psig;
    }
    if(*plista && (resul = cmp(&(*plista)->info, pdato) ) == 0){
        actualizar(&(*plista)->info, pdato);
    }else{
        pn = (t_nodo*)malloc(sizeof(t_nodo));

        if(pn == NULL)
            return 0; //SIN MEMORIA

        pn->psig = *plista;
        *plista = pn;
        pn->info = *pdato;
    }
    return 1;
}
//NO ES PRIMITIVA, ES FUNCION UTILITARIA PARA RESOLVER UNA PRIMITIVA (PUNTUALMENTE ORDENAR)
void intercambiar_nodos(t_nodo ** ppn1, t_nodo ** ppn2){
    t_nodo * pn1, * pn2, * psig, * paux;

    if((*ppn2)->psig == *ppn1){
        //POR LAS DUDAS QUE SEAN ADYACENTES Y ADEMAS ESTEN APUNTANDO AL REVES
        paux = *ppn1;
        *ppn1 = *ppn2;
        *ppn2 = paux;
    }
    if((*ppn1)->psig == *ppn2){
        //GUARDO EN VARIABLES AUXILIARS LAS DIRECCIONES
        //SOLO ENTRO ACA CUANDO SEAN ADYACENTES
        pn1 = *ppn1;
        pn2 = *ppn2;
        psig = pn2->psig;

        //EMPIEZO..
        *ppn1 = pn2;
        *ppn2 = psig;
        pn2->psig = pn1;
    }else{
        //ENTRO POR ESTE ELSE CUANDO NO SEAN ADYACENTES
        paux = (*ppn1)->psig;
        (*ppn1)->psig = (*ppn2)->psig;
        (*ppn2)->psig = paux;

        paux = *ppn1;
        *ppn1 = *ppn2;
        *ppn2 = paux;
    }
}

void ordenar_lista(t_lista * plista, t_cmp cmp){
    t_nodo ** pi, ** pmenor;

    if(*plista == NULL)
        return;
    pi = plista;
    while((*pi)->psig){
        pmenor = buscar_menor(pi, cmp);
        if(*pi != *pmenor)
            intercambiar_nodos(pi, pmenor);
        pi = &(*pi)->psig;
    }
}

t_nodo ** buscar_menor(t_lista * plista, t_cmp cmp){
    t_nodo ** pmenor = plista;
    t_nodo ** pact = &(*plista)->psig;
    while(*pact){
        if(cmp(&(*pact)->info, &(*pmenor)->info) < 0)
            pmenor = pact;
        pact = &(*pact)->psig;
    }
    return pmenor;
}

//INSERTA EN LISTA SIN ORDENAR
int insertar_en_lista_al_final(t_lista * plista, t_dato * pd){
    t_nodo * pnuevo;

    while(*plista){
        plista = &(*plista)->psig;
    }

    pnuevo = (t_nodo*)malloc(sizeof(t_nodo));

    if(!pnuevo)
        return 0; //SIN MEMORIA

    pnuevo->info = *pd;
    pnuevo->psig = *plista;
    *plista = pnuevo;

    return 1;
}
