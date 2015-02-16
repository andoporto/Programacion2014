#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define M 3

void main(void){

int mat[M][4], i, j, nota;
char seg, seguir;

for(i=0; i<M; i++)
{
clrscr();
mat[i][0]=i+1;
printf("Nota del 1╕ Trimestre: ");
scanf("%d", &mat[i][1]);
printf("\nNota del 2╕ Trimestre: ");
scanf("%d", &mat[i][2]);
printf("\nNota del 3╕ Trimestre: ");
scanf("%d", &mat[i][3]);
}
clrscr();
do
{
printf("Desea corregir alguna nota s/n?: ");
seg=getch();
seg=tolower(seg);
while(seg!='s' && seg!='n')
{
clrscr();
printf("Desea corregir alguna nota s/n?: ");
seg=getch();
seg=tolower(seg);
}
if(seg=='s')
{
clrscr();
printf("N╕ de legajo: ");
scanf("%d", &i);
	while(i>M || i<1)
	{
	clrscr();
	printf("N╕ de legajo: ");
	scanf("%d", &i);
	}
printf("\nTrimestre a corregir: ");
scanf("%d", &j);
	while(j>3 || j<1)
	{
	gotoxy(1,3);
	printf("Trimestre a corregir: ");
	scanf("%d", &j);
	}
printf("\nNueva nota: ");
scanf("%d", &nota);
clrscr();
printf("\nSu nota anterior era %d confirma cambiarla por %d s/n?: ", mat[i-1][j], nota);
seg = getch();
	while(seg!='s' && seg!='n')
	{
	clrscr();
	printf("\nSu nota anterior era %d confirma cambiarla por %d s/n?: ", mat[i-1][j], nota);
	seg=getch();
	seg=tolower(seg);
	}
}
if(seg=='s')
{
mat[i-1][j] = nota;
printf("\n\nDesea hacer otra modificaci╒n s/n?: ");
seguir=getch();
seguir=tolower(seguir);
clrscr();
	while(seguir!='s' && seguir!='n')
	{
	gotoxy(3,1);
	printf("\nDesea hacer otra modificaci╒n s/n?: ");
	seguir=getch();
	seguir=tolower(seguir);
	clrscr();
	}
}
else
{
clrscr();
printf("Desea continuar s/n?: ");
seguir=getch();
seguir=tolower(seguir);
	while(seguir!='s' && seguir!='n')
	{
	clrscr();
	printf("Desea continuar s/n?: ");
	seguir=getch();
	seguir=tolower(seguir);
	}
	clrscr();
}
}while(seguir=='s');
clrscr();
for(i=0; i<M; i++)
{
	if(i%46==0)
	{
	if(i>0)
	{
		printf("юдддддддддддддадддддддддддддадддддддддддддадддддддддддддаддддддддддддды");
		getch();
	}
	clrscr();
printf("    здддддддддддддбдддддддддддддбдддддддддддддбдддддддддддддбддддддддддддд©\n");
printf("    Ё  N╕ legajo  Ё 1╕Trimestre Ё 2╕Trimestre Ё 3╕Trimestre Ё  Promedio   Ё\n");
printf("    цдддддддддддддедддддддддддддедддддддддддддедддддддддддддеддддддддддддд╢\n    ");
	}
	printf("Ё%7d\t  Ё%7d      Ё%7d      Ё%7d      Ё     %.2f    Ё\n    ", mat[i][0], mat[i][1], mat[i][2], mat[i][3], ( mat[i][1] + mat[i][2] + mat[i][3]) / 3.0);
}
	printf("юдддддддддддддадддддддддддддадддддддддддддадддддддддддддаддддддддддддды");

getch();
}














