#include<stdio.h>
#include<conio.h>
#include<DOS.H>
void ordenar(int *a,int *b,int *c);
void cambiar(int *aux,int *x, int *y);
void main()
{
 printf("Programa que ordena 3 numeros de menor a mayor");
 int a,b,c;
 delay (1000);
 clrscr();
 printf("Dame el promer numero: ");scanf("%d", a);  //parte del programa que pide
 printf("Dame el siguiente numero");scanf("%d", b); //los valores al usuario.
 printf("Dame el  ultimo numero");scanf("%d", c);
 ordenar(&a,&b,&c);  //llamada a la funcion.
 printf("El menor valor es: %d\n", a);     //muestra el resultado
 printf("El siguiente valor es: %d\n", b); //de la operacion.
 printf("El mayor valor es: %d\n", c);
}
void ordenar (int *a,int *b,int *c); //funcion que ordena.
{
  int a,b,c;
if (*a>*b)
   {
	*x=*a;
	*y=*b;
	cambiar(int *aux,int *x,int *y);
	*a=*x;
	*b=*y;
   }
if(*a>*c)
  {
   *x=a;
   *y=c;
   cambiar(int *aux,int *x,int *y);
   *a=*y;
   *c=*x
if(*b>*c)
  {
   *x=*b;
   *y=*c;
   cambiar(int *aux,int *x,int *y);
   *b=*x;
   *c=*y;
  }
if(*b>*a)
  {
   *x=*b;
   *y=*a;
   cambiar(int *aux,int *x,int *y);
   *b=*x;
   *a=*y;
  }
if(*c>*a)
  {
   *x=*c;
   *y=*a;
   cambiar(int *aux,int *x,int *y);
   *c=*x;
   *a=*y;
  }
if(*c>*b)
  {
   *x=*c;
   *y=*b;
   cambiar(int *aux,int *x,int *y);
   *c=*x;
   *b=*y;
  }
}
void cambiar(int *aux,int *x,int *y); //funcion que permite cambiar.
	 {
	  *aux=*x;
	  *x=*y;
	  *y=*aux;
	  return *x,*y;
	 }