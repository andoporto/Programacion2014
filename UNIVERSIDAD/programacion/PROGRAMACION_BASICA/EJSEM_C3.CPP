	#include <stdio.h>
	#include <conio.h>

   void main()
{
	int C;
	float x,max,min;
	clrscr ();


 for (C=1;C<=15;C++)
 {
	printf("\n Ingrese la temperatura: ");
	scanf ("%f",&x);

	if (C==1)
		min=x;
	else
		{
		 if (x<min)
			min=x;
		 else
			max=x;
		}
 }

	min=2*min;

	if (max>min)
		printf ("\n \n El mayor valor es mayor al doble del menor");
	else
		printf ("\n \n El mayor valor es menor al doble del menor");
	getch();
}