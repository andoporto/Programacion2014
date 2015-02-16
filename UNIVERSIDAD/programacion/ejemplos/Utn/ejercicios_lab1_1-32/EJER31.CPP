#include <stdio.h>
#include <conio.h>

void main()
{
	int n1, n2, c = 0, x, p = 0;
	clrscr();
	textcolor(LIGHTGRAY);
	cprintf("Ingrese un n£mero: ");
	scanf("%d", &n1);
	cprintf("\n\rIngrese un n£mero: ");
	scanf("%d", &n2);
	cprintf("\nLos numeros naturales entre ellos son:");
	if ( n1 < n2 )
	{
		for ( n1 = n1 + 1; n1 <= n2 - 1; n1++ )
		{
			x = n1 % 2;
			c = c + 1;
			if ( x == 0 )
			{
				p = p + 1;
			}
			printf("\n\n\t\t\t\t\t%d", n1);
		}
	}
	cprintf("\n\n\n\r\rSon %d numeros de los cuales %d son pares", c, p);
	gotoxy(1,50);
	printf("Presione una tecla para salir");
	getch();
}


