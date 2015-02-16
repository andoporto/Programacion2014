#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[3][3],b[3][3],x[3][3],f,c,cont,i=12,fa,fb,ca,cb,suma=0,d=0,xx;
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
			gotoxy(15,7);printf("Elemento a[%d][%d] : ",f,c);
			scanf("%d",&a[f][c]);
		}
	}
	for(f=0;f<fb;f++)
	{
		for(c=0;c<cb;c++)
		{
			gotoxy(15,9);printf("Elemento b[%d][%d] : ",f,c);
			scanf("%d",&b[f][c]);
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
	i=10;
	for(f=0;f<fa;f++)
	{
		printf("\n");
		for(c=0;c<ca;c++)
		{
			gotoxy(15+c,i);printf("%d",a[f][c]);
		}
		i++;
	}
	gotoxy(25,12);printf("*");
	i=10;
	for(f=0;f<fb;f++)
	{
		printf("\n");
		for(c=0;c<cb;c++)
		{
			gotoxy(35+c,i);printf("%d",b[f][c]);
		}
		i++;
	}
//	i=12;
//	for(c=0;c<cb;c++)
//	{
//		printf("\n");
//		for(f=0;f<fa;f++)
//		{
//			gotoxy(55+c,i);printf("%d",x[f][c]);
//		}
//		i++;
//	}
	i=10;
	for(f=0;f<fa;f++)
	{
//	d+=2;
		printf("\n");
		for(xx=0;xx<cb;xx++)
		{
/*			gotoxy(53+d,i);*/printf(" %d ",x[f][xx]);
		}
		i++;
	}
}
else
	{
		gotoxy(26,24);printf("No se pueden multiplicar!!!");
	}
getch();
}
//  c[2][1]=((a[1][1]*b[1][1])+(a[1][2]*b[2][1])+(a[1][3]*b[3][1]));