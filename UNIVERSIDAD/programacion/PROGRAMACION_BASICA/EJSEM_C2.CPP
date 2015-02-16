	#include <stdio.h>
	#include <conio.h>

   void main()
{
	int C,I;
	float x,S,P;
	clrscr ();
	x=0; S=0;
	C=0;

 for (I=1;I<=15;I++)
 {
	printf("\n Ingrese la temperatura: ");
	scanf ("%f",&x);
	if (x>33)
	{
	    S=S+x;
	    C=C+1; }
 }
	if (C!=0)
	{
	 P=S/C;
	 printf ("\n \n El promedio de los valores mayores a 33 es: %.2f",P);
	}
	else
	  printf ("\n \n No hay valores mayores a 33 ");
	getch();
}