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
printf("N� de pedido: ");
scanf("%d", &ped);
printf("\nN� de destino: ");
scanf("%d", &i);
printf("\nN� de vuelo: ");
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
printf("\t\t\t���������������������������Ŀ\n");
printf("\t\t\t� N� de vuelo � P.Sobrantes �\n");
printf("\t\t\t���������������������������Ĵ\n\t\t\t");
for(i=0; i<4; i++)
	for(j=0; j<3; j++)
	printf("�     %d.%d     �      %d      �\n\t\t\t", i+1, j+1 ,mat[i][j]);
printf("�����������������������������\n\n");
printf("\t\t\t���������������������������Ŀ\n");
printf("\t\t\t� N� Ped.rech.� P.Solicita. �\n");
printf("\t\t\t���������������������������Ĵ\n\t\t\t");
for(i=0; i<cont; i++)
	printf("�      %d      �      %d      �\n\t\t\t", rech[i][0], rech[i][1]);
printf("�����������������������������\n\n\n");
getch();
}






