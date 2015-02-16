#include "varios.h"
#include <stdio.h>
#include <stdlib.h>


int obtener_digito(t_pila * p){
    int resul;

    if(pila_vacia(p))
        return 0;

    sacar_de_pila(p, &resul);
    return resul;
}

int cargar_numero(t_pila * p){
    char cad_num[100];
    char * act = cad_num;
    int dig;

    puts("Ingrese un numero: ");
    gets(cad_num);
    while(*act && !pila_llena(p)){
        dig = car_a_ent(*act);
        poner_en_pila(p, &dig);
        act++;
    }

    if(*act)
        return 0; //SALI DEL WHILE PORQUE LA PILA ESTABA LLENA Y NO POR HABER LLEGADO AL FINAL DE LA CADENA

    return 1;//TODO OK
}

int car_a_ent(char car){
    return car-'0';
}

//COMPARA T_DATO, SIENDO T_DATO UN ENTERO
int cmp_tdato(void * p1, void * p2){
    t_dato * a1 = (t_dato*) p1;
    t_dato * a2 = (t_dato*) p2;

    return (*a1) - (*a2);
}
