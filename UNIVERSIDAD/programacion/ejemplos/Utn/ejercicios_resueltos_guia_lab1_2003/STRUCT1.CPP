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
printf("    旼컴컴컴컴컴컴쩡컴컴컴컴컴컴쩡컴컴컴컴컴컴쩡컴컴컴컴컴컴쩡컴컴컴컴컴컴�\n");
printf("    �   Nombre    �   Equipo    �    Goles    �   Partidos  �  Promedio   �\n");
printf("    쳐컴컴컴컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴�\n    ");
for(i=0; i<M; i++)
	printf("�%7s      �%7s      �%7d      �%7d      �     %.2f    �\n    ", vect[i].nombre, vect[i].equipo, vect[i].goles, vect[i].partidos, vect[i].promedio);
printf("읕컴컴컴컴컴컴좔컴컴컴컴컴컴좔컴컴컴컴컴컴좔컴컴컴컴컴컴좔컴컴컴컴컴컴�");
getch();
}










