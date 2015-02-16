#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fechas.h"

int comparar_fechas( const t_fecha* f1 , const t_fecha* f2 )
{
    if(f1->a == f2->a)
    {
        if(f1->m == f2->m)
            return f1->d < f2->d ? -1 : f1->d > f2->d ? 1 : 0;

        return f1->m < f2->m ? -1 : f1->m > f2->m ? 1 : 0;
    }

    return f1->a < f2->a ? -1 : f1->a > f2->a ? 1 : 0;
}

unsigned long int fecha_a_num( const t_fecha* fecha )
{
    unsigned long int acum = 0;
    acum += fecha->a * 365 + fecha->a / 4 - fecha->a / 100 + fecha->a / 400;
    acum += dia_juliano( fecha );
    return acum;
}

unsigned int dia_juliano( const t_fecha* fecha )
{
    int i;
    int acum = 0;
    for ( i = 1 ; i < fecha->m ; i++)
    {
        acum += cant_dias_mes( i , fecha->a );
    }
    acum += fecha->d;
    return acum;
}

int cant_dias_mes( int m , int a )
{
    switch( m )
    {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return es_bisiesto( a ) + 28;
        default:
            return 31;
    }
}

int es_fecha_valida( const t_fecha* fecha )
{

    return  fecha->a>=1601
            && fecha->m > 0 && fecha->m<13
            && fecha->d > 0 && fecha->d <= cant_dias_mes( fecha->m , fecha->a ) ? 1 : 0;
}


void pedir_fecha(t_fecha * f_proc)
{
    int marca;
    printf("Ingrese la fecha de hoy separada por espacios. DD MM AAAA \n");
    do
    {
        scanf("%d %d %d", &f_proc->d, &f_proc->m, &f_proc->a);
        if(!es_fecha_valida(f_proc))
        {
            marca=1;
            printf("Fecha incorrecta, vuelva a intentarlo \n");
        }
        else
            marca=0;
    } while(marca == 1);

}

void suma_dias( t_fecha* fecha , int n )
{
    if(n<0)
        resta_dias(fecha, -n);
        else{
            fecha->d += n;
            while( fecha->d > cant_dias_mes( fecha->m , fecha->a ) )
            {
                fecha->d -= cant_dias_mes( fecha->m , fecha->a );
                fecha->m++;
                if( fecha->m > 12 )
                {
                    fecha->m = 1;
                    fecha->a++;
                }
            }
        }
}

void resta_dias( t_fecha* fecha , int n )
{
    fecha->d -= n;
    while( fecha->d <= 0)
    {
        fecha->d += cant_dias_mes( fecha->m-1 , fecha->a );
        fecha->m--;
        if( fecha->m <= 0 )
        {
            fecha->m = 12;
            fecha->a--;
        }
    }
}


int difDiasFechas(t_fecha *f1, t_fecha *f2){
    int fe1, fe2, flag = 0;
    fe1 = fecha_a_num2(f1);
    fe2 = fecha_a_num2(f2);
    if(fe1 > fe2){
        intercambiar_fechas(f1, f2);
        flag = 1;
    }
    int dif = f2->d - f1->d;
    int mesCurso = f1->m;
    int anioCurso = f1->a;

    if(!mesMenor(mesCurso,anioCurso,f2->m,f2->a)){
        if(dif < 0)
            dif = dif * (-1);
        int m2 = f2->m, a2 = f2->a;
        while(mesMenor(m2,a2,mesCurso,anioCurso)){
            dif += cant_dias_mes(m2,a2);
            m2++;
            if(m2 == 13){
                m2 = 1;
                a2++;
            }
        }
        return dif * (-1);
    }

    while(mesMenor(mesCurso,anioCurso,f2->m,f2->a)){
        dif += cant_dias_mes(mesCurso,anioCurso);
        mesCurso++;
        if(mesCurso == 13){
            mesCurso = 1;
            anioCurso++;
        }
    }
    if(flag == 1)
        dif *= -1;

    return dif;
}

//DEVUELVE UN NUMERO POSITIVO SI EL 1ER MES ES MENOR QUE EL 2DO Y VICEVERSA, SI SON IGUALES DEVUELVE CERO.
int mesMenor(int m1, int a1, int m2, int a2){
    int n1 = a1 * 100 + m1;
    int n2 = a2 * 100 + m2;
    //return (n1 < n2?1:(n1==n2?0:-1));
    return n2-n1;
}
void intercambiar_fechas(t_fecha * f1, t_fecha * f2){
    t_fecha aux;
    aux.a = f1->a;
    aux.m = f1->m;
    aux.d = f1->d;

    f1->a = f2->a;
    f1->m = f2->m;
    f1->d = f2->d;

    f2->a = aux.a;
    f2->m = aux.m;
    f2->d = aux.d;

    return;
}

long int fecha_a_num2(t_fecha * f1){
    long int resul = 0;
    resul += f1->a * 10000 + f1->m * 100 + f1->d;
    return resul;
}

int pedir_fecha_sin_valid(t_fecha * f_proc){
    printf("Ingrese la fecha de hoy separada por espacios. DD MM AAAA \n");
    scanf("%d %d %d", &f_proc->d, &f_proc->m, &f_proc->a);
    if(!es_fecha_valida(f_proc))
        return 0;
    return 1;
}
