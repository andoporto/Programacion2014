#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<stdio.h>

int ta, tb, tc, td, cuantum=5;
int porprocesar[4]={'A','B','C','D'};
int procesados[4]={' ',' ',' ',' '};
int ultimo=0;
int sobran=3;

void actualizar(int tiempo)
{
if(tiempo==0)
	{
	procesados[ultimo++]=porprocesar[0];
	porprocesar[0]=porprocesar[1];
	porprocesar[1]=porprocesar[2];
	porprocesar[2]=porprocesar[3];
	porprocesar[3]=' ';
	sobran--;
	}
else
	{
	char tmp=porprocesar[0];
	porprocesar[0]=porprocesar[1];
	porprocesar[1]=porprocesar[2];
	porprocesar[2]=porprocesar[3];
	porprocesar[3]=' ';
	porprocesar[sobran]=tmp;
	}
gotoxy(31, 5);printf("บ %c บ %c บ %c บ %c บ", procesados[0], procesados[1], procesados[2], procesados[3]);
gotoxy(31,12);printf("บ %c บ %c บ %c บ %c บ", porprocesar[0], porprocesar[1], porprocesar[2], porprocesar[3]);
}

void procesara()
{
do
	{
	gotoxy(39,9);printf("A");
	gotoxy(12,8);
	printf("Tiempo restante de A");gotoxy(31,9);
	printf("");gotoxy(31,10);
	printf("%d  ", ta); gotoxy(47, 8);
	printf("Tiempo restante de cuantum");gotoxy(47,9);
	printf("");gotoxy(47,10);
	printf("%d  ", cuantum);
	if(ta>0 && cuantum>0)
		ta--;
	cuantum--;
	delay(1000);
	}
while(cuantum>=0);
cuantum=5;
actualizar(ta);
}

void procesarb()
{
do
	{
	gotoxy(39,9);printf("B");
	gotoxy(12,8);
	printf("Tiempo restante de B");gotoxy(31,9);
	printf("");gotoxy(31,10);
	printf("%d  ", tb); gotoxy(47, 8);
	printf("Tiempo restante de cuantum");gotoxy(47,9);
	printf("");gotoxy(47,10);
	printf("%d  ", cuantum);
	if(tb>0 && cuantum>0)
		tb--;
	cuantum--;
	delay(1000);
	}
while(cuantum>=0);
cuantum=5;
actualizar(tb);
}

void procesarc()
{
do
	{
	gotoxy(39,9);printf("C");
	gotoxy(12,8);
	printf("Tiempo restante de C");gotoxy(31,9);
	printf("");gotoxy(31,10);
	printf("%d  ", tc); gotoxy(47, 8);
	printf("Tiempo restante de cuantum");gotoxy(47,9);
	printf("");gotoxy(47,10);
	printf("%d  ", cuantum);
	if(tc>0 && cuantum>0)
		tc--;
	cuantum--;
	delay(1000);
	}
while(cuantum>=0);
cuantum=5;
actualizar(tc);
}

void procesard()
{
do
	{
	gotoxy(39,9);printf("D");
	gotoxy(12,8);
	printf("Tiempo restante de D");gotoxy(31,9);
	printf("");gotoxy(31,10);
	printf("%d  ", td); gotoxy(47, 8);
	printf("Tiempo restante de cuantum");gotoxy(47,9);
	printf("");gotoxy(47,10);
	printf("%d  ", cuantum);
	if(td>0 && cuantum>0)
		td--;
	cuantum--;
	delay(1000);
	}
while(cuantum>=0);
cuantum=5;
actualizar(td);
}

void dibuja()
{
gotoxy(31, 3);printf("   PROCESADOS    ");
gotoxy(31, 4);printf("ษอออหอออหอออหอออป");
gotoxy(31, 5);printf("บ   บ   บ   บ   บ");
gotoxy(31, 6);printf("ศอออสอออสอออสอออผ");
gotoxy(31, 7);printf("    ษอออออออป    ");
gotoxy(31, 8);printf("    บ C P U บ    ");
gotoxy(31, 9);printf("    บ       บ    ");
gotoxy(31,10);printf("    ศอออออออผ    ");
gotoxy(31,11);printf("ษอออหอออหอออหอออป");
gotoxy(31,12);printf("บ A บ B บ C บ D บ");
gotoxy(31,13);printf("ศอออสอออสอออสอออผ");
gotoxy(31,14);printf("   POR PROCESAR  ");
}

void main()
{
clrscr();
cout<<"จDe cu nto va a ser el proceso A? (El cuantum es de 5) ";
cin>>ta;
cout<<"จDe cu nto va a ser el proceso B? (El cuantum es de 5) ";
cin>>tb;
cout<<"จDe cu nto va a ser el proceso C? (El cuantum es de 5) ";
cin>>tc;
cout<<"จDe cu nto va a ser el proceso D? (El cuantum es de 5) ";
cin>>td;
clrscr();
dibuja();
do
	{
	if (ta>0)
		procesara();
	if (tb>0)
		procesarb();
	if (tc>0)
		procesarc();
	if (td>0)
		procesard();
	}
while(ta>0 || tb>0 || tc>0 || td>0);
getch();
}