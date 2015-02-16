#include <conio.h>
#include <stdio.h>
#include <ctype.h>

void main (void){
float alt, malt=0;
char nombre[15], apellido[20], mnombre[15], mapellido[20], seguir='s';
int i;

do
{
clrscr();
printf("Nombre: ");
scanf("%s", &nombre);
printf("\nApellido: ");
scanf("%s", &apellido);
printf("\nAltura: ");
scanf("%f", &alt);
if(alt > malt)
	{
	malt = alt;
	for(i = 0; i < 16; i++)
	mnombre[i] = nombre[i];
	for(i = 0; i < 21; i++)
	mapellido[i] = apellido[i];
	}
printf("\n\nDesea seguir s/n?: ");
seguir = getch();
seguir = tolower(seguir);
}while(seguir == 's');
clrscr();
printf("\nEl alumno mas alto es %s %s y su altura es de %.2fm", mnombre, mapellido, malt);
getch();
}


