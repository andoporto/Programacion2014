#include <stdio.h>
#include <conio.h>

 void main()
{
 long int X,C,R,I;
 S=0;C=0;
 clrscr();

 printf("\n Ingrese un numero: ");
 scanf("%ld",&X);

 while (X!=0)
 {
  for(I=1;I<=X;I++)
   {
 	R=X%I;
	if (R==0)
 		C++;
   }
 if (C==2)
	printf("\n %ld es primo",X);
 else
    S=S+X;
 }
 printf("\n\n La sumatoria de lso números compuestos vale: %ld",S)
 getch();
}