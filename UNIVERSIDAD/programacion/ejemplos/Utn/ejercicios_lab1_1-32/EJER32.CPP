#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void main()
{
	float sueldo;
	int sexo, hombre = 0, mujer = 0, leg;
	char seguir = 's';
	while( seguir == 's' )
	{
		clrscr();
		textcolor(RED);
		cprintf("\n\rNumero de legajo: ");
		scanf("%d", &leg);
		cprintf("Sueldo: ");
		scanf("%f", &sueldo);
		cprintf("Sexo(1 fem, 2 masc): ");
		scanf("%d", &sexo);
		if ( sueldo > 500 )
		{
			if ( sexo == 1 )
			{
				mujer = mujer + 1;
			}
		}
		if ( sueldo > 400 )
		{
			if ( sexo == 2 )
			{
				hombre = hombre + 1;
			}
		}
		cprintf("\n\rDesea seguir? s/n: ");
		seguir = getch();
		seguir = tolower(seguir);
		}
		clrscr();
		cprintf("\n\rLa cantidad de mujeres que ganan mas de $500 son: %d", mujer);
		cprintf("\n\n\rLa cantidad de hombres que ganan mas de $400 son: %d", hombre);
		gotoxy(1,24);
		printf("Presione una tecla para salir");
		getch();
}




