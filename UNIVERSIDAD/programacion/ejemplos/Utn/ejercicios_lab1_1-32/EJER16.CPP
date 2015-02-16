#include <stdio.h>
#include <conio.h>

void main()
{
	int c, s;
	s = 0;
	clrscr();
	textcolor(RED);
	for ( c = 3; c <=99; c = c + 3 )
	{
		s = s + c;
		cprintf("*%d", c);
	}
	gotoxy(1,10);
	cprintf("La suma es: %d", s);
	gotoxy(1,24);
	cprintf("Presione una tecla para salir");
	getch();
}
