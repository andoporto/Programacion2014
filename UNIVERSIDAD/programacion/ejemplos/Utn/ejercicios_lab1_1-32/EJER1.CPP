#include <stdio.h>
#include <conio.h>

void main()
{
	clrscr();
	int cont;
	float n, total;
	cont=0;
	total=0;
	n=0;
	while (cont<5)
	{
		cprintf("Ingrese un n£mero: ");
		scanf("%f", &n);
		total = total + n;
		cont = cont + 1;
	}
	printf("\nSu promedio es: %f", total/5);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPresione una tecla para salir");
	getch();
}

