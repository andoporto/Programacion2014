#include <stdio.h>
#include <conio.h>

void main()
{

	int cont=0;
	float n, total=0;
	clrscr();
	while (cont<5)
	{
		printf("Ingrese un n£mero: ");
		scanf("%f", &n);
		total = total + n;
		cont++;
	}
	printf("\n\nSu promedio es: %.2f", total / 5);
	gotoxy(1,49);
	printf("Presione una tecla para salir");
	getch();
}

