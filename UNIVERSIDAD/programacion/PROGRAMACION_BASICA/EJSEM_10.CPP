#include <stdio.h>
#include <conio.h>

 void main()
{
 long int X,C,R,I;
 C=0;
 clrscr();

 printf("\n Ingrese un numero: ");
 scanf("%d",&X);

 for(I=1;I<=X;I++)
 {
 	R=X%I;
	if (R==0)
 		C++;
 }
 if (C==2)
	printf( "\n %ld es primo",X);
 else
    printf("\n %ld no es primo",X);
 getch();
}