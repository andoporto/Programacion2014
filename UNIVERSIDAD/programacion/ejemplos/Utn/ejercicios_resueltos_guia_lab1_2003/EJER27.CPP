#include <stdio.h>
#include <conio.h>

void main()
{
	float cat1, cat2, hyp;
	clrscr();
	textcolor(3);
	cprintf("Ingrese la medida del primer cateto: ");
	scanf("%f", &cat1);
	cprintf("\n\rIngrese la medida del segundo cateto: ");
	scanf("%f", &cat2);
	cprintf("\n\rIngrese la medida de la hipotenusa: ");
	scanf("%f", &hyp);
	if ( cat1 + cat2 < hyp )
	{
		cprintf("\n\n\rNo es un tri ngulo");
	}
	else
	{
	if (( cat1 == cat2 ) && ( cat1 != hyp ) && ( cat2 != hyp ) || ( cat1 == hyp ) && ( cat1 != cat2 ) && ( hyp != cat2 ) || ( cat2 == hyp ) && ( cat2 != cat1 ) && ( hyp != cat1 ))
	{
		cprintf("\n\n\rEs un tri ngulo Isoseles");
	}
	if (( cat1 == cat2 ) && ( cat1 == hyp ) && ( cat2 == hyp ))
	{
		cprintf("\n\n\rEs un tri ngulo Equilatero");
	}
	if (( cat1 != cat2 ) && ( cat1 != hyp ) && ( cat2 != hyp))
	{
		cprintf("\n\n\rEs un tri ngulo Escaleno");
	}
	}
	gotoxy(1,50);
	printf("\n Presione una tecla para salir");
	getch();
}