#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void){

char seguir;
int i, j;
float mat[3][12], rec, total=0, linea1=0, linea2=0, linea3=0;

for(i=0; i<3; i++)
	for(j=0; j<12; j++)
	mat[i][j]=0;
do
{
clrscr();
printf("\nN£mero de coche: ");
scanf("%d", &j);
printf("\nN£mero de linea: ");
scanf("%d", &i);
printf("\nRecaudaci¢n: ");
scanf("%f", &rec);
switch(i)
	{
	case 1: linea1=linea1 + rec; break;
	case 2: linea2=linea2 + rec; break;
	case 3: linea3=linea3 + rec; break;
	}
mat[i-1][j-1] = mat[i-1][j-1] + rec;
total = total + rec;
printf("\nDesea seguir s/n?: ");
seguir = getch();
seguir=tolower(seguir);
}while(seguir=='s');
clrscr();
printf("\n\t\t     Las recaudaciones por linea fueron:\n\n");
printf("\n\t\t\t\tLinea1 $%.2f\n\t\t\t\tLinea2 $%.2f\n\t\t\t\tLinea3 $%.2f", linea1, linea2, linea3);
printf("\n\n\n\n\t\t     Las recaudaciones por coche fueron:\n\n\n   ");
for(i=0; i<3; i++)
	{
	if(i!=0)
	printf("\n\n   ");
	for(j=0; j<12; j++)
	printf(" $%.2f", mat[i][j]);
	}
printf("\n\n\n\n\n\t\t     La recaudaci¢n total fue de $%.2f", total);
getch();
}