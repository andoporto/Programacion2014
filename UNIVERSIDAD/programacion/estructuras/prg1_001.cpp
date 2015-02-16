#include <stdio.h>
#include <conio.h>
#include <string.h>

struct auto1 { char marca[13];
			   int aniofabri;
			   char color [9];
			   float precio; };

void main()
{
 struct auto1 automovil,autito;
 int j;
 float pesos;
 clrscr();
  for (j=1;j<4;j++)
  {
	printf("Ingrese marca, a¤o, color y precio:");
 scanf("%s%d%s%f", automovil.marca,&automovil.aniofabri,automovil.color,&pesos);
 fflush(stdin);
 automovil.precio=pesos;
 autito=automovil;
  	if (autito.precio<9000)
		printf("%-13s,%-9s,%5d \n", autito.marca,autito.color,autito.aniofabri);
  	}
  	getch();
}