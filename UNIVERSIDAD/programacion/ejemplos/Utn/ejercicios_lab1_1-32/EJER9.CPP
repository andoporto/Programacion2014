#include <stdio.h>
#include <conio.h>

void main()
{
	float pul, cen, pies;
	textcolor(RED);
	clrscr();
	cprintf("\n\nIngrese el n£mero de centimetros: ");
	scanf("%f", &cen);
	pul = (cen * 11.2) / 333.3;
	pies = (cen * 10) / 333.3;
	cprintf("\n\nEl equivalente a Pulgadas es: %.1f", pul);
	gotoxy(1,6);
	cprintf("\n\nEl equivalente a Pies es: %.0f", pies);
	gotoxy(1,24);
	printf("Presione una tecla para salir");
	getch();
}
