#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void main()
{
	float hora, imp, desc, horas, neto;
	int ant;
	char nombre[32], seguir = 's';
	while( seguir == 's' )
	{
		clrscr();
		textcolor(RED);
		cprintf("\n\rValor hora: ");
		scanf("%f", &hora);
		cprintf("Nombre del empleado: ");
		fflush(stdin);
		gets(nombre);
		cprintf("Antiguedad: ");
		scanf("%d", &ant);
		cprintf("Horas trabajadas en el mes: ");
		scanf("%f", &horas);
		imp = hora * horas + ant * 30;
		desc = imp * 13 / 100;
		clrscr();
		cprintf("\n\r%s", nombre);
		cprintf("\n\n\rAntiguedad: %d a¤os", ant);
		cprintf("\n\rValor hora: $%.2f", hora);
		cprintf("\n\rEl total a cobrar bruto es: $%.2f", imp);
		cprintf("\n\rEl descuento es: $%.2f", desc);
		cprintf("\n\rEl valor neto a cobrar es: $%.2f", imp - desc);
		cprintf("\n\n\rDesea seguir? s/n: ");
		seguir = getch();
		seguir = tolower(seguir);
		}
}



