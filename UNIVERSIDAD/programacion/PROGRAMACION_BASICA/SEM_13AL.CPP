
#include <stdio.h>
#include <conio.h>

void main()
{
 int N,S,C,R;
 S=0;C=0;
 clrscr ();

 printf("\n Ingrese un numero: ");
 scanf ("%d",&X);

while(X!=0)
 {
	C=C+1;

	R=C%2;
	if (R==0)
		S=S+X;
	printf("\n Ingrese un numero: ");
 	scanf ("%d",&X);
  }

	printf ("\n \n La suma vale: %d",S);
	getch();
}

