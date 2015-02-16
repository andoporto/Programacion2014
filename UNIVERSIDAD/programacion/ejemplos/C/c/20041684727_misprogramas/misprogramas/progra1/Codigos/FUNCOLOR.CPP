#include<stdio.h>
#include<conio.h>

void pinta_cuadro(int x1,int y1,int x2,int y2, int color, char c)
{
 textcolor(color);
 for(int i=x1;i<x2;i++)
	{
	gotoxy(i,y1);
   cprintf("%c",c);
	gotoxy(i,y2);
   cprintf("%c",c);
	}

  for(int j=y1;j<y2;j++)
	{
	gotoxy(x1,j);
   cprintf("%c",c);
	gotoxy(x2,j);
   cprintf("%c",c);
	}
}

void main()
{
clrscr();
pinta_cuadro(15,2,50,10,4,'c');
pinta_cuadro(1,1,52,20,5,'c');
getch();
}
























