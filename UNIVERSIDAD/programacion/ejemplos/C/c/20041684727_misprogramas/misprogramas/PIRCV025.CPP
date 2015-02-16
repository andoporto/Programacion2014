#include<stdio.h>
#include<conio.h>
void main()
		   {
			int i;
			clrscr();
			for (i=1;i<=80;i++)
				{
				 gotoxy (i,5);
				 printf("*");
				 getch();
				}
		   }