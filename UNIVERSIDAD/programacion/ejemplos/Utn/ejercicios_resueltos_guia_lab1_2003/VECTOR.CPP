#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main ()
{
	int i, linea;
	float linea1[11], linea2[11], linea3[11], imp, timp1=0, timp2=0, timp3=0;
	char seguir='s';

	for(i=0; i<12; i++)
	{
		linea1[i] = 0;
		linea2[i] = 0;
		linea3[i] = 0;
	}
	do
	{
		clrscr();
		printf("\nRecaudacion: ");
		scanf("%f", &imp);
		printf("\nIngrese numero de coche: ");
		scanf("%d", &i);
		printf("\nIngrese numero de linea: ");
		scanf("%d", &linea);
		switch(linea)
		{
		case 1:
			clrscr();
			timp1=timp1 + imp;
			linea1[i-1] = linea1[i-1] + imp;
			break;
		case 2:
			clrscr();
			timp2=timp2 + imp;
			linea2[i-1] = linea2[i-1] + imp;
			break;
		case 3:
			clrscr();
			timp3=timp3 + imp;
			linea3[i-1] = linea3[i-1] + imp;
			break;
		}
		fflush(stdin);
		printf("Desea seguir s/n?: ");
		scanf("%c", &seguir);
		seguir = tolower(seguir);
	}while(seguir=='s');
	clrscr();
	printf("\nLa recaudacion de la linea1 es $%.2f, la linea2 es $%.2f y la linea3 $%.2f", timp1, timp2, timp3);
	printf("\n\nLa recaudacion de cada coche de la linea 1 es:\n");
	for(i=0; i<12; i++)
	printf("\ncoche %d = %.2f", i+1, linea1[i]);
	printf("\n\nLa recaudacion de cada coche de la linea 2 es:\n");
	for(i=0; i<12; i++)
	printf("\ncoche %d = %.2f", i+1, linea2[i]);
	printf("\n\nLa recaudacion de cada coche de la linea 3 es:\n");
	for(i=0; i<12; i++)
	printf("\ncoche %d = %.2f", i+1, linea3[i]);
	printf("\n\nLa recaudacion total fue %.2f", timp1 + timp2 + timp3);
	getch();
}





