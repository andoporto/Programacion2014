#include<stdio.h>
#include<conio.h>
#include<DOS.H>
void main()
{
 int i,j,n,mat[20][20],c,existe=0;
 clrscr();
 textcolor(15);
 printf("Programa que analiza las propiedades de la matriz de una relacion.\n");
 printf("La matriz tiene que ser cuadrada.");
 delay(6000);
 clrscr();
 printf("Teclea el numero de filas o columnas de la matriz: ");
 scanf("%d", &n);
 clrscr();
 printf("Acontinuacion el programa te preguntara si existe el par ordenado \n");
 printf(" en la relacion, teclea 1 si existe o 0 si no existe.");
 delay(10000);
 clrscr();
 for (i=0;i<n;i++)
	  for(j=0;j<n;j++)
		  mat[i][j]=0;
 for (i=0;i<n;i++)
	 for (j=0;j<n;j++)
		{
		 printf("El par %d,%d existe?" ,i,j);
		 scanf("%d", &existe);
		 mat[i][j]=existe;
		}
 for (i=0;i<n;i++)
	 for (j=0;j<n;j++)
		 printf("\n %d ", mat[i][j]);
 if ((mat[i][j]==1)&&(i==j))
	printf("La matriz es reflexiva\n");
 if ((mat[i][j]==0)&&(i==j))
	printf("La matriz es irreflexiva\n");
 if ((mat[i][j]==1)&&(mat[j][i]==1))
	if ((mat[i][j]==0)&&(mat[j][i]==0))
	   printf("La matriz es simetrica.");
 if ((mat[i][j]==0)&&(i==j))
	if ((mat[i][j]==1)&&(mat[j][i]==0))
	   printf("La matriz es asimetrica");
 if ((mat[i][j]==1)&&(mat[j][i]==0))
	printf("La matriz es antisimetrica");
 getch();
}