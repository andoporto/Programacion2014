#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void){

int i, n=0, band=0;
float tarifa, horas, salario, maysalario, mensalario, total=0, prom;
char seguir = 's', nombre[20], maynombre[20], mennombre[20];

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
	salario = horas * tarifa;
	total = total + salario;
	if(band ==0 || salario > maysalario)
	{
	       if(band!=2)
	       band=1;
	       else
	       band=2;
	       maysalario = salario;
	       for(i=0; i <=20; i++)
			maynombre[i] = nombre[i];
	}
	if(band==1 || salario < mensalario)
	{
		band=2;
		mensalario = salario;
		for(i=0; i <=20; i++)
			mennombre[i] = nombre[i];
	}
	clrscr();
	printf("El salario semanal de %s es de $%.2f", nombre , salario);
	printf("\n\nDesea seguir s/n?: ");
	seguir = getch();
	seguir = tolower(seguir);
	}while(seguir=='s');
	prom = total / n;
	clrscr();
	printf("Cantidad de empleados a los que se le calcul¢ el salario fue: %d", n);
	printf("\nEl empleado de mayor salario es %s y su sueldo es %.2f", maynombre, maysalario);
	printf("\nEl empleado de menor salario es %s y su sueldo es %.2f", mennombre, mensalario);
	printf("\nEl costo de la empresa en salarios es de $%.2f", total);
	printf("\nEl promedio de salarios en la empresa es de $%.2f", prom);
	gotoxy(1,50);
	printf("Presione una tecla para salir");
	getch();

}





