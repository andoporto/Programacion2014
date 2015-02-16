#include<stdio.h>
#include<conio.h>

void main()
{
textbackground(0);
clrscr();

char x;
x=getche();

printf("  %d",x);
	if(!x)
	{
	x=getche();
	printf("=  %d");
}
getch();

}
