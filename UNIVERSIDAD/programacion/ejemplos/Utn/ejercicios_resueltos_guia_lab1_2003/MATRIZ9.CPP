#include <stdio.h>
#include <conio.h>

void main(void){

int mat[8][6], venta, i, j;

for(i=0; i<8; i++)
{
clrscr();
printf("N� de revista: ");
scanf("%d", &mat[i][0]);
printf("\nCantidad de ejemplares vendidos: ");
scanf("%d", &mat[i][1]);
printf("\nValor de venta de la revista: ");
scanf("%d", &venta);
mat[i][2] = mat[i][1] * venta;
printf("\nMonto cobrado por publicidad: ");
scanf("%d", &mat[i][3]);
printf("\nGastos de edici�n: ");
scanf("%d", &mat[i][4]);
mat[i][5] = mat[i][2] + mat[i][3] - mat[i][4];
}
for(i=0; i<7; i++)
	for(j=i+1; j<8; j++)
	if(mat[i][5] < mat[j][5])
	{
	venta = mat[i][0];
	mat[i][0] = mat[j][0];
	mat[j][0] = venta;
	venta = mat[i][1];
	mat[i][1] = mat[j][1];
	mat[j][1] = venta;
	venta = mat[i][2];
	mat[i][2] = mat[j][2];
	mat[j][2] = venta;
	venta = mat[i][3];
	mat[i][3] = mat[j][3];
	mat[j][3] = venta;
	venta = mat[i][4];
	mat[i][4] = mat[j][4];
	mat[j][4] = venta;
	venta = mat[i][5];
	mat[i][5] = mat[j][5];
	mat[j][5] = venta;
	}
clrscr();
printf("\n  Listado ordenado en forma decreciente por Ganancia o perdida:\n\n\n");
printf("  �����������������������������������������������������������������������Ŀ\n");
printf("  �N� revista �Ejemplares � Recaudado �Cobrado por� Gastos de � Ganancia o�\n");
printf("  �           � vendidos  � por ventas�publicidad � edicion   � Perdida   �\n");
printf("  �����������������������������������������������������������������������Ĵ\n  ");
for(i=0; i<8; i++)
	printf("�%6d     �%6d     �%6d     �%6d     �%6d     �%6d     �\n  ", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4], mat[i][5]);
printf("�������������������������������������������������������������������������");
getch();
}