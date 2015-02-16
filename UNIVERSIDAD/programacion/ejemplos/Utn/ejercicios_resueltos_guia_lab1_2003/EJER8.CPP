#include <stdio.h>
#include <conio.h>

void main()
{
	float c, f;
	textcolor(RED);
	clrscr();
	cprintf("\n\nIngrese los grados Celcius: ");
	scanf("%f", &c);
	f = (c * 212) / 100;
	cprintf("\n\nLos correspondientes en Farenheit son: %f", f);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPresione una tecla para salir");
	getch();
}