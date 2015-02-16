#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TAM 10

struct arti { int nume;
			char desc [26];
         float costo;
         int saldo; };

void main ()
{
FILE *stock;
struct arti articulo[TAM];
int i=0, j;
if((stock= fopen("f:stockfe.dat","rb"))==NULL)
	{
   printf("Error al abrir el archivo\n");
   exit(0);
   }
   clrscr();
   fread(&articulo[i], sizeof(struct arti),1,stock);
   while(!feof(stock))
   {
   i++;
   fread(&articulo[i],sizeof(struct arti),1,stock);
   }
fclose(stock);
printf("***LISTADO DE PRODUCTOS***\n\n");
printf("Numero Descripcion Costo");
printf("					Saldo actual\n\n");
for(j=0;j<i;j++)
{
printf("%5d		%-26s", articulo[j].nume, articulo[j].desc);
printf("%10.2f %8d\n", articulo[j].costo, articulo[j].saldo);
}
getch();
}


