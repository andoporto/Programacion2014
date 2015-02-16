#include<stdio.h>
#include<conio.h>

void main ()
{
int m1[50][50],m2[50][50],m3[50][50],i,j,k,l,m;
clrscr();
printf("dame el numero de filas y columnas:  ");
scanf("%d",&m);

printf("dame los valores de la matriz 1\n");
for(i=0;i<m;i++)
 for(j=0;j<m;j++){
   m3[i][j]=0;
   printf("Valor [%d,%d] \n",i+1,j+1);
   scanf("%d",& m1[i][j]);
		 }
printf("dame los valores de la matriz 2\n");
for(i=0;i<m;i++)
 for(j=0;j<m;j++){
   printf("Valor [%d,%d] \n",i+1,j+1);
   scanf("%d",& m2[i][j]);
		 }
for(i=0;i<m;i++)

 for(l=0;l<m;l++)
 {
  k=0;

 for(j=0;(j<m && k<m);j++){

   m3[k][l]=(m1[i][j]*m2[k][l])+m3[k][l];
   k++;


		 }
 }

 for(i=0;i<m;i++){
 printf("\n");
 for(j=0;j<m;j++){
   printf("[%d] ", m3[i][j]);
		 }
		 }

getch();
}