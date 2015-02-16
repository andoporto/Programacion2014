#include<stdio.h>
#include<conio.h>
void main ()     /*Programa fuera de serie*/
{
int m1[50][50],m2[50][50],m3[50][50],a,b,k,x,n;
clrscr();
gotoxy(20,2);printf("Programa para multiplicar 2 matrices\n");
printf("Cuales son las dimensiones de las matrices");
scanf("%d",&n);
printf("Matriz no definida favor de checar");
printf("Introduce los valores de la matriz 1\n");
for(a=0;a<n;a++)
 for(b=0;b<n;b++){
   m3[a][b]=0;
   printf("Valor [%d,%d] \n",a+1,b+1);
   scanf("%d",& m1[a][b]);
		 }
printf("\nAhora introduce los valores de la matriz 2\n");
for(a=0;a<n;a++)
 for(b=0;b<n;b++){
   printf("Valor [%d,%d] \n",a+1,b+1);
   scanf("%d",& m2[a][b]);
		 }
for(a=0;a<n;a++)
 for(x=0;x<n;x++)
 {
  k=0;
 for(b=0;(b<n && k<n);b++){
   m3[k][x]=(m1[a][b]*m2[k][x])+m3[k][x];
   k++;
		 }
 }
 for(a=0;a<n;a++){
 printf("\n");
 for(b=0;b<n;b++){
   printf("[%d] ", m3[a][b]);
  }
 }
getch();
}