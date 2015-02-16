#include <stdio.h>
#include <conio.h>

void main()
{
	int n, s;
	s = 0;
	clrscr();
	textcolor(RED);
	cprintf("Ingrese un numero entero: ");
	scanf("%d", &n);
	for ( n = n - 1 ; n >= 0; n-- )
	{
		s = s + n;
	}
	gotoxy(1,5);
	cprintf("La suma es: %d", s);
	gotoxy(1,24);
	cprintf("Presione una tecla para salir");
	getch();
}