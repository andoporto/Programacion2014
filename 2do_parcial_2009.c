#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct dato_archivo1
{
    int cod_ven;
    int mes;
    int num;
    int cant;
};

struct dato_archivo2
{
    int cod_ven;
    char nombre[21];
};

struct dato
{
    int cod_ven;
    int cant_inv;
};

struct nodo
{
    struct dato d;
    struct nodo *sig;
};

void crear_lista( struct nodo ** );
int genera_lista( struct nodo **, struct dato_archivo1 );

int main()
{
    struct dato_archivo1 ventas;
    struct dato_archivo2 vende;
    struct nodo *lista;
    FILE *archivo1, *archivo2;
    int total_ven[21][13]= {{0}}, cant = 0, suma = 0;
    float prome = 0;

    crear_lista( &lista );

    if( ( archivo1 = fopen( "vtas2006.dat", "rb" ) ) == NULL )
    {
        printf( "Error al abrir el archivo\n" );
        getch();
        exit( 0 );
    }

    fread( &ventas, sizeof( struct dato_archivo1 ), 1, archivo1 );
    while( !feof( archivo1 ) )
    {
        if( ventas.cant < 0 )
        {
            if( genera_lista( &lista, ventas ) )
                printf( "La lista esta llena\n" );
        }

        total_ven[ventas.cod_ven - 1][ventas.mes - 1] += ventas.cant;
        total_ven[ventas.cod_ven - 1][12] += ventas.cant;
        suma += ventas.cant;
        cant ++;
        fread( &ventas, sizeof( struct dato_archivo1 ), 1, archivo1 );
    }

    prome = suma / cant;

    fclose( archivo1 );


    if( ( archivo2 = fopen( "vendedores.dat", "rb" ) ) == NULL )
    {
        printf( "Error al abrir el archivo\n" );
        exit( 0 );
    }
    printf( "Nombre del vendedor   mes1 mes2 mes3 mes4 mes5 mes6 mes7 mes8 mes9 mes10 mes11 mes12\n\n" );

    fread( &vende, sizeof( struct dato_archivo2 ), 1, archivo2 );
    while( !feof( archivo2 ) )
    {
        if( total_ven[vende.cod_ven - 1][12] > prome )
            printf( "%s %d %d %d %d %d %d %d %d %d %d %d %d\n", vende.nombre, total_ven[vende.cod_ven - 1][0],
                    total_ven[vende.cod_ven - 1][1], total_ven[vende.cod_ven - 1][2], total_ven[vende.cod_ven - 1][3],
                    total_ven[vende.cod_ven - 1][4], total_ven[vende.cod_ven - 1][5], total_ven[vende.cod_ven - 1][6],
                    total_ven[vende.cod_ven - 1][7], total_ven[vende.cod_ven - 1][8], total_ven[vende.cod_ven - 1][9],
                    total_ven[vende.cod_ven - 1][10], total_ven[vende.cod_ven - 1][11], total_ven[vende.cod_ven - 1][12] );
        fread( &vende, sizeof( struct dato_archivo2 ), 1, archivo2 );
    }

    fclose( archivo2 );
}


void crear_lista( struct nodo **l )
{
    *l = NULL;
}



int genera_lista( struct nodo **lista , struct dato_archivo1 x )
{
    struct nodo *nuevo, *ant = *lista, *act = *lista;
    int a = 0;

    nuevo = (struct nodo * ) malloc( sizeof( struct nodo ) );
    if( nuevo == NULL )
    {
        a = 1;
        return( a );
    }

    nuevo->d.cod_ven = x.cod_ven;
    nuevo->d.cant_inv = 0;
    while( act  &&  x.cod_ven > act->d.cod_ven )
    {
        ant = act;
        act = act->sig;
    }

    if( act  &&  x.cod_ven == act->d.cod_ven )
    {
        act->d.cant_inv ++;
        free( nuevo );
    }
    else
    {
        if( *lista == NULL )
            *lista = nuevo;
        else
        {
            if( ant == act )
            {
                nuevo->sig = act;
                *lista = nuevo;
            }
            else
            {
                ant->sig = nuevo;
                nuevo->sig = act;
            }
        }
    }
    return( a );
}
