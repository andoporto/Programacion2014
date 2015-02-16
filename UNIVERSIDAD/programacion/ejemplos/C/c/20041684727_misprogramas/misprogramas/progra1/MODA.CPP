#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[10],x,y,cont=0,d=0;
for(x=0;x<10;x++)
{
	printf("Introduce un valor: ");scanf("%d",&a[x]);
}
for(x=0;x<10;x++)
{
	for(y=1;y<=10;y++)
	{
		if(a[x]==a[y])
			cont++;
	}
	if(cont>d)
	{
		num=a[x];
		d=cont;
	}
}
getch();
}