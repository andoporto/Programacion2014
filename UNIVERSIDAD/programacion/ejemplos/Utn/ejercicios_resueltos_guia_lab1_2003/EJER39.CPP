#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void){

int i;
float tarifa, horas;
char seguir = 's', nombre[20];

do
{
	clrscr();
	flushall;
	printf("Nombre: ");
	scanf("%s", &nombre);
	printf("\nTarifa horaria: ");
	scanf("%f", &tarifa);
	printf("\nHoras trabajadas: ");
	scanf("%f", &horas);
	clrscr();
	printf("El salario semanal de %s es de $%.2f", nombre, horas * tarifa);
	printf("\n\nDesea seguir s/n?: ");
	seguir = getch();
	seguir = tolower(seguir);
	}while(seguir=='s');

}





