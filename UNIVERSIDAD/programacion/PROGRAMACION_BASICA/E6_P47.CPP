	#include <stdio.h>
	#include <conio.h>

   void main()
   {
	float pre, des, pn;
	clrscr ();
	printf("\n Ingrese el importe: ");
	scanf ("%f",&pre);
	if (pre < 55)
		des=pre*0.045;
	else
		if (pre >=100)
			des=pre*0.105;
		else
			des=pre*0.8;

	pn=pre-des;

	printf ("El precio ingresado es : %f , el descuento es: %f y el precio neto es: %f",pre,des,pn);

	getch();
	}