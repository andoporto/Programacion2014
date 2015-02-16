#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[3][3],b[3][3],x[3][3],f,c,cont,t=16,i=12,j=12,k=12;
for(f=0;f<3;f++)
{
	for(c=0;c<3;c++)
	{
		gotoxy(15,7);printf("Elemento a[%d][%d] : ",f,c);
		scanf("%d",&a[f][c]);
		gotoxy(15,9);printf("Elemento b[%d][%d] : ",f,c);
		scanf("%d",&b[f][c]);
	}
}
for(f=0;f<3;f++)
{
	if(cont>=9)
		for(c=0;c<3;c++)
		{
			x[f][c]=((a[f][c]*b[c][f])+(a[f][++c]*b[++f][c])+(a[f][++c]*b[++f][c]));
			cont++;
		}
}
clrscr();
for(f=0;f<3;f++)
{
	printf("\n");
	for(c=0;c<3;c++)
	{
		gotoxy(15+c,i);printf("%d",a[f][c]);
	}
	i++;
}
gotoxy(25,13);printf("*");
for(f=0;f<3;f++)
{
	printf("\n");
	for(c=0;c<3;c++)
	{
		gotoxy(35+c,j);printf("%d",b[f][c]);
	}
	j++;
}
for(f=0;f<3;f++)
{
	printf("\n");
	for(c=0;c<3;c++)
	{
		gotoxy(55+c,k);printf("%d",x[f][c]);
	}
	k++;
}

getch();
}
//  c[2][1]=((a[1][1]*b[1][1])+(a[1][2]*b[2][1])+(a[1][3]*b[3][1]));