
	#include <stdio.h>
	#include <conio.h>

   void main()
{
	float x,u,max;
	int c;
	clrscr ();

 for (c=1;c<=15;c++)
 {
	printf("\n Ingrese la temperatura: ");
	scanf ("%f",&x);

	if (c==1)
	{
		max=x;
		u=c;
	}
	if (x>max)
	{
		max=x;
		u=c;
	}
 }
	printf ("\n \n mayor valor= %.2f ubicaci¢n= %.0f",max,u);
	getch();
}