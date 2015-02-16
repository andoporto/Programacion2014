#include <stdio.h>
#include <conio.h>

void main()
{
	float c, n, s, p;
	clrscr();
	textcolor(RED);
	s = 0;
	p = 0;
	for ( c = 1; c <= 10; c++ )
	{
		cprintf("Ingrese un n£mero: ");
		scanf("%f", &n);
		while ( n == 0 )
		{
			cprintf("Ingrese un n£mero distinto de cero: ");
			scanf("%f", &n);
		}
		if ( n > 0 )
		{
			s = s + n;
		}
		if ( n < 0 )
		{
			if ( p == 0 )
			{
				p = n;
			}
			else
			p = p * n;
		}
	}
	gotoxy(1,16);
	cprintf("La suma de los positivos es igual a %.2f", s);
	gotoxy(1,18);
	cprintf("El producto de los negativos es igual a %.2f", p);
	gotoxy(1,24);
	printf("Presione una tecla para salir");
	getch();
}


