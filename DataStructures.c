#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define OK    1
#define ERROR 0

typedef struct {
         	int dia,
            	 mes,
                ano;
} t_date;

typedef struct {
			long   dni;
         char   apyn[36],
         	    sex;
         t_date fnac;
         float  salary;
} t_info;



typedef struct s_nodo_pila {
			t_info info;
         struct s_nodo_pila *sig;
} t_nodo_pila;


typedef t_nodo_pila *t_pila;




void CrearPila   ( t_pila *p );
int  PilaLLena   ( const t_pila * );
int  PilaVacia   ( const t_pila *p);
int  PonerEnPila ( t_pila *p, t_info *d );
int  SacarDePila ( t_pila *p, t_info *d );
int  VerTope     ( const t_pila *p, t_info *d );
void VaciarPila  ( t_pila *p );
int  ingresar    ( t_info *info );
void mostrar     ( t_info *info );


int main()
{
	t_info info;
   t_pila pila;

   CrearPila(&pila);

   if ( ingresar(&info) && PilaVacia(&pila) )
   	PonerEnPila ( &pila, &info );

   mostrar(&info);

   return 0;

}



void CrearPila ( t_pila *p )
{
	*p=NULL;
}


int PilaLLena ( const t_pila * )
{
	t_nodo_pila *aux= (t_nodo_pila*)malloc(sizeof(t_nodo_pila));
   free (aux);

   return aux==NULL;
}


int PilaVacia ( const t_pila *p)
{
	return *p==NULL;
}

int PonerEnPila ( t_pila *p, t_info *d )
{
   t_nodo_pila *nue = (t_nodo_pila*)malloc(sizeof(t_nodo_pila));

   if (nue)
	{
   	nue->info=*d;
      nue->sig=*p;
      *p=nue;
      return OK;
   }

   return ERROR;
}

                  //t_nodo_pila **p
int SacarDePila ( t_pila *p, t_info *d )
{
   t_nodo_pila *aux;

   if (*p)
   {
      aux=*p;
   	*d=(*p)->info;
    	*p=aux->sig;
      free(aux);
      return OK;
   }

   return ERROR;
}

int VerTope ( const t_pila *p, t_info *d )
{

	if (*p)
   {
     *d=(*p)->info;
     return OK;
   }

   return ERROR;
}

void VaciarPila ( t_pila *p )
{
	t_nodo_pila *aux;

	while (*p)
   {
		aux=*p;
      *p=aux->sig;
      free(aux);
   }
}




int ingresar ( t_info *info )
{

	if (&info->dni!=0)
   {
   	printf ("DNI: ");
      fflush (stdin);
   	scanf  ("%ld", &info->dni);

	   printf ("Apellido y Nombre: ");
      fflush (stdin);
   	gets   (info->apyn);

	   printf ("Sexo (M/F): ");
      fflush (stdin);
   	scanf  ("%c", &info->sex);

	   printf ("Fecha de nacimiento (dd/mm/aaaa): ");
      fflush (stdin);
   	scanf  ("%d/%d/%d", &info->fnac.dia,
   							  &info->fnac.mes,
         	              &info->fnac.ano);

      printf ("Salario: $");
      fflush (stdin);
      scanf  ("%f", &info->salary);

      return OK;
   }

   return ERROR;

}

void mostrar  ( t_info *info )
{
   if (info)
   {
   	printf ("DNI: ");
   	printf ("%ld\n", info->dni);

	   printf ("Apellido y Nombre: ");
   	puts   (info->apyn);

	   printf ("Sexo (M/F): ");
   	printf  ("%c\n", info->sex);

	   printf ("Fecha de nacimiento (dd/mm/aaaa): ");
   	printf  ("%02d/%02d/%04d\n",  info->fnac.dia,
   							    info->fnac.mes,
         	               info->fnac.ano);

      printf ("Salario: ");
      printf  ("$%.2f\n", info->salary);
   }
}


