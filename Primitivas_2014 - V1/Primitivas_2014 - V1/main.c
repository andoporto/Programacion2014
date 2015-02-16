#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fechas.h"
#include "estructuras.h"
#include "pila.h"
#include "varios.h"
#include "pila_dinam.h"
#include "cola.h"
#include "cola_dinamica.h"
#include "lista_dinam.h"

int main()
{

    printf("Hola Mundo!\n");


//EJERCICIO LISTA DINAMICA (FUNCIONANDO)
//INICIO

    t_lista lista;
    t_dato dato = 1;

    crear_lista(&lista);

    do{
        printf("\nIngrese dato (cero para terminar -1 para sacar): ");
        fflush(stdin);
        scanf("%d",&dato);
        if(dato < 0){
            printf("\nIngrese dato que desea sacar: ");
            fflush(stdin);
            scanf("%d",&dato);
            sacar_de_lista(&lista, &dato, cmp_tdato);
        }else{
            //DE LAS DOS LINEAS SIGUIENTES VA UNA COMENTADA Y LA OTRA NO
            insertar_en_lista_ord(&lista, &dato, cmp_tdato);
            //insertar_en_lista_al_final(&lista, &dato);
        }
        system("cls");
        mostrar_lista(&lista);
    }while(dato != 0);

    ordenar_lista(&lista,cmp_tdato);
    mostrar_lista(&lista);

//FIN



//EJERCICIO COLA DINAMICA (FUNCIONANDO)
//INICIO EJ1
/*
    t_cola_dinam cola;
    t_dato dato;

    crear_cola_din(&cola);
    do{
        printf("\nIngrese dato (cero para terminar -1 para sacar): ");
        fflush(stdin);
        scanf("%d",&dato);
        if(dato < 0){
            if(!sacar_de_cola_din(&cola, &dato))
                puts("Sin datos para sacar");
        }else{
            if(dato > 0)
                if(!poner_en_cola_din(&cola, &dato))
                    puts("Cola llena");
        }
        system("cls");
        mostrar_cola(&cola);
    }while(dato != 0);
*/
//FIN EJ 1



//EJERCICIO PILA DINAMICA (FUNCIONANDO)
//INICIO
/*
    int cant = 0;
    t_pila_dinam pila;
    t_dato dato;

    crear_pila_din(&pila);

    srand(7);

    if(pila_vacia_din(&pila)){
        puts("\nPila vacia, se procede a cargarla..");
        while(cant < TAM){
            dato = rand()%100;
            poner_en_pila_din(&pila, &dato);
            cant++;
        }
    }


    while(!pila_vacia_din(&pila)){
        sacar_de_pila_din(&pila, &dato);
        printf("\nDato: %d", dato);
    }

    do{
        puts("\nIngrese numero a poner en pila (-1 para sacar - 0 para terminar)");
        fflush(stdin);
        scanf("%d", &dato);

        if(dato < 0){
            if(sacar_de_pila_din(&pila,&dato)){
                system("cls");
                mostrar_pila(&pila);
                printf("\n\nDato extraido: %d\n",dato);
            }
            else{
                puts("\nPila vacia, imposible sacar de pila!");
            }
        }
        else{
            if(poner_en_pila_din(&pila, &dato)){
                system("cls");
                mostrar_pila(&pila);
            }
            else{
                puts("\nNo hay memoria, imposible poner en pila!");
            }
        }
    }while(dato != 0);

*/
//FIN



//EJERCICIO DE PILA ESTATICA (FUNCIONANDO)
//INICIO
/*
    t_pila pila1, pila2, pila_resul;
    int var1, var2, res, carry = 0;

    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pila_resul);

    cargar_numero(&pila1);
    cargar_numero(&pila2);

    while(!pila_vacia(&pila1) || !pila_vacia(&pila2)){
        var1 = obtener_digito(&pila1);
        var2 = obtener_digito(&pila2);
        res = var1 + var2 + carry;
        carry = res/10;
        res %= 10;
        if(!poner_en_pila(&pila_resul, &res)){
            puts("Error!! Pila llena!!");
            exit(0);
        }
    }
    if(carry != 0){
        if(!poner_en_pila(&pila_resul, &carry)){
            puts("Error!! Pila llena!!");
            exit(0);
        }
    }

    printf("\nDato: ");
    while(!pila_vacia(&pila_resul)){
        sacar_de_pila(&pila_resul, &res);
        printf("%d", res);
    }

*/
//FIN


//EJERCICIO DE ASIGNACION DINAMICA DE MEMORIA
//INICIO
/*
    t_vec_din * vec_din;
    int ce = 6, creado;
    size_t cap = 7;


    creado = crear_vec(vec_din, cap);

    srand(7);
    while(vec_din->ce < cap){
        vec_din->vec = (int *) rand();
        vec_din->ce ++;
    }

    mostrar_vec(vec_din,ce);
    //insertar_elementos(vec_din, &ce, &cap);
    //ordenar_vec(vec_din, ce);
//    mostrar_vec(vec_din,ce);
//    eliminar_vec(vec_din);

*/
//FIN

//EJERCICIO1 MUESTRA DE FECHAS
//INICIO
/*
    t_fecha fecha, fecha1, fecha2;
    int suma = 1;

    pedir_fecha(&fecha);
    printf("\n\nFecha (DD-MM-AA): %d-%d-%d",fecha.d,fecha.m,fecha.a);
    while(suma != 0){
        printf("\n\nIngrese los dias a sumarle a la fecha anterior (cero para terminar): ");
        scanf("%d",&suma);
        suma_dias(&fecha, suma);
        printf("\n\nFecha sumada: %d-%d-%d",fecha.d,fecha.m,fecha.a);
    }

    //EJERCICIO2 MUESTRA DE FECHAS
    printf("\n\nIngrese fecha para luego comparar con otra..\n");
    pedir_fecha(&fecha1);
    while(fecha1.a != 0){
        printf("\n\nIngrese fecha a comparar con la anterior..\n");
        pedir_fecha(&fecha2);
        printf("\n\nComparacion de fechas = %d",difDiasFechas(&fecha1,&fecha2));
    }
*/
//FIN

    return 0;
}
