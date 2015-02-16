#include <stdio.h>
#include <conio.h>

void main()
{
	int n, m, x, y;
	textcolor(CYAN);
	clrscr();
	gotoxy(1,3);
	cprintf("Los multiplos de 2 son:");
	gotoxy(1,5);
	for ( n = 1; n <=100; n++ )
	{
		x = n % 2;
		if ( x == 0 )
		{
			cprintf("*%d", n);
		}
	}
	gotoxy(1,10);
	cprintf("Los multiplos de 3 son:");
	gotoxy(1,12);
	for ( m = 1; m <=100; m++ )
	{
		y = m % 3;
		if ( y == 0 )
		{
			cprintf("*%d", m);
		}
	}
	gotoxy(1,17);
	cprintf("Los multiplos de 2 y 3 son:");
	gotoxy(1,20);
	for ( m = 1; m <=100; m++ )
	{
		y = m % 3;
		x = m % 2;
		if (( y == 0 ) && (x == 0))
		{
			cprintf("*%d", m);
		}
	}
	gotoxy(1,50);
	printf("\n");
	printf("Presione una tecla para salir");
	getch();
}