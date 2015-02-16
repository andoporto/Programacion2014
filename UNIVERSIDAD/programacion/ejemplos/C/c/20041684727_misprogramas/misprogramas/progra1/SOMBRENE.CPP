//Diana Ivonne Aceves Ruelas
//26 de marzo del 2004
//Programaci¢n
	   /* Menu con flechas de direccion y sombreado */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
char x;
int cont=1, prim=1;
textbackground(1);
clrscr();
while(x!=27)
{
	textbackground(1);
	gotoxy(25,6);printf("M E N U    P R I N C I P A L");
	if (prim==1)
	{
		textbackground(3);
		gotoxy(32,10);cprintf("Altas");
		prim=0;
		textbackground(1);
	}
	else
	{
		gotoxy(32,10);printf("Altas");
	}
	gotoxy(32,12);printf("Bajas");
	gotoxy(32,14);printf("Modificaciones");
	gotoxy(32,16);printf("Consultas");
	gotoxy(32,18);printf("Reportes");
	gotoxy(32,20);printf("Salir");gotoxy(37,20);clreol();
	x=getche();
	switch(x)
	{
		case 72: cont--;
				if(cont==0)
					cont=6;
				break;
		case 80: cont++;
				if(cont==7)
					cont=1;
				break;
		case 13: if(cont==6)
					exit(0);
	}
	switch(cont)
	{
		case 1: textbackground(3);gotoxy(32,10);cprintf("Altas");
				textbackground(1);gotoxy(32,20);cprintf("Salir");
				textbackground(1);gotoxy(32,12);cprintf("Bajas");
				break;

		case 2: textbackground(3);gotoxy(32,12);cprintf("Bajas");
				textbackground(1);gotoxy(32,10);cprintf("Altas");
				textbackground(1);gotoxy(32,14);cprintf("Modificaciones");
				break;

		case 3: textbackground(3);gotoxy(32,14);cprintf("Modificaciones");
				textbackground(1);gotoxy(32,12);cprintf("Bajas");
				textbackground(1);gotoxy(32,16);cprintf("Consultas");
				break;

		case 4: textbackground(3);gotoxy(32,16);cprintf("Consultas");
				textbackground(1);gotoxy(32,14);cprintf("Modificaciones");
				textbackground(1);gotoxy(32,18);cprintf("Reportes");
				break;

		case 5: textbackground(3);gotoxy(32,18);cprintf("Reportes");
				textbackground(1);gotoxy(32,16);cprintf("Consultas");
				textbackground(1);gotoxy(32,20);cprintf("Salir");
				break;

		case 6: textbackground(3);gotoxy(32,20);cprintf("Salir");
				textbackground(1);gotoxy(32,10);cprintf("Altas");
				textbackground(1);gotoxy(32,18);cprintf("Reportes");
				break;

	}
}
}