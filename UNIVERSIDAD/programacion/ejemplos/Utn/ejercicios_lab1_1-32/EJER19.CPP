#include <stdio.h>
#include <conio.h>

void main()
{
	int c, n;
	clrscr();
	textcolor(RED);
	cprintf("Ingrese un numero: ");
	scanf("%d", &n);
	gotoxy(1,10);
	cprintf("Los n£meros naturales que le antesceden son:");
	gotoxy(1,14);
	for ( c = 1; c <= n - 1 ; c++ )
	{
		cprintf("*%d", c);
	}
	gotoxy(1,24);
	cprintf("Presione una tecla para salir");
	getch();
}