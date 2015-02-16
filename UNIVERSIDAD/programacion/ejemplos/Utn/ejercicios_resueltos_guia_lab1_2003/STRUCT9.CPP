#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define M 2

struct biblioteca {

int codigo;
int cantidad;
int pres;
char autor[16];
char titulo[16];
};

void main(void){

int i, opc, j;
char seguir;

struct biblioteca vect[M], aux;

for(i=0; i<M; i++)
	vect[i].pres=0;
for(i=0; i<M; i++)
{
clrscr();
printf("Codigo de libro: ");
scanf("%d", &vect[i].codigo);
	while(vect[i].codigo < 1 || vect[i].codigo > 100)
	{
	printf("\nError");
	getch();
	clrscr();
	printf("Codigo de libro: ");
	scanf("%d", &vect[i].codigo);
	}
printf("\nCantidad de ejemplares: ");
scanf("%d", &vect[i].cantidad);
printf("\nAutor: ");
fflush(stdin);
gets(vect[i].autor);
printf("\nTitulo: ");
fflush(stdin);
gets(vect[i].titulo);
}
do
{
clrscr();
printf("\n\n\n\t\t\t\t  MENU\n\n\n\t\t\t1.Prestamos de libros\n\n\t\t\t2.Devolucion de libros\n\n\t\t\t3.Salir\n\n\t\t\tOpc: ");
scanf("%d", &opc);
	switch(opc)
	{
	case 1: clrscr();
		printf("Codigo de libro: ");
		scanf("%d", &i);
		while(i<1||i>100)
		{
		printf("\nError");
		getch();
		clrscr();
		printf("Codigo de libro: ");
		scanf("%d", &i);
		}
		for(j=0; j<M; j++)
			if(vect[j].codigo == i)
				i=j;
		clrscr();
		printf("\n\tAutor: %s\n\n\tTitulo: %s", vect[i].autor, vect[i].titulo);
		printf("\n\nConfirma el prestamo s/n?: ");
		seguir = getch();
		seguir=tolower(seguir);
		if(seguir=='s')
		{
			if(vect[i].cantidad ==  1)
			 {
			 clrscr();
			 printf("Solo queda el ejemplar de lectura en sala");
			 getch();
			 break;
			 }
			 if(vect[i].cantidad > 1)
			 {
			 vect[i].pres++;
			 vect[i].cantidad--;
			 break;
			 }
		}
		break;
	case 2: clrscr();
		printf("Codigo de libro: ");
		scanf("%d", &i);
		while(i<1||i>100)
		{
		printf("\nError");
		getch();
		clrscr();
		printf("Codigo de libro: ");
		scanf("%d", &i);
		}
		for(j=0; j<M; j++)
			if(vect[j].codigo == i)
				i=j;
		clrscr();
		printf("\n\tAutor: %s\n\n\tTitulo: %s", vect[i].autor, vect[i].titulo);
		printf("\n\nConfirma la devoluci¢n s/n?: ");
		seguir = getch();
		seguir=tolower(seguir);
		if(seguir=='s')
			vect[i].cantidad++;
		break;
	case 3: clrscr();
		for(i=0; i<M-1; i++)
			for(j=i+1; j<M; j++)
				if(vect[i].pres < vect[j].pres)
				{
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
				}
		printf("     Listado ordenado en forma decreciente por cantidad de veces prestado:\n\n\n");
		printf("     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
		printf("     ³       Titulo        ³        Autor        ³   Veces prestado    ³\n");
		printf("     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n     ");
		for(i=0; i<M; i++)
			printf("³%21s³%21s³%21d³\n     ",vect[i].titulo, vect[i].autor, vect[i].pres);
		printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		getch();
		break;
	}
}while(opc!=3);
}










