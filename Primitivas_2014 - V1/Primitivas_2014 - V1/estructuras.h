#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#define TODO_OK 1

//HAY QUE DEFINIR SI ES CERO O UNO PILA LLENA Y VACIA
#define PILA_LLENA 0
#define PILA_VACIA 0

#define TAM 6

#define VERDADERO 1
#define FALSO 0


//DESCOMENTAR LUEGO DEL EJEMPLO DE CLASE Y SACAR LO QUE ESTA A CONTINUACION DE LO COMENTADO.
/*
typedef struct{
    int num;
}t_dato;
*/
typedef int t_dato;

typedef struct{
    t_dato v[TAM];
    int tam;
    int tope;
}t_pila;


typedef struct s_nodo{
    t_dato info;
    struct s_nodo * psig;
}t_nodo;

typedef t_nodo * t_pila_dinam;
typedef t_nodo * t_lista;   //ES IGUAL A PILA DINAMICA, LA DIFERENCIA ES SEMANTICAMENTE. ES DECIR, NOSOTROS LOS VEMOS
                            //DISTINTOS PERO EN CUANTO A CODIGO SON IGUALES.

typedef struct{
    int * vec;
    int ce; //CANT ELEM
    int cap;
}t_vec_din;

//IMPLEMENTACION ESTATICA DE COLA
typedef struct{
    int frente;
    int fondo;
    t_dato vec[TAM];
}t_cola;

//IMPLEMENTACION DINAMICA DE COLA
typedef struct{
    t_nodo * pfrente;
    t_nodo * pfondo;
}t_cola_dinam;

typedef int (*t_cmp)(void *, void*);
typedef void (*t_actualizar)(void*, void*);

#endif // ESTRUCTURAS_H_INCLUDED
