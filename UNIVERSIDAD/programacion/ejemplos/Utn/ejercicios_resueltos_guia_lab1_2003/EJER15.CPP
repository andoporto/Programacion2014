#include <stdio.h>
#include <conio.h>

void main()
{
	int n;
	textcolor(RED);
	clrscr();
	gotoxy(1,2);
	for ( n = 100; n >= 1 ; n-- )
	{
					cprintf("*%d",n);
	}
	gotoxy(1,50);
    printf("Presione una tecla para salir");
	getch();
}

