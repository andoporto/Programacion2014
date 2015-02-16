#include <stdio.h>
#include <conio.h>
#define M 5

void main (void){

int i, edad[M], leg[M];
float salario[M], prom, total=0;

for(i=0; i<M; i++)
{
clrscr();
printf("Legajo: ");
scanf("%d", &leg[i]);
while(leg[i] > M || leg[i] < 1)
	{
	clrscr();
	printf("Legajo: ");
	scanf("%d", &leg[i]);
	}
printf("\nEdad: ");
scanf("%d", &edad[i]);
printf("\nSalario: ");
scanf("%f", &salario[i]);
total=total + salario[i];
}
clrscr();
prom = total / M;
printf("El salario promedio es de $%.2f y los n§ de legajos que superan ese salario son:", prom);
gotoxy(1,4);
for(i=0; i<M; i++)
	if(salario[i] > prom)
	printf("* %d", leg[i]);
getch();
}









