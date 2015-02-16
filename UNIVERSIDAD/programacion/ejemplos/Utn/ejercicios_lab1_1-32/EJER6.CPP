#include <stdio.h>
#include <conio.h>

void main()
{
	float n;
	clrscr();
	textcolor(RED);
	cprintf("\nIngrese un n£mero: ");
	scanf("%f", &n);
	if (n < 0)
	{
		cprintf("\nEl n£mero es negativo");
	}
	if (n > 0)
	{
		cprintf("\nEl n£mero es positivo");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPresione una tecla para salir");
	getch();
}



