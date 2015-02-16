#include<stdio.h>
#include<conio.h>
void main()                     //esta mal
{
clrscr();
int f,c,A[2][2],B[2][2],C[2][2];
printf("programa para leer una matriz y visualizar su contenido\n\n");
C[2][2]=0;
for(f=0;f<2;f++)
   for(c=0;c<2;c++)
   {
   printf("MA %d%d = ",f,c);
    scanf("%d",&A[f][c]);
   printf("MB %d%d = ",f,c);
    scanf("%d",&B[f][c]);
   C[f][c]=A[f][c]+B[f][c];
   }
   printf("M= %d%d ",C[f][c]);
getch();
}