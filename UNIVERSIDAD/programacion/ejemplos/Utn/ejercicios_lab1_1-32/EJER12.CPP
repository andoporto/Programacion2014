#include <stdio.h>
#include <conio.h>

void main()
{
	int n, c, x;
	c = 0;
	textcolor(BLUE);
	clrscr();
    gotoxy(1,2);
	for ( n = 0; n <= 100; n++ )
	{
		x = n % 2;
		if ( x == 1 )
		{
			c = c + 1;
			cprintf("*%d",n);
		}
	}
	gotoxy(1,7);
	cprintf("\nEl numero de impares es: %d", c);
	gotoxy(1,24);
	printf("Presione una tecla para salir");
	getch();
}

