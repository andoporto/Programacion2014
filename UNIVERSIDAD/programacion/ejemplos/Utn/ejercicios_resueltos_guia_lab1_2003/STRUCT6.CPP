#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define M 1

struct nacimiento{

int dia;
int mes;
int anio;
};

struct agenda{

char nombre[16];
char apellido[16];
char direccion[16];
char localidad[16];
int postal;
struct nacimiento fn;
};

void main(void){

int dia, mes, anio, i, opc;
char ape[16], loc[16];

struct agenda vect[M];

for(i=0; i<M; i++)
{
clrscr();
printf("Nombre: ");
fflush(stdin);
gets(vect[i].nombre);
printf("\nApellido: ");
fflush(stdin);
gets(vect[i].apellido);
printf("\nDirecci¢n: ");
fflush(stdin);
gets(vect[i].direccion);
printf("\nLocalidad: ");
fflush(stdin);
gets(vect[i].localidad);
printf("\nC¢digo postal: ");
scanf("%d", &vect[i].postal);
printf("\nFecha de nacimiento");
printf("\n\nDia: ");
scanf("%d", &vect[i].fn.dia);
printf("\nMes: ");
scanf("%d", &vect[i].fn.mes);
printf("\nA¤o: ");
scanf("%d", &vect[i].fn.anio);
}
do
{
clrscr();
printf("\n\n\n\t\t\t\t  MENU\n\n\n\t\t\t1.Consulta por apellido\n\n\t\t\t2.Consulta por localidad\n\n\t\t\t3.Consulta por a¤o de nacimiento\n\n\t\t\t4.Consulta por cumplea¤os\n\n\t\t\t5.Salir\n\n\t\t\tOpc: ");
scanf("%d", &opc);
	switch(opc)
	{
	case 1:
	clrscr();
	printf("Apellido: ");
	fflush(stdin);
	gets(ape);
	for(i=0; i<M; i++)
		if((strcmp(vect[i].apellido, ape)) == 0)
		{
		clrscr();
		printf("\n\nNombre: %s %s\n\nDirecci¢n: %s\n\nLocalidad: %s\n\nC¢digo Postal: %d\n\nFecha de nacimiento: %d/%d/%d", vect[i].nombre, vect[i].apellido, vect[i].direccion, vect[i].localidad, vect[i].postal, vect[i].fn.dia, vect[i].fn.mes, vect[i].fn.anio);
		getch();
		break;
		}
	break;
	case 2:
	clrscr();
	printf("Localidad: ");
	fflush(stdin);
	gets(loc);
	for(i=0; i<M; i++)
		if((strcmp(vect[i].localidad, loc)) == 0)
		{
		clrscr();
		printf("\n\nNombre: %s %s\n\nDirecci¢n: %s\n\nLocalidad: %s\n\nC¢digo Postal: %d\n\nFecha de nacimiento: %d/%d/%d", vect[i].nombre, vect[i].apellido, vect[i].direccion, vect[i].localidad, vect[i].postal, vect[i].fn.dia, vect[i].fn.mes, vect[i].fn.anio);
		getch();
		break;
		}
	break;
	case 3:
	clrscr();
	printf("A¤o de nacimiento: ");
	scanf("%d", &anio);
	for(i=0; i<M; i++)
		if(vect[i].fn.anio == anio)
		{
		clrscr();
		printf("\n\nNombre: %s %s\n\nDirecci¢n: %s\n\nLocalidad: %s\n\nC¢digo Postal: %d\n\nFecha de nacimiento: %d/%d/%d", vect[i].nombre, vect[i].apellido, vect[i].direccion, vect[i].localidad, vect[i].postal, vect[i].fn.dia, vect[i].fn.mes, vect[i].fn.anio);
		getch();
		break;
		}
	break;
	case 4:
	clrscr();
	printf("Cumplea¤os");
	printf("\n\nDia: ");
	scanf("%d", &dia);
	printf("\nMes: ");
	scanf("%d", &mes);
	for(i=0; i<M; i++)
		if(vect[i].fn.dia == dia && vect[i].fn.mes == mes)
		{
		clrscr();
		printf("\n\nNombre: %s %s\n\nDirecci¢n: %s\n\nLocalidad: %s\n\nC¢digo Postal: %d\n\nFecha de nacimiento: %d/%d/%d", vect[i].nombre, vect[i].apellido, vect[i].direccion, vect[i].localidad, vect[i].postal, vect[i].fn.dia, vect[i].fn.mes, vect[i].fn.anio);
		getch();
		break;
		}
	break;
}
}while(opc!=5);
}
