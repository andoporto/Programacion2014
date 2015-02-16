#include <stdio.h>
#include <conio.h>

void main(void){

int ped, opc, i, j, mat[10][6];

for(i=0; i<10; i++)
{
clrscr();
printf("\nCodigo de pieza: "); scanf("%d", &mat[i][0]);
printf("\nExistencia al comenzar el mes: "); scanf("%d", &mat[i][1]);
mat[i][2]=0;
mat[i][3]=0;
mat[i][4]=0;
mat[i][5]=mat[i][1];
}
do
{
clrscr();
printf("\n\t\t\t\tOpciones\n\n\n\t\t\t1.Pedido\n\n\t\t\t2.Reaprovisionamiento\n\n\t\t\t3.Salir\n\n\n\t\t\tOpci¢n: ");
scanf("%d", &opc);
	while(opc<1||opc>3)
	{
	clrscr();
	printf("\n\t\t\t\tOpciones\n\n\n\t\t\t1.Pedido\n\n\t\t\t2.Reaprovisionamiento\n\n\t\t\t3.Salir\n\n\n\t\t\tOpci¢n: ");
	scanf("%d", &opc);
	}
switch(opc){
case 1: clrscr(); printf("\nCodigo de pieza: "); scanf("%d", &i);
	printf("\nCantidad pedida: "); scanf("%d", &ped);
	if(ped > mat[i-1][5])
	{
	mat[i-1][4]++;
	printf("\n\nPedido rechazado por falta de stock");
	getch();
	break;
	}
	else
	{
	mat[i-1][3]=mat[i-1][3] + ped;
	mat[i-1][5]=mat[i-1][5] - ped;
	break;
	}
case 2: clrscr(); printf("\nCodigo de pieza: "); scanf("%d", &i);
	printf("\nCantidad recibida: "); scanf("%d", &ped);
	mat[i-1][2]=mat[i-1][2] + ped;
	mat[i-1][5]=mat[i-1][5] + ped;
	break;
	}
}while(opc!=3);
clrscr();
for(i=0; i<9; i++)
	for(j=i+1; j<10; j++)
	if(mat[i][5] > mat[j][5])
	{
	ped = mat[i][0];
	mat[i][0] = mat[j][0];
	mat[j][0] = ped;
	ped = mat[i][1];
	mat[i][1] = mat[j][1];
	mat[j][1] = ped;
	ped = mat[i][2];
	mat[i][2] = mat[j][2];
	mat[j][2] = ped;
	ped = mat[i][3];
	mat[i][3] = mat[j][3];
	mat[j][3] = ped;
	ped = mat[i][4];
	mat[i][4] = mat[j][4];
	mat[j][4] = ped;
	ped = mat[i][5];
	mat[i][5] = mat[j][5];
	mat[j][5] = ped;
	}
clrscr();
printf("\n  Listado ordenado en forma creciente por saldos finales:\n\n\n");
printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("  ³ Cod pieza ³ Cant.ini .³Total recib³Total entre³Total recha³   Saldo   ³\n");
printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n  ");
for(i=0; i<10; i++)
	printf("³%6d     ³%6d     ³%6d     ³%6d     ³%6d     ³%6d     ³\n  ", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4], mat[i][5]);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
}












