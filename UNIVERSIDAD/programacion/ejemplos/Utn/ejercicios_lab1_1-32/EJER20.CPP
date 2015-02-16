#include <stdio.h>
#include <conio.h>

void main()
{
	int n, x, y, z;
	z = 0;
	clrscr();
	textcolor(RED);
	cprintf("Ingrese un numero: ");
	scanf("%d", &n);
	for ( x = 1; x <= n; x++ )
	{
		y = x % 3;
		if ( y == 0 )
		{
			z = z + 1;
		}
	}
	gotoxy(1,6);
	cprintf("La cantidad de multiplos de 3 que hay entre 1 y %d son: %d", n, z);
	gotoxy(1,24);
	cprintf("Ingrese una tecla para salir");
	getch();
}




