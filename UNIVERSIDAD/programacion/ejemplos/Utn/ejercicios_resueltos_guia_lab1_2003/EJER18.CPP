#include <stdio.h>
#include <conio.h>

void main()
{
	int n, s;
	s = 0;
	clrscr();
	textcolor(2);
	cprintf("Ingrese un numero entero: ");
	scanf("%d", &n);
	for ( n = n - 1 ; n >= 0; n-- )
	{
		s = s + n;
	}
	gotoxy(1,5);
	cprintf("La suma es: %d", s);
	gotoxy(1,50);
	cprintf("\n Presione una tecla para salir");
	getch();
}