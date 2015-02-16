#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define M 2

struct pers{

char nombre[15];
char sexo;
int edad;
};

void main(void){

int i, muj=0, hom=0;

struct pers vect[M];

for(i=0; i<M; i++)
{
clrscr();
printf("Nombre: ");
fflush(stdin);
gets(vect[i].nombre);
printf("\nSexo m / f: ");
vect[i].sexo = getch();
vect[i].sexo = tolower(vect[i].sexo);
printf("\n\nEdad: ");
scanf("%d", &vect[i].edad);
	if(vect[i].sexo == 'f')
		if(vect[i].edad >=20 && vect[i].edad <=30)
			muj++;
	if(vect[i].sexo == 'm')
		if(vect[i].edad < 37)
			hom++;
}
clrscr();
printf("Hay %d mujer/es entre 20 y 30 a¤os y %d hombre/s menor/es de 37", muj, hom);
getch();
}
