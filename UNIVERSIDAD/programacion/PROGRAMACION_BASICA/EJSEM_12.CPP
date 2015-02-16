
#include <stdio.h>
#include <conio.h>

  void main()
{
 int N,S,I,X;
 clrscr ();
 S=0;
 printf("\n Ingrese cantidad de datos: ");
 scanf ("%d",&X);
 for (I=1;I<=N;I++)
 {
	printf("\n Ingrese dato: ");
	scanf ("%d",&X);

	if (S==0)
	{
		M=X;
		S=1; }
	else
		if (X>M)
			M=X;

 }

	printf ("\n \n El mayor valor es: %d,M);
	getch();
}

