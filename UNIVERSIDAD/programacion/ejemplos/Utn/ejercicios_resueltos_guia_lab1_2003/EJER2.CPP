#include <stdio.h>
#include <conio.h>

void main()
{
	float n, cuad;
	clrscr();
	printf("\n\tIngrese un numero mayor que cero: ");
	scanf("%f", &n);
	if (n>0)
	{
	       cuad =n*n;
	       printf("\n\tEl cuadrado de su n£mero es: %f", cuad);
	       getch();
	}
	else
	printf("\n\tERROR, el n£mero debe ser mayor que cero");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\nPresione una tecla para salir");
	getch();
}