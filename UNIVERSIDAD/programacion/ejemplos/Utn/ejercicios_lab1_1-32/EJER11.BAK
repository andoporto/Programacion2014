#include <stdio.h>
#include <conio.h>

void main()
{
	int n;
	char seguir;
	seguir = 's';
	textcolor(RED);
	clrscr();
	while (seguir == 's')
	{
		cprintf("\nIngrese un n£mero del 1 al 7: ");
		scanf("%d", &n);
		switch(n)
		{
			case 1: cprintf("\nLunes"); break;
			case 2: cprintf("\nMartes"); break;
			case 3: cprintf("\nMi‚rcoles"); break;
			case 4: cprintf("\nJueves"); break;
			case 5: cprintf("\nViernes"); break;
			case 6: cprintf("\nS bado"); break;
			case 7: cprintf("\nDomingo"); break;
			default: cprintf("\nEl numero debe pertenecer al rango 1-7");
		}
		cprintf("\n\nDesea seguir? s/n: ");
		scanf("%s", &seguir);
		if (seguir == 'n')
		{
			gotoxy(1,50);
			cprintf("Presione una tecla para salir");
		}
	}
	getch();
}
