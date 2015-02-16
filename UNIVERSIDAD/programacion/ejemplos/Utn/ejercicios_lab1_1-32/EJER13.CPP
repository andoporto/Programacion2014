#include <stdio.h>
#include <conio.h>

void main()
{
	int n, x;
	textcolor(RED);
	clrscr();
	gotoxy(1,2);
	for ( n = 0; n <= 100; n++ )
	{
		x = n % 2;
		if ( x == 0 )
		{
			cprintf("*%d",n);
		}
	}
	gotoxy(1,24);
    printf("Presione una tecla para salir");
	getch();
}

