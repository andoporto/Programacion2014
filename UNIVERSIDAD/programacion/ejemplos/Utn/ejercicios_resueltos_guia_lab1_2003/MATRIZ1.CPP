#include <stdio.h>
#include <conio.h>

void main (void){

int mat[6][5], i, j;

clrscr();
for(i=0; i<6; i++)
	for(j=0; j<5; j++)
	mat[i][j]=0;
printf("\nN£mero de fila: ");
scanf("%d", &i);
printf("\nN£mero de columna: ");
scanf("%d", &j);
printf("\nN£mero entero: ");
scanf("%d", &mat[i-1][j-1]);
clrscr();
printf("\n\t\t\t\t  Matriz\n\n\n\n\t\t\t\t");
for(i=0; i<6; i++)
	{
	if(i!=0)
	printf("\n\n\t\t\t\t");
	for(j=0; j<5; j++)
	printf(" %d", mat[i][j]);
	}
getch();
}


