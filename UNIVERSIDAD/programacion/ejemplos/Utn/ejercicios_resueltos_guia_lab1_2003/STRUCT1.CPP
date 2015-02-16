#include <stdio.h>
#include <conio.h>
#define M 2

struct jugador {

char nombre[10],
     equipo[10];
int partidos,
    goles;
float promedio;
};

void main (void){

int i;
struct jugador vect[M];

for(i=0; i<M; i++)
{
clrscr();
printf("\nNombre del jugador: ");
fflush(stdin);
gets(vect[i].nombre);
printf("\nNombre del equipo: ");
fflush(stdin);
gets(vect[i].equipo);
printf("\nCantidad de partidos jugados: ");
scanf("%d", &vect[i].partidos);
printf("\nCantidad de goles: ");
scanf("%d",&vect[i].goles);
vect[i].promedio = (float)vect[i].goles / vect[i].partidos;
}
clrscr();
printf("    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("    ³   Nombre    ³   Equipo    ³    Goles    ³   Partidos  ³  Promedio   ³\n");
printf("    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n    ");
for(i=0; i<M; i++)
	printf("³%7s      ³%7s      ³%7d      ³%7d      ³     %.2f    ³\n    ", vect[i].nombre, vect[i].equipo, vect[i].goles, vect[i].partidos, vect[i].promedio);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
}










