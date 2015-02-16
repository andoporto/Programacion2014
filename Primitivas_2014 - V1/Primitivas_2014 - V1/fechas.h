#ifndef UTIL_FECHAS_H_INCLUDED
#define UTIL_FECHAS_H_INCLUDED


typedef struct
{
    int d , m , a;
} t_fecha;

#define es_bisiesto(x)( !((x)%4) && (x)%100 ? 1 : !((x)%400) ? 1 : 0 )

int comparar_fechas( const t_fecha* fecha1 , const t_fecha* fecha2 );
unsigned long int fecha_a_num( const t_fecha* fecha );
unsigned int dia_juliano( const t_fecha* fecha );
int cant_dias_mes( int m , int a );
int es_fecha_valida( const t_fecha* fecha );
void pedir_fecha(t_fecha*);

//SI RECIBE UN NUMERO POSITIVO LO SUMA A LA FECHA RECIBIDA Y SI ES UN NUMERO NEGATIVO LO RESTA
void suma_dias( t_fecha* , int );

//A LA FECHA RECIBIDA SE LE RESTA EL ENTERO POSITIVO QUE SE RECIBE
void resta_dias( t_fecha* , int );

int difDiasFechas(t_fecha *, t_fecha *);

//DEVUELVE UN NUMERO POSITIVO SI EL 1ER MES ES MENOR QUE EL 2DO Y VICEVERSA, SI SON IGUALES DEVUELVE CERO.
int mesMenor(int , int , int , int);

void intercambiar_fechas(t_fecha *, t_fecha *);
long int fecha_a_num2(t_fecha *);

int pedir_fecha_sin_valid(t_fecha *);


#endif // UTIL_FECHAS_H_INCLUDED
