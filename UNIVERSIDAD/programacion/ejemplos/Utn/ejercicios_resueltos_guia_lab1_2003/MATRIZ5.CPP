#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main(void){

int mat[4][3], pa, i, j, ped, cont=0, rech[100][2];
char seguir='s';

for(i=0; i<4; i++)
	for(j=0; j<3; j++)
		mat[i][j] = 5;
do
{
clrscr();
printf("N¦ de pedido: ");
scanf("%d", &ped);
printf("\nN¦ de destino: ");
scanf("%d", &i);
printf("\nN¦ de vuelo: ");
scanf("%d", &j);
printf("\nCantidad de pasajes requeridos: ");
scanf("%d", &pa);
if(pa > mat[i-1][j-1])
	{
	rech[cont][0] = ped;
	rech[cont][1] = pa;
	cont++;
	clrscr();
	printf("\nNO HAY CANTIDAD DE PLAZAS DISPONIBLES");
	}
else
mat[i-1][j-1] = mat[i-1][j-1] - pa;
printf("\nDesea hacer otro pedido s/n?: ");
seguir=getch();
seguir=tolower(seguir);
}while(seguir=='s');
clrscr();
printf("\n\n\n");
printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("\t\t\t³ N¦ de vuelo ³ P.Sobrantes ³\n");
printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n\t\t\t");
for(i=0; i<4; i++)
	for(j=0; j<3; j++)
	printf("³     %d.%d     ³      %d      ³\n\t\t\t", i+1, j+1 ,mat[i][j]);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("\t\t\t³ N¦ Ped.rech.³ P.Solicita. ³\n");
printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n\t\t\t");
for(i=0; i<cont; i++)
	printf("³      %d      ³      %d      ³\n\t\t\t", rech[i][0], rech[i][1]);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n\n");
getch();
}






