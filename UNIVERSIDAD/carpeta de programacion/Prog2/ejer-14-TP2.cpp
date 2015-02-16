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
void promedio(nodo*,float*);

void main()
{
 nodo *raiz=NULL;
 int n;
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
       promedio(raiz,&prom);
       printf("\n el promedio es :%f",prom);

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
 void promedio(nodo*raiz,float *prom)
 {
  static int sum=0,cont=0;
  if(raiz!=NULL)
   {
    promedio(raiz->izq,&(*prom));
    sum+=raiz->num;
    cont++;
    *prom=sum/cont;
    promedio(raiz->der,&(*prom));
    }
   //return(sum/cont);
  }
