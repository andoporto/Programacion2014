#include <conio.h>
#include <stdio.h>
#include <ctype.h>

void main (void){

char fecha[9], mayfecha[9], minfecha[9], seguir = 's';
float tempmay=0, tempmin=0, maytemp=0, mintemp=10000;
int band=0, i;
do
{
clrscr();
flushall;
printf("Fecha: ");
scanf("%s", &fecha);
printf("\nTemperatura m xima: ");
scanf("%f", &tempmay);
printf("\nTemperatura m¡nima: ");
scanf("%f", &tempmin);
if(tempmay > maytemp || band == 0)
	{
	maytemp = tempmay;
	for(i = 0; i < 10; i++)
	mayfecha[i] = fecha[i];
	band = 1;
	}
if(tempmin < mintemp)
	{
	mintemp = tempmin;
	for(i = 0; i < 10; i++)
	minfecha[i] = fecha[i];
	}
clrscr();
printf("Desea seguir s/n?: ");
seguir = getch();
seguir = tolower(seguir);
}while(seguir == 's');
clrscr();
printf("El dia mas calido fue: %s y su temperatura fue de: %.1f grados", mayfecha, maytemp);
printf("\n\nEl dia mas frio fue: %s y su temperatura fue de: %.1f grados", minfecha, mintemp);
gotoxy(1,50);
printf("Presione una tecla para salir");
getch();
}




