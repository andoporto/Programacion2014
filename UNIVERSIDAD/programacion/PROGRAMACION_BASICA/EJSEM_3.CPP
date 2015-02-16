#include <stdio.h>
#include <conio.h>

 void main()
{
 int A,X,B,C;
 clrscr();
 C=0;
 printf("\n Ingrese primer extremo del intervalo: ");
 scanf("%d",&A);
 printf("\n Ingrese segundo extremo del intervalo: ");
 scanf("%d",&B);

 printf("\n Ingrese un valor: ");
 scanf("%d",&X);

 while (X!=B)
 {
  if ((X>A)&&(X<B))
  	C++;
  printf("\n Ingrese un valor: ");
  scanf("%d",&X);
 }
 printf("\n N£mero de valores dentro del intervalo: %d",C);
 getch();
}