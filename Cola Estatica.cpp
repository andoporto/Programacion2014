#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#ifndef IDENFITICADORES
#define TAM 		  4
#define SUCCESS     1
#define ERROR		  0
#define FULL_QUEUE   0
#define EMPTY_QUEUE -1
#endif

typedef struct
{
    long dni;
    char *apyn;
} t_info;

typedef struct
{
    t_info info[TAM];
    int pri,
        ult;
} t_cola;

void CrearCola   ( t_cola *p );
void VaciarCola  ( t_cola *p );
int  ColaLlena   ( const t_cola *p );
int  ColaVacia   ( const t_cola *p );
int  PonerEnCola ( t_cola *p, const t_info *d );
int  SacarDeCola ( t_cola *p, t_info *d );

void mostrar ( const t_cola *p );
int  cargar ( t_info *d );
void putbomb ( t_cola *p);
char menu (const char *string, const char *opc);

int main()
{
    t_cola cola;
    t_info info;

    char opcion;
    CrearCola(&cola);

    printf ("STATIC QUEUE PROGRAM\n\
   			\r====================\n\n");
    while (!ColaLlena(&cola))
    {
        cargar(&info);
        PonerEnCola (&cola, &info);
    }

    mostrar (&cola);
    getch();

    do
    {
        opcion = menu("STATIC QUEUE PROGRAM\n\
   						\r======================\n\
   						\rQue desea hacer ahora?:\n\
   	  		 		   \r1- Sacar de la Cola\n\
			   	      \r2- Poner en la Cola\n\
			      	   \r3- Mostrar la Cola\n\
			         	\r4- Salir\n", "1234");

        switch ( opcion )
        {
        case '1':
            SacarDeCola(&cola, &info);
            break;
        case '2':
            if (ColaLlena(&cola))
            {
                printf("\nCola Llena. Imposible agregar\n");
                getch();
            }
            else
            {
                cargar(&info);
                PonerEnCola(&cola, &info);
            }
            break;
        case '3':
            mostrar(&cola);
            getch();
        default:
            break;
        }
    }
    while ( opcion!='4');

    while (!ColaVacia(&cola))
        SacarDeCola(&cola, &info);
    mostrar (&cola);
    printf("\n");
    return 0;
}


void CrearCola  (t_cola *p)
{
    p->pri=0;
    p->ult=-1;
}


void VaciarCola (t_cola *p)
{
    p->pri=0;
    p->ult=-1;
}


int  ColaLlena  (const t_cola *p)
{
    return p->pri==0 && p->ult==TAM-1 ||
           p->pri==p->ult+1 && p->ult!=-1;
}


int  ColaVacia  (const t_cola *p)
{
    return p->ult==-1;
}


int  PonerEnCola (t_cola *p, const t_info *d)
{
    if ( p->pri==0 && p->ult==TAM-1 ||
            p->pri==p->ult+1 && p->ult!=-1)
        return FULL_QUEUE;
    else
    {
        if (p->ult==TAM-1)
        {
            p->ult=p->pri-1;
            p->info[p->ult]=*d;
        }
        else
            p->info[++p->ult]=*d;
        return SUCCESS;
    }
}


int  SacarDeCola (t_cola *p, t_info *d)
{
    if (p->pri==0 && p->ult==-1)
        return EMPTY_QUEUE;
    else
    {
        *d=p->info[p->pri];

        if ( p->pri==p->ult)
        {
            p->pri=0;
            p->ult=-1;
        }
        else
        {
            if (p->pri==TAM-1)
            {
                p->pri=0;
            }
            else
                p->pri++;
        }

        return SUCCESS;
    }
}


void mostrar (const t_cola *p)
{
    int mark=p->pri;

    system("CLS");

    if (p->ult!=-1)
    {
        printf("DNI\t\tApellido y Nombre\n\
      		  \r=======================================================\n");
        while ( mark!=p->ult+1 )
        {
            printf("%08ld\t%s\n", p->info[mark].dni,
                   p->info[mark].apyn?p->info[mark].apyn:"-");

            if (mark==TAM-1)
                mark=0;
            else
                mark++;
        }
    }
    else
        printf("\nCola Vacía\n");


}



int cargar (t_info *d)
{
    char aux[300];

    printf ("D.N.I.: ");
    fflush(stdin);
    scanf  ("%ld", &d->dni);

    if (!d->dni)
        return ERROR;

    printf ("Apellido y Nombre: ");
    fflush (stdin);
    gets   (aux);

    d->apyn=(char *)malloc(strlen(aux));

    if (d->apyn)
    {
        strcpy(d->apyn,aux);
        return SUCCESS;
    }
    else
        return ERROR;
}


char menu (const char *string, const char *opc)
{
    char choice;
    do
    {
        system ("CLS");
        printf(string);
        scanf("%c", &choice);

    }
    while( !strchr(opc,choice) );

    return choice;
}


