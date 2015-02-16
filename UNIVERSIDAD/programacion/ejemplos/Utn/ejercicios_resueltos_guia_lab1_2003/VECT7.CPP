#include <stdio.h>
#include <conio.h>
#define M 5

void main (void){

int i, edad[M], total=0, prom;
float salario[M];

for(i=0; i<M; i++)
{
clrscr();
printf("Edad: ");
scanf("%d", &edad[i]);
printf("\nSalario: ");
scanf("%f", &salario[i]);
total=total + edad[i];
}
clrscr();
prom = total / M;
printf("La edad promedio es de %d a¤os y los n§ de legajos que superan esa edad son:", prom);
gotoxy(1,4);
for(i=0; i<M; i++)
	if(edad[i] > prom)
	printf("* %d", i+1);
getch();
}








