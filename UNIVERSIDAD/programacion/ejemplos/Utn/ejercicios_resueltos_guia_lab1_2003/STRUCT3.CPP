#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define M 2

struct alumnos{
char apellido[10];
float nota;
int legajo;
};

void main(void){

int i, leg;
float nota, n;
char seguir;

struct alumnos vect[M];

for(i=0; i<M; i++)
{
clrscr();
printf("Apellido: ");
fflush(stdin);
gets(vect[i].apellido);
printf("\n\nNota: ");
scanf("%f", &n);
vect[i].nota=n;
printf("\nLegajo: ");
scanf("%d", &vect[i].legajo);
}
clrscr();
printf("Desea modificar alguna nota: ");
seguir=getch();
seguir=tolower(seguir);
while(seguir=='s')
{
clrscr();
printf("Legajo: ");
scanf("%d", &leg);
printf("\nNota: ");
scanf("%f", &nota);
	for(i=0; i<M; i++)
		if(vect[i].legajo == leg)
		{
		vect[i].nota= nota;
		break;
		}
	if(M==i)
	{
	printf("\nNo se encontro el legajo...");
	getch();
	}
clrscr();
printf("Desea modificar otra nota: ");
seguir =getch();
seguir=tolower(seguir);
}
clrscr();
printf("    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("    ³  N¦ legajo  ³   Apellido  ³    Nota     ³\n");
printf("    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n    ");
for(i=0; i<M; i++)
	printf("³%4d         ³%10s   ³%13.2f³\n    ", vect[i].legajo, vect[i].apellido, vect[i].nota);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
}




