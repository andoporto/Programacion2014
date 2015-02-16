#include <stdio.h>
#include <conio.h>

void main()
{
	int c, x, y, z, w, r;
	clrscr();
	textcolor(RED);
	gotoxy(1,2);
	cprintf("Los numeros primos comprendidos entre 0 y 100 son:");
	gotoxy(1,6);
	cprintf("2*3*5*7");
	for ( c = 2; c<=100; c++)
	{
		x = c % 2;
		y = c % 3;
		z = c % 4;
		w = c % 5;
		r = c % 7;
		if ( x != 0 && y != 0 && z !=0 && w !=0 && r !=0)
		{
			cprintf("*%d", c);
		}
	}
	gotoxy(1,24);
	printf("Presione una tecla para salir");
	getch();
}
