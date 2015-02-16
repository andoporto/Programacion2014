
#include <stdio.h>
#include <conio.h>

void main()
{
 int a,b,R,S,N;
 S=0;
 clrscr ();

 printf("\n \nIngrese un numero: ");
 scanf ("%d",&a);

 printf("\n Ingrese un numero: ");
 scanf ("%d",&b);

while((a!=0)&&(b!=0))
 {
	N=N+1;
	R=N%2;
	if (R==0)
		S=S+a+b;

	printf("\n \nIngrese un numero: ");
    scanf ("%d",&a);

    printf("\n Ingrese un numero: ");
    scanf ("%d",&b);
 }

	printf ("\n \n La sumatoria vale: %d",S);
	getch();
}

