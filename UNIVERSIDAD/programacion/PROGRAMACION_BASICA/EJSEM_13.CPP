
#include <stdio.h>
#include <conio.h>

  void main()
{
 int N,V,I,MIN;
 clrscr ();
 V=0;
 printf("\n Ingrese cantidad de datos: ");
 scanf ("%d",&N);

 for (I=1;I<=N;I++)
 {
	printf("\n Ingrese un numero: ");
	scanf ("%d",&X);

	if (V==0)
	{
		MIN=X;
		U=U+1;
	}
	else
	{
		if (X<MIN)
		{
			M=X;
			U=C;
	    }
    }

 }

	printf ("\n \n El minimo es: %d y su orden es: %d",MIN,V);
	getch();
}

