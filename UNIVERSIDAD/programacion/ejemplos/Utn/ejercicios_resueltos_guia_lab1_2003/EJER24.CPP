#include <stdio.h>
#include <conio.h>

void main()
{
	int n, c, cubo, cuad;
	clrscr();
	gotoxy(30,25);
	printf("Ingrese un n£mero: ");
	scanf("%d", &n);
	clrscr();
	gotoxy(30,5);
	printf("Numero  Cuadrado  Cubo");
	for ( c = 1; c <= n; c++ )
	{
	printf("\n\n\t\t\t\t%d", c);
	cuad = c * c;
	cubo = c * c * c;
	printf("\t%d", cuad);
	printf("\t%d", cubo);
	}
	gotoxy(1,50);
	printf("\n Presione una tecla para salir");
	getch();
}