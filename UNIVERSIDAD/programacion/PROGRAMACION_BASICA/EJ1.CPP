	#include <stdio.h>
	#include <conio.h>

   void main()
   {
	float a,r;
	clrscr ();
	printf("\n Ingrese un valor: ");
	scanf ("%f",&a);
	if (a>2.54)
	  {
		r=a/2.54;
		printf ("El valor de a en cm es: %f y su valor en pulg es : %f",a,r);
	  }
	else
		{
		r=a*2.54;
		printf ("El valor de a en pulg es: %f y su valor en cm es : %f",a,r);
        }
	getch();
	 }