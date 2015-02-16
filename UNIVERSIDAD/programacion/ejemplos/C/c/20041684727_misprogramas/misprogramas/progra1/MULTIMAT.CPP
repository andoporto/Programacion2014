#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[3][3],b[3][3],x[3][3],f,c,cont,i=12,fa,fb,ca,cb,suma=0,d,xx;
gotoxy(5,12);printf("Matriz a de cuantas filas?: ");scanf("%d",&fa);
gotoxy(45,12);printf("Matriz a de cuantas columnas?: ");scanf("%d",&ca);
gotoxy(5,14);printf("Matriz b de cuantas filas?: ");scanf("%d",&fb);
gotoxy(45,14);printf("Matriz b de cuantas columnas?: ");scanf("%d",&cb);
clrscr();
if(ca==fb)
{
	for(f=0;f<fa;f++)
	{
		for(c=0;c<ca;c++)
		{
			gotoxy(15,7);printf("Elemento a[%d][%d] : ",f+1,c+1);
			scanf("%d",&a[f][c]);gotoxy(34,7);clreol();
		}
		gotoxy(25,12);printf("Matriz a completa!");clrscr();
	}
	for(f=0;f<fb;f++)
	{
		for(c=0;c<cb;c++)
		{
			gotoxy(15,9);printf("Elemento b[%d][%d] : ",f+1,c+1);
			scanf("%d",&b[f][c]);gotoxy(34,9);clreol();
		}
	}
d=0;
	for(f=0;f<fa;f++)
	{
	suma=0;
		for(xx=0;xx<cb;xx++)
		{
		suma=0;
			for(c=0;c<ca;c++)
			{
				suma+=a[f][c]*b[c][xx];
			}
			d++;
			x[f][xx]=suma;
			suma=0;
		}
	}
	clrscr();
	gotoxy(20,5);
	i=10;
	for(f=0;f<fa;f++)
	{
		gotoxy(20,i);
		for(c=0;c<ca;c++)
		{
			printf("%d",a[f][c]);
		}
		i++;
	}
	gotoxy(30,11);printf("*");
	i=10;
	for(f=0;f<fb;f++)
	{
		gotoxy(35,i);
		for(c=0;c<cb;c++)
		{
			printf("%d",b[f][c]);
		}
		i++;
	}
	gotoxy(40,11);printf("=");
	i=10;
	for(f=0;f<fa;f++)
	{
		gotoxy(45,i);
		for(xx=0;xx<cb;xx++)
		{
			printf(" %d ",x[f][xx]);
		}
		i++;
	}
}
else
	{
		gotoxy(26,12);printf("No se pueden multiplicar!!!");
	}
getch();
}
