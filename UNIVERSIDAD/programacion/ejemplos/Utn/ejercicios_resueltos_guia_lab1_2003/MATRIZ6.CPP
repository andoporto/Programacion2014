#include <stdio.h>
#include <conio.h>
#define M 3

void main(void){

int i, j, aux, leg[M];
float mat[M][5], auxf, m=0;

for(i=0; i<M; i++)
{
clrscr();
printf("N� de legajo: ");
scanf("%d", &leg[i]);
printf("\nSueldo b�sico: ");
scanf("%f", &mat[i][0]);
printf("\nBonificaci�n por antig�edad: ");
scanf("%f", &mat[i][3]);
mat[i][1] = mat[i][0] * 0.16;
mat[i][2] = mat[i][0.] * 0.045;
mat[i][4] = mat[i][0] - mat[i][1] - mat[i][2] + mat[i][3];
}
clrscr();
printf("\n  Listado:\n\n\n");
printf("  �����������������������������������������������������������������������Ŀ\n");
printf("  �N� legajo  �Sueldo Base�Jubilaci�n �Obra social�Antig�edad �Sueldo neto�\n");
printf("  �����������������������������������������������������������������������Ĵ\n  ");
for(i=0; i<M; i++)
	printf("�%6d     � %8.2f  � %8.2f  � %8.2f  � %8.2f  � %8.2f  �\n  ", leg[i], mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
printf("�������������������������������������������������������������������������");
for(i=0; i<M; i++)
	if(mat[i][3] > m)
		m=mat[i][3];
printf("\n\n  La cantidad m�xima de dinero otorgada para un bono de antig�edad fue de $%.2f", m);
printf("\n\n  Y el numero de legajo de el/los obreros con esa cantidad son:\n\n ");
for(i=0; i<M; i++)
	if(mat[i][3] == m)
		printf(" %d", leg[i]);
for(i=0; i<M-1; i++)
	for(j=i+1; j<M; j++)
		if(mat[i][4] > mat[j][4])
		{
		aux = leg[i];
		leg[i] = leg[j];
		leg[j] = aux;
		auxf = mat[i][0];
		mat[i][0] = mat[j][0];
		mat[j][0] = auxf;
		auxf = mat[i][1];
		mat[i][1] = mat[j][1];
		mat[j][1] = auxf;
		auxf = mat[i][0];
		mat[i][2] = mat[j][2];
		mat[j][2] = auxf;
		auxf = mat[i][3];
		mat[i][3] = mat[j][3];
		mat[j][3] = auxf;
		auxf = mat[i][4];
		mat[i][4] = mat[j][4];
		mat[j][4] = auxf;
		}
printf("\n\n  Listado de todos los obreros ordenado por sueldo neto:\n\n\n");
printf("  �����������������������������������������������������������������������Ŀ\n");
printf("  �N� legajo  �Sueldo Base�Jubilaci�n �Obra social�Antig�edad �Sueldo neto�\n");
printf("  �����������������������������������������������������������������������Ĵ\n  ");
for(i=0; i<M; i++)
	printf("�%6d     � %8.2f  � %8.2f  � %8.2f  � %8.2f  � %8.2f  �\n  ", leg[i], mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
printf("�������������������������������������������������������������������������");
getch();
}
