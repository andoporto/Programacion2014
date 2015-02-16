#include <stdio.h>
#include <conio.h>

void main()
{
	clrscr();
	float rad, pi;
	pi = 3.1416;
	printf("Ingrese el coeficiente del radio de la circunsferencia: ");
	scanf("%f", &rad);
	textcolor(RED);
	cprintf("\n\nLa longitud de la circunsferencia es: %f", 2 * rad * pi);
	gotoxy(1,4);
	cprintf("\n\nLa superficie es: %f", (rad * rad)  * pi);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPresione una tecla para salir");
	getch();
}

