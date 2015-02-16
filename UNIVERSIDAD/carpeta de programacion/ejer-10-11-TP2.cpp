#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>



struct cliente{char ayn[51];
               long int dni;
               };

struct nodo{
            nodo *ant;
            cliente dat;
            nodo* sig;
            };

int insertar(nodo**,nodo**,cliente);
void vernodos(nodo*);
nodo* nuevonodo();
int listavacia(nodo*);
void borrarnodo(nodo**lis,cliente dat);

void main ()
{
 nodo* pri=NULL,*ult=NULL,*lis=NULL;
 cliente datos;
 int n;

 fflush(stdin);
  printf("\n ingrese nombre del cliente o ultimo para terminar:   ");
  gets(datos.ayn);

  while(strcmpi(datos.ayn,"ultimo")!=0)
  {

   printf("\n ingrese dni:   ");
   scanf("%ld",&datos.dni);

   n=insertar(&pri,&ult,datos);

   fflush(stdin);
  printf("\n ingrese nombre del cliente o ultimo para terminar:   ");
  gets(datos.ayn);
 }

 vernodos(pri);


  printf("\n ingrese dni del cliente a eliminar o cero para terminar:   ");
  scanf("%ld",&datos.dni);

  while(datos.dni!=0)
{
 borrarnodo(lis,datos);

 printf("\n ingrese dni del cliente a eliminar o cero para terminar:   ");
  scanf("%ld",&datos.dni);
 }
 vernodos(pri);
 }
 //////////////////////////////////////////////////////////////////////
  nodo* nuevonodo()
  {
    nodo*q;
    q=(nodo*)malloc(sizeof(struct nodo));
    if(q==NULL)
      {puts("memoria insuficiente");
       getch();
       exit(0);
       }
       return(q);
   }
  //////////////////////////////////////////////////////////////////////////
  int listavacia(nodo*q)
  {return(q==NULL);
  }
  //////////////////////////////////////////////////////////////////
  int insertar(nodo** pri,nodo**ult,cliente d)
  {
   nodo* actual=*pri,*ante=*pri,*q=NULL;
   q=nuevonodo();
   q->dat=d;
   if(listavacia(*pri))
   {
     *pri=q;
     *ult=q;
     q->ant=NULL;
      q->sig=NULL;
      return(1);
      }

   while((actual)&&(d.dni>actual->dat.dni))
   {
    ante=actual;
    actual=actual->sig;
    }

   if(ante==actual)
   {
    ante->ant=q;
    q->ant=NULL;
    q->sig=*pri;
    *pri=q;
    return(1);
    }
    else
  {
   q->ant=ante;
   q->sig=actual;
   ante->sig=q;
   if(actual!=NULL)
     actual->ant=q;
   else
       *ult=q;
   }

   return(1);
   }
   /////////////////////////////////////////////////////////////
    void vernodos(nodo* tope)
   {
     nodo* ant=tope,*actual=tope;

      clrscr();
     if(listavacia(tope))
       printf("\n no hay datos");

    while(actual)
    {
     textcolor(10);
     printf("\n apellido y nombre:%s:  ",actual->dat.ayn);
     printf("\n numero de dni:%ld:  ",actual->dat.dni);

     ant=actual;
     actual=actual->sig;
     }
     getch();
     }
     ////////////////////////////////////////////////////////////////////////
     
