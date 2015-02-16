#include <stdio.h>
#include <conio.h>

void main()
{
	int v, boleta;
	float imp, v1 = 0, v2 = 0, v3 = 0;
	textcolor(RED);
	clrscr();
	cprintf("\n\n\rIngrese n£mero de boleta: ");
	scanf("%d", &boleta);
	clrscr();
	while ( boleta != 0 )
	{
		cprintf("\n\n\rIngrese n£mero de vendedor: ");
		scanf("%d", &v);
		while ( v < 0 || v > 3 )
		{
			cprintf("\n\rIngrese n£mero de vendedor: ");
			scanf("%d", &v);
		}
		cprintf("\n\rIngrese el importe: ");
		scanf("%f", &imp);
		clrscr();
		switch(v)
		{
			case 1: v1 = v1 + imp * 0.05; break;
			case 2: v2 = v2 + imp * 0.05; break;
			case 3: v3 = v3 + imp * 0.05; break;
		}
		cprintf("\n\n\rIngrese n£mero de boleta: ");
		scanf("%d", &boleta);
		clrscr();
	}
	cprintf("\n\n\rLa ganancia del vendedor 1 es: %.2f", v1);
	cprintf("\n\n\rLa ganancia del vendedor 2 es: %.2f", v2);
	cprintf("\n\n\rLa ganancia del vendedor 3 es: %.2f", v3);
	gotoxy(1,50);
	printf("Presione una tecla para salir");
	getch();
}

