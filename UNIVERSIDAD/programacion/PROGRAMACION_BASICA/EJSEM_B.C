
	#include <stdio.h>
	#include <conio.h>

   void main()
{
	int a,b,c,d,p,m,r;
	clrscr ();
	printf("\n Ingrese el primer valor: ");
	scanf ("%d",&a);
	printf("\n Ingrese el segundo valor: ");
	scanf ("%d",&b);
	printf("\n Ingrese el tercer valor: ");
	scanf ("%d",&c);
	printf("\n Ingrese el cuarto valor: ");
	scanf ("%d",&d);

	if ((a<c)&&(b<c))
		printf ("\n Los dos primeros son menores al tercero");
	else
		printf ("\n Los dos primeros son mayores al tercero");

	r=a%c;
	if (r==0)
		printf ("\n %d El primero es multiplo del tercero ",r);
	else
		printf ("\n %d El primero no es multiplo del tercero",r);

	p=a*b*c*d;

	if (p>32769)
		printf ("\n %d El producto de los elementos es mayor a 32769 ",p);
	else
		printf ("\n % d El producto de los elementos es menor a 32769 ",p);

	m=a;
	if ((a>b)&&(a>c)&&(a>d))


		printf ("\n El primero es el mayor");

	if ((b>c)&&(b>d))
	{
		m=b;
		printf ("\n El segundo es el mayor");
	}
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
	printf ("\n El m ximo vale: %d",m);
	getch();
}