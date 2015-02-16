#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void){

int i, n=0;
float tarifa, horas;
char seguir = 's', nombre[20];

do
{
	n = n++;
	clrscr();
	flushall;
	printf("Nombre: ");
	scanf("%s", &nombre);
	printf("\nTarifa horaria: ");
	scanf("%f", &tarifa);
	printf("\nHoras trabajadas: ");
	scanf("%f", &horas);
	clrscr();
	printf("El salario semanal de %s es de $%.2f", nombre , horas * tarifa);
	printf("\n\nDesea seguir s/n?: ");
	seguir = getch();
	seguir = tolower(seguir);
	}while(seguir=='s');
	clrscr();
	printf("Cantidad de empleados a los que se le calcul¢ el salario fue: %d", n);
	gotoxy(1,50);
	printf("Presione una tecla para salir");
        getch();

}





