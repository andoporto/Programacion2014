#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
int a[50][50],b[50][50],c[50][50],ma[50][50];
int af,ac,bf,bc,x,y,f1,c1,f2,c2,i,j,k,m,ca,cb,fa,fb,fr,cr,q,p;

printf("De cuantas filas es la matriz a: ");scanf("%d",&af);
printf("De cuantas columnas es la matriz a: ");scanf("%d",&ac);
printf("De cuantas filas es la matriz b: ");scanf("%d",&bf);
printf("De cuantas columnas es la matriz b: ");scanf("%d",&bc);
if(!af==bc)
printf("Matriz no valida");
else
{
printf("Inserta la matriz A: ");
f1=8;
c1=8;
for(x=0;x<af;x++)
  {
	f1=8;
	c1=c1+2;
	for(y=0;y<ac;y++)
	  {
	  gotoxy(f1,c1);
	   scanf("%d",&a[x][y]);
	   f1=f1+2;
     }
}
printf("Inserta la matriz b: ");
f2=25;
c2=8;
for(i=0;i<af;i++)
  {
	f2=25;
	c2=c2+2;
	for(j=0;j<ac;j++)
	  {
	  gotoxy(f2,c2);
	   scanf("%d",&a[i][j]);
	   f2=f2+2;
 }}
for(fa=0;fa<af;fa++)
	for(ca=0;ca<ac;ca++)
		for(cb=0;cb<bc;cb++)
			for(fb=0;fb<bf;fb++)
			{
			ma[q][p]=a[x][y]*b[i][j];
			c[k][m]+=ma[q][p];
			}
printf("La matriz es: ");
fr=25;
cr=25;
for(k=0;k<ca;k++)
	{
	fr=25;
	cr=cr+2;
		for(m=0;m<fa;m++)
	{
	gotoxy(fr,cr);
	printf("%d",c[k][m]);
	fr=fr+2;
}}
}

getch();
}
