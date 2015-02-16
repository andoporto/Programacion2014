#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define M 2

struct deposito{

int codigo;
int cantidad;
char des[21];
float precio;
};

void main(void){

int n, caso, i, j, opc;
float precio;
char seguir;

struct deposito vect[M];

for(i=0; i<M; i++)
{
clrscr();
printf("Codigo de articulo: ");
scanf("%d", &vect[i].codigo);
	while(vect[i].codigo < 1 || vect[i].codigo > 30)
	{
	printf("\nERROR");
	getch();
	clrscr();
	printf("Codigo de articulo: ");
	scanf("%d", &vect[i].codigo);
	}
printf("\nDescripcion: ");
fflush(stdin);
gets(vect[i].des);
printf("\nCantidad en stock: ");
scanf("%d", &vect[i].cantidad);
printf("\nPrecio unitario: ");
scanf("%f", &precio);
vect[i].precio = precio;
}
do
{
clrscr();
printf("\n\n\n\t\t\t\t  MENU\n\n\n\t\t\t1.Registros de compras y ventas\n\n\t\t\t2.Consultar el precio\n\n\t\t\t3.Consulta existencia en stock\n\n\t\t\t4.Salir\n\n\t\t\tOpc: ");
scanf("%d", &opc);
	switch(opc)
	{
	case 1: do
		{
		clrscr();
		printf("Codigo de articulo: ");
		scanf("%d", &i);
			while(i < 1 || i > 30)
			{
			printf("\nERROR");
			getch();
			clrscr();
			printf("Codigo de articulo: ");
			scanf("%d", &i);
			}
			for(j=0; j<M; j++)
				if(vect[j].codigo == i)
					{
					i=j;
					break;
					}
			if(j=M)
			{
			clrscr();
			printf("No existe ese codigo");
			getch();
			break;
			}
		printf("\nCodigo de movimiento: ");
		scanf("%d", &caso);
			while(caso < 1 || i > 2)
			{
			printf("\nERROR");
			getch();
			clrscr();
			printf("Codigo de movimiento: ");
			scanf("%d", &caso);
			}
		printf("\nCantidad: ");
		scanf("%d", &n);
			switch(caso)
			{
			case 1: clrscr();
				if(vect[i].cantidad >= n)
				{
				vect[i].cantidad = vect[i].cantidad - n;
				printf("La venta ha sido realizada\n\n");
				}
				break;
			case 2: clrscr();
				vect[i].cantidad = vect[i].cantidad + n;
				break;
			}
		printf("Desea seguir s/n?: ");
		seguir = getch();
		seguir = tolower(seguir);
		}while(seguir=='s');
		break;
	case 2: clrscr();
		printf("Codigo de articulo: ");
		scanf("%d", &i);
			while(i < 1 || i > 30)
			{
			printf("\nERROR");
			getch();
			clrscr();
			printf("Codigo de articulo: ");
			scanf("%d", &i);
			}
				for(j=0; j<M; j++)
					if(vect[j].codigo == i)
					{
					i=j;
					break;
					}
			if(j=M)
			{
			clrscr();
			printf("No existe ese codigo");
			getch();
			break;
			}

		clrscr();
		printf("\n\tDescripcion del articulo: %s\n\tPrecio unitario: %.2f", vect[i].des, vect[i].precio);
		getch();
		break;
	case 3: clrscr();
		printf("Codigo de articulo: ");
		scanf("%d", &i);
			while(i < 1 || i > 30)
			{
			printf("\nERROR");
			getch();
			clrscr();
			printf("Codigo de articulo: ");
			scanf("%d", &i);
			}
			for(j=0; j<M; j++)
				if(vect[j].codigo == i)
					{
					i=j;
					break;
					}
			if(j=M)
			{
			clrscr();
			printf("No existe ese codigo");
			getch();
			break;
			}
		clrscr();
		printf("\n\tDescripcion del articulo: %s\n\tExistencia: %d", vect[i].des, vect[i].cantidad);
		getch();
		break;
	}
}while(opc!=4);
}












