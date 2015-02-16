#include <stdio.h>
#include <conio.h>

void main()
{
	clrscr();
	int cont, may, men;
	float a;
	cont = 0;
	men =0;
	may=0;
	clrscr();
	while (cont < 10)
	{
		printf("Ingrese un n£mero: ");
		scanf("%f", &a);
		if (a < 0)
			{
			men = men + 1;
			}
		if (a > 0)
			{
			may = may + 1;
			}
			cont = cont + 1;
	}
	textcolor(RED);
	cprintf("\nLa cantidad de n£meros mayores que cero son: %d", may);
	gotoxy(1,14);
	cprintf("\nLa cantidad de n£meros menores que cero son: %d", men);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPresione una tecla para salir");
	getch();
}


