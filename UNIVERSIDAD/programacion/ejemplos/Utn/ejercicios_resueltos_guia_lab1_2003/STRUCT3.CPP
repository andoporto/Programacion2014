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
printf("    旼컴컴컴컴컴컴쩡컴컴컴컴컴컴쩡컴컴컴컴컴컴�\n");
printf("    �  N� legajo  �   Apellido  �    Nota     �\n");
printf("    쳐컴컴컴컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴�\n    ");
for(i=0; i<M; i++)
	printf("�%4d         �%10s   �%13.2f�\n    ", vect[i].legajo, vect[i].apellido, vect[i].nota);
printf("읕컴컴컴컴컴컴좔컴컴컴컴컴컴좔컴컴컴컴컴컴�");
getch();
}




