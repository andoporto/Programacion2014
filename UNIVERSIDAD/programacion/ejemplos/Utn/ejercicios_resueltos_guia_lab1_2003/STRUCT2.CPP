#include <stdio.h>
#include <conio.h>
#include <string.h>
#define M 2

struct direccion{

int  numero;
char localidad[15], calle[12];
    };

struct empleado{

char   nombre[15],  sexo;
struct direccion fc;
int       edad;
    };

void main(void){


int i, j;
char aux[15];


struct empleado vect[M];

for(i=0; i<M; i++)
{
clrscr();
printf("\nNombre: ");
fflush(stdin);
gets(vect[i].nombre);
printf("\nCalle: ");
fflush(stdin);
gets(vect[i].fc.calle);
printf("\nNumero: ");
scanf("%d", &vect[i].fc.numero);
printf("\nLocalidad: ");
fflush(stdin);
gets(vect[i].fc.localidad);
printf("\nEdad: ");
scanf("%d", &vect[i].edad);
printf("\nSexo m/f: ");
fflush(stdin);
scanf(" %c", &vect[i].sexo);
}
clrscr();
printf("  Listado de personas menores de 25 a¤os:\n\n\n\n");
printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("  ³  Nombre   ³   Calle   ³  Numero   ³ Localidad ³    Edad   ³    Sexo   ³\n");
printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n  ");
for(i=0; i<M; i++)
	if(vect[i].edad < 25)
		printf("³%7s    ³%7s    ³%4d       ³%10s ³%2d         ³      %c    ³\n  ", vect[i].nombre, vect[i].fc.calle, vect[i].fc.numero, vect[i].fc.localidad, vect[i].edad, vect[i].sexo);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
clrscr();
printf("  Listado de personas que vivem em Avellaneda:\n\n\n\n");
printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("  ³  Nombre   ³   Calle   ³  Numero   ³ Localidad ³    Edad   ³    Sexo   ³\n");
printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n  ");
for(i=0; i<M; i++)
	if((strcmp(vect[i].fc.localidad, "Avellaneda")) == 0)
		printf("³%7s    ³%7s    ³%4d       ³%10s ³%2d         ³      %c    ³\n  ", vect[i].nombre, vect[i].fc.calle, vect[i].fc.numero, vect[i].fc.localidad, vect[i].edad, vect[i].sexo);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
clrscr();
printf("  Listado de personas que vivem em Avellaneda y tienen menos de 25 a¤os:\n\n\n\n");
printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("  ³  Nombre   ³   Calle   ³  Numero   ³ Localidad ³    Edad   ³    Sexo   ³\n");
printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n  ");
for(i=0; i<M; i++)
	if((strcmp(vect[i].fc.localidad, "Avellaneda"))==0 && vect[i].edad < 25)
		printf("³%7s    ³%7s    ³%4d       ³%10s ³%2d         ³      %c    ³\n  ", vect[i].nombre, vect[i].fc.calle, vect[i].fc.numero, vect[i].fc.localidad, vect[i].edad, vect[i].sexo);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
clrscr();
printf("  Listado de personas ordenado alfabeticamente\n\n\n\n");
printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("  ³  Nombre   ³   Calle   ³  Numero   ³ Localidad ³    Edad   ³    Sexo   ³\n");
printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n  ");
for(i=0; i<M-1; i++)
	for(j=i+1; j<M; j++)
		if((strcmp(vect[i].nombre, vect[j].nombre)) > 0)
		{
		strcpy(aux, vect[i].nombre);
		strcpy(vect[i].nombre,  vect[j].nombre);
		strcpy(vect[j].nombre, aux);
		}
for(i=0; i<M; i++)
	printf("³%7s    ³%7s    ³%4d       ³%10s ³%2d         ³      %c    ³\n  ", vect[i].nombre, vect[i].fc.calle, vect[i].fc.numero, vect[i].fc.localidad, vect[i].edad, vect[i].sexo);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
}



