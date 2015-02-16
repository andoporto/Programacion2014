#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodo{
            nodo* izq;
            int num;
            nodo* der;
            };

int arbolvacio(nodo*);
nodo* nuevonodo();
nodo* creaarbol(nodo*,int);
void inorden(nodo*);
//void promedio(nodo*,float*);
void promedio(nodo*,int*,int*,float*);
void buscar(nodo*,int,nodo*);

void main()
{
 nodo *raiz=NULL,*aux=NULL;
 int n,sum=0,cont=0;
 float prom;

 printf("\n ingrese numero o cero para terminar:");
 scanf("%d",&n);

 while(n!=0)
 {
  raiz=creaarbol(raiz,n);
  printf("\n ingrese numero o cero para terminar:");
  scanf("%d",&n);
  }

  if(arbolvacio(raiz))
     printf("\n no hay arbol");

  else
      {
       clrscr();
       inorden(raiz);
       //promedio(raiz,&prom);
       /*promedio(raiz,&sum,&cont,&prom);
       printf("\n el promedio es :%f",prom);
       sum=0;cont=0;
       promedio(raiz,&sum,&cont,&prom);
       printf("\n el promedio es :%f",prom);*/

       printf("\n ingrese numero:");
       scanf("%d",&n);

       buscar(raiz,n,aux);
       inorden(raiz);

       }
    getch();
 }
 /////////////////////////////////////////////////////////////////////////////
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
  int arbolvacio(nodo*q)
  {return(q==NULL);
  }
  //////////////////////////////////////////////////////////////////
  nodo* creaarbol(nodo* raiz,int n)
  {
   if(arbolvacio(raiz))
   {
    raiz=nuevonodo();
    raiz->izq=NULL;
    raiz->num=n;
    raiz->der=NULL;
    }
   else
   {
    if(n<raiz->num)
       raiz->izq=creaarbol(raiz->izq,n);
    else
       raiz->der=creaarbol(raiz->der,n);
   }

  return(raiz);
 }
 /////////////////////////////////////////////////////////////////////////////
 void inorden(nodo*raiz)
 {
  if(raiz!=NULL)
   {
    inorden(raiz->izq);
    printf(" %d,",raiz->num);
    inorden(raiz->der);
    }

  }
 /////////////////////////////////////////////////////////////////////////////
 /*void promedio(nodo*raiz,float *prom)
 {
  static int sum=0,cont=0;
  if(raiz!=NULL)
   {
    promedio(raiz->izq,&(*prom));
    sum+=raiz->num;
    cont++;                        //funciona una sola vez,no la puedo volver a llamar
    *prom=sum/cont;
    promedio(raiz->der,&(*prom));
    }
   //return(sum/cont);
  } */
  ///////////////////////////////////////////////////////////////////////
  void promedio(nodo*raiz,int *sum,int *cont,float *prom)
 {
  if(raiz!=NULL)
   {
    promedio(raiz->izq,&(*sum),&(*cont),&(*prom));
    *sum+=raiz->num;
    (*cont)++;
    *prom=*sum/(*cont);
    promedio(raiz->der,&(*sum),&(*cont),&(*prom));
    }
  }
  //////////////////////////////////////////////////////////////////////////

 void buscar(nodo*raiz,int n,nodo*aux)
 {
  //nodo *aux;
   if(raiz!=NULL)
   {
    buscar(raiz->izq,n,raiz);
    if((raiz->izq==NULL)&&(raiz->der==NULL))
       if((raiz->num%n)==0)
          {
           if(n<aux->num)
              aux->izq=NULL;
           else
              aux->der=NULL;
              
           free(raiz); }
    buscar(raiz->der,n,raiz);
    }
 }






