#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
clrscr();
char nombre[5][50],sexo[5];
float prom[5];
int edad[5],i;
for(i=0;i<5;i++)
{
	clrscr();
	gotoxy(20,8);printf("Regristro: %d ",i+1);
	gotoxy(20,11);printf("Cual es tu nombre: ");/* nombre=toupper(nombre)*/;fflush(stdin);gets(nombre[i]);
	gotoxy(20,12);printf("Cual es tu edad: ");fflush(stdin);scanf("%d",&edad[i]);
	gotoxy(20,13);printf("Cual es tu sexo: ");/*sexo=toupper(sexo);*/fflush(stdin);scanf("%c",&sexo[i]);
	gotoxy(20,14);printf("Cual es tu promedio: ");fflush(stdin);scanf("%f",&prom[i]);
}
for(i=0;i<5;i++)
{
	clrscr();
	gotoxy(20,8);printf("Regristro: %d ",i+1);
	gotoxy(20,10);printf(" Nombre: %s ",nombre[i]);
	gotoxy(20,11);printf(" Edad: %d ",edad[i]);
	gotoxy(20,12);printf(" Sexo: %c ",sexo[i]);
	gotoxy(20,13);printf(" Promedio: %.2f ",prom[i]);
	printf("\n");
	getch();
}
//getch();
}