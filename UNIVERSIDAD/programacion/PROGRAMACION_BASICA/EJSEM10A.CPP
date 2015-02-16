#include <stdio.h>
#include <conio.h>

 void main()
{
 int V,i,S,C,X,N;
 S=0;i=2;
 clrscr();

 printf("\n Ingrese un numero: ");
 scanf("%d",&V);

 while ((i<=(V-1))&&(S==0))
 {
   if((N%i)==0)
       S=1;
   else
       i=i+1;
 }
 if (S==0)
	printf( "\n %d es primo",X);
 else
	printf("\n %d no es primo",X);
 getch();
}