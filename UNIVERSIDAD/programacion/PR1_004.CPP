#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct arti { int nume;
			char desc [26];
         float costo;
         int saldo; };
void leedatos(struct arti*);
void main ()
{
FILE *stock;
struct arti articulo;
if((stock= fopen("f:stockfe.dat","wb"))==NULL)
	{
   printf("Error al crear el archivo|n");
   exit(0);
   }
   clrscr();
   leedatos (&articulo);
   while(articulo.nume!=0)
   {
   fwrite(&articulo, sizeof(struct arti),1,stock);
   leedatos(&articulo);
   }
fclose(stock);
getch();
}
void leedatos(struct arti *a)
{
printf("Ingrese numero de articulo: ");
scanf("%d", &a->nume); fflush(stdin);
printf("Ingrese descripcion: ");
gets(a->desc);
printf("Ingrese costo unitario: ");
scanf("%f", &a->costo); fflush(stdin);
printf("Ingrese el saldo actual: ");
scanf("%d", &a->saldo); fflush(stdin);
}

