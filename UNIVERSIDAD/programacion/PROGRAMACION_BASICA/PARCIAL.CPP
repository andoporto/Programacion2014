
/*de la carpeta*/
	#include <stdio.h>
	#include <conio.h>

   void main()
   {
	int a,b;
	clrscr ();
	printf("ingrese nota primer parcial: ");
	scanf ("%d",&a);
	printf("ingrese nota segundo parcial: ");
	scanf ("%d",&b);
	if (a>=7 && b>=7)
		printf ("promociona");
	else
		if (a>=4 && b>=4)
	printf ("da final");
		else
			printf ("recursa");
	getch();
	 }
