#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main()
{
	char seg = 's';
	float peso;
	int mas, men;
	mas = 0;
	men = 0;
	clrscr();
	textcolor(RED);
	while ( seg == 's' )
	{
		cprintf("\n\rIngresar su peso en Kg: ");
		scanf("%f", &peso);
		if ( peso <= 80 )
		{
			men = men + 1;
		}
		else
			mas = mas + 1;
		cprintf("Desea seguir s/n?: ");
		seg = getch();
		seg = tolower(seg);
		while ( seg != 's' && seg != 'n' )
		{
			cprintf("Desea seguir s/n?: ");
			seg = getch();
		}
	}
	cprintf("\n\r\nLa cantidad de personas que pesan menos u 80 son: %d", men);
	cprintf("\n\r\nLa cantidad de personas que pesan mas de 80 son: %d", mas);
	gotoxy(1,50);
	printf("Presione una tecla para salir");
	getch();
}

