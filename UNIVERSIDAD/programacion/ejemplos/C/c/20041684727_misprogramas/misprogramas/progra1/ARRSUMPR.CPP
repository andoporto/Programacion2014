#include<stdio.h>
#include<conio.h>
void main()
{         //Como hacerle para que el scanf no de un salto de linea??
clrscr();
int suma=0,prom=0,mayor=-32768,menor=32767;
int arr[4][3],i,j;
for(i=0;i<4;i++)
{
	for(j=0;j<3;j++)
	{
		printf("Fila %d Columna %d:  ",i+1,j+1);  scanf("%d",&arr[i][j]);
		suma=suma+arr[i][j];
	}
	printf("\n");
}
prom=suma/12;
for(i=0;i<4;i++)
{
	for(j=0;j<3;j++)
	{
		if(arr[i][j]>mayor)
			mayor=arr[i][j];
		if(arr[i][j]<menor)
			menor=arr[i][j];
	}
}
printf("Promedio: %d\nMayor: %d\nMenor: %d",prom,mayor,menor);
getch();
}