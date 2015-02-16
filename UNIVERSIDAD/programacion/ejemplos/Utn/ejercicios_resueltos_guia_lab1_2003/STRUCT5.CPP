#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define M 2

struct censo{

int edad;
char nombre[21];
char direccion[21];
char telefono[21];
};

void main(void){

int i, j, aux;
char aux2[21];

struct censo vect[M];

for(i=0; i<M; i++)
{
clrscr();
printf("Edad: ");
scanf("%d", &vect[i].edad);
printf("\nNombre: ");
fflush(stdin);
gets(vect[i].nombre);
printf("\nDirecci¢n: ");
fflush(stdin);
gets(vect[i].direccion);
printf("\nTelefono: ");
fflush(stdin);
gets(vect[i].telefono);
}
clrscr();
for(i=0; i<M-1; i++)
	for(j=i+1; j<M; j++)
	if((strcmp(vect[i].nombre, vect[j].nombre)) > 0)
	{
	aux = vect[i].edad;
	vect[i].edad = vect[j].edad;
	vect[j].edad = aux;
	strcpy(aux2, vect[i].nombre);
	strcpy(vect[i].nombre, vect[j].nombre);
	strcpy(vect[j].nombre, aux2);
	strcpy(aux2, vect[i].direccion);
	strcpy(vect[i].direccion, vect[j].direccion);
	strcpy(vect[j].direccion, aux2);
	strcpy(aux2, vect[i].telefono);
	strcpy(vect[i].telefono, vect[j].telefono);
	strcpy(vect[j].telefono, aux2);
	}
printf("    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("    ³      Edad      ³     Nombre     ³   Direcci¢n    ³    Telefono    ³\n");
printf("    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n    ");
for(i=0; i<M; i++)
	printf("³%16d³%16s³%16s³%16s³\n    ", vect[i].edad, vect[i].nombre, vect[i].direccion, vect[i].telefono);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
}






