
	#include <stdio.h>
	#include <conio.h>

   void main()
{
	long int a;
	long int b;
	long int c;
	long int d;
	long int p;
	long int m;
	long int r;
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

	r=a%c;
	if (r==0)
		printf ("\n %ld El primero es multiplo del tercero ",r);
	else
		printf ("\n %ld El primero no es multiplo del tercero",r);

	p=a*b*c*d;

	if (p>32769)
		printf ("\n %ld El producto de los elementos es mayor a 32769 ",p);
	else
		printf ("\n % ld El producto de los elementos es menor a 32769 ",p);

	m=a;
	if ((a>b)&&(a>c)&&(a>d))


		printf ("\n El primero es el mayor");
	else
	{
		if ((b>c)&&(b>d))
		{
		m=b;
		printf ("\n El segundo es el mayor");
		}

		else
		{
		  if (c>d)
		  {
		    m=c;
		    printf ("\n El tercero es el mayor");
		  }
		  else
		  {
			 m=d;
			 printf ("\n El cuarto es el mayor");
		  }
	    }
    }
	printf ("\n El m ximo vale: %ld",m);
	getch();
}