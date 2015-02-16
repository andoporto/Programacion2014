	#include <stdio.h>
	#include <conio.h>

   void main()
   {
	long int a;
	long int b;
	long int r;
	a=0;b=0;r=0;
	clrscr ();
	printf("\nIngrese un valor: \n");
	scanf ("%d",&a);
	printf("\nIngrese el divisor: \n");
	scanf ("%d",&b);
	r=a%b;
	if (r==0)
		printf ("\n %d es m£ltiplo de %d",a,b);
	else
		printf ("\n %d no es m£ltiplo de %d",a,b);

	getch();
	 }