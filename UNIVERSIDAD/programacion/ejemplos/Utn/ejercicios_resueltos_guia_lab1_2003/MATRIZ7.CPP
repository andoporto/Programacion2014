#include <stdio.h>
#include <conio.h>

void main(void){

int pe, band=0, opc, i, j, mat[5][3];

for(i=0; i<5; i++)
	for(j=0; j<3; j++)
		mat[i][j] = 0;
do
{
clrscr();
printf("\n\t\t\t\tOpciones\n\n\n\t\t\t1.Carga de datos\n\n\t\t\t2.Venta de articulos\n\n\t\t\t3.Existencia de mercaderias\n\n\t\t\t4.Salir\n\n\n\t\t\tOpci¢n: ");
scanf("%d", &opc);
while(opc<1||opc>4)
{
clrscr();
printf("\n\t\t\t\tOpciones\n\n\n\t\t\t1.Carga de datos\n\n\t\t\t2.Venta de articulos\n\n\t\t\t3.Existencia de mercaderias\n\n\t\t\t4.Salir\n\n\n\t\t\tOpci¢n: ");
scanf("%d", &opc);
}
switch(opc){
case 1: band=1; clrscr();
	printf("\nN¦ de sucursal: "); scanf("%d", &i);
	printf("\nN¦ de articulo: "); scanf("%d", &j);
	printf("\nCantidad: "); scanf("%d", &mat[i-1][j-1]);
	break;
case 2: if(band==1)
	{
	clrscr();
	printf("\nN¦ de sucursal: "); scanf("%d", &i);
	printf("\nN¦ de articulo: "); scanf("%d", &j);
	printf("\nCantidad: "); scanf("%d", &pe);
		if(mat[i-1][j-1] < pe)
		printf("\n\nNo se puede realizar la venta por falta de stock");
	break;
	}
	break;
case 3: if(band==1)
	{
	clrscr();
	printf("    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("    ³ Articulo 1  ³ Articulo 2  ³ Articulo 3  ³ Articulo 4  ³ Articulo 5  ³\n");
	printf("    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n    ");
	for(i=0; i<3; i++)
		{
		if(i!=0)
		printf("³\n    ");
		for(j=0; j<5; j++)
		printf("³     %d       ", mat[i][j]);
		}
	printf("³");
	printf("\n    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	getch();
	break;
	}
	break;
}
}while(opc!=4);
}


