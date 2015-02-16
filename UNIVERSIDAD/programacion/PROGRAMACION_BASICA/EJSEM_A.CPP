
	#include <stdio.h>
	#include <conio.h>

   void main()
   {
	int S,P,a,b;
	clrscr ();
	printf("\n Ingrese el primer valor: ");
	scanf ("%d",&a);
	printf("\n Ingrese el segundo valor: ");
	scanf ("%d",&b);
	printf ("\n a= %d  b= %d",a,b);
	S=a+b;
	P=a*b;
	printf ("\n \n La suma vale: %d y la multiplicaci¢n: %d",S,P);
	getch();
    }