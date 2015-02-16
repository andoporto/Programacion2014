#include <stdio.h>
#include <conio.h>

 void main()
{
 int X,R;
 clrscr();

 printf("\n Ingrese un valor: ");
 scanf("%d",&X);
  R=X%2;
  if (R==0)
	printf("\n  %d es par",X);
  else
	printf("\n  %d no es par",X);
  getch();
}