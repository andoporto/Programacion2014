#include <stdio.h>
#include <stdlib.h>

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
    char apyn[10];
} t_info;

typedef struct s_nodo
{
    t_info info;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo *t_lista;

/*PRIMITIVAS Y FUNCIONES DE LISTAS*/
/////////////////////////////////////////////////////
void CrearLista ( t_lista *p );
unsigned  VaciarLista ( t_lista *p );
/////////////////////////////////////////////////////
int  		 ListaLlena  	  ( const t_lista *p );
int  		 ListaVacia  	  ( const t_lista *p );
/////////////////////////////////////////////////////
int  		 InsertarEnOrden ( t_lista *p , const t_info *d );
int 		 InsertarAlFinal ( t_lista *p , const t_info *d );
void 		 OrdenarLista    ( t_lista *p );
unsigned  EliminaDup      ( t_lista *p );

/*FUNCIONES AUXILIARES*/
int comparar ( const t_info *d1 , const t_info *d2 );
int ingresar ( t_info *d );
void mostrar ( t_lista *p );

int main()
{
    t_lista lista;
    t_info  info;

    CrearLista(&lista);
    while (!ListaLlena (&lista) && ingresar(&info) )
        InsertarAlFinal (&lista,&info);

    OrdenarLista(&lista);
    EliminaDup(&lista);

    mostrar(&lista);

    system("PAUSE");

    //printf("Se han eliminado %d nodos de la lista\n", EliminaDup(&lista));

    return 0;
}



void CrearLista  ( t_lista *p )
{
    *p=NULL;
}


unsigned  VaciarLista ( t_lista *p )
{
    t_nodo *aux;
    unsigned total=0;

    while (*p)
    {
        aux=*p;
        p=&(*p)->sig;
        free(aux);
        total++;
    }

    return total;
}


int  ListaLlena  ( const t_lista * )
{
    return malloc(sizeof(t_nodo))==NULL;
}


int  ListaVacia  ( const t_lista *p )
{
    return *p==NULL;
}


int  InsertarEnOrden ( t_lista *p , const t_info *d )
{
    while ( *p && comparar( &(*p)->info , d )>0 )
        p=&(*p)->sig;

    t_nodo *nue = (t_nodo*) malloc (sizeof(t_nodo));

    if (nue)
    {
        nue->info=*d;
        nue->sig=*p;
        *p=nue;
        return SUCCESS;
    }
    else
        return ERROR;
}

int  InsertarAlFinal ( t_lista *p , const t_info *d )
{
    while (*p)
        p=&(*p)->sig;

    t_nodo *nue=(t_nodo *)malloc (sizeof(t_nodo));

    if (nue)
    {
        nue->info=*d;
        nue->sig=NULL;
        *p=nue;
        return SUCCESS;
    }
    else
        return ERROR;

}

/*
void OrdenarLista    ( t_lista *p )
{
	t_nodo *prv,  //Previous: Anterior
   		 *cur,  //Current:  Actual
          *nxt;  //Next:     Proximo
   int mark=1;

   while (mark)
   {
   	mark=0;
      prv=NULL;
      cur=*p;
      nxt=(*p)->sig;

      while (cur && nxt)
      {
      	if ( comparar( &cur->info, &nxt->info ) > 0 )
         {
         	mark=1;
            cur->sig=nxt->sig;
            nxt->sig=cur;

            if (prv)
            	prv->sig=nxt;
         }

         cur=nxt;
         nxt=cur->sig;
      }
   }
}
*/
void OrdenarLista ( t_lista *p )
{
    int marca=1;
    t_lista *q,
            aux;

    if (*p)
    {
        while (marca)
        {
            marca=0;
            q=p;

            while ( (*q)->sig )
            {
                if ( comparar ( &(*q)->info , &(*q)->sig->info ) > 0 )
                {

                    aux=*q;
                    *q=aux->sig;
                    aux->sig=(*q)->sig;
                    (*q)->sig=aux;
                    marca=1;
                }

                q=&(*q)->sig;
            }
        }
    }
}


unsigned EliminaDup  ( t_lista *p )
{
    int marca=0;
    t_lista aux,
            ant;

    while (*p)
    {
        aux=(*p)->sig;
        ant=*p;

        while (aux)
        {
            if (comparar(&ant->info, &aux->info)==0)
            {
                marca=1;
                ant->sig=aux->sig;
                free(aux);
            }
            else
                ant=aux;

            aux=aux->sig;
        }

        if (marca)
            free(*p);

        *p=(*p)->sig;
    }

    return 0;
}





/*
unsigned EliminaDup  ( t_lista *p )
{
	t_nodo *ant,
   		 *cur,
          *aux;

   unsigned elim=0;

   int mark, cmp;

   while (*p)
   {
   	mark=0;
      cur=*p;
      aux=cur->sig;
      ant=cur;

      while ( (*p)->sig )
      {
      	cmp = comparar (&cur->info, &cur->sig->info);

         if ( !cmp || mark==1 )
         {
         	mark=1;	//Indica que se elimino un registro duplicado
            aux=cur;
            cur=cur->sig;
            if (ant == cur) //Si entro por primera vez
            	ant=aux->sig;
            else
            	ant->sig=aux->sig;

            if (cmp)   //Si la comparacion dio distinta, pero el ultimo evaluado
            	mark=0; //tenia anteriormente un duplicado

            free (aux);

            elim++;
         }
      	else
      	{
      		ant=cur;
	         mark=0;
   	      cur=cur->sig;
	      }
      }
     p=&(*p)->sig;
   }

   return elim;
}
*/

int comparar ( const t_info *d1 , const t_info *d2 )
{
    return (d1->dni)-(d2->dni);
}


int ingresar ( t_info *d )
{
    printf ("D.N.I.: ");
    fflush(stdin);
    scanf  ("%ld", &d->dni);

    if (!d->dni)
        return ERROR;

    printf ("Apellido y Nombre: ");
    fflush (stdin);
    gets   (d->apyn);

    return SUCCESS;
}


void mostrar ( t_lista *p )
{
    while (*p)
    {
        printf("D.N.I.: %ld\tApellido y Nombre:%15s\n",(*p)->info.dni,(*p)->info.apyn);
        p=&(*p)->sig;
    }
}
