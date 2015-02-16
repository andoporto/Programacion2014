#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void){

int i, leg, aprob=0, dic=0, marzo=0, maxleg, band=0;
char seguir, nombre[20], mnombre[20];
float prom, mprom;

do{
flushall;
clrscr();
printf("N§ de legajo: ");
scanf("%d", &leg);
printf("\nNombre: ");
scanf("%s", &nombre);
printf("\nPromedio: ");
scanf("%f", &prom);
if( prom > mprom || band == 0 )
	{
	mprom = prom;
	maxleg = leg;
	for( i = 0; i <=20; i++)
	mnombre[i] = nombre[i];
	band = 1;
	}
if( prom >= 7 )
aprob = aprob++;
if( prom < 7 && prom >= 4 )
dic = dic++;
if( prom < 4 )
marzo = marzo++;
printf("\nDesea Seguir s/n?: ");
seguir = getch();
seguir = tolower(seguir);
}while(seguir=='s');
clrscr();
printf("\n%d es el n£mero de alumnos que aprobaron", aprob);
printf("\n\n%d es el n£mero de alumnos que rinden en  diciembre", dic);
printf("\n\n%d es el n£mero de alumnos que rinden en marzo", marzo);
printf("\n\nEl n£mero de legajo del alumno con mejor promedio es %d y su nombre es %s", maxleg, mnombre);
getch();
}






