#include <stdio.h>
#include <conio.h>

void main()
{
	float n1, n2, n3;
	clrscr();
	textcolor(RED);
	cprintf("\n\n\rIngrese el primer n£mero (limite) : ");
	scanf("%f", &n1);
	cprintf("\n\n\rIngrese el segundo n£mero: ");
	scanf("%f", &n2);
	cprintf("\n\n\rIngrese el tercer n£mero (limite) : ");
	scanf("%f", &n3);
	if (( n2 < n3 ) && ( n2 > n1 ) || ( n2 > n3 ) && ( n2 < n1 ))
	{
		cprintf("\n\n\r%.2f pertenece al intervalo (%.2f - %.2f)", n2, n1, n3);
	}
	else
	{
		cprintf("\n\n\r%.2f no pertenece al intervalo (%.2f - %.2f)", n2, n1, n3);
	}
	gotoxy(1,50);
	printf("Presione una tecla para salir");
	getch();
}