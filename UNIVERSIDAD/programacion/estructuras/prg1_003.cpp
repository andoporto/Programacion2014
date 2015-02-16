#include <stdio.h>
#include <conio.h>
#include <string.h>

struct articulo { int codigo;
		  char descri[16];
		  float costo;
		  int saldo; };

/*Las dos líneas que estan a continaución son necesarias
para trabajar campos reales en estructuras*/

extern unsigned_floatconvert;
#pragma extref_floatconvert

void main()
{
 struct articulo arti[10];
 int cant, i, mincodigo;
 float min;
 char mindes[16];

 do {
	 clrscr();
	 printf("Ingrese la cantidad de productos \n");
	 scanf("%d", &cant);
    } while (cant <= 0 || cant>100);

  for (i=0;i<cant;i++)
  {
	clrscr();
	printf("Datos del producto %d \n");
	printf("Ingrese codigo: ");scanf("%d",&arti[i].codigo);
	fflush(stdin);
	printf(" \n Ingrese descripcion: "); gets(arti[i].descri);
	printf(" \n Ingrese costo: "); scanf("%f",&arti[i].costo);
	fflush(stdin);
	printf(" \n Ingrese saldo: "); scanf("%d",&arti[i].saldo);
	fflush(stdin);
  }

  clrscr();
  printf("Listado de Productos\n\n",i+1);
  printf("Codigo	Descripcion			Costo		Saldo \n\n");
  for (i=0;i<cant;i++)
  {
	  if (i==0 || arti[i].costo<min)
	  {
		min=arti[i].costo;
		mincodigo=arti[i].codigo;
		strcpy(mindes,arti[i].descri);
	  }

   printf("Los datos del articulo de minimo costo son:\n");
   printf("Codigo: %d	Descripcion: %-s	Costo: %.2f", mincodigo, mindes, min);
   getch();
 }
}
