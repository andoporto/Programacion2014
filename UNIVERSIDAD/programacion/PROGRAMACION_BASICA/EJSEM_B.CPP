#include <stdio.h>
#include <conio.h>

   void main()
{
	long int a,b,c,d,P,M,R;
	clrscr ();
	printf("\n Ingrese el primer valor: ");
	scanf ("%ld",&a);
	printf("\n Ingrese el segundo valor: ");
	scanf ("%ld",&b);
	printf("\n Ingrese el tercer valor: ");
	scanf ("%ld",&c);
	printf("\n Ingrese el cuarto valor: ");
	scanf ("%ld",&d);

	if ((a<c)&&(b<c))
		printf ("\n Los dos primeros son menores al tercero");
	else
		printf ("\n Los dos primeros son mayores al tercero");

	R=a%c;
	if (R==0)
		printf ("\n El primero es multiplo del tercero ");
	else
		printf ("\n El primero no es multiplo del tercero");

	P=a*b*c*d;

	if (P>32769)
		printf ("\n El producto de los elementos es mayor a 32769 vale: %d",P);
	else
		printf ("\n El producto de los elementos es menor a 32769 vale: %d",P);

    M=a;
	if ((a>b)&&(a>c)&&(a>d))
		printf ("\n El primero es el mayor");
	else
	{
		if ((b>c)&&(b>d))
		{
		M=b;
		printf ("\n El segundo es el mayor");
		}

		else
		{
		  if (c>d)
		  {
		    M=c;
		    printf ("\n El tercero es el mayor");
		  }
		  else
		  {
			 M=d;
			 printf ("\n El cuarto es el mayor");
		  }
	    }
    }
	printf ("\n El m ximo vale: %ld",M);
	getch();
}