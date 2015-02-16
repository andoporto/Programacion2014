#include <stdio.h>
#include <conio.h>

void main()
{
	float num1, num2, num;
	clrscr();
	textcolor(MAGENTA);
	cprintf("\nIngrese un n£mero: ");
	scanf("%f", &num1);
	num = num1;
	gotoxy(1,4);
	cprintf("Ingrese un n£mero: ");
	scanf("%f", &num2);
	num1 = num2;
	num2 = num;
	gotoxy(1,24);
	cprintf("Presione una tecla para salir");
	getch();
}